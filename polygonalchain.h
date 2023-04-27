#ifndef POLYGONALCHAIN_H
#define POLYGONALCHAIN_H

#include <QObject>
#include "Primitive.h"

class PolygonalChain
{
public:
    typedef QList<QSharedPointer<LineSegment>> LineSegments;
    typedef QList<QSharedPointer<Point>> Points;

protected:
    LineSegments edges;
    Points points;

public:

    PolygonalChain() {};
    PolygonalChain(Points points) { this->points = points; }

    void SetPoints(Points points_);
    Points GetPoints();

    double Length();

private:
    void UpdateEdges();
};

#endif // POLYGONALCHAIN_H
