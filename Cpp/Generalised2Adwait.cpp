#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

// Cross product of vector AB and AC
int crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Check if point P is on segment AB
bool isOnSegment(Point A, Point B, Point P) {
    return (A.x <= P.x && P.x <= B.x || B.x <= P.x && P.x <= A.x) && 
           (A.y <= P.y && P.y <= B.y || B.y <= P.y && P.y <= A.y);
}

// Check if two line segments intersect
bool doIntersect(Line l1, Line l2) {
    int d1 = crossProduct(l1.p1, l1.p2, l2.p1);
    int d2 = crossProduct(l1.p1, l1.p2, l2.p2);
    int d3 = crossProduct(l2.p1, l2.p2, l1.p1);
    int d4 = crossProduct(l2.p1, l2.p2, l1.p2);

    if ((d1 * d2 < 0) && (d3 * d4 < 0)) return true; // Proper intersection

    if (d1 == 0 && isOnSegment(l1.p1, l1.p2, l2.p1)) return true;
    if (d2 == 0 && isOnSegment(l1.p1, l1.p2, l2.p2)) return true;
    if (d3 == 0 && isOnSegment(l2.p1, l2.p2, l1.p1)) return true;
    if (d4 == 0 && isOnSegment(l2.p1, l2.p2, l1.p2)) return true;

    return false;
}

// Check if a point is inside, outside, or on the polygon
string pointLocation(vector<Point> &polygon, Point p) {
    int count = 0;
    Point outside = {10000, p.y}; // A point far outside the polygon
    Line ray = {p, outside};

    for (size_t i = 0; i < polygon.size(); i++) {
        Line edge = {polygon[i], polygon[(i + 1) % polygon.size()]};
        if (doIntersect(ray, edge)) count++;
        if (isOnSegment(edge.p1, edge.p2, p)) return "On the polygon";
    }
    return (count & 1) ? "Inside the polygon" : "Outside the polygon";
}

int main() {
    int n;
    cout << "Enter the number of sides of the polygon: ";
    cin >> n;
    vector<Point> polygon(n);
    cout << "Enter the coordinates of the polygon vertices in order (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point p;
    cout << "Enter the coordinates of the point (x y): ";
    cin >> p.x >> p.y;

    cout << "The point is " << pointLocation(polygon, p) << ".\n";

    return 0;
}
