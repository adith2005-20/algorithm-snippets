#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point { 
    double x, y; 
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)(a.x - b.x) + (a.y - b.y)(a.y - b.y));
}

double closestUtil(vector<Point>& pts, int l, int r) {
    if (r - l <= 3) {
        double min_d = numeric_limits<double>::infinity();
        for (int i = l; i < r; i++)
            for (int j = i+1; j < r; j++)
                min_d = min(min_d, dist(pts[i], pts[j]));
        return min_d;
    }
    int mid = (l + r) / 2;
    double d1 = closestUtil(pts, l, mid);
    double d2 = closestUtil(pts, mid, r);
    double d = min(d1, d2);
    
    vector<Point> strip;
    double midx = pts[mid].x;
    for (int i = l; i < r; i++){
        if (abs(pts[i].x - midx) < d) {
            strip.push_back(pts[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](Point a, Point b){ return a.y < b.y; });
    for (int i = 0; i < strip.size(); i++){
        for (int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++){
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

double closestPair(vector<Point>& pts) {
    sort(pts.begin(), pts.end(), [](Point a, Point b){ return a.x < b.x; });
    return closestUtil(pts, 0, pts.size());
}

int main(){
    vector<Point> pts = { {2.1, 3.2}, {12.0, 30.1}, {40.0, 50.0},
                          {5.0, 1.0}, {12.0, 10.3}, {3.0, 4.0} };
    cout << "The smallest distance is " << closestPair(pts) << "\n";
    return 0;
}
