include_directories(.)
add_definitions(-Wall -W -O3 -Wno-sign-compare -DRELEASE)

add_executable(intersection main.cpp
	geom/enum.cpp
	geom/errors.cpp
	geom/utils/utils.cpp
	geom/predicates/predicates.cpp
	geom/exact/expansion/expansion.cpp
	geom/segment/segment.cpp
	geom/point/exact_point.cpp
	geom/point/point.cpp
)
