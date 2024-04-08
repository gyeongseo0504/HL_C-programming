#include <iostream>
#include <windows.h>
using namespace std;
class Circle 
{
public:
	void init(int xval, int yval, int r);
	void draw();
	void move();
private:
	int x, y, radius;
};
void Circle::init(int xval, int yval, int r) 
{
	x = xval;
	y = yval;
	radius = r;
}
void Circle::draw() 
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}
void Circle::move() 
{
	x += rand() % 50;
}
int main()
{
	Circle c1;
	Circle c2;
	c1.init(100, 100, 50);
	c2.init(100, 200, 40);
	for (int i = 0; i < 20; i++) 
	{
		c1.move();
		c1.draw();
		c2.move();
		c2.draw();
		Sleep(1000);
	}
	return 0;
}