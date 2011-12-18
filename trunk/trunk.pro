HEADERS += src/geom/point/point.h \
    src/geom/point/simple_point.h \
    src/geom/enum.h \
    src/geom/point.h \
    src/big_int/big_int/big_int.h \
    src/big_int/container/container.h \
    src/big_int/big_int.h \
    src/fraction/fraction.h \
    src/geom/errors.h \
    src/geom/traits/supertype.h \
    src/geom/utils/utils.h \
    src/geom/utils.h \
    src/geom/segment.h \
    src/geom/segment/segment.h \
    src/geom/predicates/predicates.h \
    src/geom/predicates.h \
    src/geom/traits/exact.h \
    src/geom/exact/expansion/expansion.h \
    src/geom/point/exact_point.h
SOURCES += src/geom/point/point.cpp \
    main.cpp \
    src/big_int/big_int/big_int.cpp \
    src/big_int/container/container.cpp \
    src/fraction/fraction.cpp \
    src/geom/segment/segment.cpp \
    src/geom/exact/expansion/expansion.cpp \
    src/geom/predicates/predicates.cpp \
    src/geom/point/exact_point.cpp \
    src/geom/enum.cpp \
    src/geom/errors.cpp
OTHER_FILES += trunk.pro.user \
    Makefile
