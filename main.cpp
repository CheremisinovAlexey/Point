#include <iostream>
using namespace std;

class Point
{
public:
    int y;
    int x;
    Point(int x, int y);
    Point();

    int get_x() { return x; }
    int get_y() { return y; }

    void set_x(int x1) { x = x1; }
    void set_y(int y1) { y = y1; }

    Point operator+(Point);
    Point operator-(Point);
    int operator*(Point);
    Point operator*(int);
};

Point::Point(int x1, int y1)
{
    x = x1;
    y = y1;
}

Point::Point()
{
    x = 0;
    y = 0;
}

Point Point::operator+(Point a)
{
    return Point(x + a.x, y + a.y);
}

Point Point::operator-(Point a)
{
    return Point(x - a.x, y - a.y);
}

Point Point::operator*(int a)
{
    return Point(x * a, y * a);
}

int Point::operator*(Point a)
{
    return int(x * a.y - y * a.x);
}

ostream& operator<<(ostream& out, const Point& a)
{
    return out << a.x << "; " << a.y;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    int x, y, x1, y1;
    cin>>x>>y>>x1>>y1;
    Point a(x, y);
    Point b(x1, y1);
    cout<<a * b<<endl;
    return 0;
}