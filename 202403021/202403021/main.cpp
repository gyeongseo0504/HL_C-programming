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
    cout << "연산 결과" << n << endl;
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
        cout << "오류: 0으로 나눌 수 없습니다만." << endl;
        return 0;
    }
    return x / y;
}

int main() 
{
    char jh;
    double num1, num2;

    cout << "연산할 두 수를 입력하세요: ";
    cin >> num1 >> num2;

    cout << "사용할 연산자를 입력하세요 (+, -, *, /): ";
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
        cout << "잘못된 연산자입니다." << endl;
        return 1; 
    }

    cout << "연산 결과 : " << result << endl;

    return 0;
}
