#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))						//A~Z, a~z ������ ���� ���
		{
			if (str[i] >= 65 && str[i] <= 90)
				cout << (char)(str[i] + 32);		//�빮���� ��� �ҹ��ڷ� ��ȯ
			else
				cout << (char)str[i];		// �ҹ����� ��� �״�� ���
		}
	}

	return 0;
}