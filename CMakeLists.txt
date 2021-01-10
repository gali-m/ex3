# cmake_minimum_required(VERSION 3.0.0)

# # project(ex3 VERSION 0.1.0 LANGUAGES C CXX)
# project(ex3 VERSION 0.1.0)

# set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -o progA -IpartA -Iprovided provided/test_partA.cpp partA/*.cpp -Lprovided -ldate")
# # set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -o progA -IpartA -Iprovided -Lprovided -ldate")
# set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

# # add_executable(progA provided/test_partA.cpp partA/date_wrap.cpp partA/date_wrap.h)

# add_library(date provided/date.c provided/date.h)

cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

include(CTest)
enable_testing()

set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
link_directories(.)

add_executable(progA test_partA.cpp date_wrap.cpp date_wrap.h date.h)
target_link_libraries(progA libdate.a)