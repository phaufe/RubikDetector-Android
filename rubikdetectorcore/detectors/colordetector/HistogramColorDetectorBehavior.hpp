//
// Created by catalin on 26.07.2017.
//

#ifndef RUBIKDETECTORDEMO_COLORDETECTORBEHAVIOR_HPP
#define RUBIKDETECTORDEMO_COLORDETECTORBEHAVIOR_HPP

#include <vector>
#include <memory>
#include "../../imagesaver/ImageSaver.hpp"
#include "../../data/RubikFacelet.hpp"
#include "ColorDetector.hpp"

namespace cv {
    class Mat;
}

class HistogramColorDetectorBehavior : ColorDetector {

public:
    HistogramColorDetectorBehavior();

    HistogramColorDetectorBehavior(std::shared_ptr<ImageSaver> imageSaver);

    virtual ~HistogramColorDetectorBehavior();

    RubikFacelet::Color detectColor(const cv::Mat &image,
                                    const float whiteRatio = 0.5,
                                    const int regionInfo = -1,
                                    const int frameNr = -1) override;

    void setDebuggable(bool debuggable) override;

    bool isDebuggable() const override;

private:
    static constexpr int HUE = 0;
    static constexpr int SATURATION = 1;
    static constexpr int VALUE = 2;
    static constexpr int MIN_HSV_VALUE_NON_GRAY = 80;
    static constexpr int MIN_HSV_VALUE_FOR_WHITE = 160;
    static constexpr int SATURATION_HISTOGRAM_SIZE = 256;
    static constexpr int HUE_HISTOGRAM_SIZE = 180;
    static constexpr int SATURATION_THRESHOLD = 100;

    bool debuggable = false;

    std::shared_ptr<ImageSaver> imageSaver;

    void printOwnHistogram(const int hist[], const int histogramSize,
                           const int frameNumber, const int regionId) const;

    void computeSaturationHistogram(const std::vector<cv::Mat> &hsvChannels,
                                    int *saturationHistogram,
                                    int &nrNonWhiteNonGrayPixels) const;
};


#endif //RUBIKDETECTORDEMO_COLORDETECTORBEHAVIOR_HPP
