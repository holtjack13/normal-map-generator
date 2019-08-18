#include <array>
#include <cmath>

#include <opencv2/opencv.hpp>

#include "normal_map_generator.hpp"

NormalMapGenerator::NormalMapGenerator(const cv::Mat& heightMap):
    mHeightMap(heightMap)
{}

const std::array<cv::Mat, 2> NormalMapGenerator::computeDerivatives()
{
    cv::Mat derivativeX { mHeightMap.rows, mHeightMap.cols, CV_8U};
    cv::Mat derivativeY { mHeightMap.rows, mHeightMap.cols, CV_8U};

    // Use Sobel operator on height map to approximate derivatives
    cv::Sobel(mHeightMap, derivativeX, -1, 1, 0, 5);
    cv::Sobel(mHeightMap, derivativeY, -1, 0, 1, 5);

    return std::array<cv::Mat, 2>{derivativeX, derivativeY};
}

cv::Vec3b NormalMapGenerator::computeNormal(uchar derivX, uchar derivY)
{
    // Define lambdas to scale values between -1 and 1 and back to 0 to 255
    auto invertScale = [](double scaledHeight) { return ((scaledHeight + 1.0) / 2.0) * 255.0; };

    cv::Vec3i scaledNormVec { 255, -derivY, -derivX };

    cv::normalize(scaledNormVec, scaledNormVec, 1.0, 0.0, cv::NORM_L2);

    cv::Vec3b normal { static_cast<uchar>(invertScale(scaledNormVec[0])), 
                       static_cast<uchar>(invertScale(scaledNormVec[1])),
                       static_cast<uchar>(invertScale(scaledNormVec[2])) };

    return normal;
}

cv::Mat NormalMapGenerator::generate()
{
    const std::array<cv::Mat, 2> derivatives { computeDerivatives() };

    // Initialise 3 channel RGB image
    cv::Mat normalMap ( mHeightMap.rows, mHeightMap.cols, CV_8UC3 );

    // Scan through derivative images, computing each normal and inserting
    // into the normal map encoded as an RGB pixel
 
    for (int i = 0; i < mHeightMap.rows; ++i)
    {
        for (int j = 0; j < mHeightMap.cols; ++j)
        {
            cv::Vec3b normal { computeNormal(derivatives[0].at<uchar>(i, j),
                                             derivatives[1].at<uchar>(i, j)) };
            normalMap.at<cv::Vec3b>(i, j) = normal;
        }
    }

    return normalMap;
}
