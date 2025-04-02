#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
};

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return val == 0 ? 0 : (val > 0 ? 1 : -1);
}

vector<Point> grahamScan(vector<Point> points) {
    sort(points.begin(), points.end());
    vector<Point> hull;
    for (int i = 0; i < 2; i++) {
        int s = hull.size();
        for (Point &p : points) {
            while (hull.size() >= s + 2 && orientation(hull[hull.size()-2], hull.back(), p) != -1)
                hull.pop_back();
            hull.push_back(p);
        }
        reverse(points.begin(), points.end());
    }
    hull.pop_back();
    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    cout << "Grahams Scan Convex Hull:\n";
    for (auto p : grahamScan(points))
        cout << "(" << p.x << ", " << p.y << ")\n";
    return 0;
}