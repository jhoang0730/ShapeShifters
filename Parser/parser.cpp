#include "parser.h"

#include <Qt>
#include <QPen>
#include <QColor>
#include <QFont>
#include <QMap>

FileParser::FileParser() {}

FileParser::~FileParser() {}

void FileParser::parseFile(Canvas &canvas) {
	ifstream inFile;
	inFile.open("shapes.txt");

	int id;
	string buffer;

	while (inFile) {
		int type = 0;

		inFile.ignore(1000, ":");
		inFile >> id;
		inFile.ignore(1000, ":");
		inFile >> buffer;

		if(inFile.eof()) {
			break;
		}

		if (buffer == "Line") {
			canvas.addShape(readLine(inFile, id))
		}
		else if (buffer == "Polyline") {
			//parsedShapes.push_back(readPolyLine(inFile, id));
		}
		else if (buffer == "Polygon") {
			//parsedShapes.push_back(readPolygon(inFile, id));
		}
		else if (buffer == "Rectangle") {
			canvas.addShape(readRectangle(inFile, id));
		}
		else if (buffer == "Square") {
			canvas.addShape(readSquare(inFile, id));
		}
		else if (buffer == "Ellipse") {
			canvas.addShape(readEllipse(inFile, id));
		}
		else if (buffer == "Circle") {
			canvas.addShape(readCircle(inFile, id));
		}
		else if (buffer == "Text") {
			canvas.addShape(readText(inFile, id));
		}
		else {
			cout << "Error";
		}

	}

	inFile.close();
	return parsedShapes;
}

Shape* readLine(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y , x2, y2, width;
	string color, pen, cap, join;

	// Read in two points.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ',');
	inFile >> y;
	inFile.ignore(1000, ',');
	inFile >> x2;
	inFile.ignore(1000, ',');
	inFile >> y2;

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, style);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, style);

	// I don't know what the qpaint device is. 
	Line *line = new Line(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), x, y, x2, y2);
	return line;
}

Shape* readPolyLine(Canvas &canvas, ifstream &inFile, int id)
{
	int width;
	string color, pen, cap, join;
	vector<QPoint> points;

	// Read in points.
	inFile.ignore(1000, ':');
	do {
		int x, y;
		inFile.get();
		inFile >> x;
		inFile.get();
		inFile >> y;
		ERR:PUSH_TO_VECTOR(EMPLACE_BACK?) // points.emplace_back(x, y)
	} while (inFile.peek() == ',');

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	Polyline *pline = new Polyline (canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), ERR:CONSTRUCTOR_ONLY_HAS_ONE_SET_OF_POINTS);
	return pline;
}

Shape* readPolygon(Canvas &canvas, ifstream &inFile, int id)
{
	int width;
	string color, pen, cap, join, bstyle, bcolor;
	vector<QPoint> points;

	// Read in points.
	inFile.ignore(1000, ':');
	do {
		int x, y;
		inFile.get();
		inFile >> x;
		inFile.get();
		inFile >> y;
		ERR:PUSH_TO_VECTOR(EMPLACE_BACK?)
	} while (inFile.peek() == ',');

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	// Read brush color.
	inFile.ignore(1000, ':');
	getline(inFile, bcolor);
	QColor brushColor(getColor(bcolor))

	// Read brush style.
	inFile.ignore(1000, ':');
	getline(inFile, bstyle);

	Polygon *pgon = new Polygon(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), brushColor, getBrush(bstyle), ERR:CONSTRUCTOR_ONLY_HAS_ONE_SET_OF_POINTS);
	return pgon;
}

Shape* readRectangle(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y, l, w, width;
	string color, pen, cap, join, bstyle, bcolor;

	// Read in points and dimensions.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ':');
	inFile >> y;
	inFile.ignore(1000, ':');
	inFile >> l;
	inFile.ignore(1000, ':');
	inFile >> w;

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	// Read brush color.
	inFile.ignore(1000, ':');
	getline(inFile, bcolor);
	QColor brushColor(getColor(bcolor))

	// Read brush style.
	inFile.ignore(1000, ':');
	getline(inFile, bstyle);

	Rectangle *rect = new Rectangle(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), brushColor, getBrush(bstyle), x, y, l, w);
	return rect;
}

Shape* readSquare(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y, l, width;
	string color, pen, cap, join, bstyle, bcolor;

	// Read in points and dimensions.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ':');
	inFile >> y;
	inFile.ignore(1000, ':');
	inFile >> l;

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	// Read brush color.
	inFile.ignore(1000, ':');
	getline(inFile, bcolor);
	QColor brushColor(getColor(bcolor))

	// Read brush style.
	inFile.ignore(1000, ':');
	getline(inFile, bstyle);

	Square *squ = new Square(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), brushColor, getBrush(bstyle), x, y, l);
	return squ;
}

