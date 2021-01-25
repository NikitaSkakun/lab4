#include <iostream>

using namespace std;

class Ccomplex
{
private:
	int a;
	int b;

public:
	Ccomplex()
	{
		cout << "Запустился конструктор по умолчанию Ccomplex (" << this << ")" << endl;
		a = 1;
		b = 1;
	}

	Ccomplex(int a, int b)
	{
		this->a = a;
		this->b = b;
		cout << "Запустился конструктор Ccomplex (" << this << ")" << endl;

	}

	int GetA() { return a; }
	int GetB() { return b; }

	void SetA(int a) { this->a = a; }
	void SetB(int b) { this->b = b; }

	Ccomplex& operator = (const Ccomplex& other);
	void operator / (Ccomplex& another);
	Ccomplex& operator *= (const Ccomplex& another);


};
