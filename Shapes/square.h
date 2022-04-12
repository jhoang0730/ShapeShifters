#ifndef SQUARE_H_
#define SQUARE_H_

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

class Square : public Shape
{
public:
    // Constructor 
    Square( QPaintDevice *pdevice, int xId, QPen xpen, QBursh xbrush );
    Square() = delete;         // default constructor 
    Square& operator=(const Square&) = delete;  // Disallow copying
    Square(const Square&) = delete;
    ~Square() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // SQUARE_H_