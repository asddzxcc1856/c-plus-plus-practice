#include <iostream>
#include <vector>
using namespace std;

vector<int> v[3];
int m,n,get;

void hanoi(int m,int a,int b,int c) 
{
	if(m == 0 || get >= n)
	{
		return;
	}
	else
	{
		hanoi(m - 1,a,c,b);
		if(get >= n)
			return;
		v[c].push_back(v[a].back());
		v[a].pop_back();
		for(int i = 0 ; i < 3 ; i++)
		{
			if(v[i].size() > 0)
			{
				cout << (char)(i+'A') << "=>   ";
				for(int j = 0 ; j < v[i].size() - 1; j++)
				{
					cout << v[i][j] << " ";
				}
				cout << v[i][v[i].size() - 1];
			}	
			else
				cout << (char)(i+'A') << "=>";
			cout << "\n";
		}
		cout << "\n";
		get++;
		hanoi(m - 1,b,a,c);
	}
}
int main ()
{
	int times = 1;
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
		{
			return 0;
		}
		get = 0;
		cout << "Problem #" << times++ << "\n\n";
		for(int i = 0 ; i < 3 ; i++)
		{
			v[i].clear();
		}
		for(int i = m ; i >= 1 ; i--)
		{
			v[0].push_back(i);
		}
		for(int i = 0 ; i < 3 ; i++)
		{
			if(v[i].size() > 0)
			{
				cout << (char)(i+'A') << "=>   ";
				for(int j = 0 ; j < v[i].size() - 1; j++)
				{
					cout << v[i][j] << " ";
				}
				cout << v[i][v[i].size() - 1];
			}	
			else
				cout << (char)(i+'A') << "=>";
			cout << "\n";
		}
		cout << "\n";
		hanoi(m,0,1,2);
	}
	
}