#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void)
{
	char str1[1024], str2[1024];
	char* pstr1 = str1;			//�Է¹��� ���ڿ�
	char* pstr2 = str2;			// ��ȯ�Ͽ� ����� ���ڿ�

	cin.getline(str1, sizeof(str1));		//���鵵 �Է¹���

	char temp = str1[0];
	int count = 1;

	while (*pstr1 != '\0')
	{
		pstr1++;
		if (temp == (*pstr1))		//���� ���� ���ڶ� ���� ���ڰ� ���� ��� ���ڸ� 1 ī��Ʈ�Ѵ�.
		{
			count++;
		}
		else				// �ƴ� ��쿡�� ī��Ʈ�� 1�̸� �״�� pstr2�� ���ڸ� ������ �ƴ� ���� pstr2�� ���ڿ� ī��Ʈ�� �� �� ������.
		{
			*pstr2 = temp;
			pstr2++;
			temp = *pstr1;
			if (count != 1)
			{
				_itoa_s(count, pstr2, sizeof(pstr2), 10);
				pstr2 = str2 + strlen(str2);
				count = 1;
			}
		}
	}
	*pstr2 = '\0';

	cout << str2 << endl;

	return 0;
}