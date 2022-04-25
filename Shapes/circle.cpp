#include "circle.h"

Circle::Circle( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush )
    : Shape (pdevice, assign_id, ShapeType::Circle, assign_pen, assign_brush) {}

Circle::Circle(QPaintDevice*       pdevice,             // Constructor with parameters
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
        int                assign_diameter)
    : Shape (pdevice, assign_id, ShapeType::Circle)
{
    /* Assigning "pen" properties */
    circle_pen.setColor(assign_pen_color);
    circle_pen.setWidth(assign_pen_width);
    circle_pen.setStyle(assign_penstyle);
    circle_pen.setCapStyle(assign_pencap_style);
    circle_pen.setJoinStyle(assign_penjoin_style);

    /* Assigning "brush" properties */
    circle_brush.setColor(assign_burshcolor);
    circle_brush.setStyle(assign_brushstyle);

    /* Setting up point */
    QPoint ul(top_leftx,top_lefty);
    top_left = ul;
    QPoint lr(top_leftx+assign_diameter, top_lefty+assign_diameter);
    bottom_right = lr;
}

std::ostream& Circle::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Circle::sketch(QPaintDevice* other)
{
    QRect draw_rect(top_left, bottom_right);
    QPainter& paint = GetPainter();
    paint.begin(other);
    paint.setPen(circle_pen);
    paint.setBrush(circle_brush);
    paint.drawEllipse(draw_rect);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Circle::move(QPoint &left_side)
{
    int X = (left_side.x() - top_left.x());
    int Y = (left_side.y() - top_left.y());

    top_left = left_side;
    bottom_right.setX(bottom_right.x() + X);
    bottom_right.setY(bottom_right.y() + Y);
}

void Circle::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Circle::calcPerimeter() const
{
     double A = bottom_right.x()-top_left.x();
     double perimeter = (M_PI) * A;
     return perimeter;      // using PI constant
}

double Circle::calcArea() const
{
    double A = bottom_right.x()-top_left.x();
    double area = pow( (A/2),2 ) * M_PI;
    return area;      // using pow() function and PI constant
}

