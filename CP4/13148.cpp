#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	set<int> s1,s2;
	for(int i = 1 ; i <= 10000 ; i++)
	{
		s1.insert(i*i);
	}
	for(int i = 1 ; i <= 1000 ; i++)
	{
		s2.insert(i*i*i);
	}
	vector<int> v;
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(v));
	set<int> s3;
	for(int i = 0 ; i < v.size() ; i++)
	{
		s3.insert(v[i]);
	}
	int N;
	while(cin >> N,N)
	{
		if(s3.find(N) != s3.end())
		{
			cout << "Special\n";
		}
		else
		{
			cout << "Ordinary\n";
		}
	}
	
}
