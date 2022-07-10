#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char adj[25][25];
vector<char> s1,s2;
vector<int> lis;

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int m,n;
		cin >> m >> n;
		for(int i = 1 ; i <= m ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				cin >> adj[i][j];			
			}
		}
		int N1,N2,X1,Y1,X2,Y2;
		cin >> N1 >> X1 >> Y1;
		string str;
		if(N1 != 0)
			cin >> str;
		else
			str = "";
		s1.clear();
		s1.push_back(adj[X1][Y1]);
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == 'N')
			{
				s1.push_back(adj[X1 - 1][Y1]);
				X1 -= 1;
			}
			else if (str[i] == 'S')
			{
				s1.push_back(adj[X1 + 1][Y1]);
				X1 += 1;
			}
			else if (str[i] == 'E')
			{
				s1.push_back(adj[X1][Y1 + 1]);
				Y1 += 1;
			}
			else if (str[i] == 'W')
			{
				s1.push_back(adj[X1][Y1 - 1]);
				Y1 -= 1;
			}
		}
		cin >> N2 >> X2 >> Y2;
		if(N2 != 0)
			cin >> str;
		else
			str = "";
		s2.clear();
		s2.push_back(adj[X2][Y2]);
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == 'N')
			{
				s2.push_back(adj[X2 - 1][Y2]);
				X2 -= 1;
			}
			else if (str[i] == 'S')
			{
				s2.push_back(adj[X2 + 1][Y2]);
				X2 += 1;
			}
			else if (str[i] == 'E')
			{
				s2.push_back(adj[X2][Y2 + 1]);
				Y2 += 1;
			}
			else if (str[i] == 'W')
			{
				s2.push_back(adj[X2][Y2 - 1]);
				Y2 -= 1;
			}
		}
		
		vector<int> v[128];
		if(s1.size() <= s2.size())
		{
			for(int i = 0 ; i < s2.size() ; i++)
			{
				v[s2[i]].push_back(i);
			}
			
			lis.clear();
			lis.push_back(-1);
			for(int i = 0 ; i < s1.size() ; i++)
			{
				for(int j = v[s1[i]].size() - 1 ; j >= 0 ; j--)
				{
					int num = v[s1[i]][j];
					if(lis.back() < num)
					{
						lis.push_back(num);
					}
					else
					{
						*lower_bound(lis.begin(),lis.end(),num) = num;
					}
				}
			}
			cout << "Case " << k << ": " << s1.size() - lis.size() + 1 << " " << s2.size() - lis.size() + 1 << "\n";
		}
		else
		{
			for(int i = 0 ; i < s1.size() ; i++)
			{
				v[s1[i]].push_back(i);
			}
			
			lis.clear();
			lis.push_back(-1);
			for(int i = 0 ; i < s2.size() ; i++)
			{
				for(int j = v[s2[i]].size() - 1 ; j >= 0 ; j--)
				{
					int num = v[s2[i]][j];
					if(lis.back() < num)
					{
						lis.push_back(num);
					}
					else
					{
						*lower_bound(lis.begin(),lis.end(),num) = num;
					}
				}
			}
			cout << "Case " << k << ": " << s1.size() - lis.size() + 1 << " " << s2.size() - lis.size() + 1 << "\n";
		}
		
	}
}