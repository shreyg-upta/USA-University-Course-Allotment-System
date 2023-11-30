#include <iostream>
#include <map>

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}

    // Overloading equality operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Overloading less than operator
    bool operator<(const Point& other) const {
        // Compare based on the Euclidean distance from the origin (0, 0)
        double distance_self = sqrt(x * x + y * y);
        double distance_other = sqrt(other.x * other.x + other.y * other.y);
        return distance_self < distance_other;
    }

public:
    int x;
    int y;
};

int main() {
    std::map<Point, std::string> pointMap;

    Point point1(1, 2);
    Point point2(3, 4);
    Point point3(1, 2);

    pointMap[point1] = "Point 1";
    pointMap[point2] = "Point 2";
    pointMap[point3] = "Point 3";  // This will overwrite the entry for point1 because point1 == point3

    // Display the map
    for (const auto& pair : pointMap) {
        std::cout << "Key: (" << pair.first.x << ", " << pair.first.y << "), Value: " << pair.second << std::endl;
    }

    return 0;
}