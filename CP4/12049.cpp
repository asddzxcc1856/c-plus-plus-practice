#include <iostream>
#include <set>
#include <cmath>
using namespace std;



int main()
{
	int T;
	cin >> T;
	for(int k = 1 ; k <= T ; k++)
	{
		int M,N;
		cin >> M >> N;
		multiset<int> A,B;
		for(int i = 0 ; i < M ; i++)
		{
			int a;
			cin >> a;
			A.insert(a);	
		} 
		for(int i = 0 ; i < N ; i++)
		{
			int a;
			cin >> a;
			B.insert(a);	
		} 
		int now = 0;
		int cost = 0;
		for(multiset<int>::iterator it = A.begin() ; it != A.end() ; )
		{
			int num2 = B.count(*it);
			B.erase(*it);
			int	num1 = A.count(*it);
			now = *it;
			cost += abs(num2 - num1);
			while(*it == now)
			{
				it++;
			}
		} 
		for(multiset<int>::iterator it = B.begin() ; it != B.end() ; )
		{
			int num2 = B.count(*it);
			now = *it;
			cost += num2;
			while(*it == now)
			{
				it++;
			}
		} 
		cout << cost << "\n";
	}
}
