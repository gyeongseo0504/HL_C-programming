#include <iostream>
#include <string>
using namespace std;

int main()
{/*
	string s1 = "Slow", s2 = "steady";
	string s3 = "the race";
	string s4;

	s4 = s1 + "and" + s2 + "win" + s3;
	cout << s4 << endl;
	return 0;*/
	/*
	string s1 = "hello", s2 = "world";
	if (s1 == s2)
		cout << "������ ���� �Դϴ�" << endl;
	else
		cout << "������ ���ڿ��� �ƴմϴ�" << endl;
	if (s1 > s2)
		cout << "s1�� �տ� �ֽ��ϴ�" << endl;
	else
		cout << "s2�� �տ� �ֽ��ϴ�" << endl;

	string s1, addr;
	cout << "�̸��� �Է��Ͻÿ� : ";
	cin >> s1;
	cin.ignore(); // ����Ű�� ���ֱ� ���Ͽ� �ʿ��ϴ�.
	cout << "�ּҸ� �Է��Ͻÿ� : ";
	getline(cin, addr);
	cout << addr << "�� " << s1 << "�� �ȳ��ϼ���? " << endl;
	return 0;*/

	/*string s = "When in Rome, do as the Romans.";
	int index = s.find("Rome");
	cout << index << endl;
	return 0;*/
	string list[] = { "ö��", "����", "�浿" };
	for (auto& x : list)
		cout << (x + "�� �ȳ�!") << endl;
	return 0;

}
