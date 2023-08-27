#include <iostream>
#include <algorithm>
using namespace std;

struct person{
	string name;
	int day;
	int month;
	int year;
};

person p[100];

bool cmp(person a,person b){
	if(a.year != b.year)
	{
		return a.year > b.year;
	}
	else if (a.month != b.month)
	{
		return a.month > b.month;
	}
	else
	{
		return a.day > b.day;
	}
}

int main ()
{
	int n;
	cin >> n;
	for(int idx = 0 ; idx < n ; idx++)
	{
		cin >> p[idx].name >> p[idx].day >> p[idx].month >> p[idx].year;
	}
	sort(p,p+n,cmp);
	cout << p[0].name << "\n" << p[n - 1].name << "\n";
}
