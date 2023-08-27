#include <iostream>
using namespace std;

int jos(int n,int k)//f(n,k) = (f(n-1,k) + k)%(n-1)
{
	int p = 0;
	for(int i = 2 ; i <= n ; i++)
	{
		p = (p + k) % i; 
	}
	
	return p + 1;
}

int main ()
{
	int t,n,k;
	cin >> t;
	for(int j = 1 ; j <= t ; j++)
	{
		cin >> n >> k;
		cout << "Case " << j << ": " << jos(n,k) << "\n";
	}
}