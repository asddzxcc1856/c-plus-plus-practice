#include <iostream>
using namespace std;

int sum,temp,maxn;
int i;
string ch;

int main ()
{
	while(getline(cin,ch))
	{
		sum = 0;
		maxn = 1;
		for (i = 0 ; i < ch.length() ; i++)
		{
			if (ch[i] >= '0' && ch[i] <= '9') {
                temp = ch[i] - '0';
            }
            else if (ch[i] >= 'A' && ch[i] <= 'Z') {
                temp = ch[i] - 'A' + 10;
            }
            else if (ch[i] >= 'a' && ch[i] <= 'z') {
                temp = ch[i] - 'a' + 36;
            }
            else continue;
 
            if (maxn < temp)
                maxn = temp;
            sum += temp;	
		}
		
		for (i = maxn ; i < 62 ; i++)
		{
			if((sum%i)==0)
			{
				cout << i + 1 << "\n";
				break;
			}
		}
		
		if (i == 62)
		{
			cout << "such number is impossible!\n";
		}
	}
	
    return 0;
}

