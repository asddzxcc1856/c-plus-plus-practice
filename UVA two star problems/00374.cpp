#include <iostream>
#include <map>
using namespace std;

unsigned long long int mo(unsigned long long int b, unsigned long long int p,unsigned long long int m)
{
	if(p == 0)
		return 1;
	else if (p == 1)
		return b;
	else if (p % 2 == 0)
	{
		unsigned long long int result = mo(b,p/2,m)%m;
		return (result * result)%m;
	}
	else
	{
		unsigned long long int result = mo(b,(p-1)/2,m)%m;
		return (result * result * (b%m))%m;
	}
} 

int main ()
{
	unsigned long long int b,p,m;
	while(cin >> b >> p >> m)
	{
		unsigned long long int result = mo(b,p,m);
		cout << result << "\n"; 
	}
}
