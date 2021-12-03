#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

int c[505],t,k,num,i;
double mid,d;


int main ()
{
	cin >> t;
	//FILE *f;
	//f = freopen("out.txt","w",stdout);
	for(k = 0 ; k < t ; k++)
	{
		cin >> num;
		for(i = 0 ; i < num ; i++)
			cin >> c[i];
		sort(c,c+num);
		if(num%2==0)
		{
			mid = ((c[num / 2] + c[num / 2 - 1]) / 2);
			d = 0;
			for(i = 0 ; i < num ; i++)
			{
				d += abs(c[i] - mid);
			}
		}
		else
		{
			mid = c[num / 2];
			d = 0;
			for(i = 0 ; i < num ; i++)
			{
				d += abs(c[i] - mid);
			}
		}
		cout << (int)d << "\n";
	}
	//fclose(f);
    return 0;
}

