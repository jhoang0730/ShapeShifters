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
    QString            String;     
    QColor             Color;       
    // Text alignment?
    // Text point size? 
    int                FontSize;    
    QString            FontFamily;  
    QFont::Style       FontStyle;       // normal (0), italic (1), or oblique (2) 
    QFont::Weight      FontWeight;      // thin (100), extra light (200), light (300), normal (400), medium (500), demibold (600), bold (700), extra bold (800), black (900)

    Text() = delete;
    Text& operator=(const Text&) = delete;  // Disallow copying
    Text(const Text&) = delete;
    ~Text() {}
};
#endif // TEXT_H_