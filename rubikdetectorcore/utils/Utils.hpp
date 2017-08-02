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
    float pointsDistance(const cv::Point &firstPoint, const cv::Point &secondPoint);

    bool quickSaveImage(const cv::Mat &mat, const int frameNumber, const int regionId);

    char colorIntToChar(const int colorInt);

    void drawCircle(cv::Mat &drawingCanvas, const Circle circle, const cv::Scalar color,
                    const int radiusModifier = 0, const bool fillArea = false);

    void
    drawCircles(cv::Mat &drawingCanvas, const std::vector<Circle> circles, const cv::Scalar color);

    void drawCircles(cv::Mat &drawingCanvas, const std::vector<std::vector<Circle>> circles,
                     const cv::Scalar color, const int radiusModifier = 0,
                     const bool fillArea = false);
}
#endif //RUBIKDETECTORDEMO_UTILS_HPP