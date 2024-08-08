#include <iostream>
#include <windows.h>
using namespace std;

void Getnum(int&);				//�Է� �Լ�
long long int Fibo(int);		//�Ǻ���ġ ���� �Լ�

int main(void)
{
	int num = -1;

	while (num == -1)			//1~50 ������ ���� �Է¹���
	{
		system("cls");
		Getnum(num);
	}

	cout << Fibo(num) << endl;	//�Ǻ���ġ ���� �Լ��� ���� �����

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

long long int Fibo(int num)		//�Ǻ���ġ ���� �Լ�(50��° ������ �Լ����� int �������� ������� long long int������ �� ���)
{
	if (num == 1 || num == 2)	//�Է°��� 1�Ǵ� 2�� ��� 1 ��� 
		return 1;

	long long int result;	//Fn
	long long int n1 = 1;		//Fn-1(F1�� ���� 1������ 1�� �ʱ�ȭ)
	long long int n2 = 1;		//Fn-2(F2�� ���� 1������ 1�� �ʱ�ȭ)

	for (int i = 3; i <= num; i++)		//�Ǻ���ġ ���� ���
	{
		result = n1 + n2;

		n2 = n1;
		n1 = result;
	}

	return result;			//����� ���
}