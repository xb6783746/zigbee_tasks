
#include <common.h>
#include "zb_common.h"
#include "zb_aps.h"
#include "zb_zdo.h"
#include "zb_secur_api.h"
#include "command_generator.h"

/*! \addtogroup ZB_TESTS */
/*! @{ */

#ifndef ZB_COORDINATOR_ROLE
#error Coordinator role is not compiled!
#endif

#ifndef ZB_SECURITY
#error Define ZB_SECURITY
#endif


zb_ieee_addr_t g_ieee_addr = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08};
zb_uint8_t g_key[16] = {0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0, 0, 0, 0, 0, 0, 0, 0};

void data_indication(zb_uint8_t param) ZB_CALLBACK;

MAIN()
{
    ARGV_UNUSED;

    if (argc < 3)
    {
        printf("%s <read pipe path> <write pipe path>\n", argv[0]);
        return 0;
    }

    ZB_INIT("zdo_zc", argv[1], argv[2]);

    ZB_IEEE_ADDR_COPY(ZB_PIB_EXTENDED_ADDRESS(), &g_ieee_addr);

    /* let's always be coordinator */
    ZB_AIB().aps_designated_coordinator = 1;

    zb_secur_setup_preconfigured_key(g_key, 0);

    if (zdo_dev_start() != RET_OK)
    {
        TRACE_MSG(TRACE_ERROR, "zdo_dev_start failed", (FMT__0));
    } else
    {
        zdo_main_loop();
    }

    TRACE_DEINIT();

    MAIN_RETURN(0);
}

void zb_zdo_startup_complete(zb_uint8_t param) ZB_CALLBACK
{
    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    if (buf->u.hdr.status == 0)
    {
        TRACE_MSG(TRACE_APS1, "Device STARTED OK", (FMT__0));

        zb_af_set_data_indication(data_indication);
    } else
    {
        TRACE_MSG(TRACE_ERROR, "Device started FAILED status %d", (FMT__D, (int) buf->u.hdr.status));
    }

    zb_free_buf(buf);
}


void data_indication(zb_uint8_t param) ZB_CALLBACK
{
    zb_ushort_t i;
    zb_uint8_t *ptr;
    zb_buf_t *asdu = (zb_buf_t *) ZB_BUF_FROM_REF(param);

    zb_apsde_data_indication_t *ind = ZB_GET_BUF_PARAM(asdu, zb_apsde_data_indication_t);

    zb_uint16_t src_addr = ind->src_addr;

    ZB_BUF_INITIAL_ALLOC(asdu, sizeof(src_addr), ptr);

    *((zb_uint16_t *) (ptr)) = src_addr;

    command_generator_generate(ind->src_addr);
}

/*! @} */
