#include <iostream>
#include <cmath>
#define MAXN 20001
using namespace std;

int pa[MAXN];

int findlen(int n,int len)
{
	
	return pa[n] == n ? len : findlen(pa[n],len + abs(n - pa[n])%1000);
}
int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		int n;
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			pa[i] = i;
		}
		string str;
		int a,b;
		while(cin >> str)
		{
			if(str == "O")
			{
				break;
			}
			else if (str == "E")
			{
				cin >> a;
				cout << findlen(a,0)  << "\n";
			}
			else if (str == "I")
			{
				cin >> a >> b;
				pa[a] = b;
			}
		}
		
	}
}
