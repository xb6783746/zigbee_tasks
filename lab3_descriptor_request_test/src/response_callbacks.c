
#include <zb_common.h>
#include <response_callbacks.h>
#include <response_logger.h>
#include <zb_aps.h>

static void simple_descr_resp_callback(uint8_t param);

void ieee_addr_resp_callback(zb_uint8_t param)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_zdo_nwk_addr_resp_head_t *resp;
    resp = (zb_zdo_nwk_addr_resp_head_t *) ZB_BUF_BEGIN(buf);

    log_ieee_addr_resp(resp);
}

void node_descr_resp_callback(zb_uint8_t param)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_node_desc_resp_t *resp = (zb_zdo_node_desc_resp_t *) (zdp_cmd);

    log_node_descr_resp(resp);
}

void power_descr_resp_callback(zb_uint8_t param)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_power_desc_resp_t *resp = (zb_zdo_power_desc_resp_t *) (zdp_cmd);

    log_power_descr_resp(resp);
}

void active_ep_descr_resp_callback(zb_uint8_t param)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_ep_resp_t *resp = (zb_zdo_ep_resp_t *) zdp_cmd;
    zb_uint8_t *ep_list = zdp_cmd + sizeof(zb_zdo_ep_resp_t);

    log_active_ep_descr_resp(resp, ep_list);

    zb_uint16_t nwk = resp->nwk_addr;
    zb_uint8_t ep = ep_list[0];

    zb_zdo_simple_desc_req_t *req;

    ZB_BUF_INITIAL_ALLOC(buf, sizeof(zb_zdo_simple_desc_req_t), req);
    req->nwk_addr = nwk;
    req->endpoint = ep;

    zb_zdo_simple_desc_req(param, simple_descr_resp_callback);
}

static void simple_descr_resp_callback(uint8_t param)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);
    zb_uint8_t *zdp_cmd = ZB_BUF_BEGIN(buf);
    zb_zdo_simple_desc_resp_t *resp = (zb_zdo_simple_desc_resp_t *) (zdp_cmd);

    simple_descr_cluster_list_t cluster_list;
    parse_simple_descr_cluster_list(&resp->simple_desc, &cluster_list);

    log_simple_descr_resp(resp, &cluster_list);

    zb_buf_t *out_buf = zb_get_out_buf();

    zb_apsde_data_req_t *req;
    ZB_BUF_INITIAL_ALLOC(out_buf, 10, req);
    req = ZB_GET_BUF_TAIL(out_buf, sizeof(zb_apsde_data_req_t));

    req->dst_addr.addr_short = resp->hdr.nwk_addr;
    req->addr_mode = ZB_APS_ADDR_MODE_16_ENDP_PRESENT;
    req->tx_options = ZB_APSDE_TX_OPT_ACK_TX;
    req->radius = 1;
    req->profileid = resp->simple_desc.app_profile_id;
    req->src_endpoint = resp->simple_desc.endpoint;
    req->dst_endpoint = resp->simple_desc.endpoint;
    req->clusterid = cluster_list.input_clusters[0];
    out_buf->u.hdr.handle = 0x11;

    ZB_SCHEDULE_CALLBACK(zb_apsde_data_request, ZB_REF_FROM_BUF(out_buf));
}