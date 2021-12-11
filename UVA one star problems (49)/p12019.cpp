#include <iostream>
using namespace std;

string s[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int d[13][32],i,j,t,a,b,n;
int day[13] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main ()
{
	t = 6;
	for(i = 1 ; i <= 12 ; i++)
	{
		for(j = 1 ; j <=day[i] ; j++)
		{
			if(t==7)
				t = 0;
			d[i][j] = t;
			t++;
		}
	}
	
	cin >> n;
	for(i = 0 ; i < n ; i++)
	{
		cin >> a >> b;
		cout << s[d[a][b]] << "\n";
	}
    return 0;
}

