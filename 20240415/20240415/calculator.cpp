#include "calculator.h"

double Calculator::calculator(double x, char oper, double y) {
	switch (oper) {
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case '*':
		return x * y;
		break;
	case '/':
		if (y != 0) return x / y;
		else cout << "���Է� ���(0���� ����)";
		break;
	default:
		cout << "���Է� ���(��Ģ������ �ƴ�)";
		break;
	}

}