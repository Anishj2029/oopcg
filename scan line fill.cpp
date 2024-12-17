// polygon filling scan line


#include <iostream>
#include <graphics.h>
#include <vector>
using namespace std;

class Polygon {
protected:
    vector<pair<int, int>> points;

public:
    void addPoint(int x, int y) {
        points.push_back({x, y});
    }

    void drawPolygon() {
        for (size_t i = 0; i < points.size(); i++) {
            int next = (i + 1) % points.size();
            line(points[i].first, points[i].second, points[next].first, points[next].second);
        }
    }
};

class FilledPolygon : public Polygon {
public:
    void scanFill(int fillColor) {
        int ymin = INT_MAX, ymax = INT_MIN;

        for (auto &point : points) {
            ymin = min(ymin, point.second);
            ymax = max(ymax, point.second);
        }

        for (int y = ymin; y <= ymax; y++) {
            vector<int> intersections;
            for (size_t i = 0; i < points.size(); i++) {
                int x1 = points[i].first, y1 = points[i].second;
                int x2 = points[(i + 1) % points.size()].first, y2 = points[(i + 1) % points.size()].second;

                if (y1 != y2 && y >= min(y1, y2) && y < max(y1, y2)) {
                    int x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                    intersections.push_back(x);
                }
            }

            sort(intersections.begin(), intersections.end());
            for (size_t i = 0; i < intersections.size(); i += 2) {
                line(intersections[i], y, intersections[i + 1], y);
                setcolor(fillColor);
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    FilledPolygon poly;
    poly.addPoint(100, 150);
    poly.addPoint(200, 100);
    poly.addPoint(300, 150);
    poly.addPoint(250, 250);
    poly.addPoint(150, 250);

    poly.drawPolygon();
    poly.scanFill(YELLOW);

    getch();
    closegraph();
    return 0;
}
