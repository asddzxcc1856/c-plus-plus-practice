#include <iostream>
#include <cstring>
using namespace std;

int max1D(int a[],int n)
{
	int sum = -1e9;
	int s = 0;
	for(int i = 0 ; i < n ; i++)
	{
		s += a[i];
		if(s < 0)
		{
			s = 0;
		}
		sum = max(sum,s);
	}
	
	return sum;
}

int max2D(int a[][30],int n)
{
	int sum = -1e9;
	int s[30];
	for(int i = 0 ; i < n ; i++)
	{
		memset(s,0,sizeof(s));
		for(int j = i ; j < n ; j++)
		{
			for(int k = 0 ; k < n ; k++)
			{
				s[k] += a[j][k];
			}
			sum = max(sum,max1D(s,n));
		}
	}
	return sum;
}

int main ()
{
	string str;
	int t;
	cin >> t; 
	getline(cin,str);
	getline(cin,str);
	for(int k = 1 ; k <= t ; k++)
	{
		if(k != 1)
		{
			cout << "\n";
		}
		int len = 0;
		int a[30][30] = {};
		while(getline(cin,str))
		{
			if(str == "")
				break;
			for(int i = 0 ; i < str.length() ; i++)
			{
				if(str[i] == 49)
					a[len][i] = str[i] - '0';
				else
					a[len][i] = -1e6;
			}
			len++;
		}
		int ans = max2D(a,len);
		cout << ans << "\n";
	}
}