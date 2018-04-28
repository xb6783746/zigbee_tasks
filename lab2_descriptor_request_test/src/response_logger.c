
#include <zb_common.h>
#include <response_logger.h>

void log_ieee_addr_resp(zb_zdo_nwk_addr_resp_head_t *resp)
{

    TRACE_MSG(TRACE_INFO1, "IEEE ADDR RESPONSE: ieee addr: %p", (FMT__P, resp->ieee_addr));
}

void log_node_descr_resp(zb_zdo_node_desc_resp_t *resp)
{

    zb_af_node_desc_t node_desc = resp->node_desc;

    TRACE_MSG(TRACE_INFO1, "NODE DESCR RESPONSE", (FMT__0));

    TRACE_MSG(TRACE_INFO1, "Node Desc Flags: 0x%x", (FMT__D, node_desc.node_desc_flags));
    TRACE_MSG(TRACE_INFO1, "mac_capability_flags: 0x%x", (FMT__D, node_desc.mac_capability_flags));
    TRACE_MSG(TRACE_INFO1, "manufacturer_code: 0x%x", (FMT__D, node_desc.manufacturer_code));
    TRACE_MSG(TRACE_INFO1, "max_buf_size: %d", (FMT__D, node_desc.max_buf_size));
    TRACE_MSG(TRACE_INFO1, "max_incoming_transfer_size: %d", (FMT__D, node_desc.server_mask));
    TRACE_MSG(TRACE_INFO1, "server_mask: 0x%x", (FMT__D, node_desc.server_mask));
    TRACE_MSG(TRACE_INFO1, "max_outgoing_transfer_size: %d", (FMT__D, node_desc.max_outgoing_transfer_size));
    TRACE_MSG(TRACE_INFO1, "desc_capability_field: 0x%x", (FMT__D, node_desc.desc_capability_field));

}

void log_power_descr_resp(zb_zdo_power_desc_resp_t *resp)
{

    TRACE_MSG(
            TRACE_INFO1,
            "POWER DESCR RESPONSE: flags: %x",
            (FMT__D, resp->power_desc.power_desc_flags)
    );
}

void log_active_ep_descr_resp(zb_zdo_ep_resp_t *resp, zb_uint8_t *ep_list)
{

    TRACE_MSG(TRACE_INFO1, "ACTIVE EP DESCR RESPONSE", (FMT__0));

    TRACE_MSG(TRACE_INFO1, "Endpoint count: %d", (FMT__D, resp->ep_count));

    for (int i = 0; i < resp->ep_count; i++)
    {

        TRACE_MSG(TRACE_INFO1, "#%d: %d", (FMT__D, i, ep_list[i]));
    }
}

void log_simple_descr_resp(zb_zdo_simple_desc_resp_t *resp, simple_descr_cluster_list_t *cl_list)
{


    TRACE_MSG(
            TRACE_INFO1,
            "SIMPLE DESCR RESPONSE: Input/output cluster count: %d/%d",
            (FMT__D_D,
                    cl_list->app_input_cluster_count,
                    cl_list->app_output_cluster_count
            )
    );

    for (int i = 0; i < cl_list->app_input_cluster_count; i++)
    {

        TRACE_MSG(
                TRACE_INFO1,
                "Input cluster #%d: %x",
                (FMT__D_D, i, cl_list->input_clusters[i])
        );
    }

    for (int i = 0; i < cl_list->app_output_cluster_count; i++)
    {

        TRACE_MSG(
                TRACE_INFO1,
                "Output cluster #%d: %x",
                (FMT__D_D, i, cl_list->output_clusters[i])
        );
    }
}