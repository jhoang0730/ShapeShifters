#include "rectangle.h"

Rectangle::Rectangle(   QPaintDevice*      pdevice,             // Constructor with parameters
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
                        int                assign_width,
                        int                assign_height)
    : Shape (pdevice, assign_id, ShapeType::Rectangle)
{
    /* Assigning "pen" properties */
    rectangle_pen.setColor(assign_pen_color);
    rectangle_pen.setWidth(assign_pen_width);
    rectangle_pen.setStyle(assign_penstyle);
    rectangle_pen.setCapStyle(assign_pencap_style);
    rectangle_pen.setJoinStyle(assign_penjoin_style);

    /* Assigning "brush" properties */
    rectangle_brush.setColor(assign_burshcolor);
    rectangle_brush.setStyle(assign_brushstyle);

    /* Setting up point */
    QPoint ul(top_leftx,top_lefty);
    top_left = ul;
    QPoint lr(top_leftx+assign_width, top_leftx+assign_height);
    bottom_right = lr;
}

std::ostream& Rectangle::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Rectangle::sketch(QPaintDevice* other)
{
    QRect draw_rect(top_left, bottom_right);
    QPainter& paint = GetPainter();
    paint.begin(other);
    paint.setPen(rectangle_pen);
    paint.setBrush(rectangle_brush);
    paint.drawRect(draw_rect);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Rectangle::move(QPoint &left_side)
{
    int X = (left_side.x() - top_left.x());
    int Y = (left_side.y() - top_left.y());

    top_left = left_side;
    bottom_right.setX(bottom_right.x() + X);
    bottom_right.setY(bottom_right.y() + Y);
}

void Rectangle::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Rectangle::calcPerimeter() const
{
    return ( ((bottom_right.x()-top_left.x()) * 2) + ((bottom_right.y()-top_left.y()) * 2));
}

double Rectangle::calcArea() const
{
    return ( (bottom_right.x()-top_left.x()) * (bottom_right.y()-top_left.y()));
}
