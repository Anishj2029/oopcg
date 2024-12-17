//snowflex 

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Function to draw a Koch curve recursively
void drawKochCurve(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
    } else {
        int x3 = (2 * x1 + x2) / 3;
        int y3 = (2 * y1 + y2) / 3;

        int x4 = (x1 + 2 * x2) / 3;
        int y4 = (y1 + 2 * y2) / 3;

        int x5 = (x3 + x4) / 2 - (y4 - y3) * sqrt(3) / 2;
        int y5 = (y3 + y4) / 2 + (x4 - x3) * sqrt(3) / 2;

        drawKochCurve(x1, y1, x3, y3, depth - 1);
        drawKochCurve(x3, y3, x5, y5, depth - 1);
        drawKochCurve(x5, y5, x4, y4, depth - 1);
        drawKochCurve(x4, y4, x2, y2, depth - 1);
    }
}

// Function to draw the snowflake by creating three Koch curves
void drawSnowflake(int x1, int y1, int x2, int y2, int x3, int y3, int depth) {
    drawKochCurve(x1, y1, x2, y2, depth);
    drawKochCurve(x2, y2, x3, y3, depth);
    drawKochCurve(x3, y3, x1, y1, depth);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int depth;
    cout << "Enter the depth of the snowflake (e.g., 1 to 5): ";
    cin >> depth;

    int x1 = 200, y1 = 150;
    int x2 = 400, y2 = 150;
    int x3 = 300, y3 = 300;

    drawSnowflake(x1, y1, x2, y2, x3, y3, depth);

    getch();
    closegraph();
    return 0;
}

