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

// Check if point is inside the polygon (Ray-casting method)
bool isInsidePolygon(vector<Point> &polygon, Point p) {
    int count = 0;
    Point outside = {10000, p.y}; // A point far outside the polygon
    Line ray = {p, outside};

    for (size_t i = 0; i < polygon.size(); i++) {
        Line edge = {polygon[i], polygon[(i + 1) % polygon.size()]};
        if (doIntersect(ray, edge)) count++;
    }
    return count & 1; // Using bitwise AND instead of division for modulus check
}

// Determine the intersection type
string checkIntersection(vector<Point> &pentagon, Line l) {
    Point mid = {l.p1.x + l.p2.x, l.p1.y + l.p2.y}; // No division for midpoint calculation
    bool inside = isInsidePolygon(pentagon, mid);
    bool onSide = false;
    
    for (size_t i = 0; i < pentagon.size(); i++) {
        Line edge = {pentagon[i], pentagon[(i + 1) % pentagon.size()]};
        if (doIntersect(l, edge)) {
            onSide = true;
            break;
        }
    }
    
    if (onSide) return "On a side of the polygon";
    return inside ? "Inside the polygon" : "Outside the polygon";
}

int main() {
    vector<Point> pentagon = {{0, 0}, {4, 0}, {5, 3}, {2, 5}, {-1, 3}};
    Line line1 = {{1, 1}, {3, 3}};
    Line line2 = {{-2, 2}, {6, 2}};
    
    cout << "Line 1: " << checkIntersection(pentagon, line1) << endl;
    cout << "Line 2: " << checkIntersection(pentagon, line2) << endl;
    
    return 0;
}
