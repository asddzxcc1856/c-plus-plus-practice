#include <iostream>
#include <map>
using namespace std;

int n,i;
string str1,str2;
map<string,int> ma;
map<string,bool> exist;
int main ()
{
    while(cin >> n)
    {
        for(i = 0 ; i < n ; i++)
        {
            cin >> str1;
            getline(cin,str2);
            if( exist.find(str1 + str2) != exist.end() )
            {
                continue;
            }
            else
            {
                exist[str1 + str2] = true;
                ma[str1]++;
            }
            
        }
        for(map<string,int>::iterator it = ma.begin() ; it!=ma.end() ; it++)
        {
            cout << it->first << " " << it->second << "\n";
        }
    }
}