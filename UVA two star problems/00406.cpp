#include <iostream>
#include <vector>
using namespace std;

bool isp(int n)
{
	if(n == 2)
		return true;
	else
	{
		for(int i = 2 ; i*i <= n ; i++)
		{
			if(n % i == 0)
				return false;
		}
	}
	return true;
}

int main ()
{
	int n,c;
	while(cin >> n >> c)
	{
		vector<int> v; 
		v.push_back(1);
		for(int i = 2 ; i <= n; i++)
		{
			if(isp(i))
			{
				v.push_back(i);
			}
		}
		cout << n << " " << c << ": ";
		if(v.size() > 0 &&((v.size()%2 == 0 && c*2 >= v.size())||(v.size()%2 != 0 && c*2 - 1 >= v.size())))
		{
			for(int i = 0 ; i < v.size() ; i++)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
		}//1 2 3 5 7 11 13 17 19
		else 
		{
			if(v.size() > 0 && v.size()%2 == 0)
			{
				for(int i = (v.size() - c*2)/2; i <=(v.size() - c*2)/2 + c*2 - 1; i++)
				{
					cout << v[i] << " ";
				}
				cout << "\n";
			}
			else
			{
				for(int i = (v.size() - c*2)/2 + 1; i <=(v.size() - c*2)/2 + c*2 - 1; i++)
				{
					cout << v[i] << " ";
				}
				cout << "\n";
			}
		}	
	}
}
