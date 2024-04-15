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
		else cout << "ÀçÀÔ·Â ¿ä¸Á(0À¸·Î ³ª´®)";
		break;
	default:
		cout << "ÀçÀÔ·Â ¿ä¸Á(»çÄ¢¿¬»êÀÌ ¾Æ´Ô)";
		break;
	}

}