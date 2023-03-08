#include "base/Label.hpp"
#include <QSizePolicy>

Label::Label(QWidget *parent)
    : QLabel(parent)
{
    QLabel::setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void Label::setPixmap(const QPixmap & pixmap)
{
    _pixmap = pixmap.copy();
    int w = QLabel::width(), h = QLabel::height();
    QLabel::resize(++w, ++h);
    QLabel::resize(--w, --h);
}

QPixmap Label::pixmap() const
{
    return _pixmap;
}

void Label::resizeEvent(QResizeEvent *event)
{
    QLabel::setPixmap(_pixmap.scaled(event->size(), Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation));
}