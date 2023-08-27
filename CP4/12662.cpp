#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	int n;
	string str[101];
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> str[i];
	}
	int relate = 10000;
	int num[101];
	memset(num,0,sizeof(num));
	for(int i = 1 ; i <= n ; i++)
	{
		relate++;
		if(str[i] != "?")
		{
			relate = 0;
		}
		else
		{
			num[i] = relate;
		}
	}
	relate = 10000;
	int num2[101];
	for(int i = n ; i >= 1 ; i--)
	{
		relate++;
		if(str[i] != "?")
		{
			relate = 0;
		}
		else
		{
			num2[i] = relate;
		}
	}
	int q;
	cin >> q;
	for(int i = 0 ; i < q ; i++)
	{
		int a;
		cin >> a;
		if(str[a] != "?")
		{
			cout << str[a] << "\n";
		}
		else if(num[a] == num2[a])
		{
			cout << "middle of " << str[a - num[a]] << " and "<< str[a + num2[a]] << "\n"; 
		}
		else if(num[a] > num2[a])
		{
			for(int j = 0 ; j < num2[a] ; j++)
			{
				cout << "left of ";
			}
			cout << str[a + num2[a]] << "\n"; 
		}
		else if(num[a] < num2[a])
		{
			for(int j = 0 ; j < num[a] ; j++)
			{
				cout << "right of ";
			}
			cout << str[a - num[a]] << "\n"; 
		}
	}
	return 0;
}
