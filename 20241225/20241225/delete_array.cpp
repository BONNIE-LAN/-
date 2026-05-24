#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
    vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	vector<int>b(m);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	vector<int>c;
	for (int i = 0; i < n; i++)
	{
		bool found = false;
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				found = true;
				break;
			}
		}
		if (!found && (find(c.begin(), c.end(), a[i]) == c.end()))
		{
			c.push_back(a[i]);
		}
	}
	for (int i = 0; i <c.size()-1; i++)
	{
		for (int j = 0; j <c.size()-1 - i; j++)
		{
			if (c[j] > c[j + 1])
			{
				swap(c[j], c[j + 1]);
			}
		}
	}
	for (int i = 0; i <c.size(); i++)
	{
		cout << c[i]<<" ";
	}
	return 0;
}
