#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <opencv2/opencv.hpp>
#include <iostream>

#include "normal_map_generator.hpp"

TEST_CASE("Compute Vector Normal: Flat Surface")
{
    unsigned char derivX { 0 };
    unsigned char derivY { 0 };

    NormalMapGenerator nmg { cv::imread("../test_images/metal.jpg", 
                                        cv::IMREAD_GRAYSCALE) };

    cv::Vec3b testNormal { nmg.computeNormal(derivX, derivY) };

    std::cout << testNormal[0] << '\n'
              << testNormal[1] << '\n'
              << testNormal[2] << std::endl;

    bool normalPointingUpwards { (testNormal[0] == 255) && 
                                 (testNormal[1] == 127) && 
                                 (testNormal[2] == 127) };

    REQUIRE(normalPointingUpwards);
}
