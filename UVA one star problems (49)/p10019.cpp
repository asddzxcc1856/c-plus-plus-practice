#include <iostream>
using namespace std;


int n,num,bh,bd;

int main ()
{
	
	cin >> n;
	
	for (int k = 0 ; k < n ; k++)
	{
		
		
		cin >> num;
		
		bh = 0;
		bd = 0;
		
		for(int i = 1 ; i <= num ; i<<=1)
			if(num & i)
				bd++;
				
		while(num!=0)
		{
			int num2 = num%10;
			for(int i = 1 ; i <= num2 ; i<<=1)
				if(num2&i)
					bh++;
			num /= 10;
		}
		
		cout << bd << " " << bh << "\n";
	}
	
	return 0;
}


