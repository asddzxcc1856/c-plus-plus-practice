#include <iostream>
#include <sstream>
using namespace std;

int c[100];
int b[100];
int arr[100];
int main ()
{
	int n;
	while(cin >> n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			int a;
			cin >> a;
			c[i] = a;
		}
		string str;
		getline(cin,str);
		while(getline(cin,str))
		{
			stringstream ss(str);
			int num;
			for(int i = 1 ; i <= n ; i++)
			{
				arr[i] = 0;
			}
			int len = 1;
			while(ss >> num)
			{
				b[num] = c[len++];
			}
			for(int i = 1 ; i <= n ; i++)
			{
				if(arr[b[i]] == 0)
				{
					arr[b[i]] = 1;
				}
				for(int j = 1 ; j < b[i] ; j++)
				{
					arr[b[i]] = max(arr[b[i]],arr[j] + 1);
				}
			}
			
			int l = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				l = max(l,arr[i]);
			}
			cout << l << "\n";
		}
	}
}