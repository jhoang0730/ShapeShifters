#ifndef POLYGON_H_
#define POLYGON_H_

/* Ultility */
#include <iostream>
#include <math.h>
#include "shape.h"
using namespace std;

/* Qt libraries */
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPoint>

class Polygon : public Shape
{
public:
    /* Public data members */
    QPen   polygon_pen;
    QBrush polygon_brush;
    QPoint top_left;
    QPoint bottom_right;
    vector<QPoint> vpoints;

    /* Constructors */
    Polygon() = delete;         // default constructor
    Polygon( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush );
    Polygon& operator=(const Polygon&) = delete;  // Disallow copying
    Polygon(const Polygon&) = delete;
    Polygon( QPaintDevice*      pdevice,             // Constructor with parameters
            int                assign_id,
            QColor             assign_pen_color,
            qreal              assign_pen_width,
            Qt::PenStyle       assign_penstyle,
            Qt::PenCapStyle    assign_pencap_style,
            Qt::PenJoinStyle   assign_penjoin_style,
            QColor             assign_burshcolor,
            Qt::BrushStyle     assign_brushstyle,
            int                top_leftx,
            int                top_lefty);

    /* Destrcutor */
    ~Polygon() {}

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
#endif // POLYGON_H_

