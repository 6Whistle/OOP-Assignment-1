#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int Makearr(int**&, int);			//array ���� �Լ�
void Printarr(int**, int);			//array ��� �Լ�
void Sortarr(int**&, int);			//array ���� ���� �Լ�
void Change(int&, int&);			//2���� ���� ���� �ٲٴ� �Լ�
void Deletearr(int**&, int);		//array ��ȯ �Լ�

int main(void)
{
	srand((unsigned)time(NULL));

	int size;			//�Է¹��� ũ�⸦ ������ �Լ�
	bool state = 0;

	while (state == 0)			//1~10 ������ ���� �Է¹���
	{
		system("cls");
		cout << "Array Size(0<N<11) : ";
		cin >> size;
		if (size < 11 && size > 0)
			state = 1;
	}

	int** arr;

	if (Makearr(arr, size) == -1)		// size*size ũ���� 2���� array ���� �� 1~99 ������ �� �Ҵ�
	{
		cout << "�޸� �Ҵ� ����" << endl;
		return -1;
	}

	Printarr(arr, size);		//array ���

	int k = 0;
	int** parr = new int* [size * size];		//����� size^2�� 1���� ������ �迭 parr ���� �� �� ������ �ּҰ��� 2���� �迭 arr�� ����
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			parr[k] = &(arr[i][j]);
			k++;
		}
	}

	Sortarr(parr, size * size);			//1���� �迭 ��������

	Printarr(arr, size);

	return 0;

	Deletearr(arr, size);

}

// 2���� �迭 ���� �Լ�
int Makearr(int**& rarr, int num)
{
	rarr = new  int* [num];
	if (rarr == NULL)
	{
		return -1;
	}
	for (int i = 0; i < num; i++)
	{
		rarr[i] = new int[num];

		if (rarr + i == NULL)
		{
			return -1;
		}

		for (int j = 0; j < num; j++)
		{
			rarr[i][j] = rand() % 99 + 1;
		}
	}

	return 0;
}

//�迭 ��� �Լ�
void Printarr(int** parr, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << parr[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;

	return;
}

//�������� �Լ�
void Sortarr(int**& rarr, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		int temp = i;
		for (int j = i + 1; j < num; j++)
		{
			if (*(rarr[temp]) > *(rarr[j]))
				temp = j;
		}
		Change(*(rarr[i]), *(rarr[temp]));
	}
	return;
}

//�� ������ ���� �ٲٴ� �Լ�
void Change(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;

	return;
}

//�迭 ��ȯ �Լ�
void Deletearr(int**& rarr, int num)
{
	for (int i = 0; i < num; i++)
	{
		delete[] rarr[i];
	}
	delete[] rarr;

	return;
}