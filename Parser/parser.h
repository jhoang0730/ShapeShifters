#ifndef PARSER_H
#define PARSER_H

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "text.h"
#include "vector.h"
#include "canvas.h"

Shape* readLine(ifstream&, int id);
Shape* readPolyLine(ifstream&, int id);
Shape* readPolygon(ifstream&, int id);
Shape* readRectangle(ifstream&, int id);
Shape* readSquare(ifstream&, int id);
Shape* readEllipse(ifstream&, int id);
Shape* readCircle(ifstream&, int id);
Shape* readText(ifstream&, int id);

Qt::GlobalColor getColor(const string&);
Qt::PenStyle getPen(const string&);
Qt::PenCapStyle getCap(const string&);
Qt::PenJoinStyle getJoin(const string&);
Qt::BrushStyle getBrush(const string&);
Qt::AlignmentFlag getAlignFlag(const string&);
QFont::Style getText(const string&)
QFont::Weight getWeight(const string&);

class FileParser
{
public:
	FileParser();

	~FileParser();

	void parseFile(Canvas &canvas);
}

#endif // Shape_Parser