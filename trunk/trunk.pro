HEADERS += geom/point/point.h \
    geom/point/simple_point.h \
    geom/enum.h \
    geom/point.h \
    big_int/big_int/big_int.h \
    big_int/container/container.h \
    big_int/big_int.h \
    fraction/fraction.h \
    geom/errors.h \
    geom/traits/supertype.h \
    geom/utils/utils.h \
    geom/utils.h \
    geom/segment.h \
    geom/segment/segment.h \
    geom/predicates/predicates.h \
    geom/predicates.h \
    geom/traits/exact.h \
    geom/exact/expansion/expansion.h \
    geom/point/exact_point.h
SOURCES += geom/point/point.cpp \
    main.cpp \
    big_int/big_int/big_int.cpp \
    big_int/container/container.cpp \
    fraction/fraction.cpp \
    geom/segment/segment.cpp \
    geom/exact/expansion/expansion.cpp \
    geom/predicates/predicates.cpp \
    geom/point/exact_point.cpp
OTHER_FILES += trunk.pro.user \
    Makefile
