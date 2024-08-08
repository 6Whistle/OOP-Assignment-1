#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int Makearr(int**&, int);			//array 생성 함수
void Printarr(int**, int);			//array 출력 함수
void Sortarr(int**&, int);			//array 순차 정렬 함수
void Change(int&, int&);			//2개의 값을 서로 바꾸는 함수
void Deletearr(int**&, int);		//array 반환 함수

int main(void)
{
	srand((unsigned)time(NULL));

	int size;			//입력받을 크기를 저장할 함수
	bool state = 0;

	while (state == 0)			//1~10 까지의 수만 입력받음
	{
		system("cls");
		cout << "Array Size(0<N<11) : ";
		cin >> size;
		if (size < 11 && size > 0)
			state = 1;
	}

	int** arr;

	if (Makearr(arr, size) == -1)		// size*size 크기의 2차원 array 생성 후 1~99 사이의 값 할당
	{
		cout << "메모리 할당 실패" << endl;
		return -1;
	}

	Printarr(arr, size);		//array 출력

	int k = 0;
	int** parr = new int* [size * size];		//사이즈가 size^2인 1차원 포인터 배열 parr 생성 후 각 인자의 주소값을 2차원 배열 arr에 연결
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			parr[k] = &(arr[i][j]);
			k++;
		}
	}

	Sortarr(parr, size * size);			//1차원 배열 순차정렬

	Printarr(arr, size);

	return 0;

	Deletearr(arr, size);

}

// 2차원 배열 생성 함수
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

//배열 출력 함수
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

//순차정렬 함수
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

//두 변수의 값을 바꾸는 함수
void Change(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;

	return;
}

//배열 반환 함수
void Deletearr(int**& rarr, int num)
{
	for (int i = 0; i < num; i++)
	{
		delete[] rarr[i];
	}
	delete[] rarr;

	return;
}