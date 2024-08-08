#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Sender(void);			//���ڸ� �Է¹ް� ���ǿ� �°� ���ڿ� �������� ���� �߰��� �� ���ڿ��� ���, Transmission_Process�� ����
void Transmission_Process(const char*);		//���޹��� ���ڿ��� Ȯ���� ���� ��ȯ �� Receiver�� ����
void Receiver(const char*);			//���޹��� ���� ������ ���� ���� ���ڿ��� ���ߴ��� Ȯ�� �� ���


int main(void)
{
	srand((unsigned)time(NULL));

	Sender();

	return 0;
}

//���ڸ� �Է¹ް� ���ǿ� �°� ���ڿ� �������� ���� �߰��� �� ���ڿ��� ���, Transmission_Process�� ����
void Sender(void)
{
	char num[5], snum[6];
	int intnum;
	int sum;

	cout << "Data :";
	cin >> num;

	intnum = atoi(num);

	// ���ڿ� ���� �� �ڸ����� �հ��� �߰�
	sum = (intnum / 1000 + (intnum / 100 - intnum / 1000 * 10) + (intnum / 10 - intnum / 100 * 10) + (intnum - intnum / 10 * 10)) % 10;
	intnum = intnum * 10 + sum;
	_itoa_s(intnum, snum, sizeof(snum), 10);

	cout << "Send Data:" << snum << endl;

	Transmission_Process(snum);

	return;
}

//���޹��� ���ڿ��� Ȯ���� ���� ��ȯ �� Receiver�� ����
void Transmission_Process(const char* pnum)
{
	int prob = rand() % 5;
	int change = rand() % 10;
	if (prob < 2)			//40% Ȯ���� ����
	{
		int prob2 = rand() % 5;			//5�ڸ��� �� �� ������ ���� �ߺ����� �ʴ� ���� �ٲ�
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
		Receiver(pnum);		//60% Ȯ���� �״�� ����


	return;
}

//���޹��� ���� ������ ���� ���� ���ڿ��� ���ߴ��� Ȯ�� �� ���
void Receiver(const char* pnum)
{
	cout << "Received Data:" << pnum << endl;

	//���ڿ��� ������ �ڸ��� ���ڿ� ������ ������ �� ��
	int int_tnum = atoi(pnum);
	int tsum = (int_tnum / 10000 + (int_tnum / 1000 - int_tnum / 10000 * 10) + (int_tnum / 100 - int_tnum / 1000 * 10) + (int_tnum / 10 - int_tnum / 100 * 10)) % 10;
	int psum = int_tnum - int_tnum / 10 * 10;

	if (psum == tsum)
		cout << psum << "==" << tsum << "\t Error is not Occured!" << endl;
	else
		cout << psum << "!=" << tsum << "\t Error!" << endl;

	return;
}
