#include <iostream>
#include "Ccomplex_.h"

using namespace std;

///Методы и перегрузки операторов для Ccomplex///
Ccomplex& Ccomplex::operator = (const Ccomplex& other)
{
	this->a = other.a;
	this->b = other.b;
	return *this;
}
void Ccomplex::operator / (Ccomplex& other)
{
	//Ccomplex numeration(a * other.GetA(), a * -other.GetB() + b * other.GetA() + b * -other.GetB());
	//Ccomplex denominator(other.GetA() * other.GetA(), other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB());
	auto Im_1 = a * -other.GetB() + b * other.GetA() + b * -other.GetB();
	auto Im_2 = other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB();

	auto Re_1 = a * other.GetA();
	auto Re_2 = other.GetA() * other.GetA();

	if (Re_1 != 0)
	{
		if (Im_1 > 0)
			cout << "(" << a * other.GetA() << "+" << a * -other.GetB() + b * other.GetA() + b * -other.GetB() << "*i) / (";
		else
			if (Im_1 < 0)
				cout << "(" << a * other.GetA() << "-" << -(a * -other.GetB() + b * other.GetA() + b * -other.GetB()) << "*i) / (";
			else
				if (Im_1 == 0)
					cout << "(" << a * other.GetA() << "i) / (";
	}
	else
	{
		if (Re_1 == 0)
			if (Im_1 > 0)
				cout << "(" << a * -other.GetB() + b * other.GetA() + b * -other.GetB() << "*i) / (";
			else
				if (Im_1 < 0)
					cout << "(" << -(a * -other.GetB() + b * other.GetA() + b * -other.GetB()) << "*i) / (";
				else
					if (Im_1 == 0)
						cout << "(0) / (";
	}

	if (Re_2 != 0)
	{
		if (Im_2 > 0)
			cout << "(" << other.GetA() * other.GetA() << "+" << other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB() << "*i)";
		else
			if (Im_2 < 0)
				cout << "(" << other.GetA() * other.GetA() << "-" << -(other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB()) << "*i)";
			else
				if (Im_2 == 0)
					cout << "(" << other.GetA() * other.GetA() << "i)";
	}
	else
	{
		if (Re_2 == 0)
			if (Im_2 > 0)
				cout << "(" << other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB() << "*i)";
			else
				if (Im_2 < 0)
					cout << "(" << -(other.GetA() * -other.GetB() + other.GetB() * other.GetA() + other.GetB() * -other.GetB()) << "*i)";
				else
					if (Im_2 == 0)
						cout << "(0)";
	}

	cout << endl;
}
Ccomplex& Ccomplex::operator*=(const Ccomplex& other)
{
	int Re = a * other.a;
	int Im = a * other.b + b * other.b + b * other.a;

	this->a = Re;
	this->b = Im;
	return *this;
}


char Decision_3()
{
	char x;
	cout << "\nВыберите, какую из функций вы хотите выбрать и введите соответствующий символ: '=' or '*'\n";
	cout << "Вы ввели:";
	cin >> x;
	while (x != '=' && x != '/' && x != '*')
	{
		cout << "Введите один из предложенных вариантов: ";
		cin >> x;
	}

	return x;
}

void menu_1()
{
	int a, b;
	bool flag = true;

	while (flag)
	{
		cout << "Введите действительную часть для первого компелксного числа: ";
		cin >> a;

		cout << "Введите мнимую часть для первого компелксного числа: ";
		cin >> b;
		Ccomplex first(a, b);

		cout << "Введите действительную часть для второго компелксного числа: ";
		cin >> a;

		cout << "Введите мнимую часть для второго компелксного числа: ";
		cin >> b;
		Ccomplex second(a, b);

		switch (Decision_3())
		{
		case '=':
		{
			Ccomplex first_second;
			first_second = first;

			if (first_second.GetA() > 0 || first_second.GetA() < 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << first_second.GetA() << "+i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetA() << "+" << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = " << first_second.GetA() << "-i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetA() << "-" << -first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = " << first_second.GetA() << endl;
					break;
				}

			}

			if (first_second.GetA() == 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << "i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = -i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = 0" << endl;
					break;
				}

			}

			first_second = second;

			if (first_second.GetA() > 0 || first_second.GetA() < 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << first_second.GetA() << "+i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetA() << "+" << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = " << first_second.GetA() << "-i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetA() << "-" << -first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = " << first_second.GetA() << endl;
					break;
				}

			}

			if (first_second.GetA() == 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << "i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = -i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = 0" << endl;
					break;
				}

			}
		}

		case '*':
		{
			cout << "Введите действительную часть для компелксного числа: ";
			cin >> a;

			cout << "Введите мнимую часть для компелксного числа: ";
			cin >> b;
			Ccomplex first_second(a, b);
			first_second *= first;

			if (first_second.GetA() > 0 || first_second.GetA() < 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << first_second.GetA() << "+i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetA() << "+" << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = " << first_second.GetA() << "-i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetA() << "-" << -first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = " << first_second.GetA() << endl;
					break;
				}

			}

			if (first_second.GetA() == 0)
			{
				if (first_second.GetB() == 1)
				{
					cout << "z = " << "i" << endl;
					break;
				}


				if (first_second.GetB() > 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == -1)
				{
					cout << "z = -i" << endl;
					break;
				}

				if (first_second.GetB() < 0)
				{
					cout << "z = " << first_second.GetB() << "*i" << endl;
					break;
				}

				if (first_second.GetB() == 0)
				{
					cout << "z = 0" << endl;
					break;
				}

			}
		}
		break;

		case '/':
		{
			first / second;
		}
		}
	}
}