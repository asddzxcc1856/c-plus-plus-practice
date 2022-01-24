#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int fib[5001][201] = {};

int main ()
{
	memset(fib,0,sizeof(fib));
	fib[0][0] = 0;
	fib[1][0] = 1;
	// 1 1 2 3 5
	int s = 0;
	for(int i = 2 ; i <= 5000 ; i++)
	{
		for(int j = 0 ;j < 200; j++)
		{
			fib[i][j] += fib[i - 1][j] + fib[i - 2][j];	
			if(fib[i][j] >= 1000000000)
			{
				fib[i][j + 1] += fib[i][j] / 1000000000; 
				fib[i][j] %= 1000000000;
			}
		}
		
			
	}
	int n;
	
	while(cin >> n)
	{
		
		int i;
		cout << "The Fibonacci number for " << n << " is ";
		for(i = 200 ; i >= 0 && fib[n][i] == 0; i--);
		if(i == -1)
		{
			cout << "0\n";
		}
		else
		{
			cout << fib[n][i];
			i--;
			for(;i>=0;i--)
			{
				cout << setw(9) << setfill('0') << fib[n][i]; 
			}
			cout << "\n";
		}
		
	}	
} 
