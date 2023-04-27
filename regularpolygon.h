#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "polygon.h"
#include <QtMath>

class RegularPolygon : public Polygon
{
    //temp
public:
    double angle;
    double radius;
    int angleCount;

    QSharedPointer<Point> center;

public:
    RegularPolygon(QSharedPointer<Point> center, int angleCount, double radius);
};

#endif // REGULARPOLYGON_H
