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
        xPlusYplus, xPlusYminus, xMinusYplus, xMinusYminus
    };
    QPainter *p;
    QTimer* timer;

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
    Side getDirection(QPointF p1,QPointF p2);
    QPointF getNewPoint(QPointF p1, QPointF p2, Side side);
    QPointF getTangentPoint(QPointF p1, QPointF p2);

    bool drawTangentLine;
    QLineF tangentLine;
    QLineF rayLine;
    QPointF computeTangentPoint3(QPointF tangentPoint);
};


#endif // WINDOW_H
