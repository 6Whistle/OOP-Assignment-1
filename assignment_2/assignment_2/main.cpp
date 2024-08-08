#include <iostream>
using namespace std;

void Getnum(int&, int, int);				//입력받는 함수
int Makearr(int**&, int);			//arr 생성 함수
void Deletearr(int**&, int);		//arr 반환 함수
void Printarr(int**, int);			//arr 출력 함수

class _Movearr
{
public:
	int dir = -1;		//입력받을 방향을 저장할 변수

	//위로 합산 함수
	void Up(int**& rarr, int num)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (j != 0)
				{
					rarr[0][i] += rarr[j][i];
					rarr[j][i] = 0;
				}
			}
		}
		return;
	}

	//아래로 합산 함수
	void Down(int**& rarr, int num)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (j != num - 1)
				{
					rarr[num - 1][i] += rarr[j][i];
					rarr[j][i] = 0;
				}
			}
		}
		return;
	}

	//좌측으로 합산 함수
	void Left(int**& rarr, int num)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (j != 0)
				{
					rarr[i][0] += rarr[i][j];
					rarr[i][j] = 0;
				}
			}
		}
		return;
	}

	//우측으로 합산 함수
	void Right(int**& rarr, int num)
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = num - 1; j >= 0; j--)
			{
				if (j != num - 1)
				{
					rarr[i][num - 1] += rarr[i][j];
					rarr[i][j] = 0;
				}
			}
		}
		return;
	}

	//우측 하단으로 합산 함수
	void DownLeft(int**& rarr, int num)
	{
		for (int j = 0; j < num;)
		{
			int temp = j;
			for (int i = 0; i <= temp; i++, j--)
			{
				if (i != temp && j != 0)
				{
					rarr[temp][0] += rarr[i][j];
					rarr[i][j] = 0;
				}

			}
			j = temp + 1;
		}
		for (int i = 1; i < num;)
		{
			int  temp = i;
			for (int j = num - 1; j >= temp; i++, j--)
			{
				if (i != num - 1 && j != temp)
				{
					rarr[num - 1][temp] += rarr[i][j];
					rarr[i][j] = 0;
				}
			}
			i = temp + 1;
		}

		return;
	}

	//좌측 상단으로 합산 함수
	void UpRight(int**& rarr, int num)
	{
		for (int i = 0; i < num;)
		{
			int temp = i;
			for (int j = 0; j <= temp; i--, j++)
			{
				if (i != 0 && j != temp)
				{
					rarr[0][temp] += rarr[i][j];
					rarr[i][j] = 0;
				}

			}
			i = temp + 1;
		}
		for (int j = 1; j < num;)
		{
			int  temp = j;
			for (int i = num - 1; i >= temp; i--, j++)
			{
				if (i != temp && j != num - 1)
				{
					rarr[temp][num - 1] += rarr[i][j];
					rarr[i][j] = 0;
				}
			}
			j = temp + 1;
		}
		return;
	}

};

int main(void)
{
	int size = -1;		//사이즈 변수

	while (size == -1)		//1~9 사이의 사이즈값을  입력받음		
	{
		cout << "Array Size(0<N<10):";
		Getnum(size, 0, 10);
	}

	int** arr;

	if (Makearr(arr, size) == -1)		//사이즈만큼 2차원 배열 생성
	{
		cout << "메모리 할당 실패" << endl;
		return -1;
	}

	_Movearr Movearr;

	Printarr(arr, size);

	if (size == 1)		// 크기가 1일 시 종료
		return 0;

	while (Movearr.dir == -1)		//1~6 사이의 방향값을 입력받음
	{
		cout << "Shift All Direction:";
		Getnum(Movearr.dir, -1, 6);
	}


	switch (Movearr.dir)		// 입력받은 방향에 따라 함수 실행
	{
	case 0: Movearr.Up(arr, size);	break;
	case 1:	Movearr.Down(arr, size);	break;
	case 2: Movearr.Right(arr, size);	break;
	case 3:	Movearr.Left(arr, size);	break;
	case 4: Movearr.DownLeft(arr, size);	break;
	case 5: Movearr.UpRight(arr, size);	break;

	default: break;
	}

	Printarr(arr, size);

	Deletearr(arr, size);

	return 0;
}

//정해진 구간만큼의 수을 입력받는 함수
void Getnum(int& rnum, int min, int max)
{
	cin >> rnum;

	if (rnum > min && rnum < max)
		return;
	else
	{
		rnum = -1;
		return;
	}

}

//2차원 배열 동적 할당 및 1 초기화 함수
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
			rarr[i][j] = 1;
		}
	}


	return 0;
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

//2차원 배열 출력 함수
void Printarr(int** parr, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << parr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	return;
}