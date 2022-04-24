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
    /* Public data members */
    QPen   square_pen;
    QBrush square_brush;
    QPoint top_left;
    QPoint bottom_right;

     /* Constructors */
    Square( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush );
    Square() = delete;                          // default constructor
    Square& operator=(const Square&) = delete;  // Disallow copying
    Square(const Square&) = delete;             // Disallow copying
    Square(QPaintDevice*       pdevice,             // Constructor with parameters
            int                assign_id,
            QColor             assign_pen_color,
            qreal              assign_pen_width,
            Qt::PenStyle       assign_penstyle,
            Qt::PenCapStyle    assign_pencap_style,
            Qt::PenJoinStyle   assign_penjoin_style,
            QColor             assign_burshcolor,
            Qt::BrushStyle     assign_brushstyle,
            int                top_leftx,
            int                top_lefty,
            int                assign_side);

    /* Destrcutor */
    ~Square() {}

    /* Print function
     * Postcondition: print out the current object ID, perimeter, and area.
     */
    std::ostream& print(std::ostream& os) const override;

    /* Sketch/draw function
     * Postcondition: draw the shape
     */
    void sketch(QPaintDevice* other) override;

    /* Move function
     * Postcondition: the "shape" object is moved to the desire position.
     */
    void move(QPoint &left_side) override;

    /* Update the shape function
     * Postcondition: the object properties are updated.
     */
    void update(void) override;

    /* Calculate perimeter or area functions
     * Postcondition: calculate the object's perimeter and area.
     */
    double calcPerimeter() const override;
    double calcArea() const override;
};

#endif // SQUARE_H_
