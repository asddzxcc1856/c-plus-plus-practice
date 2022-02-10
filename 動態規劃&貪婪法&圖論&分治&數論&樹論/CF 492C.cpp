#include <iostream>
#include <algorithm>
using namespace std;

struct s{
	long long int a;
	long long int b;
};

s c[100005];
long long int n;
long long int r,avg;

bool cmp(s a,s b)
{
	if(a.b != b.b)
		return a.b < b.b;
	else
		return a.a < b.a;
}

int main ()
{
	bool win = false;
	long long int sum = 0;
	cin >> n >> r >> avg;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> c[i].a >> c[i].b;
		sum += c[i].a;
		if(sum/n >= avg)
		{
			win = true;
		}
	}
	
	sort(c,c+n,cmp);
	
	long long int cnt = 0;
	for(int i = 0 ; i < n && win == false; i++)
	{
		if(sum/n >= avg)
		{
			win = true;
			break;
		}
		if(c[i].a < r)
		{
			if((sum + r - c[i].a)/n < avg)
			{
				sum += (r - c[i].a);
				cnt += c[i].b * (r - c[i].a);
			}
			else
			{
				cnt += c[i].b * (avg * n - sum);
				sum += (avg * n - sum);
				
			}
		}
		
	}
	cout << cnt << "\n";
	return 0;
} 
