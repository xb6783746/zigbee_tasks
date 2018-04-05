
#include <zb_common.h>
#include <response_callbacks.h>
#include <response_logger.h>
#include <zb_aps.h>

static void simple_descr_resp_callback(uint8_t param);

void ieee_addr_resp_callback(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_zdo_nwk_addr_resp_head_t *resp;
    resp = (zb_zdo_nwk_addr_resp_head_t*)ZB_BUF_BEGIN(buf);

    log_ieee_addr_resp(resp);
}

void node_descr_resp_callback(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_node_desc_resp_t *resp = (zb_zdo_node_desc_resp_t*)(zdp_cmd);

    log_node_descr_resp(resp);
}

void power_descr_resp_callback(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_power_desc_resp_t *resp = (zb_zdo_power_desc_resp_t*)(zdp_cmd);

    log_power_descr_resp(resp);
}

void active_ep_descr_resp_callback(zb_uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_ep_resp_t *resp = (zb_zdo_ep_resp_t*)zdp_cmd;
    zb_uint8_t *ep_list = zdp_cmd + sizeof(zb_zdo_ep_resp_t);

    log_active_ep_descr_resp(resp, ep_list);
}

static void simple_descr_resp_callback(uint8_t param){

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_simple_desc_resp_t *resp = (zb_zdo_simple_desc_resp_t*)(zdp_cmd);

    simple_descr_cluster_list_t cluster_list;
    parse_simple_descr_cluster_list(&resp->simple_desc, &cluster_list);

    log_simple_descr_resp(resp, &cluster_list);
}