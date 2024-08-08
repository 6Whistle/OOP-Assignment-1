#include <iostream>
#include <windows.h>
#define MAX_SIZE 5
using namespace std;

void Printarr(char(*)[MAX_SIZE]);		//arr 출력 함수
bool Checkarr(char(*)[MAX_SIZE], int, int);		//현재 위치 주변에 더 갈 수 있는 곳이 있는지 확인하는 함수
void Left(char(*)[MAX_SIZE], int&, int&);		//좌로 이동하는 함수
void Right(char(*)[MAX_SIZE], int&, int&);		//우로 이동하는 함수
void Up(char(*)[MAX_SIZE], int&, int&);			//위로 이동하는 함수
void Down(char(*)[MAX_SIZE], int&, int&);		//아래로 이동하는 함수


int main(void)
{
	//5*5사이즈의 2차원 arr 생성 및 초기화
	char arr[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			arr[i][j] = '0';
	}
	arr[0][0] = 'a';

	char cmd;		//입력받을 방향을 저장할 변수

	int x = 0, y = 0;
	while (true)
	{
		Printarr(arr);

		cout << "Command : ";

		if (Checkarr(arr, x, y) == 0)		//만약 이동할 곳이 없을 경우 END 출력 후 종료
		{
			cout << "END" << endl;
			return 0;
		}
		cin >> cmd;


		if (cmd == 'w')		//w를 입력받을 시 위쪽에 a가 없고 첫번째 행이 아닐 경우 이동
		{
			if (x != 0 && arr[x - 1][y] != 'a')
				Up(arr, x, y);

		}
		else if (cmd == 'a')		//a를 입력받을 시 왼쪽에 a가 없고 첫번째 열이 아닐 경우 이동
		{
			if (y != 0 && arr[x][y - 1] != 'a')
				Left(arr, x, y);
		}
		else if (cmd == 's')		//s를 입력받을 시 아래쪽에 a가 없고 마지막 행이 아닐 경우 이동
		{
			if (arr[x + 1][y] != 'a' && x != MAX_SIZE - 1)
				Down(arr, x, y);
		}
		else if (cmd == 'd')		//d를 입력받을 시 오른쪽에 a가 없고 마지막 열이 아닐 경우 이동
		{
			if (arr[x][y + 1] != 'a' && y != MAX_SIZE - 1)
				Right(arr, x, y);
		}

		system("cls");
	}
}

//배열 출력 함수
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

//이동이 가능한지 확인하는 함수
bool Checkarr(char(*parr)[MAX_SIZE], int x, int y)
{
	bool can_go = 0;

	if (parr[x - 1][y] != 'a' && x != 0)		//위로 갈 수 있을 때
		can_go = true;
	else if (parr[x + 1][y] != 'a' && x != MAX_SIZE)		//아래로 갈 수 있을 때
		can_go = true;
	else if (parr[x][y - 1] != 'a' && y != 0)		//좌로 갈 수 있을 때
		can_go = true;
	else if (parr[x][y + 1] != 'a' && y != MAX_SIZE)		// 우로 갈 수 있을 때
		can_go = true;

	return can_go;
}

//좌표 좌측 이동 후 왼쪽 배열 값을 a로 바꾸는 함수
void Left(char(*parr)[MAX_SIZE], int& x, int& y)
{
	y--;
	parr[x][y] = 'a';
	return;
}

//좌표 우측 이동 후 오른쪽 배열 값을 a로 바꾸는 함수
void Right(char(*parr)[MAX_SIZE], int& x, int& y)
{
	y++;
	parr[x][y] = 'a';
	return;
}

//좌표 위로 이동 후 위쪽 배열 값을 a로 바꾸는 함수
void Up(char(*parr)[MAX_SIZE], int& x, int& y)
{
	x--;
	parr[x][y] = 'a';
	return;
}

//좌표 아래로 이동 후 아래쪽 배열 값을 a로 바꾸는 함수
void Down(char(*parr)[MAX_SIZE], int& x, int& y)
{
	x++;
	parr[x][y] = 'a';
	return;
}
