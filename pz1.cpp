#include <iostream>
using namespace std;

class ArrayClass
{
private:
	int* a;
	int razmer;

public:
	ArrayClass(int);
	ArrayClass(const ArrayClass&);
	void print();
	~ArrayClass();
	void set(int, int);
	int get(int);
	void push_back(int);
	friend ArrayClass operator + (ArrayClass, ArrayClass);
	friend ArrayClass operator - (ArrayClass, ArrayClass);
};

ArrayClass::ArrayClass(int razmer)
{
	this->razmer = razmer;
	a = new int[razmer];
}

ArrayClass::ArrayClass(const ArrayClass& ac)
{
	razmer = ac.razmer;
	a = new int[razmer];

	for (int i = 0; i < razmer; i++)
	{
		a[i] = ac.a[i];
	}
}

ArrayClass::~ArrayClass()
{
	delete[] a;
}

void ArrayClass::print()
{
	for (int i = 0; i < razmer; i++) cout << p[i] << " ";
	cout << endl;
}

void ArrayClass::push_back(int val)
{
	int* new_mas = new int[razmer + 1];
	memcpy(new_mas, a, razmer*sizeof(int));
	new_mas[razmer] = val;

	razmer++;
	a = new_mas;
}

void ArrayClass::set(int pos, int val)
{
	if (pos < 0 || pos >= razmer)
	{
		cout << "sЕrror: array out of bounds" << endl;
		return;
	}
	else if (val < -100 || val > 100)
	{
		cout << "sError: value out of range" << endl;
		return;
	}
	else a[pos] = val;
}

int ArrayClass::get(int pos)
{
	if (pos < 0 || pos >= razmer)
	{
		cout << "gError: array out of bounds" << endl;
		return -1;
	}
	else return a[pos];
}

ArrayClass operator + (ArrayClass ac1, ArrayClass ac2)
{
	int min_razmer = ((ac1.razmer < ac2.razmer) ? ac1.razmer : ac2.razmer);
	ArrayClass out(min_razmer);
	for (int i = 0; i < min_razmer; i++) out.set(i, ac1.get(i) + ac2.get(i));
	
	return out;
}

ArrayClass operator - (ArrayClass ac1, ArrayClass ac2)
{
	int min_razmer = ((ac1.razmer < ac2.razmer) ? ac1.razmer : ac2.razmer);
	ArrayClass out(min_razmer);
	for (int i = 0; i < min_razmer; i++) out.set(i, ac1.get(i) - ac2.get(i));

	return out;
}

int main()
{
	ArrayClass ac1(3);
	for (int i = 0; i < 3; i++) ac1.set(i, i + 1);

	ArrayClass ac2(ac1);

	ac1.push_back(4);
	ac1.print();
	ac2.print();
	cout << "Push back functions correctly \n" << endl;
	ac1.set(1, 101); 
	ac1.set(101, 1); 
	ac1.get(101); 
	cout << "Get element #3: " << ac1.get(2) << "\n" << endl;
	ArrayClass ac3 = ac1 - ac2;
	ac3.print();
	ArrayClass ac4 = ac1 + ac2;
	ac4.print();
}
