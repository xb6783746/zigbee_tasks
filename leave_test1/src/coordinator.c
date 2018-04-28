
#include "zb_common.h"
#include "zb_scheduler.h"
#include "zb_bufpool.h"
#include "zb_nwk.h"
#include "zb_aps.h"
#include "zb_zdo.h"
#include "zb_secur.h"
#include "zb_secur_api.h"

/*! \addtogroup ZB_TESTS */
/*! @{ */

#ifndef ZB_COORDINATOR_ROLE
#error Coordinator role is not compiled!
#endif

#ifndef ZB_SECURITY
#error Define ZB_SECURITY
#endif

#define ARRAY_SIZE 2

zb_ieee_addr_t g_ieee_addr = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08};
zb_uint8_t g_key[16] = { 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0, 0, 0, 0, 0, 0, 0, 0};

zb_uint16_t ed_addrs[ARRAY_SIZE];
zb_size_t count = 0;

void data_indication(zb_uint8_t param) ZB_CALLBACK;

void leave_callback(zb_uint8_t param) ZB_CALLBACK ;

void kick(zb_uint8_t param);

void kick_all(zb_uint8_t param);

int entry_point(int argc, char **argv)
{
    ARGV_UNUSED;

    if ( argc < 3 )
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
        TRACE_MSG(TRACE_ERROR, "Device started FAILED status %d", (FMT__D, (int)buf->u.hdr.status));
    }

    zb_free_buf(buf);
}

void data_indication(zb_uint8_t param) ZB_CALLBACK
{
    zb_buf_t *asdu = ZB_BUF_FROM_REF(param);

    zb_apsde_data_indication_t *ind = ZB_GET_BUF_PARAM(asdu, zb_apsde_data_indication_t);

    if(count < ARRAY_SIZE) {

        ed_addrs[count] = ind->src_addr;
        count++;
    }

    if(count == ARRAY_SIZE){

        ZB_SCHEDULE_ALARM(kick_all, 0, ZB_TIME_ONE_SECOND * 3);
    }
}

void kick_all(zb_uint8_t param){

    for(zb_size_t i = 0; i < ARRAY_SIZE; i++) {

        zb_buf_t *buf = zb_get_out_buf();

        zb_uint16_t *addr = ZB_GET_BUF_PARAM(buf, uint16_t);
        *addr = ed_addrs[i];

        ZB_SCHEDULE_ALARM(kick, ZB_REF_FROM_BUF(buf), ZB_TIME_ONE_SECOND * i);
    }
}

void kick(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    zb_uint16_t ed_addr =  *ZB_GET_BUF_PARAM(buf, zb_uint16_t);
    zb_zdo_mgmt_leave_param_t *req = ZB_GET_BUF_PARAM(buf, zb_zdo_mgmt_leave_param_t);

    ZB_MEMSET(req->device_address, 0, sizeof(zb_ieee_addr_t));
    req->remove_children = ZB_FALSE;
    req->rejoin = ZB_FALSE;
    req->dst_addr = ed_addr;

    zdo_mgmt_leave_req(param, leave_callback);
}

void leave_callback(zb_uint8_t param) ZB_CALLBACK {

    zb_uint8_t *ret = (zb_uint8_t *)ZB_BUF_BEGIN(ZB_BUF_FROM_REF(param));
    TRACE_MSG(TRACE_ERROR, "LEAVE resp status: %x", (FMT__D, *ret));
}

/*! @} */
