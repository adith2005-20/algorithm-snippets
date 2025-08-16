#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : (val > 0) ? 1 : 2;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2);
}

void convexHullGraham(vector<Point> points) {
    int n = points.size();
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
        if ((points[i].y < ymin) || (ymin == points[i].y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;

    swap(points[0], points[min]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), compare);

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (S.size() > 1) {
            Point second = S.top();
            S.pop();
            Point first = S.top();
            if (orientation(first, second, points[i]) != 2) {
                continue;
            } else {
                S.push(second);
                break;
            }
        }
        S.push(points[i]);
    }

    while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        S.pop();
    }
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHullGraham(points);
    return 0;
}
