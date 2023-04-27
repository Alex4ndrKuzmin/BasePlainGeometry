#include "polygon.h"

void Polygon::UpdateEdges()
{
    edges.clear();
    for (int i = 0; i < points.size()-1; i++)
    {
        LineSegment *ls = new LineSegment(points[i], points[i+1]);
        edges.append(QSharedPointer<LineSegment>(ls));
    }
    LineSegment *ls = new LineSegment(points[points.size()], points[0]);
    edges.append(QSharedPointer<LineSegment>(ls));
}

double Polygon::Area()
{
    //Нахождение площади многоугольника по формуле Гаусса
    double sum = 0;
    for (int i = 0; i < points.size()-1; i++)
        sum += points[i]->x() * points[i+1]->y();
    sum += points[points.size()-1]->x() * points[0]->y();

    for (int i = 0; i < points.size()-1; i++)
        sum -= points[i+1]->x() * points[i]->y();
    sum -= points[0]->x() * points[points.size()-1]->y();

    return abs(sum)/2;
}

double Polygon::Perimeter()
{
    return Length();
}
