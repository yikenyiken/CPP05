#include <iostream>

using namespace std;

class base
{
	protected:
	int x;
};

class a : virtual public base
{

};

class b : a
{

};


class c : b
{

};

class d : c
{

};


class last : public a, public b
{
	public:
	void	display()
	{
		cout << "x is " << x << endl;
	}

};

int main() {
	
	last	obj;
	
	obj.display();

	return 0;
}

// might we add only one exception for the unsigned form case
// and use the Form::gradeTooLow exception for the insufficient grade case