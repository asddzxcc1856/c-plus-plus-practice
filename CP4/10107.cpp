#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main ()
{
	int num;
	int len = 0;
	while(cin >> num)
	{
		arr[len] = num;
		len++;
		sort(arr,arr + len);
		if(len % 2 == 0)
		{
			int mid = (arr[len / 2] + arr[len / 2 - 1]) / 2;
			cout << mid << "\n"; 
		}
		else
		{
			cout << arr[len / 2] << "\n"; 
		}
	}	
} 
