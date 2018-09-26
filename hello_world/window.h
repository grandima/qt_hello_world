#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*) override;

private:
    enum Side {
        xleftYnormal, xnormalYUp, xrightYnormal, xnormalYdown
    };
    QPainter *p;
    QTimer* timer;
    int i;
    int k=0;

    QPointF p1, p2;
    QPointF tangentPoint1, tangentPoint2;
    QPointF computeSidePoint(const QPointF& p1, const QPointF& p2, qreal precision);
    qreal ellipseFormula(QPointF p);
    QPointF computeTangentPoint2(QPointF tangentPoint);
    QPointF computeSidePoint(QPointF p1, QPointF p2);
    bool didDraw;
    Side side;
    qreal computeAngleToRotate(QLineF tangentLine, QLineF line);
    QPointF rotatePoint(QPointF p, QPointF p0, qreal angle);
};


#endif // WINDOW_H
