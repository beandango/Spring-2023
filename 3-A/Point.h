#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        double x, y;
    public:
        Point(double x=0, double y=0);
        double getX()
        { return x; }
        double getY()
        { return y; }
        void setX(int x)
        { this->x = x; }
        void setY(int y)
        { this->y = y; }
};


#endif //POINT_H