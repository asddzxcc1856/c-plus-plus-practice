#include <iostream>
using namespace std;

/*
-----in-----
2
RB

-----out------
G

-----in-----
3
GRG

-----out------
BR

-----in-----
5
BBBBB

-----out------
B

-----in-----
5
BBBBG

-----out------
GR

-----in-----
6
BBBBBG

-----out------
GR

-----in-----
5
BBBGG

-----out------
BGR

-----in-----
5
BBGG

-----out------
BRG

*/

/*
 --------------
 B>=1 G==0 R==0
 cout << B
 B==0 G>=1 R==0
 cout << G
 B==0 G==0 R>=1
 cout << R
 B==1 G==1 R==0
 cout << R
 B==0 G==1 R==1
 cout << B
 B==1 G==0 R==1
 cout << G
 --------------
 B==1 G==2 R==0
 cout << BR
 B==2 G==1 R==0
 cout << GR
 B==2 G==0 R==1
 cout << GR
 B==0 G==2 R==1
 cout << BR
 B==0 G==1 R==2
 cout << BG
 B==1 G==0 R==2
 cout << BG
 --------------
 other
  BGR
*/

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
