#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq[750];
int pre[750];
int number[750];

int main () 
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int k;
	while(cin >> k)
	{
		for(int i = 0 ; i < k ; i++)
			while(!pq[i].empty())
				pq[i].pop();
		for(int i = 0 ; i < k ; i++)
		{
			for(int j = 0 ; j < k ; j++)
			{
				int num;
				cin >> num;
				pq[i].push(num);
			}
		}
		int sum = 0;
		for(int i = 0 ; i < k ; i++)
		{
			sum += pq[i].top();
			pre[i] = pq[i].top();
			pq[i].pop();
			number[i] = 1;
			while(!pq[i].empty() && pq[i].top() == pre[i])
			{
				number[i]++;
				pq[i].pop();
			}	
		}
		int d = 1;
		for(int i = 0 ; i < k ; i++)
			d *= number[i];
		cout << sum;
		for(int i = 1 ; i < d ; i++)
			cout << " " << sum;
		for(int j = d ; j < k ; j+=d)
		{
			int idx = 0;
			int minn = 2147483647;
			for(int i = 0 ; i < k ; i++)
			{
				if(!pq[i].empty() && sum - pre[i] + pq[i].top() < minn)
				{
					minn = sum - pre[i] + pq[i].top();
					idx = i;
				}
			}
			int tmp1 = pq[idx].top();
			pq[idx].pop();
			int tmp2 = 1;
			while(!pq[idx].empty() && pq[idx].top() == tmp1)
			{
				tmp2++;
				pq[idx].pop();
			}	
			d = 1;
			for(int i = 0 ; i < k ; i++)
				if(i != idx)
					d *= number[i];
			d *= tmp2;
			for(int i = 0 ; i < d && i < (k - j) ; i++)
				cout << " " << minn;
		}
		cout << "\n";
		
	}
	
}
