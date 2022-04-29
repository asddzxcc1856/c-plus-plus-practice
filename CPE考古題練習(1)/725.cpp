#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

map<int,int> ma;
int n;

void rec(int num,int len,bool nu[10])
{
	
	if(len == 5)
	{
		
		if(n * num <= 99999)
		{
			int num2 = n * num;
			bool used[10] = {};
			for(int j = 0 ; j <= 9 ; j++)
			{
				used[j] = nu[j];
			}
			bool ok = true;
			for(int j = 0 ; j < 5 ; j++)
			{
				if(used[num2 / (int)(pow(10,j)) % 10] == false)
					used[num2 / (int)(pow(10,j)) % 10] = true;
				else
				{
					ok = false;
					break;
				}
			}
			if(ok)
				ma[num] = n * num;
		}
		return;
	}
	for(int i = 0 ; i <= 9 ; i++)
	{
		if(nu[i] == false)
		{
			nu[i] = true;
			num += i * (int)pow(10,4 - len);
			rec(num,len + 1,nu);
			num -= i * (int)pow(10,4 - len);
			nu[i] = false;
		}
	}
}

int main ()
{
	bool first = false;
	while(cin >> n,n)
	{
		if(first)
		{
			cout << "\n";
		}
		else
		{
			first = true;
		}
		bool nu[10];
		for(int i = 0 ; i <= 9 ; i++)
		{
			nu[i] = false;
		}
		ma.clear();
		rec(0,0,nu);
		if(!ma.empty())
		{
			for(map<int,int>::iterator it = ma.begin() ; it != ma.end() ; it++)
			{
				cout << setfill('0') << setw(5) << it->second << " / " << setfill('0') << setw(5) << it->first << " = " << n << "\n";
			}
		}
		else
		{
			cout << "There are no solutions for " << n << ".\n";
		}
		
	}
}