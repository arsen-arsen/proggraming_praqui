#include <string>
#include <iostream>
using namespace std;

const int DIV = 'x' - 'a' + 1;
const int L = 3; 
const unsigned long long int K = pow(DIV, L); 
int cid = 0;
class Str
{
private:
	const int k = 31, md = 1e9 + 7;
public:
	int uid;
	string s;
	int hash;
	Str()
	{
		uid = cid;
		cid++;
		s = "";
		hash = 0;
	}
	void encrpt()
	{
		int z;
		for (char c : s)
		{
			z = (int)(c - 'a' + 1);
			hash = (hash * k + z) % md;
		}
	}
};
unsigned long long int pow(int z, int a)
{
	unsigned long long int pw = 1;
	for (int i = 0; i < a; i++) pw *= z;
	return pw;
}
void print(Str* arr)
{
	cout << endl << string(70, '=') << endl;
	for (int i = 0; i < K; i++)
	{
		cout << arr[i].uid << ' ' << arr[i].s << endl;
		getchar();
	}
	cout << string(70, '=') << endl;
}
void generator(Str* arr)
{
	typedef unsigned long long int ulli;
	ulli dir = K / DIV; 
	ulli dim = 1;		
	for (int i = 0; i < L; i++)		
	{
		cout << "DEBUG\t" << i << " char init" << endl;
		for(int g = 0; g < dim; g++)				
			for (int j = 0; j < DIV; j++)			
				for (ulli k = 0; k < dir; k++)
				{
					arr[dir * (j + DIV * g) + k].s.push_back('a' + j);
				}
		dir /= DIV;
		dim *= DIV;
	}
	cout << "DEBUG\t Created " << K << " strings" << endl << endl;
}
void h_cmp(Str* arr)
{
	cout << "Start of hash comparison:" << endl;
	int match = 0, hmatch = 0;
	auto ts = clock();
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if (arr[i].hash == arr[j].hash)
			{
				int g;
				hmatch++;
				for (g = 0; g < L; g++)
					if (arr[i].s[g] != arr[j].s[g]) break;
				if (g == L) match++;
			}
	auto te = clock();
	cout << "Hash comparison ended with " << hmatch << " hash matches (" << match << " confirmed). Time elapsed: " << (double)(te - ts)/CLOCKS_PER_SEC << endl;
}
void s_cmp(Str* arr)
{
	cout << "String comparison start:" << endl;
	int match = 0;
	auto ts = clock();
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			for (int g = 0; g < L; g++)
				if (arr[i].s[g] != arr[j].s[g]) break;
	auto te = clock();
	cout << "String comparison ended " << match << " matches. Time elapsed: " << (double)(te - ts) / CLOCKS_PER_SEC << endl;
}
int main()
{
	Str* smas = new Str[K];
	generator(smas);
	for (int i = 0; i < K; i++) smas[i].encrpt();
	h_cmp(smas);
	cout << endl << endl;
	s_cmp(smas);
	
}
