#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))						//A~Z, a~z 사이의 값만 출력
		{
			if (str[i] >= 65 && str[i] <= 90)
				cout << (char)(str[i] + 32);		//대문자일 경우 소문자로 전환
			else
				cout << (char)str[i];		// 소문자일 경우 그대로 출력
		}
	}

	return 0;
}