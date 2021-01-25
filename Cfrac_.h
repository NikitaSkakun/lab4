#include <iostream>

using namespace std;

class Cfrac
{
	int p;
	int q;

public:
	int GetQ() { return q; }
	int GetP() { return p; }

	void SetQ(int q) { this->q = q; }
	void SetP(int p) { this->p = p; }

	void Enter_value();

	Cfrac()
	{
		p = 5;
		q = 7;
	}

	~Cfrac()
	{

	}

	void Fraction();

	void Reduction_Fraction();

};
