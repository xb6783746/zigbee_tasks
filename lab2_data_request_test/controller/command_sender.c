

#include <common.h>
#include "zb_common.h"
#include "zb_aps.h"
#include <command_sender.h>

#define LED_ENDPOINT 10
#define LED_PROFILE 0x0104
#define LED_CLUSTER 0x54

static void send(zb_buf_t *buf, zb_uint16_t addr);

static void fill_buffer_and_send(zb_uint8_t param, zb_uint8_t command_id);

void led_send_led_control_command(zb_uint8_t param)
{

    fill_buffer_and_send(param, LedControlCommand);
}

void led_send_set_level_command(zb_uint8_t param)
{

    fill_buffer_and_send(param, LedSetLevelCommand);
}

void led_send_level_up_down_command(zb_uint8_t param)
{

    fill_buffer_and_send(param, LedLevelUpDownCommand);
}

static void fill_buffer_and_send(zb_uint8_t param, zb_uint8_t command_id)
{

    zb_buf_t *buf = ZB_BUF_FROM_REF(param);

    led_command_args_t *ptr = ZB_GET_BUF_PARAM(buf, led_command_args_t);

    zb_uint8_t val = ptr->data;
    zb_uint16_t addr = ptr->addr;

    led_packet_t *packet;
    ZB_BUF_INITIAL_ALLOC(buf, sizeof(led_packet_t), packet);

    packet->command_type = command_id;
    packet->data = val;

    send(buf, addr);
}

static void send(zb_buf_t *buf, zb_uint16_t addr)
{

    zb_apsde_data_req_t *req;

    req = ZB_GET_BUF_TAIL(buf, sizeof(zb_apsde_data_req_t));

    req->dst_addr.addr_short = addr; /* send to ZR */
    req->addr_mode = ZB_APS_ADDR_MODE_16_ENDP_PRESENT;
    req->tx_options = ZB_APSDE_TX_OPT_ACK_TX;
    req->radius = 1;
    req->profileid = LED_PROFILE;
    req->src_endpoint = LED_ENDPOINT;
    req->dst_endpoint = LED_ENDPOINT;
    req->clusterid = LED_CLUSTER;
    buf->u.hdr.handle = 0x11;

    ZB_SCHEDULE_CALLBACK(zb_apsde_data_request, ZB_REF_FROM_BUF(buf));
}