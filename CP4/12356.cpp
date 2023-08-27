#include <iostream>
#include <cstring>
using namespace std;

int s,b;
int vl[100001];
int vr[100001];
int main ()
{
	ios::sync_with_stdio(false),cin.tie(0);
	
	while(cin >> s >> b)
	{
		if(s == 0 && b == 0)
		{
			break;
		}
		else
		{
			for(int i = 1 ; i <= s ; i++)
			{
				vl[i] = i - 1;
				vr[i] = i + 1;
			}
			vl[1] = 0;
			vr[s] = 0;
			vl[0] = vr[0] = 0;
			for(int i = 0 ; i < b ; ++i)
			{
				int l,r;
				cin >> l >> r;
				
				vl[vr[r]] = vl[l];
				vr[vl[l]] = vr[r];  
				int f1 = vl[l],f2 = vr[r];
				if(f1)
				{
					cout << f1 << " ";
				}
				else
				{
					cout << "* ";
				}
				if(f2)
				{
					cout << f2 << "\n";
				}
				else
				{
					cout << "*\n";
				}
			}
			cout << "-\n";
		}
	}
	return 0;
}
