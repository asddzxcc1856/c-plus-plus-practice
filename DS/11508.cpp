#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

long long int n[10000005];
long long int a[100005];

int main ()
{
	string str;
	while(getline(cin,str))
	{
		if(str == "0")
		{
			return 0;
		}
		memset(n,0,sizeof(n));
		memset(a,-1,sizeof(a));
		stringstream ss(str);
		long long int num;
		long long int len = 0;
		long long int maxn = 0;
		while(ss >> num)
		{
			maxn = max(maxn,num);
			n[num]++;
			len++;
		}
		int idx = 0;
		for(int i = 0 ; i < len ; i++)
		{
			if(n[i] >= 1)
			{
				a[i] = i;
				n[i]--;
			}
		}
		for(int i = 0 ; i < len ; i++)
		{
			if(a[i] != -1)
			{
				continue;
			}
			while(n[idx] == 0 && idx <= maxn)
			{
				idx++;
			}
			if(n[idx] >= 1)
			{
				a[i] = idx;
				n[idx]--;	
			}
		}
		bool ok = true;
		for(int i = 0 ; i < len ; i++)
		{
			if(a[i] == -1)
			{
				ok = false;
			}
			else if (a[a[i]] != a[i])
			{
				ok = false;	
			} 
		}
		if(ok)
		{
			for(int i = 0 ; i < len - 1 ; i++)
			{
				cout << a[i] << " ";
			}
			cout << a[len - 1] << "\n";
		}
		else
		{
			cout << "Message hacked by the Martians!!!\n";
		}
	}
}