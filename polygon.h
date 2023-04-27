#ifndef POLYGON_H
#define POLYGON_H

#include "polygonalchain.h"

class Polygon : public PolygonalChain
{   
public:
    Polygon() { };
    Polygon(Points points) : PolygonalChain(points)
    {
        this->points = points;
        UpdateEdges();
    };

protected:
    void UpdateEdges();
};

#endif // POLYGON_H
