#include "ellipse.h"

Ellipse::Ellipse( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush )
    : Shape (pdevice, assign_id, ShapeType::Ellipse, assign_pen, assign_brush) {}

Ellipse::Ellipse(QPaintDevice*     pdevice,             // Constructor with parameters
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
    : Shape (pdevice, assign_id, ShapeType::Ellipse)
{
    /* Assigning "pen" properties */
    ellipse_pen.setColor(assign_pen_color);
    ellipse_pen.setWidth(assign_pen_width);
    ellipse_pen.setStyle(assign_penstyle);
    ellipse_pen.setCapStyle(assign_pencap_style);
    ellipse_pen.setJoinStyle(assign_penjoin_style);

    /* Assigning "brush" properties */
    ellipse_brush.setColor(assign_burshcolor);
    ellipse_brush.setStyle(assign_brushstyle);

    QPoint assign_topleft(top_leftx,top_lefty);
    top_left = assign_topleft;
    QPoint assign_bottomright(top_leftx+assign_width, top_lefty+assign_height);
    bottom_right = assign_bottomright;
}

std::ostream& Ellipse::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Ellipse::sketch(QPaintDevice* other)
{
    QRect draw_rect(top_left, bottom_right);
    QPainter& paint = GetPainter();
    paint.begin(other);
    paint.setPen(ellipse_pen);
    paint.setBrush(ellipse_brush);
    paint.drawEllipse(draw_rect);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Ellipse::move(QPoint &left_side)
{
    top_left = left_side;
    bottom_right.setX(bottom_right.x() + left_side.x() - top_left.x());
    bottom_right.setY(bottom_right.y() + left_side.y() - top_left.y());
}

void Ellipse::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

/*
 * Ramanujan Forumla:
 * P = M_PI[3(A+B) - sqrt(3(A+B)(A+3B))]
 */
double Ellipse::calcPerimeter() const
{
    double A = ((bottom_right.x()-top_left.x()));
    double B = ((bottom_right.y()-top_left.y()));
    double perimeter = ( (M_PI) * (3*(A-B)) - (sqrt(((3*A)+B) * (A+(3*B)))) );
    return perimeter;      // using PI constant and applying Ramanujan Forumla to find perimeter
}

double Ellipse::calcArea() const
{
    double A = ((bottom_right.x()-top_left.x()));
    double B = ((bottom_right.y()-top_left.y()));
    double area = ( ( A / 2) * ( B / 2) * M_PI);
    return area;      // using PI constant
}
