#include <iostream>
using namespace std;

int weight[(1 << 15)]; 
int sum[(1 << 15)]; 
int main ()
{
	int N;
	while(cin >> N)
	{
		int num = (1 << N);
		
		for(int i = 0 ; i < num ; i++)
		{
			cin >> weight[i];
		}	
		for(int i = 0 ; i < num ; i++)
		{
			sum[i] = 0;
			for(int j = 0 ; j < N ; j++)
			{
				sum[i] += weight[i ^ (1 << j)];
			}
		}
		int ans = 0;
		for(int i = 0 ; i < num ; i++)
		{
			for(int j = 0 ; j < N ; j++)
			{
				ans = max(ans, sum[i] + sum[i ^ (1 << j)]);
			}
		}
		cout << ans << "\n";
	}		
} 
