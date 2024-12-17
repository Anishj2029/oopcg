// 2D rotation translation

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Point {
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point &p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator*(float scale) {
        return Point(x * scale, y * scale);
    }
};

class Shape {
    Point points[3];

public:
    Shape(Point p1, Point p2, Point p3) {
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
    }

    void draw(int color) {
        setcolor(color);
        line(points[0].x, points[0].y, points[1].x, points[1].y);
        line(points[1].x, points[1].y, points[2].x, points[2].y);
        line(points[2].x, points[2].y, points[0].x, points[0].y);
    }

    void translate(Point translation) {
        for (int i = 0; i < 3; i++) {
            points[i] = points[i] + translation;
        }
    }

    void scale(float factor) {
        for (int i = 0; i < 3; i++) {
            points[i] = points[i] * factor;
        }
    }

    void rotate(float angle) {
        float radians = angle * M_PI / 180;
        for (int i = 0; i < 3; i++) {
            int x = points[i].x;
            int y = points[i].y;
            points[i].x = x * cos(radians) - y * sin(radians);
            points[i].y = x * sin(radians) + y * cos(radians);
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Shape triangle(Point(200, 200), Point(250, 100), Point(300, 200));
    triangle.draw(WHITE);

    triangle.translate(Point(50, 50));
    triangle.draw(GREEN);

    triangle.scale(0.8);
    triangle.draw(RED);

    triangle.rotate(45);
    triangle.draw(YELLOW);

    getch();
    closegraph();
    return 0;
}
