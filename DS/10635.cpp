#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> s1,s2,v[62505],lis;

int main ()
{
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; k++)
	{
		int n,p,q;
		cin >> n >> p >> q;
		s1.clear();
		for(int i = 0 ; i <= p ; i++)
		{
			int a;
			cin >> a;
			s1.push_back(a);
		}
		s2.clear();
		for(int i = 0 ; i <= q ; i++)
		{
			int a;
			cin >> a;
			s2.push_back(a);
		}
		if(s1.size() <= s2.size())
		{
			int len = n*n;
			for(int i = 0 ; i <= len ; i++)
				v[i].clear();
			for(int i = 0 ; i < s2.size() ; i++)
			{
				v[s2[i]].push_back(i);
			}
			
			lis.clear();
			lis.push_back(-1);
			for(int i = 0 ; i < s1.size() ; i++)
			{
				for(int j = v[s1[i]].size() - 1 ; j >= 0  ; j--)
				{
					if(lis.back()  < v[s1[i]][j])
					{
						lis.push_back(v[s1[i]][j]);
					}
					else
					{
						*lower_bound(lis.begin(),lis.end(),v[s1[i]][j]) = v[s1[i]][j];
					}
				}
			}
			cout << "Case " << k << ": " << lis.size() - 1 << "\n";
		}
		else
		{
			int len = n*n;
			for(int i = 0 ; i <= len ; i++)
				v[i].clear();
			for(int i = 0 ; i < s1.size() ; i++)
			{
				v[s1[i]].push_back(i);
			}
			
			lis.clear();
			lis.push_back(-1);
			for(int i = 0 ; i < s2.size() ; i++)
			{
				for(int j = v[s2[i]].size() - 1 ; j >= 0  ; j--)
				{
					if(lis.back()  < v[s2[i]][j])
					{
						lis.push_back(v[s2[i]][j]);
					}
					else
					{
						*lower_bound(lis.begin(),lis.end(),v[s2[i]][j]) = v[s2[i]][j];
					}
				}
			}
			cout << "Case " << k << ": " << lis.size() - 1 << "\n";
		}
		
	}
}