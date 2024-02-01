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

void Detector::set_detect_circle(const bool value)
{
    _detect_circle = value;
}

void Detector::set_detect_rectangle(const bool value)
{
    _detect_rectangle = value;
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

void Detector::detect(const double param1, const double param2, const int min_radius, const int max_radius, const double area_deviation)
{
    cv::Mat gray;
    cv::cvtColor(_src, gray, cv::COLOR_RGB2GRAY);
    cv::medianBlur(gray, gray, 7);

    if (_detect_circle)
    {
        std::vector<cv::Vec3f> circles;
        cv::HoughCircles(gray,
                        circles,
                        cv::HOUGH_GRADIENT, // Define the detection method. Currently this is the only one available in OpenCV.
                        1,   // The inverse ratio of resolution.
                        gray.rows/32,  // Minimum distance between detected centers.
                        param1, // Upper threshold for the internal Canny edge detector.
                        param2,  // Threshold for center detection.
                        min_radius, max_radius // (min_radius & max_radius) to detect larger circles.
                        );
        for (const cv::Vec3i& c : circles)
        {
            cv::Point center = cv::Point(c[0], c[1]);
            int radius = c[2];
            cv::circle(_src, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
        }
    }

    if (_detect_rectangle)
    {
        std::vector<std::vector<cv::Point>> contours;
	    std::vector<cv::Vec4i> hierarchy;

        cv::Mat binary;
        cv::Canny(gray, binary, 50, 200);

        cv::findContours(binary, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double area;
        cv::RotatedRect min_rect;
        cv::Point2f points[4];

        for (const std::vector<cv::Point> &contour : contours)
        {
            min_rect = cv::minAreaRect(contour);
            if (std::abs(1.0 - cv::contourArea(contour) / (min_rect.size.width * min_rect.size.height)) < area_deviation)
            {
                min_rect.points(points);
                cv::line(_src, points[0], points[1], cv::Scalar(255, 0, 0), 3, cv::LINE_AA);
                cv::line(_src, points[1], points[2], cv::Scalar(255, 0, 0), 3, cv::LINE_AA);
                cv::line(_src, points[2], points[3], cv::Scalar(255, 0, 0), 3, cv::LINE_AA);
                cv::line(_src, points[0], points[3], cv::Scalar(255, 0, 0), 3, cv::LINE_AA);
            }
        }
    }
}