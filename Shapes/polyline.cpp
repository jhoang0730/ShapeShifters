#include "polyline.h"

Polyline::Polyline(QPaintDevice*    pdevice,         // Constructor with parameters
                 int                assign_id,
                 QColor             assign_pen_color,
                 qreal              assign_pen_width,
                 Qt::PenStyle       assign_penstyle,
                 Qt::PenCapStyle    assign_pencap_style,
                 Qt::PenJoinStyle   assign_penjoin_style,
                 int                top_leftx,
                 int                top_lefty)
     : Shape (pdevice, assign_id, ShapeType::Polyline)
{
    /* Assigning "pen" properties */
    polyline_pen.setColor(assign_pen_color);
    polyline_pen.setWidth(assign_pen_width);
    polyline_pen.setStyle(assign_penstyle);
    polyline_pen.setCapStyle(assign_pencap_style);
    polyline_pen.setJoinStyle(assign_penjoin_style);

    /* Setting up point */
    // ???
}

std::ostream& Polyline::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Polyline::sketch(QPaintDevice* other)
{
    QPainter& paint = GetPainter();
    const QPoint *draw_point = &(*vpoints.begin());

    paint.drawPolyline(draw_point,vpoints.size());
    paint.begin(other);
    paint.setPen(polyline_pen);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Polyline::move(QPoint &left_side)
{
    int X = (left_side.x() - top_left.x());
    int Y = (left_side.y() - top_left.y());

    top_left = left_side;
    bottom_right.setX(bottom_right.x() + X);
    bottom_right.setY(bottom_right.y() + Y);

    // Moving points??
}


void Polyline::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Polyline::calcPerimeter() const
{
    return 0;
}

double Polyline::calcArea() const
{
    return 0;
}
