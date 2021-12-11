#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n,j,cnt;
int c[3005];
bool f[3005];

int main ()
{
	while(cin >> n)
	{
		memset(f,false,sizeof(f));
		for(j = 0 ; j < n ; j++)
		{
			cin >> c[j];
		}
		cnt = 0;
		for(j = 1 ; j < n ; j++)
		{
			int a = abs(c[j] - c[j - 1]);
			if(a >= 1 && a <= n-1 && f[a] == false)
			{
				f[a] = true;
				cnt++;
			}
		}
		if(cnt == n - 1)
		{
			cout << "Jolly\n";
		}
		else
		{
			cout << "Not jolly\n";
		}
	}
	
    return 0;
}

