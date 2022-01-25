#include <iostream>
#include <cstring>
using namespace std;

int depth,l;
int temp;
int t;
int main ()
{
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> t;
	for(int k = 0 ; k < t ; k++)
	{
		
		cin >> depth >> l;
		l-=1;
		temp = 1;
		for(int j = 0 ; j < depth - 1; j++)
		{
			int next = l%2;
			l/=2;
			if(next == 0)
			{	
				temp = temp * 2;
			}
			else
			{
				temp = temp * 2 + 1;
			}
		} 
		cout << temp << "\n"; 
	}
}
