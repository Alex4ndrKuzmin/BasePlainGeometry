#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include <QPoint>
#include <QList>
#include <QPair>
#include <QSharedPointer>
#include <QtMath>

enum Errors
{
    NoErrors,
    MismatchedPoints,
    MatchingPoints
};

struct Point
{
protected:
    double x_ = 0;
    double y_ = 0;

public:
    Point (double x, double y)
    {
        SetX(x);
        SetY(y);
    }

    void SetX(double x){ x_ = x; }
    void SetY(double y){ y_ = y; }
    double x() { return x_; }
    double y() { return y_; }
};

struct LineSegment
{
private:
    void UpdateLength() { length = sqrt(pow(first->x() - second->x(), 2) + pow(first->y() - second->y(), 2)); }

protected:
    QSharedPointer<Point> first;
    QSharedPointer<Point> second;
    double length = 0;

public:
    LineSegment(QSharedPointer<Point> first, QSharedPointer<Point> second)
    {
        this->first = first;
        this->second = second;
        UpdateLength();
    }

    Point* First(){ return first.get(); };
    Point* Second(){ return second.get(); };
    void SetFirst(QSharedPointer<Point> first_)
    {
        first = first_;
        UpdateLength();
    };

    void SetSecond(QSharedPointer<Point> second_)
    {
        second = second_;
        UpdateLength();
    };

    double Length()
    {
        return length;
    };
};

struct Angle
{
private:
    void UpdateAngle()
    {
        Point v1(first->x() - second->x(), first->y() - second->y());
        Point v2(third->x() - second->x(), third->y() - second->y());
        double scalar = v1.x()*v2.x() + v1.y()*v2.y();
        double lenMult = sqrt((pow(v1.x(), 2) + pow(v1.y(), 2)) * (pow(v2.x(), 2) + pow(v2.y(), 2)));
        angleRadian = qAcos(scalar/lenMult);
        angle = qRadiansToDegrees(angleRadian);
    }

protected:
    QSharedPointer<Point> first;
    QSharedPointer<Point> second;
    QSharedPointer<Point> third;
    double angle = 0;
    double angleRadian = 0;

public:
    Angle(QSharedPointer<Point> first, QSharedPointer<Point> second, QSharedPointer<Point> third)
    {
        this->first = first;
        this->second = second;
        this->third = third;
        UpdateAngle();
    }

    void SetFirst(QSharedPointer<Point> first_)
    {
        first = first_;
        UpdateAngle();
    };

    void SetSecond(QSharedPointer<Point> second_)
    {
        second = second_;
        UpdateAngle();
    };

    void SetThird(QSharedPointer<Point> third_)
    {
        third = third_;
        UpdateAngle();
    };

    double Degree() { return angle; }
    double Radian() { return angleRadian; }
};


namespace Operations
{
    double ScalarMult(Point);

    double AngleNormalize360(double angle)
    {
        angle = fmod(angle, 360);
        return angle < 0 ? angle + 360: angle;
    }
}

#endif // PRIMITIVE_H
