#ifndef CIRCLE_H
#define CIRCLE_H

#include "Primitive.h"

class Circle
{
protected:
    double radius;
    QSharedPointer<Point> center;

public:
    Circle(QSharedPointer<Point> center, double radius);
    void SetCenter(QSharedPointer<Point> center);
    void SetRadius(double radius);

    double Area();
    double Diameter();
    double Circumference();
    double SectorArea(double angle);
    double SegmentArea(double angle);

};

#endif // CIRCLE_H
