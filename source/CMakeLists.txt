add_library(entity_lib STATIC
    "entity/entity.h"
    "entity/entity.cpp"
    "entity/point.h"
    "entity/point.cpp"
)

set_property(TARGET entity_lib PROPERTY CXX_STANDARD 20)

add_library(grid_lib STATIC
    "grid/grid.h"
    "grid/grid.cpp"
)

set_property(TARGET grid_lib PROPERTY CXX_STANDARD 20)
target_link_libraries(grid_lib PRIVATE entity_lib)
target_include_directories(grid_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})