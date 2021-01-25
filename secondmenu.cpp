#include <iostream>
#include "Cfrac_.h"

using namespace std;

/// �������� ������� ��� ������ Cfrac ///
void Cfrac::Enter_value()
{
	cout << "Enter numerator= ";
	cin >> p;

	cout << endl;

	cout << "Enter denominator= ";
	cin >> q;
	while (q == 0)
	{
		cout << "������ �� ���� ������! ������� ������ �������� � �����������: ";
		cin >> q;
	}
}
void Cfrac::Fraction()
{
	cout << "Your fraction " << p << "/" << q << "=" << (double)p / q << endl;
}


void Cfrac::Reduction_Fraction()
{
	if (q == 1)
	{
		cout << "\nReduction fraction =" << p << "/" << q << "=" << p << endl;
		return;
	}

	if (q == -1)
	{
		if (p < 0)
		{
			cout << "\nReduction fraction =" << p << "/" << q << "= " << -p << endl;
			return;
		}

		if (p > 0)
		{
			cout << "\nReduction fraction =" << p << "/" << q << "= " << -p << endl;
			return;
		}

	}

	for (int i = 9; 1 < i; i--)
		if (p % i == 0 && q % i == 0)
		{
			while (p % i == 0 && q % i == 0)
			{
				q /= i;
				p /= i;
			}
		}

	if (q == 1)
	{
		cout << "\nReduction fraction =" << p << "/" << q << "=" << p << endl;
		return;
	}

	if (q == -1)
	{
		cout << "\nReduction fraction =" << p << "/" << q << "=" << -p << endl;
		return;
	}

	if (q < -1)
	{
		if (p > 0)
		{
			cout << "\nReduction fraction =" << -p << "/" << q << endl;
			return;
		}

		if (p < 0)
		{
			cout << "\nReduction fraction =" << -p << "/" << -q << endl;
			return;
		}
	}

	cout << "\nReduction fraction =" << p << "/" << q << endl;
}
Cfrac operator + (Cfrac& that, Cfrac& other)
{
	Cfrac temp1 = that;
	Cfrac temp2 = other;

	if (temp1.GetQ() != temp2.GetQ()) //���� ���� ��������� �� ����� �������
	{
		if (temp1.GetQ() < temp2.GetQ()) //���� ���� ��������� ������ ������� 
		{
			if (temp2.GetQ() % temp1.GetQ() == 0) //� �� ������� ������ �� ������ 
			{
				int difference = temp2.GetQ() / temp1.GetQ(); // �������� ������� � ����������
				temp1.SetP(temp1.GetP() * difference); // �������� ������� ����� ��������� �� ������� difference
				temp1.SetP(temp1.GetP() + temp2.GetP()); // ������� ��������� ���� ������
				temp2.SetQ(temp1.GetQ()); // �������� ����������� ������� ����� �� �����
				return temp1;
			}
			else // ���� ������� ����. �� ������� ������ �� �������, ��������� ���.����������� ����� ���������� �������� � �������� ��� �� �������
			{
				int new_numeration = temp2.GetQ();

				do
					temp2.SetQ(temp2.GetQ() + new_numeration);
				while (temp2.GetQ() % temp1.GetQ() != 0);

				int difference = temp2.GetQ() / temp1.GetQ();
				temp1.SetP(temp1.GetP() * difference); // �������� ��������� ������� �����
				difference = temp2.GetQ() / new_numeration;
				temp2.SetP(temp2.GetP() * difference); // �������� ��������� ������� �����
				temp1.SetQ(temp2.GetQ()); // ��������� ����� ����������� � �����. �����
				temp1.SetP(temp1.GetP() + temp2.GetP()); // ������� �����������
				return temp1;
			}
		}

		if (temp1.GetQ() > temp2.GetQ())
		{
			if (temp1.GetQ() % temp2.GetQ() == 0) //� �� ������� ������ �� ������ 
			{
				int difference = temp1.GetQ() / temp2.GetQ(); // �������� ������� � ����������
				temp2.SetP(temp2.GetP() * difference); // �������� ������� ����� ��������� �� ������� difference
				temp2.SetP(temp2.GetP() + temp1.GetP()); // ������� ��������� ���� ������
				temp2.SetQ(temp1.GetQ()); // �������� ����������� ������� ����� �� �����
				return temp2;
			}
			else // ���� ������� ����. �� ������� ������ �� �������, ��������� ���.����������� ����� ���������� �������� � �������� ��� �� �������
			{
				int new_numeration = temp1.GetQ();

				do
					temp1.SetQ(temp1.GetQ() + new_numeration);
				while (temp1.GetQ() % temp2.GetQ() != 0);

				int difference = temp1.GetQ() / temp2.GetQ();
				temp2.SetP(temp2.GetP() * difference); // �������� ��������� ������� �����
				difference = temp1.GetQ() / new_numeration;
				temp1.SetP(temp1.GetP() * difference); // �������� ��������� ������� �����
				temp2.SetQ(temp1.GetQ()); // ��������� ����� ����������� � �����. �����
				temp2.SetP(temp2.GetP() + temp1.GetP()); // ������� �����������
				return temp2;
			}
		}
	}
	else
	{
		temp1.SetP(temp1.GetP() + temp2.GetP());
		return temp1;
	}
}
Cfrac operator - (Cfrac& that, Cfrac& other)
{
	Cfrac temp1 = that;
	Cfrac temp2 = other;

	if (temp1.GetQ() != temp2.GetQ()) //���� ���� ��������� �� ����� �������
	{
		if (temp1.GetQ() < temp2.GetQ()) //���� ���� ��������� ������ ������� 
		{
			if (temp2.GetQ() % temp1.GetQ() == 0) //� �� ������� ������ �� ������ 
			{
				int difference = temp2.GetQ() / temp1.GetQ(); // �������� ������� � ����������
				temp1.SetP(temp1.GetP() * difference); // �������� ������� ����� ��������� �� ������� difference
				temp1.SetP(temp1.GetP() - temp2.GetP()); // ����� ��������� ���� ������
				temp2.SetQ(temp1.GetQ()); // �������� ����������� ������� ����� �� �����
				return temp1;
			}
			else // ���� ������� ����. �� ������� ������ �� �������, ��������� ���.����������� ����� ���������� �������� � �������� ��� �� �������
			{
				int new_numeration = temp2.GetQ();

				do
					temp2.SetQ(temp2.GetQ() + new_numeration);
				while (temp2.GetQ() % temp1.GetQ() != 0);

				int difference = temp2.GetQ() / temp1.GetQ();
				temp1.SetP(temp1.GetP() * difference); // �������� ��������� ������� �����
				difference = temp2.GetQ() / new_numeration;
				temp2.SetP(temp2.GetP() * difference); // �������� ��������� ������� �����
				temp1.SetQ(temp2.GetQ()); // ��������� ����� ����������� � �����. �����
				temp1.SetP(temp1.GetP() - temp2.GetP()); // ����� ��������� ���� ������
				return temp1;
			}
		}

		if (temp1.GetQ() > temp2.GetQ())
		{
			if (temp1.GetQ() % temp2.GetQ() == 0) //� �� ������� ������ �� ������ 
			{
				int difference = temp1.GetQ() / temp2.GetQ(); // �������� ������� � ����������
				temp2.SetP(temp2.GetP() * difference); // �������� ������� ����� ��������� �� ������� difference
				temp2.SetP(temp2.GetP() - temp1.GetP()); // ����� ��������� ���� ������
				temp2.SetQ(temp1.GetQ()); // �������� ����������� ������� ����� �� �����
				return temp2;
			}
			else // ���� ������� ����. �� ������� ������ �� �������, ��������� ���.����������� ����� ���������� �������� � �������� ��� �� �������
			{
				int new_numeration = temp1.GetQ();

				do
					temp1.SetQ(temp1.GetQ() + new_numeration);
				while (temp1.GetQ() % temp2.GetQ() != 0);

				int difference = temp1.GetQ() / temp2.GetQ();
				temp2.SetP(temp2.GetP() * difference); // �������� ��������� ������� �����
				difference = temp1.GetQ() / new_numeration;
				temp1.SetP(temp1.GetP() * difference); // �������� ��������� ������� �����
				temp2.SetQ(temp1.GetQ()); // ��������� ����� ����������� � �����. �����
				temp2.SetP(temp2.GetP() - temp1.GetP()); // ����� ���������
				return temp2;
			}
		}
	}
	else
	{
		temp1.SetP(temp1.GetP() + temp2.GetP());
		return temp1;
	}
}
Cfrac operator * (Cfrac& that, Cfrac& other)
{
	Cfrac temp;
	temp.SetP(that.GetP() * other.GetP());
	temp.SetQ(that.GetQ() * other.GetQ());
	return temp;
}
Cfrac operator / (Cfrac& that, Cfrac& other)
{
	Cfrac temp1 = that;
	Cfrac temp2 = other;

	temp1.SetP(temp1.GetP() * temp2.GetQ());
	temp1.SetQ(temp1.GetQ() * temp2.GetP());

	return temp1;
}

