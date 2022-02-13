#include "mandelbrot_view.hpp"

#include <QColor>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>

MandelbrotView::MandelbrotView(QWidget* parent)
    : QWidget {parent}
{
}

void MandelbrotView::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    if ((!image_) || (image_->size() != event->size()))
    {
        image_.reset(new QImage {event->size(), QImage::Format_RGB32});
    }
}

void MandelbrotView::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter {this};
    if (!image_)
    {
        painter.fillRect(rect(), Qt::black);
        return;
    }

    QSize sz {image_->size()};
    image_->fill(0);
    for (int x = 0; x < sz.width(); x++)
    {
        for (int y = 0; y < sz.height(); y++)
        {
            int g {((x + y) * 256 / (sz.width() + sz.height())) % 256};
            image_->setPixel(x, y, QColor {g, g, g}.rgb());
        }
    }

    painter.drawImage(0, 0, *image_);
}
