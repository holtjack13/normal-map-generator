#include <opencv2/opencv.hpp>
#include <iostream>

#include "normal_map_generator.hpp"

int main(int argc, char *argv[])
{
    cv::Mat inputImage { cv::imread(argv[1], cv::IMREAD_GRAYSCALE) };

    NormalMapGenerator nmg { inputImage };

    cv::Mat normalMap { nmg.generate() };

    cv::imwrite(argv[2], normalMap);
}
