project(normal-map-generator-tests)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/tests/bin)

# Packages
find_package(Catch2 REQUIRED)
find_package(OpenCV REQUIRED)

enable_testing()

add_executable(nmg-test)

target_sources(nmg-test
    PRIVATE
        src/main_test.cpp
)

target_include_directories(nmg-test
    PRIVATE
        include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(nmg-test
    PRIVATE
        Catch2::Catch2
        ${OpenCV_LIBS}
)

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(nmg-test)
