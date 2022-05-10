#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    numShapes = 0;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void Canvas::paintEvent(QPaintEvent*)
{
    QPaintDevice *device = this;
    for(int i = 0; i < shapeVec.size(); i++)
    {
        shapeVec[i]->draw(device);
    }
}

const shapeVector<Shape*>& Canvas::getShape()
{
    return shapeVec;
}

void Canvas::addShape(Shape* insertShape)
{
    shapeVec.push_back(insertShape);
    numShapes++;
}

void Canvas::deleteShape(int removeIndex)
{
    Vector<Shape*>::iterator i;
    for(i = shapeVec.begin(); i < shapeVec.end(); i++)
    {
        if((*i)->getID() = removeIndex)
        {
            shapeVec.erase(i);
            numShapes--;
            break;
        }
    }
}

void Canvas::shapeMove(int moveIndex, int moveCoord, int x, int y)
{
    for(int i = 0; i < shapeVec.size(); i++)
    {
        if(shapeVec[i]->getID() = moveIndex)
        {
            shapeVec[i]->move(x,y,moveCoord);
            break;
        }
    }
}

int Canvas::getNumShapes()
{
    return numShapes;
}

QSize Canvas::sizeHint() const
{
    return QSize(1000, 500);
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(1000, 500);
}

int Canvas::getSize()
{
    return shapeVec.size();
}


