HEADERS += \
    number.h \
    event.h \
    event_impl.h \
    site_event.h \
    point.h \
    point.hpp \
    circle_event.h \
    voronoi_diagram.h \
    skiplist.h \
    node.h \
    iterator.h \
    iterator.hpp \
    skiplist.hpp \
    node.hpp

SOURCES += \
    number.cpp \
    main.cpp \
    site_event.cpp \
    circle_event.cpp

LIBS += \
    -lgmp -lgmpxx

QMAKE_CXXFLAGS += \
    -std=c++0x
