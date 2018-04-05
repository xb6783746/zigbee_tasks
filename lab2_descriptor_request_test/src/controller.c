

#include <zb_common.h>
#include <zb_zdo.h>
#include <controller.h>
#include <response_callbacks.h>


static void send_ieee_addr_req(zb_uint8_t param);
static void send_node_descr_req(zb_uint8_t param);
static void send_power_descr_req(zb_uint8_t param);
static void send_active_ep_req(zb_uint8_t param);

zb_uint8_t get_buf(zb_uint16_t nwk_addr){

    zb_buf_t *buf = zb_get_in_buf();

    zb_uint16_t *nwk = ZB_GET_BUF_PARAM(buf, zb_uint16_t);
    *nwk = nwk_addr;

    return ZB_REF_FROM_BUF(buf);
}
void start(zb_uint16_t nwk_addr) {

    ZB_SCHEDULE_ALARM(send_ieee_addr_req, get_buf(nwk_addr), ZB_TIME_ONE_SECOND*1);
    ZB_SCHEDULE_ALARM(send_node_descr_req, get_buf(nwk_addr), ZB_TIME_ONE_SECOND*2);
    ZB_SCHEDULE_ALARM(send_power_descr_req, get_buf(nwk_addr), ZB_TIME_ONE_SECOND*3);
    ZB_SCHEDULE_ALARM(send_active_ep_req, get_buf(nwk_addr), ZB_TIME_ONE_SECOND*4);
}

static void send_ieee_addr_req(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    zb_uint16_t nwk_addr = *ZB_GET_BUF_PARAM(buf, zb_uint16_t);

    zb_zdo_ieee_addr_req_t *req = NULL;

    ZB_BUF_INITIAL_ALLOC(buf, sizeof(zb_zdo_ieee_addr_req_t), req);

    req->nwk_addr = nwk_addr;
    req->request_type = ZB_ZDO_SINGLE_DEV_RESPONSE;
    req->start_index = 0;

    zb_zdo_ieee_addr_req(param, ieee_addr_resp_callback);
}
static void send_node_descr_req(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    zb_uint16_t nwk_addr = *ZB_GET_BUF_PARAM(buf, zb_uint16_t);

    zb_zdo_node_desc_req_t *req;

    ZB_BUF_INITIAL_ALLOC(buf, sizeof(zb_zdo_node_desc_req_t), req);
    req->nwk_addr = nwk_addr;

    zb_zdo_node_desc_req(param, node_descr_resp_callback);

}
static void send_power_descr_req(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    zb_uint16_t nwk_addr = *ZB_GET_BUF_PARAM(buf, zb_uint16_t);

    zb_zdo_power_desc_req_t *req;

    ZB_BUF_INITIAL_ALLOC(buf, sizeof(zb_zdo_power_desc_req_t), req);
    req->nwk_addr = nwk_addr;

    zb_zdo_power_desc_req(param, power_descr_resp_callback);

}
static void send_active_ep_req(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    zb_uint16_t nwk_addr = *ZB_GET_BUF_PARAM(buf, zb_uint16_t);

    zb_zdo_active_ep_req_t *req;

    ZB_BUF_INITIAL_ALLOC(buf, sizeof(zb_zdo_active_ep_req_t), req);
    req->nwk_addr = nwk_addr;

    zb_zdo_active_ep_req(param, active_ep_descr_resp_callback);
}
