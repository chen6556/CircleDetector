#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <QPixmap>
#include <QImage>

class Detector
{
private:
    cv::Mat _src;
    bool _detect_circle = true;
    bool _detect_rectangle = false;

public:
    void load_img(const std::string& path);
    void load_img(const QImage& image);
    void load_img(const QPixmap& pixmap);

    void set_detect_circle(const bool value);
    void set_detect_rectangle(const bool value);

    const cv::Mat& result() const;
    const QImage result_to_QImage() const;
    const QPixmap result_to_QPixmap() const;

    void detect(const double param1 = 80, const double param2 = 100, const int min_adius = 10,
        const int max_adius = 200, const double area_deviation = 0.1);
};