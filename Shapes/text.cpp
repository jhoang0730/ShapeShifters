#include"text.h"

Text::Text(QPaintDevice*      pdevice,
           int                assign_id,
           QString            assign_string,
           QColor             assign_color,
           Qt::AlignmentFlag  assign_allignment,
           int                assign_fontsize,
           QString            assign_fontfamily,
           QFont::Style       assign_fontstyle,
           QFont::Weight      assign_fontweight,
           int                top_leftx,
           int                top_lefty,
           int                assign_width,
           int                assign_height)
    : Shape(pdevice, assign_id, ShapeType::Text), String{assign_string}, Color{assign_color}, Alignment{assign_allignment},
      FontSize{assign_fontsize}, FontFamily{assign_fontfamily}, FontStyle{assign_fontstyle},
      FontWeight{assign_fontweight}
{
    /* Setting up points */
    QPoint ul(top_leftx,top_lefty);
    top_left = ul;
    QPoint lr(top_leftx+assign_width, top_lefty+assign_height);
    bottom_right = lr;
}


std::ostream& Text::print(std::ostream& os) const
{
    return os << "= Shape's Id:" << GetID() << " and shape's perimeter: " << calcPerimeter() << ", area: " << calcArea();
}


void Text::sketch(QPaintDevice* other)
{
    QPainter& tPaint = GetPainter();
    QFont tFont(FontFamily, FontSize);
    QPen  tPen(Color);
    QRect tRect(top_left, bottom_right);
    tFont.setStyle(FontStyle);
    tFont.setWeight(FontWeight);
    tPaint.begin(&GetPaintDevice());
    tPaint.setFont(tFont);
    tPaint.setPen(tPen);
    tPaint.drawText(tRect, Alignment, String);
    tPaint.setPen(QPen());
    tPaint.drawText((top_left.x()) - 5, (top_left.y()) - 5, QString::number(this->GetID()));
    tPaint.end();
}


void Text::move(QPoint &left_side)
{
    top_left = left_side;
    bottom_right.setX(bottom_right.x() + left_side.x() - top_left.x());
    bottom_right.setY(bottom_right.y() + left_side.y() - top_left.y());
}


void Text::update(void)
{
    sketch((&GetPaintDevice()));
    return;
}


double Text::calcPerimeter() const
{
    return 0;
}


double Text::calcArea() const
{
    return 0;
}
