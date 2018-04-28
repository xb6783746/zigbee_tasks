

#ifndef PROJECT_SIMPLE_DESCR_PARSER_H
#define PROJECT_SIMPLE_DESCR_PARSER_H

#include <zb_common.h>

typedef struct simple_descr_cluster_list_s
{

    zb_uint8_t app_input_cluster_count;
    zb_uint16_t *input_clusters;

    zb_uint8_t app_output_cluster_count;
    zb_uint16_t *output_clusters;
} simple_descr_cluster_list_t;

void parse_simple_descr_cluster_list(
        zb_af_simple_desc_1_1_t *descr,
        simple_descr_cluster_list_t *cluster_list
);

#endif //PROJECT_SIMPLE_DESCR_PARSER_H
