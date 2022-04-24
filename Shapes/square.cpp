#include "square.h"

Square::Square( QPaintDevice *pdevice, int assign_id, QPen assign_pen, QBrush assign_brush )
    : Shape (pdevice, assign_id, ShapeType::Square, assign_pen, assign_brush) {}

Square::Square( QPaintDevice*      pdevice,             // Constructor with parameters
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
                int                assign_side)
    : Shape (pdevice, assign_id, ShapeType::Square)
{
    /* Assigning "pen" properties */
    square_pen.setColor(assign_pen_color);
    square_pen.setWidth(assign_pen_width);
    square_pen.setStyle(assign_penstyle);
    square_pen.setCapStyle(assign_pencap_style);
    square_pen.setJoinStyle(assign_penjoin_style);

    /* Assigning "brush" properties */
    square_brush.setColor(assign_burshcolor);
    square_brush.setStyle(assign_brushstyle);

    /* Setting up point */
    QPoint ul(top_leftx,top_lefty);
    top_left = ul;
    QPoint lr(top_leftx+assign_side, top_leftx+assign_side);
    bottom_right = lr;
}

std::ostream& Square::print(std::ostream& os) const
{
    return os << " Id:" << GetID() << " P:" << calcPerimeter() << " A:" << calcArea();
}

void Square::sketch(QPaintDevice* device)
{
    QRect rect1(top_left, bottom_right);
    QPainter& paint = GetPainter();
    paint.begin(device);
    paint.setPen(square_pen);
    paint.setBrush(square_brush);
    paint.drawRect(rect1);
    paint.setPen(QPen());
    paint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    paint.end();
}

void Square::move(QPoint &left_side)
{
    int deltaX = (left_side.x() - top_left.x());
    int deltaY = (left_side.y() - top_left.y());

    top_left = left_side;
    bottom_right.setX(bottom_right.x() + deltaX);
    bottom_right.setY(bottom_right.y() + deltaY);
}

void Square::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}

double Square::calcPerimeter() const
{
    return ( ((bottom_right.x()-top_left.x()) * 2) + ((bottom_right.y()-top_left.y()) * 2));
}

double Square::calcArea() const
{
    return ( (bottom_right.x()-top_left.x()) * (bottom_right.y()-top_left.y()));
}
