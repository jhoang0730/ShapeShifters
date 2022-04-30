#include "line.h"

Line::Line(  QPaintDevice*      pdevice,         // Constructor with parameters
             int                assign_id,
             QColor             assign_pen_color,
             qreal              assign_pen_width,
             Qt::PenStyle       assign_penstyle,
             Qt::PenCapStyle    assign_pencap_style,
             Qt::PenJoinStyle   assign_penjoin_style,
             int                top_leftx,
             int                top_lefty,
             int                bottom_leftx,
             int                bottom_lefty)
       : Shape(pdevice, assign_id, ShapeType::Line)
{
    line_pen.setColor(assign_pen_color);
    line_pen.setWidth(assign_pen_width);
    line_pen.setStyle(assign_penstyle);
    line_pen.setCapStyle(assign_pencap_style);
    line_pen.setJoinStyle(assign_penjoin_style);

    // object specific transform from points supplied to bounding points
    QPoint assign_topleft(top_leftx,top_lefty);
    top_left = assign_topleft;
    vpoints.push_back(assign_topleft);
    QPoint assign_bottomright(bottom_leftx, bottom_lefty);
    bottom_right = assign_bottomright;
    vpoints.push_back(assign_bottomright);
}

std::ostream& Line::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Line::sketch(QPaintDevice* other)
{
    QPainter& paint = GetPainter();
    paint.begin(other);
    paint.setPen(line_pen);
    paint.drawLine(top_left, bottom_right);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Line::move(QPoint &left_side)
{
    top_left = left_side;
    bottom_right.setX(bottom_right.x() + left_side.x() - top_left.x());
    bottom_right.setY(bottom_right.y() + left_side.y() - top_left.y());
}

void Line::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Line::calcPerimeter() const
{
    return 0;
}

double Line::calcArea() const
{
    return 0;
}
