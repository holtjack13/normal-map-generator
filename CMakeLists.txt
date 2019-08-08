cmake_minimum_required(VERSION 3.8)

project(normal-map-generator)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Packages
find_package( OpenCV REQUIRED )

# Create executable and configure
add_executable(nmg-bin)

target_sources(nmg-bin
    PRIVATE
        src/main.cpp
)

target_include_directories(nmg-bin 
    PUBLIC
        include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(nmg-bin 
    PUBLIC
        ${OpenCV_LIBS}
)

# Add relevant compiler warnings depending on platform 
if(MSVC)
    target_compile_options(nmg-bin
        PRIVATE
            /W4
            /w14640
    )
else()
    target_compile_options(nmg-bin
        PRIVATE
            -Wall
            -Wextra
            -Wshadow
            -Wnon-virtual-dtor
            -Wpedantic
        )
endif()

# Add additional compiler settings depending on Debug or Release for G++ or
# Clang++. If built using Windows, user can choose Debug or Release from Visual 
# Studio.
if(NOT MSVC)
    if($<STREQUAL:${CMAKE_BUILD_TYPE}:Debug>)
        target_compile_options(nmg-bin
            PRIVATE
                -g
        )
    elseif($<STREQUAL:${CMAKE_BUILD_TYPE}:Release>)
        target_compile_options(nmg-bin
            PRIVATE
                -O2
                -DNDEBUG
        )
    endif()
endif()

if(TESTS_ON)
    add_subdirectory(tests)
endif()
