#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main ()
{
	int t;
	cin >> t;
	for (int w =1 ; w <= t ; w++)
	{
		queue<int> q;
		set<int> se;
		int n,m,k,minlen = 1000005;
		bool ok = false;
		cin >> n >> m >> k;
		q.push(1);se.insert(1);
		int n1 = 1,n2 = 2,n3 = 3,n4;
		if(se.size() == k)
		{
			ok = true;
		}
		if(ok)
		{
			int size = q.size();
			minlen = min(minlen,size);	
		} 
		q.push(2);se.insert(2);
		if(se.size() == k)
		{
			ok = true;
		}
		if(ok)
		{
			int size = q.size();
			minlen = min(minlen,size);	
		} 
		q.push(3);se.insert(3);
		if(se.size() == k)
		{
			ok = true;
		}
		if(ok)
		{
			int size = q.size();
			minlen = min(minlen,size);	
		} 
		int num[1005];
		for(int i = 0 ; i < 105 ; i++)
		{
			num[i] = 0;
		}
		num[1] = 1;
		num[2] = 1;
		num[3] = 1;
		for(int i = 0 ; i < n ; i++)
		{
			
			n4 = (n1 + n2 + n3) % m + 1;
			n1 = n2;
			n2 = n3;
			n3 = n4;
			
			if(n4 >= 1 && n4 <= k)
			{
				se.insert(n4);
			}
			
			if(se.size() == k)
			{
				ok = true;
			}
			num[n4]++;
			q.push(n4);
			while((q.size() > 0 && num[q.front()] >= 2) || (q.size() > 0 && (q.front() > k)))
			{
				num[q.front()]--;
				q.pop();
				if(q.size() == 0)
					break;
			}
			if(ok)
			{
				int size = q.size();
				minlen = min(minlen,size);	
			} 
		}
		if(ok)
			cout << "Case " << w << ": " << minlen << "\n";
		else
			cout << "Case " << w << ": " << "sequence nai\n";
	}
}