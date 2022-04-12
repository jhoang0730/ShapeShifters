#ifndef SHAPE_H_
#define SHAPE_H_

/**************************
 *      Base Class        *
 **************************/

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
    // Shape Types
    enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};

    // Constructors
    Shape() = delete;         // default constructor

    Shape( QPaintDevice *pdevice, int xId, ShapeType type, QPen xpen, QBursh xbrush );       // Copy constructor with parameters

    Shape& operator=(const Shape&) = delete;  // Disallow copying

    Shape(const Shape&) = delete;

    // Virtual Destructor
    virtual ~Shape() {}

    // Setters
    void SetShapeType(ShapeType xShape);
    void SetPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void SetPen(Qt::GlobalColor);
    void SetBrush(Qt::GlobalColor, Qt::BrushStyle);

    // Getters
    int GetID() const;
    ShapeType GetShapeType() const;
    QPen& GetPen() const;
    QBrush& GetBrush() const;

    // Pure Virtual functions
    virtual void sketch(QPaintDevice* other) = 0;
    virtual void move(QPoint &left_side) = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
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
