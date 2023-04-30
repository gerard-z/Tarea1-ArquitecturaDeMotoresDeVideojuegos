cmake_minimum_required(VERSION 3.15)
project(game_frogger_project C CXX)

add_definitions(-D_USE_MATH_DEFINES)

set(BOX_RENDERER_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/box_renderer")
set(BOX_RENDERER_LIBRARY box_renderer)

set(GAME_FROGGER_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(GAME_FROGGER_LIBRARY grid_lib)

add_subdirectory(box_renderer)
add_subdirectory(source)
add_subdirectory(sample)
