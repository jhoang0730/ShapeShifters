#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <math.h>
using namespace std;

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPoint>

class Shape {
public:
    /* Public data members */


    // Shape Types
    enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

    /* Constructors */
    Shape() = delete;         // default constructor
    Shape( QPaintDevice *pdevice, int assign_id, ShapeType assign_type) : device{pdevice}, shapeID{assign_id}, shape_type{assign_type} {}
    Shape( QPaintDevice *pdevice, int assign_id, ShapeType assign_type, QPen assign_pen, QBrush assign_brush );       // Copy constructor with parameters
    Shape& operator=(const Shape&) = delete;  // Disallow copying
    Shape(const Shape&) = delete;

    // Virtual Destructor
    virtual ~Shape() {}

    /* Setters
     * Precondition: ShapeType, GlobalColor, PenStyle, PenCapStyle, PenJoinStyle, BrushStyle
     * Postcondition: set the private data members to the corresponding parameters.
     */
    void SetShapeType(ShapeType xShape);
    void SetPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void SetPen(Qt::GlobalColor);
    void SetBrush(Qt::GlobalColor, Qt::BrushStyle);

    /* Getters
     * Precondition: <none>
     * Postcondition: return the corresponding private data members.
     */
    int GetID() const;
    QPaintDevice& GetPaintDevice() const;
    ShapeType GetShapeType() const;
    QPainter& GetPainter() const;
    QPen GetPen() const;
    QBrush GetBrush() const;

    /* Pure Virtual functions
     * Precondition: QPaintDevice, QPoint, ostream
     */

    /* Print function
     * Postcondition: print out the current object ID, perimeter, and area.
     */
    virtual std::ostream& print(std::ostream& os) const = 0;

    /* Sketch/draw function
     * Postcondition: draw the shape
     */
    virtual void sketch(QPaintDevice* other) = 0;

    /* Move function
     * Postcondition: the "shape" object is moved to the desire position.
     */
    virtual void move(QPoint &left_side) = 0;

    /* Update the shape function
     * Postcondition: the object properties are updated.
     */
    virtual void update(void) = 0;

    /* Calculate perimeter or area functions
     * Postcondition: calculate the object's perimeter and area.
     */
    virtual double calcPerimeter(void) const = 0;
    virtual double calcArea(void) const = 0;

private:
    QPaintDevice *device;
    int shapeID;
    ShapeType shape_type;   // type of shape, from the enum shapeType
    QPen pen;
    QBrush brush;
    QPainter *painter;
};

#endif /* SHAPE_H_ */
