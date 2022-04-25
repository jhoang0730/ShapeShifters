#include "polygon.h"

Polygon::Polygon( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush )
    : Shape (pdevice, assign_id, ShapeType::Polygon, assign_pen, assign_brush) {}

Polygon::Polygon(QPaintDevice*       pdevice,             // Constructor with parameters
        int                assign_id,
        QColor             assign_pen_color,
        qreal              assign_pen_width,
        Qt::PenStyle       assign_penstyle,
        Qt::PenCapStyle    assign_pencap_style,
        Qt::PenJoinStyle   assign_penjoin_style,
        QColor             assign_burshcolor,
        Qt::BrushStyle     assign_brushstyle,
        int                top_leftx,
        int                top_lefty)
    : Shape (pdevice, assign_id, ShapeType::Polygon)
{
    /* Assigning "pen" properties */
    polygon_pen.setColor(assign_pen_color);
    polygon_pen.setWidth(assign_pen_width);
    polygon_pen.setStyle(assign_penstyle);
    polygon_pen.setCapStyle(assign_pencap_style);
    polygon_pen.setJoinStyle(assign_penjoin_style);

    /* Assigning "brush" properties */
    polygon_brush.setColor(assign_burshcolor);
    polygon_brush.setStyle(assign_brushstyle);

    /* Setting up point */
    // Need implementation
}

std::ostream& Polygon::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}

void Polygon::sketch(QPaintDevice* other)
{
    QPainter& paint = GetPainter();
    paint.begin(other);
    paint.setPen(polygon_pen);
    paint.setBrush(polygon_brush);
    const QPoint *starting_point = &(*vpoints.begin());
    paint.drawPolygon(starting_point,vpoints.size());
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Polygon::move(QPoint &left_side)
{
    int X = (left_side.x() - top_left.x());
    int Y = (left_side.y() - top_left.y());

    top_left = left_side;
    bottom_right.setX(bottom_right.x() + X);
    bottom_right.setY(bottom_right.y() + Y);
}

void Polygon::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Polygon::calcPerimeter() const
{
    double perimeter = 0;
    for(std::vector<QPoint>::const_iterator i=vpoints.begin();i<vpoints.end()-1;++i)
    {
       perimeter += sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2)));   // Need to check again
    }
    return perimeter;
}

double Polygon::calcArea() const
{
    std::vector<QPoint>::const_iterator i=vpoints.begin();
    double area = ((calcPerimeter())*((sqrt((pow((i->x()-((i+1)->x())),2)+pow((i->y()-(i+1)->y()),2))))/(2*tan(180/vpoints.size()))))/2; // Need to check again
    return area;
}

