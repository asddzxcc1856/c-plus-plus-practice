#include <iostream>
using namespace std;

bool n1,n2;
int i;
string str;

int main ()
{
	bool n1 = false;
	while(getline(cin,str))
	{
		
		for(i = 0 ; i < str.length() ; i++)
		{
			if(str[i] == '"' && n1 == false)
			{
				n1 = true;
				str[i] = '`';
				str.insert(i,"`");
				i++;
			}
			if(str[i] == '"' && n1 == true)
			{
				n1 = false;
				str[i] = '\'';
				str.insert(i,"'");
				i++;
			}
		}
		cout << str << "\n";
	}
	

    return 0;
}

