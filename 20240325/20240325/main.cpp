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
		cout << "동일한 문자 입니다" << endl;
	else
		cout << "동일한 문자열이 아닙니다" << endl;
	if (s1 > s2)
		cout << "s1이 앞에 있습니다" << endl;
	else
		cout << "s2가 앞에 있습니다" << endl;

	string s1, addr;
	cout << "이름을 입력하시오 : ";
	cin >> s1;
	cin.ignore(); // 엔터키를 없애기 위하여 필요하다.
	cout << "주소를 입력하시오 : ";
	getline(cin, addr);
	cout << addr << "의 " << s1 << "씨 안녕하세요? " << endl;
	return 0;*/

	/*string s = "When in Rome, do as the Romans.";
	int index = s.find("Rome");
	cout << index << endl;
	return 0;*/
	string list[] = { "철수", "영희", "길동" };
	for (auto& x : list)
		cout << (x + "야 안녕!") << endl;
	return 0;

}
