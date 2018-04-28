/***************************************************************************
*                      ZBOSS ZigBee Pro 2007 stack                         *
*                                                                          *
*          Copyright (c) 2012 DSR Corporation Denver CO, USA.              *
*                       http://www.dsr-wireless.com                        *
*                                                                          *
*                            All rights reserved.                          *
*          Copyright (c) 2011 ClarIDy Solutions, Inc., Taipei, Taiwan.     *
*                       http://www.claridy.com/                            *
*                                                                          *
*          Copyright (c) 2011 Uniband Electronic Corporation (UBEC),       *
*                             Hsinchu, Taiwan.                             *
*                       http://www.ubec.com.tw/                            *
*                                                                          *
*          Copyright (c) 2011 DSR Corporation Denver CO, USA.              *
*                       http://www.dsr-wireless.com                        *
*                                                                          *
*                            All rights reserved.                          *
*                                                                          *
*                                                                          *
* ZigBee Pro 2007 stack, also known as ZBOSS (R) ZB stack is available     *
* under either the terms of the Commercial License or the GNU General      *
* Public License version 2.0.  As a recipient of ZigBee Pro 2007 stack, you*
* may choose which license to receive this code under (except as noted in  *
* per-module LICENSE files).                                               *
*                                                                          *
* ZBOSS is a registered trademark of DSR Corporation AKA Data Storage      *
* Research LLC.                                                            *
*                                                                          *
* GNU General Public License Usage                                         *
* This file may be used under the terms of the GNU General Public License  *
* version 2.0 as published by the Free Software Foundation and appearing   *
* in the file LICENSE.GPL included in the packaging of this file.  Please  *
* review the following information to ensure the GNU General Public        *
* License version 2.0 requirements will be met:                            *
* http://www.gnu.org/licenses/old-licenses/gpl-2.0.html.                   *
*                                                                          *
* Commercial Usage                                                         *
* Licensees holding valid ClarIDy/UBEC/DSR Commercial licenses may use     *
* this file in accordance with the ClarIDy/UBEC/DSR Commercial License     *
* Agreement provided with the Software or, alternatively, in accordance    *
* with the terms contained in a written agreement between you and          *
* ClarIDy/UBEC/DSR.                                                        *
*                                                                          *
****************************************************************************
PURPOSE:
*/

#include <zb_common.h>
#include <zb_aps.h>
#include "zb_zdo.h"
#include <controller.h>

#ifndef ZB_ROUTER_ROLE
#error Router role is not compiled!
#endif

#ifndef ZB_SECURITY
#error Define ZB_SECURITY
#endif


/*! \addtogroup ZB_TESTS */
/*! @{ */


void data_indication(zb_uint8_t param) ZB_CALLBACK;

zb_ieee_addr_t g_ieee_addr = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09};

MAIN()
{
    ARGV_UNUSED;

    if (argc < 3)
    {
        printf("%s <read pipe path> <write pipe path>\n", argv[0]);
        return 0;
    }

    ZB_INIT("zdo_zr", argv[1], argv[2]);

    zb_address_ieee_ref_t ref;

    zb_address_update(g_ieee_addr, 0, ZB_FALSE, &ref);

    ZG->nwk.nib.security_level = 0;

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

        start(0);
    } else
    {
        TRACE_MSG(TRACE_ERROR, "Device started FAILED status %d", (FMT__D, (int) buf->u.hdr.status));
    }
}

void data_indication(zb_uint8_t param)
{
    zb_uint8_t *ptr;
    zb_buf_t *asdu = ZB_BUF_FROM_REF(param);

    /* Remove APS header from the packet */
    ZB_APS_HDR_CUT_P(asdu, ptr);

    TRACE_MSG(TRACE_INFO1, "RESPONSE: packet %p", (FMT__P, asdu));

    for (int i = 0; i < ZB_BUF_LEN(asdu); ++i)
    {
        TRACE_MSG(TRACE_APS2, "%x %c", (FMT__D_C, (int) ptr[i], ptr[i]));
    }

    zb_free_buf(asdu);
}

/*! @} */
