#include "shape.h"

Shape( QPaintDevice *pdevice, int xId, ShapeType type, QPen xpen, QBursh xbrush )       // Copy constructor with parameters
           : device{pDevice}, shapeId{xId}, typeShape{type}, painter{pDevice}  {
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}