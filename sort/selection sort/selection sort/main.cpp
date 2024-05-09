#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int a[10] = { 3,6,7,1,4,2,9,0,5,8 };

int main()
{
	for (int i = 0; i < 10; i++)
	{
		int min = a[i];
		int location = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				location = j;
			}
		}
		swap(a[i], a[location]);
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
}