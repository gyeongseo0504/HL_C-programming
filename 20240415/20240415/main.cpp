#include "calculator.h"

int main(void) {
	Calculator c;
	double X, Y;
	char operation;

	cout << "계산기를 적으시오 예) X + Y : " << endl;
	cin >> X >> operation >> Y;
	double result = c.calculator(X, operation, Y);

	while (1) 
	{
		cout << "결과 : " << result << endl;
		cout << "C를 입력하면 초기화" << endl;
		cout << "Q를 입력하면 종료" << endl;
		cin >> operation >> Y;
		X = result;
		if (operation == 'C') 
		{
			cout << "계산기를 적으시오 예) X + Y : " << endl;
			cin >> X >> operation >> Y;
			result = c.calculator(X, operation, Y);
		}
		else if (operation == 'Q') 
		{
			return 0;
		}
		else {
			result = c.calculator(X, operation, Y);
		}

	}
	return 0;
}