#include <iostream>
#include <windows.h>
#define MAX_SIZE 5
using namespace std;

void Printarr(char(*)[MAX_SIZE]);		//arr ��� �Լ�
bool Checkarr(char(*)[MAX_SIZE], int, int);		//���� ��ġ �ֺ��� �� �� �� �ִ� ���� �ִ��� Ȯ���ϴ� �Լ�
void Left(char(*)[MAX_SIZE], int&, int&);		//�·� �̵��ϴ� �Լ�
void Right(char(*)[MAX_SIZE], int&, int&);		//��� �̵��ϴ� �Լ�
void Up(char(*)[MAX_SIZE], int&, int&);			//���� �̵��ϴ� �Լ�
void Down(char(*)[MAX_SIZE], int&, int&);		//�Ʒ��� �̵��ϴ� �Լ�


int main(void)
{
	//5*5�������� 2���� arr ���� �� �ʱ�ȭ
	char arr[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			arr[i][j] = '0';
	}
	arr[0][0] = 'a';

	char cmd;		//�Է¹��� ������ ������ ����

	int x = 0, y = 0;
	while (true)
	{
		Printarr(arr);

		cout << "Command : ";

		if (Checkarr(arr, x, y) == 0)		//���� �̵��� ���� ���� ��� END ��� �� ����
		{
			cout << "END" << endl;
			return 0;
		}
		cin >> cmd;


		if (cmd == 'w')		//w�� �Է¹��� �� ���ʿ� a�� ���� ù��° ���� �ƴ� ��� �̵�
		{
			if (x != 0 && arr[x - 1][y] != 'a')
				Up(arr, x, y);

		}
		else if (cmd == 'a')		//a�� �Է¹��� �� ���ʿ� a�� ���� ù��° ���� �ƴ� ��� �̵�
		{
			if (y != 0 && arr[x][y - 1] != 'a')
				Left(arr, x, y);
		}
		else if (cmd == 's')		//s�� �Է¹��� �� �Ʒ��ʿ� a�� ���� ������ ���� �ƴ� ��� �̵�
		{
			if (arr[x + 1][y] != 'a' && x != MAX_SIZE - 1)
				Down(arr, x, y);
		}
		else if (cmd == 'd')		//d�� �Է¹��� �� �����ʿ� a�� ���� ������ ���� �ƴ� ��� �̵�
		{
			if (arr[x][y + 1] != 'a' && y != MAX_SIZE - 1)
				Right(arr, x, y);
		}

		system("cls");
	}
}

//�迭 ��� �Լ�
void Printarr(char(*parr)[MAX_SIZE])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << parr[i][j];
		}
		cout << "\n";
	}
	cout << endl;

	return;
}

//�̵��� �������� Ȯ���ϴ� �Լ�
bool Checkarr(char(*parr)[MAX_SIZE], int x, int y)
{
	bool can_go = 0;

	if (parr[x - 1][y] != 'a' && x != 0)		//���� �� �� ���� ��
		can_go = true;
	else if (parr[x + 1][y] != 'a' && x != MAX_SIZE)		//�Ʒ��� �� �� ���� ��
		can_go = true;
	else if (parr[x][y - 1] != 'a' && y != 0)		//�·� �� �� ���� ��
		can_go = true;
	else if (parr[x][y + 1] != 'a' && y != MAX_SIZE)		// ��� �� �� ���� ��
		can_go = true;

	return can_go;
}

//��ǥ ���� �̵� �� ���� �迭 ���� a�� �ٲٴ� �Լ�
void Left(char(*parr)[MAX_SIZE], int& x, int& y)
{
	y--;
	parr[x][y] = 'a';
	return;
}

//��ǥ ���� �̵� �� ������ �迭 ���� a�� �ٲٴ� �Լ�
void Right(char(*parr)[MAX_SIZE], int& x, int& y)
{
	y++;
	parr[x][y] = 'a';
	return;
}

//��ǥ ���� �̵� �� ���� �迭 ���� a�� �ٲٴ� �Լ�
void Up(char(*parr)[MAX_SIZE], int& x, int& y)
{
	x--;
	parr[x][y] = 'a';
	return;
}

//��ǥ �Ʒ��� �̵� �� �Ʒ��� �迭 ���� a�� �ٲٴ� �Լ�
void Down(char(*parr)[MAX_SIZE], int& x, int& y)
{
	x++;
	parr[x][y] = 'a';
	return;
}
