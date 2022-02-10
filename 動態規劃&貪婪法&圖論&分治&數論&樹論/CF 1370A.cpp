#include <iostream>
using namespace std;

int GCD(int a,int b)
{
	if(b == 0)
		return a;
	return GCD(b,a%b);
}

int main ()
{
	int t,n;
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		cin >> n;
		cout << n/2 << "\n";
	}	
} 
