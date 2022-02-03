#include <iostream>
using namespace std;

int main ()
{
	int n;
	cin >> n;
	int c[100005];
	for(int i = 0 ; i < n ; i++)
	{
		cin >> c[i];
	}	
	int num = c[0];
	int len = 1;
	int maxlen = 1;
	for(int i = 1 ; i < n ; i++)
	{
		if(c[i] > num)
		{
			len++;
			if(maxlen < len)
				maxlen = len;
		}
		else
		{
			len = 1;
		}
		num = c[i];
	}
	cout << maxlen << "\n";
} 
