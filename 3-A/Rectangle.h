#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    Rectangle();
    ~Rectangle();

    private:
        int x1, x2, x3, x4, y1, y2, y3, y4;
        double line1Len, line2Len, line3Len, line4Len;
    public:
        bool square();
        double area();
        int length();
        int width();
        void setCoords();

        
};

#endif //RECTANGLE_H