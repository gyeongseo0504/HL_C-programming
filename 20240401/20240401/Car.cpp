#include <iostream>
#include <string>
#include "car.h"

using namespace std;

class Car {
    int speed;
    int gear;
    string color;
public:
    int getSpeed();
    void setSpeed(int a);
};

int Car::getSpeed() {
    return speed;
}

void Car::setSpeed(int s) {
    speed = s;
}

int main() {
    Car myCar;

    myCar.setSpeed(80);
    cout << "현재 속도는 " << myCar.getSpeed() << endl;

    return 0;
}