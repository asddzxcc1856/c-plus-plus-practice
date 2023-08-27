#include <bits/stdc++.h>
using namespace std;

set<int> L,R,S;
set<int> tmpset1;
set<int> tmpset2;

int main ()
{
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++)
	{
		int l,r,s;
		cin >> l >> r >> s;
		L.clear();
		R.clear();
		S.clear();
		for(int i = 0 ; i < l ; i++)
		{
			int tmp;
			cin >> tmp;
			L.insert(tmp);
		}
		for(int i = 0 ; i < r ; i++)
		{
			int tmp;
			cin >> tmp;
			R.insert(tmp);
		}
		for(int i = 0 ; i < s ; i++)
		{
			int tmp;
			cin >> tmp;
			S.insert(tmp);
		}
		cout << "Case #" << t << ":\n";
		tmpset1.clear();
		set_union(R.begin(),R.end(),S.begin(),S.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(L.begin(),L.end(),tmpset1.begin(),tmpset1.end(),inserter(tmpset2,tmpset2.begin()));
		cout << tmpset2.size();
		tmpset1.clear();
		set_intersection(R.begin(),R.end(),S.begin(),S.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(tmpset1.begin(),tmpset1.end(),L.begin(),L.end(),inserter(tmpset2,tmpset2.begin()));
		cout << " " << tmpset2.size() << "\n";
		
		tmpset1.clear();
		set_union(L.begin(),L.end(),S.begin(),S.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(R.begin(),R.end(),tmpset1.begin(),tmpset1.end(),inserter(tmpset2,tmpset2.begin()));
		cout << tmpset2.size();
		tmpset1.clear();
		set_intersection(L.begin(),L.end(),S.begin(),S.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(tmpset1.begin(),tmpset1.end(),R.begin(),R.end(),inserter(tmpset2,tmpset2.begin()));
		cout << " " << tmpset2.size() << "\n";
		
		tmpset1.clear();
		set_union(R.begin(),R.end(),L.begin(),L.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(S.begin(),S.end(),tmpset1.begin(),tmpset1.end(),inserter(tmpset2,tmpset2.begin()));
		cout << tmpset2.size();
		tmpset1.clear();
		set_intersection(R.begin(),R.end(),L.begin(),L.end(),inserter(tmpset1,tmpset1.begin()));
		tmpset2.clear();
		set_difference(tmpset1.begin(),tmpset1.end(),S.begin(),S.end(),inserter(tmpset2,tmpset2.begin()));
		cout << " " << tmpset2.size() << "\n";
	}
}
