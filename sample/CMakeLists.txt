function(MakeGameFrogger TARGETNAME FILENAME)
    add_executable(${TARGETNAME} ${FILENAME})
    set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${TARGETNAME} PROPERTY FOLDER sample)
    target_link_libraries(${TARGETNAME} PRIVATE ${GAME_FROGGER_LIBRARY})
    target_include_directories(${TARGETNAME} PRIVATE ${GAME_FROGGER_INCLUDE_DIRECTORIES})
endfunction(MakeGameFrogger)

MakeGameFrogger(main main.cpp)