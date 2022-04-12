#ifndef POLYGON_H_
#define POLYGON_H_

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

class Polygon : public Shape
{
public:
    // Constructor 
    Polygon( QPaintDevice *pdevice, int xId, QPen xpen, QBursh xbrush );

    Polygon() = delete;         // default constructor 
    Polygon& operator=(const Polygon&) = delete;  // Disallow copying
    Polygon(const Polygon&) = delete;
    ~Polygon() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // POLYGON_H_