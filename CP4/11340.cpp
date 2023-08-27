#include <iostream>
#include <iomanip>
using namespace std;

int t[128];
string str;

int main ()
{
	
	int N;
	cin >> N;
	for(int k = 0 ; k < N ; k++)
	{
		int K;
		cin >> K;
		for(int i = 0 ; i < 128 ; i++)
			t[i] = 0;
		for(int i = 0 ; i < K ; i++)
		{
			char alpha;
			int value;
			cin >> alpha >> value;
			t[alpha] = value;
		}	
		int M,cost = 0;
		cin >> M;
		getline(cin,str);
		for(int i = 0 ; i < M ; i++)
		{
			getline(cin,str);
			for(int j = 0 ; j < str.length() ; j++)
			{
				if(str[j] >= 0 && str[j] < 128)
					cost += t[str[j]];
			}
		}
		cout << fixed << setprecision(2) << (double)cost/100 << "$\n";
	}	
} 
