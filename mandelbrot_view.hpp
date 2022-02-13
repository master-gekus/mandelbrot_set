#ifndef MANDELBROTVIEW_HPP
#define MANDELBROTVIEW_HPP

#include <QImage>
#include <QSharedPointer>
#include <QWidget>

class MandelbrotView : public QWidget
{
    Q_OBJECT
public:
    explicit MandelbrotView(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    QSharedPointer<QImage> image_;

signals:
};

#endif // MANDELBROTVIEW_HPP
