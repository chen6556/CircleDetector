#pragma once
#include <opencv2/opencv.hpp>
#include <string>
#include <QPixmap>
#include <QImage>

class Detector
{
private:
    cv::Mat _src;

public:
    void load_img(const std::string& path);
    void load_img(const QImage& image);
    void load_img(const QPixmap& pixmap);

    const cv::Mat& result() const;
    const QImage result_to_QImage() const;
    const QPixmap result_to_QPixmap() const;

    void detect(double param1 = 80, double param2 = 100, int minRadius = 10, int maxRadius = 200);
};