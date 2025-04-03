bool isParallel(Point p1, Point q1, Point p2, Point q2) {
    return ((q1.y - p1.y) * (q2.x - p2.x)) == ((q2.y - p2.y) * (q1.x - p1.x));
}

bool isPerpendicular(Point p1, Point q1, Point p2, Point q2) {
    return ((q1.x - p1.x) * (q2.x - p2.x) + (q1.y - p1.y) * (q2.y - p2.y)) == 0;
}
