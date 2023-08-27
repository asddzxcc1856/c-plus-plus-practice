#include <iostream>
#include <map>
using namespace std;

map<string,string> ma;
map<string,int> si;

string findpa(string n)
{
	return ma[n] == n ? n : findpa(ma[n]);
}

int main ()
{
	int C,R;
	while(cin >> C >> R)
	{
		if(C == 0 && R == 0)
		{
			return 0;
		}
		else
		{
			for(int i = 0 ; i < C ; i++)
			{
				string str;
				cin >> str;
				ma[str] = str;
				si[str] = 1;
			}
			for(int i = 0 ; i < R ; i++)
			{
				string a,b;
				cin >> a >> b;
				string pa = findpa(a);
				string pb = findpa(b);
				if(pa != pb)
				{
					if(si[pa] >= si[pb])
					{
						ma[pb] = pa;
						si[pa] += si[pb];
					}
					else
					{
						ma[pa] = pb;
						si[pb] += si[pa];
					}
				}
			}
			int ans = 0;
			for(map<string,int>::iterator it = si.begin() ; it != si.end() ; it++)
			{
				if(it->second > ans)
				{
					ans = it->second;
				}
			}
			cout << ans << "\n";
			ma.clear();
			si.clear();
		}
	}
}
