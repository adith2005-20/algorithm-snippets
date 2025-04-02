#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    return val == 0 ? 0 : (val > 0 ? 1 : -1);
}

vector<Point> jarvisMarch(vector<Point> points) {
    if (points.size() < 3) return points;
    vector<Point> hull;
    int leftmost = min_element(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }) - points.begin();
    
    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % points.size();
        for (int i = 0; i < points.size(); i++)
            if (orientation(points[p], points[i], points[q]) == -1)
                q = i;
        p = q;
    } while (p != leftmost);
    
    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    cout << "Jarvis March Convex Hull:\n";
    for (auto p : jarvisMarch(points))
        cout << "(" << p.x << ", " << p.y << ")\n";
    return 0;
}