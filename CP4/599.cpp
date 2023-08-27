#include <iostream>
using namespace std;

int pa[26];
int num[26];

int findpa(int n)
{
	return pa[n] == n ? n : findpa(pa[n]); 
}

int main()
{
	int n;
	cin >> n;
	for(int k = 1 ; k <= n ; k++)
	{
		for(int i = 0 ; i < 26 ; i++)
		{
			pa[i] = i;
			num[i] = 1;
		}
		string str;
		while(cin >> str)
		{
			if(str[0] != '(')
			{
				break;
			}
			int pra = findpa(str[1] - 'A'),prb = findpa(str[3] - 'A');
			if(pra != prb)
			{
				if(num[pra] >= num[prb])
				{
					pa[prb] = pra; 
					num[pra] += num[prb];	
				}	
				else
				{
					pa[pra] = prb; 
					num[prb] += num[pra];
				}
			} 
		}
		cin >> str;
		int dot = 0,tree = 0;
		for(int i = 0 ; i < str.length() ; i+=2)
		{
			int pra = findpa(str[i] - 'A');	
			if(num[pra] == 1)
			{
				dot++;
			}
			else
			{
				int pra = findpa(str[i] - 'A');	
				if(num[pra] != 0)
				{
					tree++;
					num[pra] = 0;
				}
			}
		}
		cout << "There are " << tree << " tree(s) and " << dot << " acorn(s).\n";
	}
}
