/*#include <iostream>
using namespace std;

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int n;
    n = max(2, 3);
    cout << "���� ���" << n << endl;
    return 0;

}

*/


#include <iostream>
using namespace std;
int wprhq(int x, int y)
{
    return x ^ y;
}
int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    if (y == 0) 
    {
        cout << "����: 0���� ���� �� �����ϴٸ�." << endl;
        return 0;
    }
    return x / y;
}

int main() 
{
    char jh;
    double num1, num2;

    cout << "������ �� ���� �Է��ϼ���: ";
    cin >> num1 >> num2;

    cout << "����� �����ڸ� �Է��ϼ��� (+, -, *, /): ";
    cin >> jh;

    double result;

    
    switch (jh) 
    {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = subtract(num1, num2);
        break;
    case '*':
        result = multiply(num1, num2);
        break;
    case '/':
        result = divide(num1, num2);
        break;
    case'^':
        result = wprhq(num1, num2);
        break;
    default:
        cout << "�߸��� �������Դϴ�." << endl;
        return 1; 
    }

    cout << "���� ��� : " << result << endl;

    return 0;
}
