#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Sender(void);			//숫자를 입력받고 조건에 맞게 문자열 마지막에 수를 추가한 후 문자열을 출력, Transmission_Process로 전달
void Transmission_Process(const char*);		//전달받은 문자열을 확률에 따라 변환 후 Receiver로 전달
void Receiver(const char*);			//전달받은 수의 마지막 값을 통해 문자열이 변했는지 확인 후 출력


int main(void)
{
	srand((unsigned)time(NULL));

	Sender();

	return 0;
}

//숫자를 입력받고 조건에 맞게 문자열 마지막에 수를 추가한 후 문자열을 출력, Transmission_Process로 전달
void Sender(void)
{
	char num[5], snum[6];
	int intnum;
	int sum;

	cout << "Data :";
	cin >> num;

	intnum = atoi(num);

	// 문자열 끝에 각 자리수의 합값을 추가
	sum = (intnum / 1000 + (intnum / 100 - intnum / 1000 * 10) + (intnum / 10 - intnum / 100 * 10) + (intnum - intnum / 10 * 10)) % 10;
	intnum = intnum * 10 + sum;
	_itoa_s(intnum, snum, sizeof(snum), 10);

	cout << "Send Data:" << snum << endl;

	Transmission_Process(snum);

	return;
}

//전달받은 문자열을 확률에 따라 변환 후 Receiver로 전달
void Transmission_Process(const char* pnum)
{
	int prob = rand() % 5;
	int change = rand() % 10;
	if (prob < 2)			//40% 확률로 동작
	{
		int prob2 = rand() % 5;			//5자리의 수 중 임의의 수를 중복되지 않는 수로 바꿈
		while (pnum[prob2] == (char)(change + 48))
		{
			change = rand() % 10;
		}
		char tnum[6];
		strcpy_s(tnum, pnum);
		tnum[prob] = (char)(change + 48);

		Receiver(tnum);
	}
	else
		Receiver(pnum);		//60% 확률로 그대로 전달


	return;
}

//전달받은 수의 마지막 값을 통해 문자열이 변했는지 확인 후 출력
void Receiver(const char* pnum)
{
	cout << "Received Data:" << pnum << endl;

	//문자열의 마지막 자리의 숫자와 나머지 숫자의 합 비교
	int int_tnum = atoi(pnum);
	int tsum = (int_tnum / 10000 + (int_tnum / 1000 - int_tnum / 10000 * 10) + (int_tnum / 100 - int_tnum / 1000 * 10) + (int_tnum / 10 - int_tnum / 100 * 10)) % 10;
	int psum = int_tnum - int_tnum / 10 * 10;

	if (psum == tsum)
		cout << psum << "==" << tsum << "\t Error is not Occured!" << endl;
	else
		cout << psum << "!=" << tsum << "\t Error!" << endl;

	return;
}
