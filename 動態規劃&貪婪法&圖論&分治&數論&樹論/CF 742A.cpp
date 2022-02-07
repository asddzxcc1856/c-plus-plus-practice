#include <iostream>
using namespace std;

int main ()
{
	int d[4] = {6,8,4,2};
	int n;
	
	cin >> n;
	
	if(n == 0)
		cout << 1 << "\n";
	else
		cout << d[n%4] << "\n";
		
	return 0;
}
