
set(SRC
        src/nwk_main.c
        src/nwk_nlme.c 
        src/nwk_discovery.c 
        src/nwk_formation.c 
        src/nwk_cr_formation.c 
        src/nwk_cr_permit_join.c 
        src/nwk_cr_join.c 
        src/nwk_join.c 
        src/nwk_neighbor.c 
        src/nwk_cr_route_discovery.c 
        src/nwk_address_assign.c 
        src/nwk_cr_tree_routing.c 
        src/nwk_cr_mesh_routing.c 
        src/nwk_panid_conflict.c
)

add_library(nwk OBJECT ${SRC})

target_include_directories(
    nwk PUBLIC
    include
)
