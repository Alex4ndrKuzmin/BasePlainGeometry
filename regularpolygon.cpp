#include "regularpolygon.h"

RegularPolygon::RegularPolygon(QSharedPointer<Point> center, int angleCount, double radius)
{
    this->center = center;
    this->angleCount = angleCount;
    this->radius = radius;
    angle = double((angleCount-2)*180)/double(angleCount);

    for (int i = 0; i < angleCount; i++)
    {
        Point *point = new Point
        (
            center->x() + radius*qCos(M_PI/2 + i * 2 * M_PI / angleCount),
            center->y() + radius*qSin(M_PI/2 + i * 2 * M_PI / angleCount)
        );
        points.append(QSharedPointer<Point>(point));
    }
}
