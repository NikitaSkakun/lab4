#include <iostream>
#include "Cfrac_.h"

using namespace std;

/// Описание методов для класса Cfrac ///
void Cfrac::Enter_value()
{
	cout << "Enter numerator= ";
	cin >> p;

	cout << endl;

	cout << "Enter denominator= ";
	cin >> q;
	while (q == 0)
	{
		cout << "Делить на ноль нельзя! Введите другое значение в знаменатель: ";
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

	if (temp1.GetQ() != temp2.GetQ()) //Если один числитель не равен другому
	{
		if (temp1.GetQ() < temp2.GetQ()) //Если один числитель меньше другого 
		{
			if (temp2.GetQ() % temp1.GetQ() == 0) //И он делится нацело на другой 
			{
				int difference = temp2.GetQ() / temp1.GetQ(); // Записали разницу в переменную
				temp1.SetP(temp1.GetP() * difference); // Чилитель меньшей дроби домножаем на разницу difference
				temp1.SetP(temp1.GetP() + temp2.GetP()); // Сложили числители двух дробей
				temp2.SetQ(temp1.GetQ()); // Изменили знаменатель меньшей дроби на общий
				return temp1;
			}
			else // Если больший числ. не делится нацело на меньший, подбираем общ.знаменатель через домножение большего и делением его не меньший
			{
				int new_numeration = temp2.GetQ();

				do
					temp2.SetQ(temp2.GetQ() + new_numeration);
				while (temp2.GetQ() % temp1.GetQ() != 0);

				int difference = temp2.GetQ() / temp1.GetQ();
				temp1.SetP(temp1.GetP() * difference); // Умножаем числитель меньшей дроби
				difference = temp2.GetQ() / new_numeration;
				temp2.SetP(temp2.GetP() * difference); // Умножаем числитель большей дроби
				temp1.SetQ(temp2.GetQ()); // Приминяем общий знаменатель к меньш. дроби
				temp1.SetP(temp1.GetP() + temp2.GetP()); // Сложили знаменатели
				return temp1;
			}
		}

		if (temp1.GetQ() > temp2.GetQ())
		{
			if (temp1.GetQ() % temp2.GetQ() == 0) //И он делится нацело на другой 
			{
				int difference = temp1.GetQ() / temp2.GetQ(); // Записали разницу в переменную
				temp2.SetP(temp2.GetP() * difference); // Чилитель меньшей дроби домножаем на разницу difference
				temp2.SetP(temp2.GetP() + temp1.GetP()); // Сложили числители двух дробей
				temp2.SetQ(temp1.GetQ()); // Изменили знаменатель меньшей дроби на общий
				return temp2;
			}
			else // Если больший числ. не делится нацело на меньший, подбираем общ.знаменатель через домножение большего и делением его не меньший
			{
				int new_numeration = temp1.GetQ();

				do
					temp1.SetQ(temp1.GetQ() + new_numeration);
				while (temp1.GetQ() % temp2.GetQ() != 0);

				int difference = temp1.GetQ() / temp2.GetQ();
				temp2.SetP(temp2.GetP() * difference); // Умножаем числитель меньшей дроби
				difference = temp1.GetQ() / new_numeration;
				temp1.SetP(temp1.GetP() * difference); // Умножаем числитель большей дроби
				temp2.SetQ(temp1.GetQ()); // Приминяем общий знаменатель к меньш. дроби
				temp2.SetP(temp2.GetP() + temp1.GetP()); // Сложили знаменатели
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

	if (temp1.GetQ() != temp2.GetQ()) //Если один числитель не равен другому
	{
		if (temp1.GetQ() < temp2.GetQ()) //Если один числитель меньше другого 
		{
			if (temp2.GetQ() % temp1.GetQ() == 0) //И он делится нацело на другой 
			{
				int difference = temp2.GetQ() / temp1.GetQ(); // Записали разницу в переменную
				temp1.SetP(temp1.GetP() * difference); // Чилитель меньшей дроби домножаем на разницу difference
				temp1.SetP(temp1.GetP() - temp2.GetP()); // Вычли числители двух дробей
				temp2.SetQ(temp1.GetQ()); // Изменили знаменатель меньшей дроби на общий
				return temp1;
			}
			else // Если больший числ. не делится нацело на меньший, подбираем общ.знаменатель через домножение большего и делением его не меньший
			{
				int new_numeration = temp2.GetQ();

				do
					temp2.SetQ(temp2.GetQ() + new_numeration);
				while (temp2.GetQ() % temp1.GetQ() != 0);

				int difference = temp2.GetQ() / temp1.GetQ();
				temp1.SetP(temp1.GetP() * difference); // Умножаем числитель меньшей дроби
				difference = temp2.GetQ() / new_numeration;
				temp2.SetP(temp2.GetP() * difference); // Умножаем числитель большей дроби
				temp1.SetQ(temp2.GetQ()); // Приминяем общий знаменатель к меньш. дроби
				temp1.SetP(temp1.GetP() - temp2.GetP()); // Вычли числители двух дробей
				return temp1;
			}
		}

		if (temp1.GetQ() > temp2.GetQ())
		{
			if (temp1.GetQ() % temp2.GetQ() == 0) //И он делится нацело на другой 
			{
				int difference = temp1.GetQ() / temp2.GetQ(); // Записали разницу в переменную
				temp2.SetP(temp2.GetP() * difference); // Чилитель меньшей дроби домножаем на разницу difference
				temp2.SetP(temp2.GetP() - temp1.GetP()); // Вычли числители двух дробей
				temp2.SetQ(temp1.GetQ()); // Изменили знаменатель меньшей дроби на общий
				return temp2;
			}
			else // Если больший числ. не делится нацело на меньший, подбираем общ.знаменатель через домножение большего и делением его не меньший
			{
				int new_numeration = temp1.GetQ();

				do
					temp1.SetQ(temp1.GetQ() + new_numeration);
				while (temp1.GetQ() % temp2.GetQ() != 0);

				int difference = temp1.GetQ() / temp2.GetQ();
				temp2.SetP(temp2.GetP() * difference); // Умножаем числитель меньшей дроби
				difference = temp1.GetQ() / new_numeration;
				temp1.SetP(temp1.GetP() * difference); // Умножаем числитель большей дроби
				temp2.SetQ(temp1.GetQ()); // Приминяем общий знаменатель к меньш. дроби
				temp2.SetP(temp2.GetP() - temp1.GetP()); // Вычли числители
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
	cout << "\nВыберите, какую из функций вы хотите выбрать и введите соответствующий символ: '+' '-' '*' '/'\n";
	cout << "Вы ввели:";
	cin >> x;
	while (x != '+' && x != '-' && x != '*' && x != '/')
	{
		cout << "Введите один из предложенных вариантов: ";
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