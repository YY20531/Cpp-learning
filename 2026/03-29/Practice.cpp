#include <iostream> 

using namespace std; 
 
class Point
{
private:
    int x, y;
public:
    Point(int a, int b): x(a), y(b){};
    
    friend ostream& operator<<(ostream &os, const Point &a);
    friend Point operator+(Point &a, Point &other);
    int get_x(){return x;}
    int get_y(){return y;}
};

ostream& operator<<(ostream &os, const Point &a)
{
    os << "(" << a.x << ", " << a.y << ")";
    return os;
}

Point operator+(Point & a, Point &other)
{
    return Point(a.x + other.get_x(), a.y + other.get_y());
}
int main() 
{ 
    Point a(1, 2);
    Point b(3, 4);
    
    cout << a + b << endl;
    return 0;
}
