#include <iostream>
using namespace std;

int main ()
{
	int n;
	char ch;
	int B = 0,G = 0,R = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> ch;
		if(ch == 'B')
			B++;
		else if (ch == 'G')
			G++;
		else
			R++;
	}	
	if((B >= 1 && G == 0 && R == 0) || (B == 0 && G == 1 && R == 1))
	{
		cout << "B\n";
	}
	else if((B == 0 && G >= 1 && R == 0) || (B == 1 && G == 0 && R == 1))
	{
		cout << "G\n";
	}
	else if((B == 0 && G == 0 && R >= 1) || (B == 1 && G == 1 && R == 0))
	{
		cout << "R\n";
	}
	else if(B >= 2 && G == 1 && R == 0)
	{
		cout << "GR\n";
	}
	else if(B >= 2 && G == 0 && R == 1)
	{
		cout << "GR\n";
	}
	else if(B == 1 && G >= 2 && R == 0)
	{
		cout << "BR\n";
	}
	else if(B == 0 && G >= 2 && R == 1)
	{
		cout << "BR\n";
	}
	else if(B == 1 && G == 0 && R >= 2)
	{
		cout << "BG\n";
	}
	else if(B == 0 && G == 1 && R >= 2)
	{
		cout << "BG\n";
	}
	else
	{
		cout << "BGR\n";
	}
} 
