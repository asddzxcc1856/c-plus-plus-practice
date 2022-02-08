#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for(int k = 0 ; k < t ;  k++)
	{
		string str;
		int dp[105];
		
		cin >> str;
		bool ok = true;
		memset(dp,0,sizeof(dp)); 
		int con0 = 0,con1 = 0;
		int idx0 = 0,idx1 = 10000;
		for(int i = str.length() ; i >= 0 ; i--)
		{
			if(str[i] == '0')
			{
				con0++;
			}
			else
			{
				con0 = 0;
			}
			if(con0 >= 2)
			{
				idx0 = i + con0 - 1;
				break;
			}
		}
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '1')
			{
				con1++;
			}
			else
			{
				con1 = 0;
			}
			if(con1 >= 2)
			{
				idx1 = i - con1 + 1;
				break;
			}
		}
		if(idx1 >= idx0)
			cout << "YES\n"; 
		else
			cout << "NO\n";
	}	
}
