#include "calculator.h"

int main(void) {
	Calculator c;
	double X, Y;
	char operation;

	cout << "���⸦ �����ÿ� ��) X + Y : " << endl;
	cin >> X >> operation >> Y;
	double result = c.calculator(X, operation, Y);

	while (1) 
	{
		cout << "��� : " << result << endl;
		cout << "C�� �Է��ϸ� �ʱ�ȭ" << endl;
		cout << "Q�� �Է��ϸ� ����" << endl;
		cin >> operation >> Y;
		X = result;
		if (operation == 'C') 
		{
			cout << "���⸦ �����ÿ� ��) X + Y : " << endl;
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