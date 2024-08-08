#include <iostream>
using namespace std;

void Getnum(int&, int, int);				//�Է¹޴� �Լ�
int Makearr(int**&, int);			//arr ���� �Լ�
void Deletearr(int**&, int);		//arr ��ȯ �Լ�
void Printarr(int**, int);			//arr ��� �Լ�

class _Movearr
{
public:
	int dir = -1;		//�Է¹��� ������ ������ ����

	//���� �ջ� �Լ�
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

	//�Ʒ��� �ջ� �Լ�
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

	//�������� �ջ� �Լ�
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

	//�������� �ջ� �Լ�
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

	//���� �ϴ����� �ջ� �Լ�
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

	//���� ������� �ջ� �Լ�
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
	int size = -1;		//������ ����

	while (size == -1)		//1~9 ������ �������  �Է¹���		
	{
		cout << "Array Size(0<N<10):";
		Getnum(size, 0, 10);
	}

	int** arr;

	if (Makearr(arr, size) == -1)		//�����ŭ 2���� �迭 ����
	{
		cout << "�޸� �Ҵ� ����" << endl;
		return -1;
	}

	_Movearr Movearr;

	Printarr(arr, size);

	if (size == 1)		// ũ�Ⱑ 1�� �� ����
		return 0;

	while (Movearr.dir == -1)		//1~6 ������ ���Ⱚ�� �Է¹���
	{
		cout << "Shift All Direction:";
		Getnum(Movearr.dir, -1, 6);
	}


	switch (Movearr.dir)		// �Է¹��� ���⿡ ���� �Լ� ����
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

//������ ������ŭ�� ���� �Է¹޴� �Լ�
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

//2���� �迭 ���� �Ҵ� �� 1 �ʱ�ȭ �Լ�
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

//2���� �迭 ��� �Լ�
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