#include <iostream>
#include <cctype>
#include <map>
using namespace std;

int main ()
{	 
	string cs1=" `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	
	string str;
	
	while(getline(cin,str))
	{
		for(int i = 0 ; i < str.length() ; i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i] = tolower(str[i]);
			for(int j = 0 ; j < cs1.length() ; j++)
			{
				if(str[i] == cs1[0])
				{
					cout << " ";
					break;
				}
				else if (str[i]==cs1[j])
				{
					cout << cs1[j-2];
					break;
				}
			}
			
		}
		cout<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
    return 0;
}

