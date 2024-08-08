#include <iostream>
#include <windows.h>
using namespace std;

void Getnum(int&);				//입력 함수
long long int Fibo(int);		//피보나치 수열 함수

int main(void)
{
	int num = -1;

	while (num == -1)			//1~50 사이의 값을 입력받음
	{
		system("cls");
		Getnum(num);
	}

	cout << Fibo(num) << endl;	//피보나치 수열 함수의 값을 출력함

	return 0;
}

void Getnum(int& rnum)
{
	cout << "Number:";
	cin >> rnum;

	if (rnum > 0 && rnum < 51)
		return;
	else
	{
		rnum = -1;
		return;
	}
}

long long int Fibo(int num)		//피보나치 수열 함수(50번째 수열의 함수값이 int 범위에서 벗어남으로 long long int형으로 값 출력)
{
	if (num == 1 || num == 2)	//입력값이 1또는 2일 경우 1 출력 
		return 1;

	long long int result;	//Fn
	long long int n1 = 1;		//Fn-1(F1의 값이 1임으로 1로 초기화)
	long long int n2 = 1;		//Fn-2(F2의 값이 1임으로 1로 초기화)

	for (int i = 3; i <= num; i++)		//피보나치 수열 계산
	{
		result = n1 + n2;

		n2 = n1;
		n1 = result;
	}

	return result;			//결과값 출력
}