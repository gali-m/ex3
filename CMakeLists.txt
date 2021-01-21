# cmake_minimum_required(VERSION 3.0.0)

# project(ex3 VERSION 0.1.0 LANGUAGES C CXX)
# project(ex3 VERSION 0.1.0)

# set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -o progA -IpartA -Iprovided provided/test_partA.cpp partA/*.cpp -Lprovided -ldate")
# set(MTM_FLAGS_DEBUG "-std=c++11 -Wall -Werror -pedantic-errors -o progA -IpartA -Iprovided -Lprovided -ldate")
# set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

# add_executable(progA provided/test_partA.cpp partA/date_wrap.cpp partA/date_wrap.h)

# add_library(date date.c date.h)

cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0 LANGUAGES CXX)

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "-Wextra" "-Wpedantic")
endif()

include(CTest)
enable_testing()

set(MTM_FLAGS_DEBUG "-std=c++11 --pedantic-errors -Wall -Werror -g")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
link_directories(.)

# add_executable(progA provided/test_partA.cpp partA/date_wrap.cpp partA/date_wrap.h provided/date.h partA/exceptions.h)
# target_link_libraries(progA provided/libdate.a)

add_executable(progB test_partB.cpp base_event.cpp base_event.h event_container.cpp event_container.h festival.h festival.cpp recurring_event.h recurring_event.cpp one_time_event.h one_time_event.cpp date_wrap.cpp date_wrap.cpp date_wrap.h date.h exceptions.h closed_event.cpp closed_event.h open_event.cpp open_event.h custom_event.cpp custom_event.h)
target_link_libraries(progB libdate.a)

# add_executable(progC test_partC.cpp schedule.h schedule.cpp base_event.cpp base_event.h event_container.cpp event_container.h festival.h festival.cpp recurring_event.h recurring_event.cpp one_time_event.h one_time_event.cpp date_wrap.cpp date_wrap.cpp date_wrap.h date.h exceptions.h closed_event.cpp closed_event.h open_event.cpp open_event.h custom_event.cpp custom_event.h)
# target_link_libraries(progC libdate.a)