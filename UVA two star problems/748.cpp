#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long int inter[200];
long long int temp[200];
long long int t[20];

int main ()
{
	string a;
	int n;
	while(cin >> a >> n)
	{
		memset(inter,0,sizeof(inter));
		memset(temp,0,sizeof(temp));
		memset(t,0,sizeof(t));
		int num = 0;
		int e;
		int te;
		int cnt = 0;
		for(te = 0 ; te < a.length() && a[te] != '.' ; te++)
			num = num * 10 + a[te] - '0';
		for(e = te + 1 ; e < a.length() ; e++,cnt++)
			num = num * 10 + a[e] - '0';
		
		e = cnt * n;
		int maxl = 0;
		while(num!=0)
		{
			inter[maxl++] = num%10;
			num /= 10;
		}
		
		for(int i = maxl - 1 ; i >= 0 ; i--)
		{
			t[i] = inter[i];
		}
		for(int i = maxl - 1 ; i >= 0 ; i--)
		{
			inter[i] = t[i];
		}
		for(int i = 1 ; i < n ; i++)
		{
			for(int j = 0 ; j < maxl ; j++)
			{
				for(int k = 0 ; k < 200 ; k++)
				{
					temp[k + j] += inter[k] * t[j];		
				}
				
				
				
				for(int k = 0 ; k < 199 ; k++)
				{
					if(temp[k] >= 10)
					{
						temp[k + 1] += temp[k] / 10;
						temp[k] %= 10;
					}
				}
			}
			for(int k = 0 ; k < 200 ; k++)
			{
				inter[k] = temp[k];
				temp[k] = 0;
			}
			
		}
		int i;
		for(i = 199 ; i >= 0 && inter[i] == 0 ; i--);
		
		for(;i >= e;i--)
		{
			cout << inter[i];
		}

			
		
		int j = 0;
		for(;inter[j] == 0;j++);
		if(i>=j)
			cout << ".";
		while(--e>i)
		{
			cout << "0";
		}
		for(;i >= j; i--)
		{
			cout << inter[i];
		}
		cout << "\n";
	}	
} 
