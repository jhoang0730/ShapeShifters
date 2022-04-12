#ifndef RECTANGLE_H_
#define RECTANGLE_H_

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

class Rectangle : public Shape
{
public:
    // Constructor 
    Rectangle( int xId );

    Rectangle() = delete;         // default constructor 
    Rectangle& operator=(const Rectangle&) = delete;  // Disallow copying
    Rectangle(const Rectangle&) = delete;
    ~Rectangle() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // RECTANGLE_H_