Shape* readEllipse(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y, l, w, width;
	string color, pen, cap, join, bstyle, bcolor;

	// Read in points and dimensions.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ':');
	inFile >> y;
	inFile.ignore(1000, ':');
	inFile >> l;
	inFile.ignore(1000, ':');
	inFile >> w;

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	// Read brush color.
	inFile.ignore(1000, ':');
	getline(inFile, bcolor);
	QColor brushColor(getColor(bcolor))

	// Read brush style.
	inFile.ignore(1000, ':');
	getline(inFile, bstyle);

	Ellipse *ell = new Ellipse(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), brushColor, getBrush(bstyle), x, y, l, w);
	return ell;
}

Shape* readCircle(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y, l, width;
	string color, pen, cap, join, bstyle, bcolor;

	// Read in points and dimensions.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ':');
	inFile >> y;
	inFile.ignore(1000, ':');
	inFile >> l;

	// Read and assign color.
	inFile.ignore(1000, ':');
	getline(inFile, color);

	// Read width.
	inFile.ignore(1000, ':');
	inFile >> width;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, pen);

	// Read cap.
	inFile.ignore(1000, ':');
	getline(inFile, cap);

	// Read join.
	inFile.ignore(1000, ':');
	getline(inFile, join);

	// Read brush color.
	inFile.ignore(1000, ':');
	getline(inFile, bcolor);
	QColor brushColor(getColor(bcolor))

	// Read brush style.
	inFile.ignore(1000, ':');
	getline(inFile, bstyle);

	Circle *circ = new Circle(canvas, id, getColor(color), width, getPen(pen), getCap(cap), getJoin(join), brushColor, getBrush(bstyle), x, y, l);
	return circ;
}

Shape* readText(Canvas &canvas, ifstream &inFile, int id)
{
	int x, y, l, w, width;
	string textStr, color, allignment, fsize, fontfam, fontstyle, fweight;

	// Read in points and dimensions.
	inFile.ignore(1000, ':');
	inFile >> x;
	inFile.ignore(1000, ':');
	inFile >> y;
	inFile.ignore(1000, ':');
	inFile >> l;
	inFile.ignore(1000, ':');
	inFile >> w;

	// Read text.
	inFile.ignore(1000, ':');
	getline(inFile, textStr);

	// Read color.
	inFile.ignore(1000, ':');
	getline(inFile, color);
	QColor textColor(getColor(color))

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, allignment);

	// Read font sie.
	inFile.ignore(1000, ':');
	inFile >> fsize;

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, fontfam);

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, fontstyle);

	// Read pen.
	inFile.ignore(1000, ':');
	getline(inFile, fweight);

	Text *txt = new Text(canvas, id, textStr, textColor, getAlignFlag(allignment), fsize, fontfam, getText(fontstyle), getWeight(fweight) x, y, l, w);
	return txt;
}

Qt::GlobalColor getColor(const string& text) {
	int num = 0;
	if (text == "black")
		num = 1;
	else if (text == "red")
		num = 2;
	else if (text == "green")
		num = 3;
	else if (text == "blue")
		num = 4;
	else if (text == "cyan")
		num = 5;
	else if (text == "magenta")
		num = 6;
	else if (text == "yellow")
		num = 7;
	else if (text == "gray")
		num = 8;

	return num;
}

Qt::PenStyle getPen(const string& text) {
	int num = 0;
	if(text == "SolidLine")
		num = 1;
	else if (text == "DashLine")
		num = 2;
	else if (text == "DotLine")
		num = 3;
	else if (text == "DashDotLine")
		num = 4;
	else if (text == "DashDotDotLine")
		num = 5;

	return num;
}

Qt::PenCapStyle getCap(const string& text) {
	int num = 0;
	if (text == "SquareCap")
		num = 1;
	else if (text == "RoundCap")
		num = 2;

	return num;
}

Qt::PenJoinStyle getJoin(const string& text) {
	int num = 0;
	if (text == "BevelJoin")
		num = 1;
	else if (text == "RoundJoin")
		num = 2;

	return num;
}

Qt::BrushStyle getBrush(const string& text) {
	int num = 0;
	if (text == "HorPattern")
		num = 1;
	else if (text == "VerPattern")
		num = 2;
	else if (text == "NoBrush")
		num = 3;

	return num;
}

Qt::AlignmentFlag getAlignFlag(const string& text) {
	int num = 0;
	if (text == "AlignRight")
		num = 1;
	else if (text == "AlignTop")
		num = 2;
	else if (text == "AlignBottom")
		num = 3;
	else if (text == "AlignCenter")
		num = 4;

	return num;
}

Qt::GlobalColor getColor(const string& text) {
	int num = 0;
	if (text == "black")
		num = 1;
	else if (text == "red")
		num = 2;
	else if (text == "green")
		num = 3;
	else if (text == "blue")
		num = 4;
	else if (text == "cyan")
		num = 5;
	else if (text == "magenta")
		num = 6;
	else if (text == "yellow")
		num = 7;
	else if (text == "gray")
		num = 8;

	return num;
}

QFont::Style getText(const string& text) {
	int num = 0;
	if (text == "StyleItalic")
		num = 1;
	else if (text == "StyleOblique")
		num = 2;

	return num;
}

QFont::Weight getWeight(const string& text) {
	int num = 0;
	if (text == "Light")
		num = 1;
	else if (text == "Normal")
		num = 2;
	else if (text == "Bold")
		num = 3;

	return num;
}