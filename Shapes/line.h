#ifndef LINE_H_
#define LINE_H_

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

class Line : public Shape
{
public:
    // Constructor 
    Line( int xId );

    Line() = delete;         // default constructor 
    Line& operator=(const Line&) = delete;  // Disallow copying
    Line(const Line&) = delete;
    ~Line() {}

    std::ostream& print(std::ostream& os) const override;

    void sketch(QPaintDevice* other) override;
    void move(QPoint &left_side) override;
    // double calcPerimeter() const override; ??
    // double calcArea() const override; ??
};
#endif // LINE_H_