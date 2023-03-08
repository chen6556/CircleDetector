#pragma once
#include <QLabel>
#include <QResizeEvent>


class Label : public QLabel
{
    Q_OBJECT

private:
    QPixmap _pixmap;

public:
    Label(QWidget *parent = nullptr);
    void setPixmap(const QPixmap & pixmap);
    QPixmap pixmap() const;

protected:
    void resizeEvent(QResizeEvent* event);
    
};