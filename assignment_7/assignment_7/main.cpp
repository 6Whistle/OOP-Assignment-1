#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool PareCheck(const char*, int&, int&);		//��ȣ Ȯ�� �Լ�
bool FormulCheck(const char*, const int, const int);		//�� Ȯ�� �Լ�

int main(void)
{
	char str[1024];			//�Է¹��� ���ڿ�
	char copy[1024];		//���� Ȯ���ϴµ� ���� ���ڿ�

	cout << "fomula:";
	cin >> str;

	strcpy_s(copy, str);


	while (true)
	{
		int start = -1;			//���� �������� ��ġ�� ��ȣ�� ��ġ
		int end = -1;		//start ������ ��ġ�� ��ȣ �� ���� ó�� ��ġ�� ��ȣ�� ��ġ

		if (PareCheck(copy, start, end) == 0)		//start���� end���� Ȯ���ϰ� ��ȣ�� ���������� �Ǿ����� ���� �� faulty ��� �� ����
		{
			cout << "faulty" << endl;
			return 0;
		}

		if (FormulCheck(copy, start, end) == 0)		// ���� �־��� ���ǿ� �°� �Ǿ����� ���� �� faulty ��� �� ����
		{
			cout << "faulty" << endl;
			return 0;
		}

		if (start == -1)		//��ȣ�� ���� ��� integrity ��� �� ����
		{
			cout << "integrity" << endl;
			return 0;
		}

		//Ȯ���ߴ� ��ȣ �κ��� x�� ġȯ �� �ٽ� ���� �˻�
		char strn[100] = "x";
		int i;
		for (i = 1; copy[end + i] != '\0'; i++)
			strn[i] = copy[end + i];
		strn[i] = '\0';
		copy[start] = '\0';
		strcat_s(copy, strn);

		cout << copy << endl;
	}
}


// ���� ���� ��ȣ�� ��ġ�� ���������� ��ȣ�� �Ǿ��ִ��� Ȯ���ϴ� �Լ�
bool PareCheck(const char* str, int& start, int& end)
{
	for (int i = 0; str[i] != '\0'; i++)			// '('�� ������ ��ġ Ȯ��
	{
		if (str[i] == '(')
			start = i;
	}

	if (start == -1)				// '(' �� ���� ��� ')'�� ������ faulty ���
	{
		int i;
		for (i = 0; str[i] != '\0'; i++)
			if (str[i] == ')')
				return 0;
		end = i;					// ��ȣ�� ��� ���� ��� end ���� '\0' ��ġ�� ����

	}
	else						// '('�� ���� ���
	{
		for (int i = start + 1; str[i] != '\0'; i++)		// ')'�� ù��° ��ġ Ȯ��
			if (str[i] == ')')
			{
				end = i;
				break;
			}
		if (end == -1)			// '('��  ���� ��� ')'�� ������ faulty ���
			return 0;
	}

	return 1;
}

//���� ���� ���� ���������� �̷�����ִ��� Ȯ���ϴ� �Լ�
bool FormulCheck(const char* str, const int start, const int end)
{
	if (end - start == 1)		//���� ��ȣ �ȿ� �ƹ��͵� ���� ��� faulty ���
		return 0;
	for (int i = start + 1; i < end; i++)
	{
		if ((str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != 'x') && (str[i] < '0' || str[i] > '9'))		//����, x, ������ �ܴ̿� faulty ���
		{
			return 0;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')		//�����ڸ� �Է¹��� ��� �� �쿡 ���� ���ڰ� ������ ���� ���
		{
			if (i - 1 == start || i + 1 == end)
				return 0;
			else if (!(str[i - 1] <= '9' && str[i - 1] >= '0') && str[i - 1] != 'x')
				return 0;
			else if (!(str[i + 1] <= '9' && str[i + 1] >= '0') && str[i + 1] != 'x')
				return 0;
		}
		else if (str[i] == 'x')		//x�� �Է¹��� ��� �� �쿡 ���� ���� ��� ���� ���
		{
			if ((str[i - 1] <= '9' && str[i - 1] >= '0') || str[i - 1] == 'x')
				return 0;
			else if ((str[i + 1] <= '9' && str[i + 1] >= '0') || str[i + 1] == 'x')
				return 0;
		}
	}
	return 1;
}