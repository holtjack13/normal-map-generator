project(normal-map-generator-tests)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/tests/bin)

# Packages
find_package(Catch2 REQUIRED)
find_package(OpenCV REQUIRED)

enable_testing()

add_executable(nmg-test
    src/normal_map_generator_tests.cpp
    ${CMAKE_SOURCE_DIR}/src/normal_map_generator.cpp
)

target_include_directories(nmg-test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(nmg-test
    PRIVATE
        Catch2::Catch2
        ${OpenCV_LIBS}
)

target_compile_features(nmg-test
    PUBLIC
        cxx_std_11
)

include(ParseAndAddCatchTests)
ParseAndAddCatchTests(nmg-test)
