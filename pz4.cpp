#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void map_fx()
{
	map<string, int> dict;
	string c;
	while (cin >> c)
	{
		if (c == "/exit") break;
		dict[c]++;
	}
	cout << endl;
	for (pair<string, int> p : dict) cout << p.second << ' ' << p.first << endl;
}
void vector_fx()
{
	srand(time(NULL));
	int x1, x2;
	cin >> x1 >> x2;
	map<int, int> num;
	vector<int> v1(x1), v2(x2);
	int sum1 = 0, sum2 = 0;
	cout << "First vector: \n";
	for (int& a : v1)
	{
		a = rand() % 201 - 100;
		sum1 += a;

		cout << a << ' ' << " \n ";
	}
	cout << "Second vector: ";
	for (int& a : v2)
	{
		a = rand() % 201 - 100;
		sum2 += a;
		if (find(v1.begin(), v1.end(), a) != v1.end()) num[a]++;
		cout << a << ' '<< " \n ";
	}
	cout << "Avg in 1st vector: \n " << (float)sum1 / x1 << " \n ";
	cout << "Avg in 2nd vector: \n " << (float)sum2 / x2 << " \n ";
	cout << "Matching elements: \n ";
	for (pair<int, int> p : num)
		cout << p.first << ' ';
}

void dfs(int v, vector<vector<int>>& m)
{
	vector<bool> used(m.size(), false);
	stack<int> q;
	while (v != -1)
	{
		if (used[v] == false)
		{
			used[v] = true;

			for (int i = 0; i < m.size(); i++)
				if (m[v][i] == 1 && used[i] == false) q.push(i);
		}
		if (q.size() > 0)
		{
			v = q.top();
			q.pop();
		}
		else v = -1;
	}
	for (bool a : used) cout << a << ' ' << " \n ";
	cout << endl;
}	
void stack_fx()
{
	int N;
	cin >> N;
	vector<vector<int>> matrix(N, vector<int>(N, 0));
	int x;
	for (int i = 0; i < N; i++)
	{
		do
		{
			cin >> x;
			if (x != 0) matrix[i][x - 1] = 1;
		} while (cin.peek() != '\n');
	}
	for (int i = 0; i < N; i++) dfs(i, matrix);
}
int main()
{
	stack_func();
}
