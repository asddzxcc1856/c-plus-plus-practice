#include <iostream>
using namespace std;

// a + c = x1 
// a + b = x2 
// b + c = x3;
// µ¹©w a if(a + c == x1 && a + b == x2 )  
int main ()
{
	int a,b,c;
	cin >> a >> b >> c;
	int all = a + b + c;
	bool ok = false;
	for(int i = 0 ; i <= a && ok == false ; i++)
	{
		int j = b - i; 
		int k = c - j;
		if(i >= 0 && j >= 0 && k >= 0 && i + k == a && i + j == b && j + k == c)
		{
			cout << i << " " << j << " " << k << "\n";
			ok = true;
			break;	
		}
		j = a - i; 
		if(i >= 0 && j >= 0 && k >= 0 && i + j == a && i + k == b && k + j == c)
		{
			cout << i << " " << k << " " << j << "\n";
			ok = true;	
			break;	
		}
		j = c - i; 
		k = b - j;
		if(i >= 0 && j >= 0 && k >= 0 && k + i == a && k + j == b && j + i == c)
		{
			cout << k << " " << j << " " << i << "\n";
			ok = true;
			break;		
		}
		j = a - i; 
		if(i >= 0 && j >= 0 && k >= 0 && j + i == a && j + k == b && k + i == c)
		{
			cout << j << " " << k << " " << i << "\n";
			ok = true;	
			break;	
		}
		j = b - i; 
		k = c - i;
		if(i >= 0 && j >= 0 && k >= 0 && j + k == a && j + i == b && i + k == c)
		{
			cout << j << " " << i << " " << k << "\n";
			ok = true;	
			break;	
		}
		j = c - i; 
		k = b - i;
		if(i >= 0 && j >= 0 && k >= 0 && k + j == a && k + i == b && i + j == c)
		{
			cout << k << " " << i << " " << j << "\n";
			ok = true;	
			break;	
		}
	}
	if(ok == false)
		cout << "Impossible\n";
}
