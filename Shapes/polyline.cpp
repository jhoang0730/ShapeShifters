#include "polyline.h"

Polyline::Polyline(QPaintDevice*    pdevice,         // Constructor with parameters
                 int                assign_id,
                 QColor             assign_pen_color,
                 qreal              assign_pen_width,
                 Qt::PenStyle       assign_penstyle,
                 Qt::PenCapStyle    assign_pencap_style,
                 Qt::PenJoinStyle   assign_penjoin_style,
                 const std::vector<QPoint> assign_points)
     : Shape (pdevice, assign_id, ShapeType::Polyline)
{
    /* Assigning "pen" properties */
    polyline_pen.setColor(assign_pen_color);
    polyline_pen.setWidth(assign_pen_width);
    polyline_pen.setStyle(assign_penstyle);
    polyline_pen.setCapStyle(assign_pencap_style);
    polyline_pen.setJoinStyle(assign_penjoin_style);

    /* Setting up point */
    vpoints = assign_points;

    qreal x_min = 0;        // qreal - typedef for double
    qreal y_min = 0;
    qreal x_max = 0;
    qreal y_max = 0;

    std::vector<QPoint>::iterator iterate = vpoints.begin();


    // Connecting points
    while (iterate!=vpoints.end()-1) {
        // Finding the min points
        if (iterate->x() < x_min)
        {
            x_min = iterate->x();
        }
        if (iterate->y() < y_min)
        {
            y_min = iterate->y();
        }

        // Finding the max points
        if (iterate->x() > x_max)
        {
            x_max = iterate->x();
        }
        if (iterate->y() > y_max)
        {
            y_max = iterate->y();
        }
        ++iterate;
    }

    // Setting points
    top_left.setX(x_min);
    top_left.setY(y_min);
    bottom_right.setX(x_max);
    bottom_right.setY(y_max);
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
    top_left = left_side;
    bottom_right.setX(bottom_right.x() + left_side.x() - top_left.x());
    bottom_right.setY(bottom_right.y() + left_side.y() - top_left.y());

    // Moving points
    std::vector<QPoint>::iterator iterate = vpoints.begin();
    while (iterate!=vpoints.end()-1) {
        iterate->setX(iterate->x() + left_side.x() - top_left.x());
        iterate->setY(iterate->y() + left_side.y() - top_left.y());
    }
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
