#include "circle.h"

Circle::Circle(QSharedPointer<Point> center, double radius)
{
    this->center = center;
    this->radius = radius;
}

void Circle::SetCenter(QSharedPointer<Point> center)
{
    this->center = center;
}

void Circle::SetRadius(double radius)
{
    this->radius = radius;
}

double Circle::Area()
{
    return M_PI*radius*radius;
}

double Circle::Diameter()
{
    return 2*radius;
}

double Circle::Circumference()
{
    return 2*M_PI*radius;
}

double Circle::SectorArea(double angle)
{
    angle = Operations::AngleNormalize360(angle);
    return Area()*angle/360;
}

double Circle::SegmentArea(double angle)
{
    return SectorArea(angle) - radius*radius*qSin(qDegreesToRadians(angle))/2;
}
