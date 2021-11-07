#include <iostream>
#include <cmath>
using namespace std;

int digits(int a)
{
	int n = 0;
	a = abs(a);
	while (a > 0)
	{
		a /= 10;
		n++;
	}
	return n;
}
int rotate(int a)
{
	int b = 0;
	a = abs(a);
	while (a > 0)
	{
		b *= 10;
		b += a % 10;
		a /= 10;
	}
	return b;
}
bool check(int &i, int a)
{
	a = abs(a);
	a /= 10;
	while (a > 0)
	{
		if (a % 10 != 0) return  true;
		a = a / 10;
	}
	i = -1;
	return false;
}
int main()
{
	int a, k;
	cin >> a;
	cout << a << " = ";
	if (a == 0) cout << 0;
	int i = digits(a);
	a = (a < 0 ? -1 : 1) * rotate(a);
	for (; i > 0; i--)
	{
		k = a % 10;
		if (k != 0)
		{
			cout << "10^" << i - 1 << " *" << k;
			if (i != 1 && check(i, a)) cout << " + ";
		}
		a /= 10;
	}
	cout << ";" << endl;
}
