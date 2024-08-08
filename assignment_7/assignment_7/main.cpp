#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool PareCheck(const char*, int&, int&);		//괄호 확인 함수
bool FormulCheck(const char*, const int, const int);		//식 확인 함수

int main(void)
{
	char str[1024];			//입력받을 문자열
	char copy[1024];		//식을 확인하는데 쓰일 문자열

	cout << "fomula:";
	cin >> str;

	strcpy_s(copy, str);


	while (true)
	{
		int start = -1;			//가장 마지막의 위치한 괄호의 위치
		int end = -1;		//start 이후의 위치한 괄호 중 가장 처음 위치한 괄호의 위치

		if (PareCheck(copy, start, end) == 0)		//start값과 end값을 확인하고 괄호가 정상적으로 되어있지 않을 시 faulty 출력 후 종료
		{
			cout << "faulty" << endl;
			return 0;
		}

		if (FormulCheck(copy, start, end) == 0)		// 식이 주어진 조건에 맞게 되어있지 않을 시 faulty 출력 후 종료
		{
			cout << "faulty" << endl;
			return 0;
		}

		if (start == -1)		//괄호가 없을 경우 integrity 출력 후 종료
		{
			cout << "integrity" << endl;
			return 0;
		}

		//확인했던 괄호 부분을 x로 치환 후 다시 식을 검사
		char strn[100] = "x";
		int i;
		for (i = 1; copy[end + i] != '\0'; i++)
			strn[i] = copy[end + i];
		strn[i] = '\0';
		copy[start] = '\0';
		strcat_s(copy, strn);

		cout << copy << endl;
	}
}


// 가장 안쪽 괄호의 위치와 정상적으로 괄호가 되어있는지 확인하는 함수
bool PareCheck(const char* str, int& start, int& end)
{
	for (int i = 0; str[i] != '\0'; i++)			// '('의 마지막 위치 확인
	{
		if (str[i] == '(')
			start = i;
	}

	if (start == -1)				// '(' 가 없을 경우 ')'가 있으면 faulty 출력
	{
		int i;
		for (i = 0; str[i] != '\0'; i++)
			if (str[i] == ')')
				return 0;
		end = i;					// 괄호가 모두 없을 경우 end 값을 '\0' 위치로 지정

	}
	else						// '('가 있을 경우
	{
		for (int i = start + 1; str[i] != '\0'; i++)		// ')'의 첫번째 위치 확인
			if (str[i] == ')')
			{
				end = i;
				break;
			}
		if (end == -1)			// '('가  있을 경우 ')'가 없으면 faulty 출력
			return 0;
	}

	return 1;
}

//가장 안쪽 식이 정상적으로 이루어져있는지 확인하는 함수
bool FormulCheck(const char* str, const int start, const int end)
{
	if (end - start == 1)		//만약 괄호 안에 아무것도 없을 경우 faulty 출력
		return 0;
	for (int i = start + 1; i < end; i++)
	{
		if ((str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != 'x') && (str[i] < '0' || str[i] > '9'))		//숫자, x, 연산자 이외는 faulty 출력
		{
			return 0;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')		//연산자를 입력받을 경우 좌 우에 수나 문자가 없으면 오류 출력
		{
			if (i - 1 == start || i + 1 == end)
				return 0;
			else if (!(str[i - 1] <= '9' && str[i - 1] >= '0') && str[i - 1] != 'x')
				return 0;
			else if (!(str[i + 1] <= '9' && str[i + 1] >= '0') && str[i + 1] != 'x')
				return 0;
		}
		else if (str[i] == 'x')		//x를 입력받을 경우 좌 우에 수가 있을 경우 오류 출력
		{
			if ((str[i - 1] <= '9' && str[i - 1] >= '0') || str[i - 1] == 'x')
				return 0;
			else if ((str[i + 1] <= '9' && str[i + 1] >= '0') || str[i + 1] == 'x')
				return 0;
		}
	}
	return 1;
}