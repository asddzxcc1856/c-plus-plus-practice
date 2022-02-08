#include <iostream>
#include <map>
#include <cstring>
#include <vector>
using namespace std;



int c[200005][2];


int main ()
{
	int t;
	cin >> t;
	int l,r;
	map<int,int> ma1,ma2;
	vector<int> v1,v2;
	if(t%2 == 0)
	{
		for(int k = 0 ; k < t ; k++)
		{
			cin >> c[k][0] >> c[k][1];
			if(c[k][0] == 0)
				l = k;
			if(c[k][1] == 0)
				r = k;
			if(c[k][0] != 0)
				ma1[c[k][0]] = k;
			if(c[k][1] != 0)	
				ma2[c[k][1]] = k;
		}
		v2.push_back(c[r][0]);
		while(ma2.find(c[r][0]) != ma2.end())
		{	
			r = ma2[c[r][0]];
			v2.push_back(c[r][0]);		
		}
		v1.push_back(c[l][1]);
		while(ma1.find(c[l][1]) != ma1.end())
		{
			l = ma1[c[l][1]];
			v1.push_back(c[l][1]);
		}	
		for(int i = v1.size() - 1 ,j = 0; i>=1 ; i--,j++)
		{
			cout << v2[i] << " " << v1[j] << " ";
		}
	
		cout << v2[0] << " " << v1[v1.size() - 1] << "\n"; 
	}
	else if (t != 3)
	{
		map<int,int> ma3;
		for(int k = 0 ; k < t ; k++)
		{
			cin >> c[k][0] >> c[k][1];
			if(c[k][0] == 0)
				l = k;
			if(c[k][0] != 0)
				ma1[c[k][0]] = k;
			if(c[k][1] != 0)	
				ma2[c[k][1]] = k;
			ma3[c[k][1]]++;
			ma3[c[k][0]]++;
		}
		int ll = 0,rr = 0;
		for(map<int,int>::iterator it = ma3.begin() ; it != ma3.end() ; it++)
		{
			if(it->second == 1 && ll == 0)
				ll = it->first;
			else if(it->second == 1)
				rr = it->first;
		}
		for(int k = 0 ; k < t ; k++)
		{
			if(c[k][1] == ll)
			{
				r = k;
				break;
			}
			if(c[k][1] == rr)
			{
				r = k;
				break;
			}
		}
		v2.push_back(c[r][1]);
		while(ma2.find(c[r][0]) != ma2.end())
		{	
			r = ma2[c[r][0]];
			v2.push_back(c[r][1]);		
		}
		v2.push_back(c[r][0]);
		v1.push_back(c[l][1]);
		while(ma1.find(c[l][1]) != ma1.end())
		{
			l = ma1[c[l][1]];
			v1.push_back(c[l][1]);
		}
		v1.pop_back();
		for(int i = 0 ,j = v2.size() - 1; i < v1.size() ; i++,j--)
		{
			cout << v2[j] << " " << v1[i] << " ";
		}
	
		cout << v2[0] << "\n";  
	}
	else
	{
		map<int,int> ma3;
		for(int k = 0 ; k < t ; k++)
		{
			cin >> c[k][0] >> c[k][1];
			if(c[k][0] == 0)
				l = k;
			if(c[k][0] != 0)
				ma1[c[k][0]] = k;
			if(c[k][1] != 0)	
				ma2[c[k][1]] = k;
			ma3[c[k][1]]++;
			ma3[c[k][0]]++;
		}
		int ll = 0,rr = 0;
		for(map<int,int>::iterator it = ma3.begin() ; it != ma3.end() ; it++)
		{
			if(it->second == 1 && ll == 0)
				ll = it->first;
			else if(it->second == 1)
				rr = it->first;
		}
		for(int k = 0 ; k < t ; k++)
		{
			if(c[k][1] == ll)
			{
				r = k;
				break;
			}
			if(c[k][1] == rr)
			{
				r = k;
				break;
			}
		}
		v2.push_back(c[r][0]);
		while(ma2.find(c[r][0]) != ma2.end())
		{	
			r = ma2[c[r][0]];
			v2.push_back(c[r][0]);		
		}
		v2.push_back(c[r][1]);
		v1.push_back(c[l][1]);
		while(ma1.find(c[l][1]) != ma1.end())
		{
			l = ma1[c[l][1]];
			v1.push_back(c[l][1]);
		}
		v1.pop_back();
		for(int i = v1.size() - 1 ,j = 0; i>=0 ; i--,j++)
		{
			cout << v2[j] << " " << v1[i] << " ";
		}
	
		cout << v2[v2.size() - 1] << "\n"; 
	}
	
	
}
