

#ifndef PROJECT_RESPONSE_CALLBACK_H
#define PROJECT_RESPONSE_CALLBACK_H

#include <zb_zdo.h>

void ieee_addr_resp_callback(zb_uint8_t param);

void node_descr_resp_callback(zb_uint8_t param);
void power_descr_resp_callback(zb_uint8_t param);
void active_ep_descr_resp_callback(zb_uint8_t param);
#endif //PROJECT_RESPONSE_CALLBACK_H
