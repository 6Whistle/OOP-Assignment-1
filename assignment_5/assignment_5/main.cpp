#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void)
{
	char str1[1024], str2[1024];
	char* pstr1 = str1;			//입력받은 문자열
	char* pstr2 = str2;			// 변환하여 출력할 문자열

	cin.getline(str1, sizeof(str1));		//공백도 입력받음

	char temp = str1[0];
	int count = 1;

	while (*pstr1 != '\0')
	{
		pstr1++;
		if (temp == (*pstr1))		//만약 현재 숫자랑 다음 숫자가 같을 경우 숫자를 1 카운트한다.
		{
			count++;
		}
		else				// 아닐 경우에는 카운트가 1이면 그대로 pstr2에 문자를 보내고 아닐 경우는 pstr2에 문자와 카운트를 둘 다 보낸다.
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