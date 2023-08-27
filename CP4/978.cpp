#include <bits/stdc++.h>
using namespace std;

multiset<int> G,B;
vector<int> v1(100000),v2(100000);

int main ()
{
	int N;
	cin >> N;
	while(N--)
	{
		int b,SG,SB;
		cin >> b >> SG >> SB;
		for(int i = 0 ; i < SG ; i++)
		{
			int tmp;
			cin >> tmp;
			G.insert(tmp);
		}
		for(int i = 0 ; i < SB ; i++)
		{
			int tmp;
			cin >> tmp;
			B.insert(tmp);
		}
		while(true)
		{
			int cnt = 0;
			while((!G.empty()) && (!B.empty()) && cnt < b)
			{
				v1[cnt] = *G.rbegin();
				v2[cnt] = *B.rbegin();
				G.erase((++G.rbegin()).base());
				B.erase((++B.rbegin()).base());
				
				cnt++;
			}
			if(cnt == 0)
			{
				break;
			}
			for(int i = 0 ; i < cnt ; i++)
			{
				if(v1[i] > v2[i])
				{
					G.insert(v1[i] - v2[i]);
				}
				else if(v1[i] < v2[i])
				{
					B.insert(v2[i] - v1[i]);
				}
			}
		}
			
			
		if(!G.empty())
		{
			cout << "green wins\n";
			for(multiset<int>::reverse_iterator it = G.rbegin() ; it != G.rend() ; it++)
			{
				cout << *it << "\n";
			}
		}
		else if (!B.empty())
		{
			cout << "blue wins\n";
			for(multiset<int>::reverse_iterator it = B.rbegin() ; it != B.rend() ; it++)
			{
				cout << *it << "\n";
			}
		}
		else
		{
			cout << "green and blue died\n"; 
		}
		if(N != 0)
		{
			cout << "\n";
		}
		G.clear();
		B.clear();
	}
} 
