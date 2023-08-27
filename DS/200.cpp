#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[100];
set<int> se;
int in[100];
int len,n;
string str[5000],s;

void topological_ordering()
{
	queue<int> q;
	
	for(set<int>::iterator it = se.begin() ; it != se.end() ; it++)
	{
		if(in[*it] == 0)
			q.push(*it);
	}
	
	for(int i = 0 ; i < n ; i++)
	{
		if(q.empty())
			break;
		
		int now = q.front();
		q.pop();
		in[now] = -1;
		
		cout << (char)(now+'A');
		
		for(int j = 0 ; j < v[now].size() ; j++)
		{
			in[v[now][j]]--;
			if(in[v[now][j]] == 0)
			{
				q.push(v[now][j]);
			}
		}
	}
	cout << "\n";
}

int main ()
{
	len = 0;
	while(getline(cin,str[len]))
	{
		if(str[len] == "#")
			break;
		len++;
	}
	memset(in,0,sizeof(in));
	for(int i = 0 ; i < len - 1 ; i++)
	{
		for(int j = 0 ; j < str[i].length() && j < str[i + 1].length() ; j++)
		{
			if(str[i][j] != str[i + 1][j])
			{
				se.insert(str[i][j] - 'A');
				se.insert(str[i + 1][j] - 'A');
				v[str[i][j] - 'A'].push_back(str[i + 1][j] - 'A');
				break;
			}
		}
	}
	n = se.size();
	for(set<int>::iterator it = se.begin() ; it != se.end() ; it++)
	{
		for(int j = 0 ; j < v[*it].size() ; j++)
		{
			in[v[*it][j]]++;
		}
	}
	topological_ordering();
}