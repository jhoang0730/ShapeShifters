/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "renderarea.h"

#include <QPainter>

#include "shapes.h"

//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
//! [0]

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(1000, 500);
}
//! [2]

//! [3]
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
//! [3]

//! [4]
void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [6]

//! [7]
void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    Project2::Line line(this);

    line.set_points(QPoint(20, 90), QPoint(100, 20));

    line.set_pen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

    line.draw();

    line.default_style();
    line.draw_rect(width() - 1, height() - 1);

    Project2::Polyline polyline(this);

    polyline.set_point(QPoint(460, 90));
    polyline.set_point(QPoint(470, 20));
    polyline.set_point(QPoint(530, 40));
    polyline.set_point(QPoint(540, 80));

    polyline.set_pen(Qt::green, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    polyline.draw();

    polyline.default_style();
    polyline.draw_rect(width() - 1, height() - 1);

    Project2::Polygon polygon(this);

    polygon.set_point(QPoint(900, 90));
    polygon.set_point(QPoint(910, 20));
    polygon.set_point(QPoint(970, 40));
    polygon.set_point(QPoint(980, 80));

    polygon.set_pen(Qt::cyan, 6, Qt::DashDotDotLine, Qt::FlatCap, Qt::MiterJoin);
    polygon.set_brush(Qt::yellow, Qt::SolidPattern);

    polygon.draw();

    polygon.default_style();
    polygon.draw_rect(width() - 1, height() - 1);

    Project2::Rectangle rectangle(this);

    rectangle.set_rect(QRect(20, 200, 170, 100));

    rectangle.set_pen(Qt::blue, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
    rectangle.set_brush(Qt::red, Qt::VerPattern);

    rectangle.draw();

    rectangle.default_style();
    rectangle.draw_rect(width() - 1, height() - 1);

    Project2::Rectangle square(this);

    square.set_rect(QRect(250, 150, 200, 200)); // length == width => square

    square.set_pen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    square.set_brush(Qt::blue, Qt::HorPattern);

    square.draw();

    square.default_style();
    square.draw_rect(width() - 1, height() - 1);

    Project2::Ellipse ellipse(this);

    ellipse.set_rect(QRect(520, 200, 170, 100));

    ellipse.set_pen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    ellipse.set_brush(Qt::white, Qt::NoBrush);

    ellipse.draw();

    ellipse.default_style();
    ellipse.draw_rect(width() - 1, height() - 1);

    Project2::Ellipse circle(this);

    circle.set_rect(QRect(750, 150, 200, 200)); // semi major axis == semi minor axis => circle

    circle.set_pen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    circle.set_brush(Qt::magenta, Qt::SolidPattern);

    circle.draw();

    circle.default_style();
    circle.draw_rect(width() - 1, height() - 1);

    Project2::Text text(this);

    text.set_rect(QRect(250, 425, 500, 50));

    text.draw();

    text.default_style();
    text.draw_rect(width() - 1, height() - 1);
















//     static const QPoint points[4] = {
//         QPoint(10, 80),
//         QPoint(20, 10),
//         QPoint(80, 30),
//         QPoint(90, 70)
//     };

//     QRect rect(10, 20, 80, 60);

//     QPainterPath path;
//     path.moveTo(20, 80);
//     path.lineTo(20, 30);
//     path.cubicTo(80, 0, 50, 50, 80, 80);

//     int startAngle = 20 * 16;
//     int arcLength = 120 * 16;
// //! [8]

// //! [9]
//     QPainter painter(this);
//     painter.setPen(pen);
//     painter.setBrush(brush);
//     if (antialiased)
//         painter.setRenderHint(QPainter::Antialiasing, true);
// //! [9]

// //! [10]
//     for (int x = 0; x < width(); x += 100) {
//         for (int y = 0; y < height(); y += 100) {
//             painter.save();
//             painter.translate(x, y);
// //! [10] //! [11]
//             if (transformed) {
//                 painter.translate(50, 50);
//                 painter.rotate(60.0);
//                 painter.scale(0.6, 0.9);
//                 painter.translate(-50, -50);
//             }
// //! [11]

// //! [12]
//             switch (shape) {
//             case Line:
//                 painter.drawLine(rect.bottomLeft(), rect.topRight());
//                 break;
//             case Points:
//                 painter.drawPoints(points, 4);
//                 break;
//             case Polyline:
//                 painter.drawPolyline(points, 4);
//                 break;
//             case Polygon:
//                 painter.drawPolygon(points, 4);
//                 break;
//             case Rect:
//                 painter.drawRect(rect);
//                 break;
//             case RoundedRect:
//                 painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
//                 break;
//             case Ellipse:
//                 painter.drawEllipse(rect);
//                 break;
//             case Arc:
//                 painter.drawArc(rect, startAngle, arcLength);
//                 break;
//             case Chord:
//                 painter.drawChord(rect, startAngle, arcLength);
//                 break;
//             case Pie:
//                 painter.drawPie(rect, startAngle, arcLength);
//                 break;
//             case Path:
//                 painter.drawPath(path);
//                 break;
//             case Text:
//                 painter.drawText(rect,
//                                  Qt::AlignCenter,
//                                  tr("Qt by\nThe Qt Company"));
//                 break;
//             case Pixmap:
//                 painter.drawPixmap(10, 10, pixmap);
//             }
// //! [12] //! [13]
//             painter.restore();
//         }
//     }

//     painter.setRenderHint(QPainter::Antialiasing, false);
//     painter.setPen(palette().dark().color());
//     painter.setBrush(Qt::NoBrush);
//     painter.drawRect(QRect(0, 0, width() - 1, height() - 1));


}
//! [13]
