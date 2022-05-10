#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "shape.h"
#include "vector.h"
#include <QPaintEvent>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>

class Canvas : public QWidget
{
    Q_OBJECT

private:
    const QImage canvas;
    vector<Shape*> shapeVec;
    int numShapes;

public:
    explicit Canvas(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    const shapeVector<Shape*>& getShape();

    void addShape(Shape* insertShape);

    int getSize();
    int getNumShapes();

    void deleteShape(int removeIndex);
    void shapeMove(int moveIndex, int moveCoord, int x, int y);

signals:

};

#endif // CANVAS_H
