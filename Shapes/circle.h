#ifndef CIRCLE_H
#define CIRCLE_H

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

class Circle : public Shape
{
public:
    // Constructor
    Circle( QPaintDevice *pdevice, int xId, QPen xpen, QBursh xbrush );

    Circle() = delete;         // default constructor 
    Circle& operator=(const Circle&) = delete;  // Disallow copying
    Circle(const Circle&) = delete;
    ~Circle() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // CIRCLE_H
