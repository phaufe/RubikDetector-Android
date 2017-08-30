//
// Created by catalin on 26.07.2017.
//

#ifndef RUBIKDETECTORDEMO_UTILS_HPP
#define RUBIKDETECTORDEMO_UTILS_HPP

#include "../data/Circle.hpp"

namespace cv {
    class Mat;
}

namespace utils {
    float pointsDistance(const cv::Point2f &firstPoint, const cv::Point2f &secondPoint);

    bool quickSaveImage(const cv::Mat &mat, const std::string path, const int frameNumber,
                        const int regionId);

    char colorIntToChar(const int colorInt);

    cv::Scalar getColorAsScalar(int color);

    void drawCircle(cv::Mat &drawingCanvas, const Circle circle, const cv::Scalar color,
                    const float scalingFactor = 1,
                    const int radiusModifier = 0,
                    const bool fillArea = false);

    void drawCircles(cv::Mat &drawingCanvas, const std::vector<Circle> circles,
                     const cv::Scalar color,
                     const float scalingFactor = 1);

    void drawCircles(cv::Mat &drawingCanvas, const std::vector<std::vector<Circle>> circles,
                     const cv::Scalar color,
                     const float scalingFactor = 1,
                     const int radiusModifier = 0,
                     const bool fillArea = false);

    double getCurrentTimeMillis();

    void encodeNV21(const cv::Mat &inputArgb, const cv::Mat &outputNv21, int width, int height);

    void encodeNV12(const cv::Mat &inputArgb, const cv::Mat &outputNv12, int width, int height);

    }
#endif //RUBIKDETECTORDEMO_UTILS_HPP
