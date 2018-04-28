
#include <common.h>
#include <button_controller.h>
#include <init.h>
#include "zb_aps.h"
#include "zb_zdo.h"

/*! \addtogroup ZB_TESTS */
/*! @{ */

#ifndef ZB_COORDINATOR_ROLE
#error Coordinator role is not compiled!
#endif


zb_ieee_addr_t g_zc_addr = {0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa};

void data_indication(zb_uint8_t param) ZB_CALLBACK;

MAIN()
{
    ARGV_UNUSED;


    /* Init device, load IB values from nvram or set it to default */
#ifndef ZB8051
    ZB_INIT("zdo_zc", argv[1], argv[2]);
#else
    ZB_INIT("zdo_zc", "1", "1");
#endif
#ifdef ZB_SECURITY
    ZG->nwk.nib.security_level = 0;
#endif
    ZB_IEEE_ADDR_COPY(ZB_PIB_EXTENDED_ADDRESS(), &g_zc_addr);

    /* let's always be a coordinator */
    ZB_AIB().aps_designated_coordinator = 1;
    ZB_AIB().aps_channel_mask = (1l << 22);

    init_buttons();
    init_interrupts();

    if (zdo_dev_start() != RET_OK)
    {
        TRACE_MSG(TRACE_ERROR, "zdo_dev_start failed", (FMT__0));
    }
    else
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
    }
    else
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

    button_controller_init(ind->src_addr);
}

/*! @} */
