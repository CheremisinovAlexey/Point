#include <iostream>
#include <math.h>
#include <clocale>
#include <Windows.h>

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
    double operator^(Point);
    double operator&(Point);
    double operator|(Point);
    bool operator==(Point);
    bool operator!=(Point);
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

double Point::operator^(Point)
{
    return double(sqrt((x * x) + (y * y)));
}

double Point::operator&(Point a)
{
    int g, h;
    if ((x * a.y) < 0)
    {
        g = -x * a.y;
    }
    else
    {
        g = x * a.y;
    }
    if ((y * a.x) < 0)
    {
        h = -y * a.x;
    }
    else
    {
        h = y * a.x;
    }
    return int(g + h);
}

//double Point::operator|(Point a)
//{
//return double();
//}

bool Point::operator==(Point a)
{
    return bool(x == a.x & y == a.y);
}

bool Point::operator!=(Point a)
{
    return bool(x != a.x & y != a.y);
}

ostream& operator<<(ostream& out, const Point& a)
{
    return out << a.x << "; " << a.y;
}


int main() {
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
    int x, y, x1, y1, k;
    double c;
    cout<<"Введите координаты первого вектора: "<<endl;
    cin>>x>>y;
    cout<<"Введите координаты второго вектора: "<<endl;
    cin>>x1>>y1;
    Point d(x, y);
    Point f(x1, y1);
    cout<<"Какую операцию произвести?"<<endl;
    cout<<"1. Сложить два вектора"<<endl;
    cout<<"2. Вычесть из первого вектора второй"<<endl;
    cout<<"3. Умножить оба вектора на число"<<endl;
    cout<<"4. Скалярное произведение двух векторов"<<endl;
    cout<<"5. Косое произведение двух векторов"<<endl;
    cout<<"6. Вычислить длины векторов"<<endl;
    cout<<"7. <Пока в разработке> Вычисление угла между векторами"<<endl;
    cout<<"8. Сравнить два вектора"<<endl;
    int r;
    cin>>r;
    if(r == 1)
    {
        cout<<d + f<<endl;
    }
    else if(r == 2)
    {
        cout<<d - f<<endl;
    }
    else if(r == 3)
    {
        cout<<"Введите число, на которое хотите умножить"<<endl;
        int l;
        cin >> l;
        cout<<d * l<<' '<< f * l<<endl;
    }
    else if(r == 4)
    {
        cout<<d * f<<endl;
    }
    else if(r == 5)
    {
        int k = d & f;
        cout<<k<<endl;
    }
    else if(r == 6)
    {
        int v = d^d;
        int q = f^f;
        cout<< v <<' '<< q <<endl;
    }
    else if(r == 7)
    {
        cout<<"Простите, эта функция еще не доступна"<<endl;
    }
    else if(r == 8)
    {
        if (d == f)
        {
            cout<<"Вектора равны"<<endl;
        }
        else
        {
            cout<<"Вектора не равны"<<endl;
        }
    }
    else
    {
        cout<<"Пожалуйста, введите цифру от 1 до 8"<<endl;
    }
}