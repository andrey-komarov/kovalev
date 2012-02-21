set(tree_SRCS
    main.cpp
ololo.h
)

add_executable(tree ${tree_SRCS})

target_link_libraries(tree ${QT_QTCORE_LIBRARY})

