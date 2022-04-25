#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>
#include <math.h>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPoint>
#include "shape.h"
using namespace std;

class Text : public Shape
{
public:
    /* Public data members */
    QString            String;
    QColor             Color;
    Qt::AlignmentFlag  Alignment;
    int                FontSize;
    QString            FontFamily;
    QFont::Style       FontStyle;       // normal (0), italic (1), or oblique (2)
    QFont::Weight      FontWeight;      // thin (100), extra light (200), light (300), normal (400), medium (500), demibold (600), bold (700), extra bold (800), black (900)
    QPoint             top_left;
    QPoint             bottom_right;

    /* Constructors */
    Text() = delete;
    Text& operator=(const Text&) = delete;  // Disallow copying
    Text(const Text&) = delete;             // Disallow copying
    Text(QPaintDevice*      pdevice,             // Constructor with parameters
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
         int                assign_height);

    /* Destrcutor */
     ~Text() {}

    /* Print function
     * Postcondition: print out the current object ID, perimeter, and area.
     */
    std::ostream& print(std::ostream& os) const override;

    /* Sketch/draw function
     * Postcondition: draw the shape
     */
    void sketch(QPaintDevice* other) override;

    /* Move function
     * Postcondition: the "shape" object is moved to the desire position.
     */
    void move(QPoint &left_side) override;

    /* Update the shape function
     * Postcondition: the object properties are updated.
     */
    void update(void) override;

    /* Calculate perimeter or area functions
     * Postcondition: calculate the object's perimeter and area.
     */
    double calcPerimeter() const override;
    double calcArea() const override;
};
#endif // TEXT_H_

