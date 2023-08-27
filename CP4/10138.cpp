#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

struct node{
	int year;
	int month;
	int hour;
	int minute;
	string isBegin;	
	int point;
	friend bool operator < (const node & a, const node & b){
		if(a.month != b.month)
		{
			return a.month > b.month;
		}
		else if(a.hour != b.hour)
		{
			return a.hour > b.hour;
		}
		else if (a.minute != b.minute)
		{
			return a.minute > b.minute;
		}
	}
};

struct cmp{
	bool operator() (const string & a, const string & b){
		for(int i = 0 ; i < a.length() && i < b.length() ; i++)
		{
			if(a[i] != b[i])
			{
				return a[i] < b[i];
			}
		}
		return a.length() < b.length();
	}
};

map<string,priority_queue<node> > ma;
map<string,int, cmp> ans;
int cost[24];

int main()
{
	int T;
	cin >> T;
	for(int k = 1 ; k <= T ; k++)
	{
		if(k > 1)
			cout << "\n";
		ma.clear();
		ans.clear();
		for(int i = 0 ; i < 24 ; i++)
			cin >> cost[i];
		string str;
		getline(cin,str);
		while(getline(cin,str))
		{
			
			if(str == "")
			{
				break;
			}
			else
			{
				stringstream ss(str);
				char ch;
				string tstr;
				node tmp;
				ss >> tstr >> tmp.year >> ch >> tmp.month >> ch >> tmp.hour >> ch >> tmp.minute >> tmp.isBegin >> tmp.point;
				if(ma.find(tstr) != ma.end())
				{
					ma[tstr].push(tmp);
				}
				else
				{
					priority_queue<node> t;
					t.push(tmp);
					ma[tstr] = t;
					ans[tstr] = 0;
				}
			}
		}
		for(map<string,int,cmp>::iterator it = ans.begin() ; it != ans.end() ; it++)
		{
			while(!ma[it->first].empty())
			{
				while((!ma[it->first].empty()) && ma[it->first].top().isBegin != "enter")
				{
					
					ma[it->first].pop();
				}
				if(ma[it->first].empty())
					break;
				node tmp1;
				while((!ma[it->first].empty()) && ma[it->first].top().isBegin != "exit")
				{
					tmp1 = ma[it->first].top();
				
					ma[it->first].pop();
				}
				if(ma[it->first].empty())
					break;
				node tmp2;
				if((!ma[it->first].empty()) && ma[it->first].top().isBegin != "enter")
				{
					tmp2 = ma[it->first].top();
				
					ma[it->first].pop();
				}
				it->second += cost[tmp1.hour] * abs(tmp2.point - tmp1.point) + 100;
			}
			if(it->second != 0)
				cout << it->first << " $" << fixed << setprecision(2) << (double)(it->second + 200) / 100 << "\n";
		}
	}
}
