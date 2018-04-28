
#include <simple_descr_parser.h>

#define GET_PARAM(p, type) *(type*)p

void parse_simple_descr_cluster_list(
        zb_af_simple_desc_1_1_t *descr,
        simple_descr_cluster_list_t *cluster_list)
{


    cluster_list->app_input_cluster_count = descr->app_input_cluster_count;

    char *p = (char *) (&descr->app_input_cluster_count) + sizeof(zb_uint8_t);

    cluster_list->input_clusters = (zb_uint16_t *) p;

    p += sizeof(zb_uint16_t) * cluster_list->app_input_cluster_count;

    cluster_list->app_output_cluster_count = GET_PARAM(p, zb_uint8_t);

    p += sizeof(zb_uint8_t);

    cluster_list->output_clusters = (zb_uint16_t *) p;
}