#include "shape.h"
#include "./ui_shape.h"

/* Constructor with parameters */
Shape::Shape( QPaintDevice *pdevice, int assign_id, ShapeType assign_type, QPen assign_pen, QBrush assign_brush )       // Copy constructor with parameters
           : device{pdevice}, shapeID{assign_id}, shape_type{assign_type} /*painter{pdevice}*/  {
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
    // painter = ??
}

/* Setters */
void Shape::SetShapeType(ShapeType xShape) {
    shape_type = xShape;
}

void Shape::SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle pStyle, Qt::PenJoinStyle pjStyle) {
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(style);
    pen.setCapStyle(pStyle);
    pen.setJoinStyle(pjStyle);
}

void Shape::SetPen(Qt::GlobalColor color) {
    pen.setColor(color);
}

void Shape::SetBrush(Qt::GlobalColor color, Qt::BrushStyle style) {
    brush.setColor(color);
    brush.setStyle(style);
}

/* Getters */
int Shape::GetID() const {
    return shapeID;
}

QPaintDevice& Shape::GetPaintDevice() const {
    return *device;
}

Shape::ShapeType Shape::GetShapeType() const {
    return shape_type;
}

QPainter& Shape::GetPainter() const {
    return *painter;
}

QPen Shape::GetPen() const {
    return pen;
}

QBrush Shape::GetBrush() const {
    return brush;
}
