#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

// Compute the cross product of vectors AB and AC
double cross(const Point &A, const Point &B, const Point &C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Check if a point p is inside the convex polygon 'poly'
// Assumes vertices of poly are in order (clockwise or counterclockwise)
bool isPointInsidePolygon(const vector<Point> &poly, const Point &p) {
    int n = poly.size();
    bool hasPos = false, hasNeg = false;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double cp = cross(poly[i], poly[j], p);
        if (cp > 0) hasPos = true;
        if (cp < 0) hasNeg = true;
        // If both positive and negative cross products occur, p is outside
        if (hasPos && hasNeg)
            return false;
    }
    return true; // p is inside or on the boundary
}

// Check if a line segment defined by points p and q is completely inside the polygon
// For a convex polygon, if both endpoints are inside, then the entire segment is inside.
bool isLineInsidePolygon(const vector<Point> &poly, const Point &p, const Point &q) {
    return isPointInsidePolygon(poly, p) && isPointInsidePolygon(poly, q);
}

int main() {
    int n;
    cout << "Enter the number of sides of the regular polygon: ";
    cin >> n;
    vector<Point> polygon(n);
    cout << "Enter the coordinates of the polygon vertices in order (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    int queryType;
    cout << "\nQuery Options:\n";
    cout << "1. Check if a point is inside the polygon\n";
    cout << "2. Check if a line segment is completely inside the polygon\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> queryType;

    if (queryType == 1) {
        Point p;
        cout << "Enter the coordinates of the point (x y): ";
        cin >> p.x >> p.y;
        if (isPointInsidePolygon(polygon, p))
            cout << "The point is inside the polygon.\n";
        else
            cout << "The point is NOT inside the polygon.\n";
    } else if (queryType == 2) {
        Point p, q;
        cout << "Enter the coordinates of the first endpoint of the line (x y): ";
        cin >> p.x >> p.y;
        cout << "Enter the coordinates of the second endpoint of the line (x y): ";
        cin >> q.x >> q.y;
        if (isLineInsidePolygon(polygon, p, q))
            cout << "The line segment is completely inside the polygon.\n";
        else
            cout << "The line segment is NOT completely inside the polygon.\n";
    } else {
        cout << "Invalid query type entered.\n";
    }

    return 0;
}
