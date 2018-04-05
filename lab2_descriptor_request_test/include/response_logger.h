

#ifndef PROJECT_RESPONSE_LOGGER_H
#define PROJECT_RESPONSE_LOGGER_H

#include <zb_zdo.h>
#include <simple_descr_parser.h>

void log_ieee_addr_resp(zb_zdo_nwk_addr_resp_head_t *resp);

void log_node_descr_resp(zb_zdo_node_desc_resp_t *resp);
void log_power_descr_resp(zb_zdo_power_desc_resp_t *resp);
void log_active_ep_descr_resp(zb_zdo_ep_resp_t *resp, zb_uint8_t *ep_list);
void log_simple_descr_resp(zb_zdo_simple_desc_resp_t* resp, simple_descr_cluster_list_t *cl_list);

#endif //PROJECT_RESPONSE_LOGGER_H
