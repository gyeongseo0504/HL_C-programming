#include <iostream>
#include <string>
using namespace std;
class Car {
private:
	int speed; //�ӵ�
	int gear; //���
	string color; //����
public:
	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string c);
	void speedUp();
	void speedDown();
	void init(int s, int gear, string c);
	void show();
};
int Car::getSpeed() {
	return speed;
}
void Car::setSpeed(int s) {
	speed = s;
}
int Car::getGear() {
	return gear;
}
void Car::setGear(int g) {
	gear = g;
}
string Car::getColor() {
	return color;
}
void Car::setColor(string c) {
	color = c;
}
void Car::speedUp() { // �ӵ���������Լ�
	speed += 10;
}
void Car::speedDown() { // �ӵ����Ҹ���Լ�
	speed -= 10;
}
void Car::init(int s, int g, string c)
{
	speed = s;
	gear = g;
	color = c;
}
void Car::show() {
	cout << "============== " << endl;
	cout << "�ӵ�: " << speed << endl;
	cout << "���: " << gear << endl;
	cout << "����: " << color << endl;
	cout << "============== " << endl;
}
int main()
{
	Car car1, car2;
	car1.init(rand() % 200, 1, "red");
	car1.show();
	car2.init(rand() % 200, 1, "red");
	car2.show();
	if (car1.getSpeed() > car2.getSpeed())
		cout << "car1�� �¸��Ͽ����ϴ�" << endl;
	else
		cout << "car2�� �¸��Ͽ����ϴ�" << endl;
	return 0;
}