char Decision_2()
{
	char x;
	cout << "\n��������, ����� �� ������� �� ������ ������� � ������� ��������������� ������: '+' '-' '*' '/'\n";
	cout << "�� �����:";
	cin >> x;
	while (x != '+' && x != '-' && x != '*' && x != '/')
	{
		cout << "������� ���� �� ������������ ���������: ";
		cin >> x;
	}

	return x;
}

void menu_2()
{
	Cfrac A;
	A.Enter_value();
	A.Reduction_Fraction();

	Cfrac B;
	B.Enter_value();
	B.Reduction_Fraction();

	Cfrac AB;

	switch (Decision_2())
	{
	case '+':
	{
		AB = operator + (A, B);
		cout << "AB.P= " << AB.GetP() << ";\t";
		cout << "AB.Q= " << AB.GetQ() << ";";

		if (AB.GetQ() == 1)
			cout << "\t----->" << AB.GetP() << endl;
		else
			cout << "\t----->" << AB.GetP() << "/" << AB.GetQ() << endl;
	}
	break;

	case '-':
	{
		AB = A - B;
		cout << "AB.P= " << AB.GetP() << ";\t";
		cout << "AB.Q= " << AB.GetQ() << ";";

		if (AB.GetQ() == 1)
			cout << "\t----->" << AB.GetP() << endl;
		else
			cout << "\t----->" << AB.GetP() << "/" << AB.GetQ() << endl;
	}
	break;

	case '*':
	{
		AB = operator * (A, B);
		if (AB.GetQ() == 1)
			cout << "\t----->" << AB.GetP() << endl;
		else
			cout << "\t----->" << AB.GetP() << "/" << AB.GetQ() << endl;
	}
	break;

	case '/':
	{
		AB = A / B;
		if (AB.GetQ() == 1)
			cout << "\t----->" << AB.GetP() << endl;
		else
			//cout << "\t----->" << AB.GetP() << "/" << AB.GetQ() << endl;
			if (AB.GetP() == -1 && AB.GetQ() == -1)
				cout << "\t----->" << -AB.GetP() << "/" << -AB.GetQ() << endl;
			else
				cout << "\t----->" << AB.GetP() << "/" << AB.GetQ() << endl;
	}

	}
}