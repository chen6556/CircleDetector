#include "base/Detector.hpp"
#include <vector>


void Detector::load_img(const std::string& path)
{
    _src = cv::imread(path);
}

void Detector::load_img(const QImage& image)
{
    QImage image_rgb = image.convertToFormat(QImage::Format_RGB888);
    cv::Mat(image_rgb.height(), image_rgb.width(), CV_8UC3, image_rgb.bits(), image_rgb.bytesPerLine()).copyTo(_src);
}

void Detector::load_img(const QPixmap& pixmap)
{
    load_img(pixmap.toImage());
}

const cv::Mat& Detector::result() const
{
    return _src;
}

const QImage Detector::result_to_QImage() const
{
    return QImage(_src.data, _src.cols, _src.rows, _src.step, QImage::Format_RGB888);
}

const QPixmap Detector::result_to_QPixmap() const
{
    return QPixmap::fromImage(result_to_QImage());
}

void Detector::detect(double param1, double param2, int minRadius, int maxRadius)
{
    cv::Mat gray;
    cv::cvtColor(_src, gray, cv::COLOR_RGB2GRAY);
    cv::medianBlur(gray, gray, 7);
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gray,
                    circles, 
                    cv::HOUGH_GRADIENT, // Define the detection method. Currently this is the only one available in OpenCV.
                    1,   // The inverse ratio of resolution.
                    gray.rows/32,  // Minimum distance between detected centers.
                    param1, // Upper threshold for the internal Canny edge detector.
                    param2,  // Threshold for center detection.
                    minRadius, maxRadius // (min_radius & max_radius) to detect larger circles.
                    );
    for (const cv::Vec3i& c : circles)
    {
        cv::Point center = cv::Point(c[0], c[1]);
        // circle center
        // circle(_src, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);
        // circle outline
        int radius = c[2];
        circle(_src, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    }
}