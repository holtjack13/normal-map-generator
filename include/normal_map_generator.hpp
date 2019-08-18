#ifndef __NORMAL_MAP_GENERATOR__
#define __NORMAL_MAP_GENERATOR__

#include <array>

#include <opencv2/opencv.hpp>

class NormalMapGenerator
{
    private:
        const cv::Mat& mHeightMap;
        
        const std::array<cv::Mat, 2> computeDerivatives();

    public:
        NormalMapGenerator(const cv::Mat& heightMap);

        cv::Mat generate();
        cv::Vec3b computeNormal(uchar derivX, uchar derivY);
};

#endif
