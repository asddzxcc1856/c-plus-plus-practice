#include <iostream>
#include <set>
using namespace std;

set<string> A,B,C;

int main ()
{
	int T;
	cin >> T;
	for(int k = 1 ; k <= T ; k++)
	{
		int M,N;
		cin >> M >> N;
		cin.get();
		A.clear();
		for(int i = 0 ; i < M ; i++)
		{
			string tmp;
			getline(cin,tmp);
			A.insert(tmp);
		}
		B.clear();
		for(int i = 0 ; i < N ; i++)
		{
			string tmp;
			getline(cin,tmp);
			B.insert(tmp);
		}
		C.clear();
		for(set<string>::iteratorit = A.begin() ; it != A.end() ; it++)
		{
			for(set<string>::iterator it2 = B.begin() ; it2 != B.end() ; it2++)
			{
				C.insert((*it) + (*it2));
			}
		}
		cout << "Case " << k << ": " << C.size() << "\n";
	}
} 
