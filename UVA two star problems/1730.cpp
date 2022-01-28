#include <iostream>
#include <cstring>
using namespace std;

long long int ans[20000001];

int main ()
{
	int n;
	memset(ans,0,sizeof(ans));
	for(int i = 2 ; i < 20000001 ;i++)
	{
		for(int j = i ; j < 20000001 ; j+=i)
		{
			ans[j] += i;
		} 
		
		ans[i] += ans[i - 1] + 1;
	}
	while(cin >> n,n)
	{
		cout << ans[n] << "\n";	
	}
}
