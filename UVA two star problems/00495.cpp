#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int fib[5001][150];
int f[5001];

int main ()
{
	freopen("out.txt","w",stdout);
	memset(fib,0,sizeof(fib));
	fib[0][0] = 0;
	fib[1][0] = 1;
	f[0] = 1;
	f[1] = 1;
	// 1 1 2 3 5
	int s = 0;
	for(int i = 2 ; i <= 5000 ; i++)
	{
		for(int j = 0 ;j < f[i - 1] || j < f[i - 2] || s!=0; j++)
		{
			fib[i][j] += fib[i - 1][j] + fib[i - 2][j] + s;	
			if(fib[i][j] >= 1000000000)
			{
				s = 1;
				fib[i][j] -= 1000000000;
			}
			else
				s = 0;
			f[i]++;
		}
		
			
	}
	int n;
	
	while(cin >> n)
	{
		int i;
		cout << "The Fibonacci number for " << n << " is " << fib[n][f[n] - 1];
		for(i = f[n] - 2;i>=0;i--)
		{
			cout << setw(9) << setfill('0') << fib[n][i]; 
		}
		
		cout << "\n";
	}	
} 
