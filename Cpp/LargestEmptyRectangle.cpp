#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point { 
    int x, y; 
};

struct Rectangle {
    int x1, y1, x2, y2;
    int area() const { return (x2 - x1) * (y2 - y1); }
};

bool isEmpty(const Rectangle &rect, const vector<Point> &points) {
    for (auto &p : points) {
        // Check if p is strictly inside the rectangle.
        if (p.x > rect.x1 && p.x < rect.x2 && p.y > rect.y1 && p.y < rect.y2)
            return false;
    }
    return true;
}

int main(){
    // Example points and bounding box.
    vector<Point> points = {{3,3}, {5,5}, {7,2}};
    int minX = 0, maxX = 10, minY = 0, maxY = 10;
    
    // Collect candidate x and y coordinates.
    vector<int> xs = {minX, maxX}, ys = {minY, maxY};
    for (auto &p : points) {
        xs.push_back(p.x);
        ys.push_back(p.y);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    Rectangle best = {minX, minY, minX, minY};
    // Try every candidate rectangle.
    for (int i = 0; i < xs.size(); i++){
        for (int j = i+1; j < xs.size(); j++){
            for (int k = 0; k < ys.size(); k++){
                for (int l = k+1; l < ys.size(); l++){
                    Rectangle rect = {xs[i], ys[k], xs[j], ys[l]};
                    if(isEmpty(rect, points)){
                        if(rect.area() > best.area()){
                            best = rect;
                        }
                    }
                }
            }
        }
    }
    
    cout << "Largest Empty Rectangle: (" << best.x1 << "," << best.y1 << ") to ("
         << best.x2 << "," << best.y2 << ") with area " << best.area() << "\n";
    return 0;
}
