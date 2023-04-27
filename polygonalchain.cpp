#include "polygonalchain.h"

void PolygonalChain::SetPoints(Points points_)
{
    points = points_;
};

PolygonalChain::Points PolygonalChain::GetPoints()
{
    return points;
};

void PolygonalChain::UpdateEdges()
{
    edges.clear();
    for (int i = 0; i < points.size()-1; i++)
    {
        LineSegment *ls = new LineSegment(points[i], points[i+1]);
        edges.append(QSharedPointer<LineSegment>(ls));
    }
}

double PolygonalChain::Length()
{
    double p = 0;
    foreach(QSharedPointer<LineSegment> ls, edges)
        p += ls->Length();
    return p;
}
