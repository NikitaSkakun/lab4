#include <iostream>

using namespace std;

void menu_1();
void menu_2();

char Decision_1()
{
	char x;

	cout << "��������, ����� �� ���������� ��������� - '1' '2'\n";
	cout << "�� �����:";
	cin >> x;
	while (x != '1' && x != '2')
	{
		cout << "������� ���� �� ������������ ���������: ";
		cin >> x;
	}

	return x;
}

int main()
{
	setlocale(LC_ALL, "rus");
	switch (Decision_1())
	{
	case '1':
	{
		cout << "�� ������� ������ 1�� ����� �������" << endl;
		menu_1();
	}
	break;

	case '2':
	{
		cout << "�� ������� ������ 2�� ����� �������" << endl;
		menu_2();
	}
	}
}