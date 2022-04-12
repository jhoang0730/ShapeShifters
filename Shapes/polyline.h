#ifndef POLYLINE_H
#define POLYLINE_H

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

class Polyline : public Shape
{
public:
    // Constructor 
    Polyline( QPaintDevice *pdevice, int xId, QPen xpen, QBursh xbrush );

    Polyline() = delete;         // default constructor 
    Polyline& operator=(const Polyline&) = delete;  // Disallow copying
    Polyline(const Polyline&) = delete;
    ~Polyline() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // POLYLINE_H
