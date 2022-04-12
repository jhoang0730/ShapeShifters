#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include <iostream>
#include <math.h>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPoint>
#include "shape.h"
using namespace std;

class Ellipse : public Shape
{
public:
    // Constructor 
    Ellipse( QPaintDevice *pdevice, int xId, QPen xpen, QBursh xbrush );

    Ellipse() = delete;         // default constructor 
    Ellipse& operator=(const Ellipse&) = delete;  // Disallow copying
    Ellipse(const Ellipse&) = delete;
    ~Ellipse() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // ELLIPSE_H_