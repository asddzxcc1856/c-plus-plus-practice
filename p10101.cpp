#include <iostream>
#include <iomanip>
using namespace std;

long long int num;
int t;
long long int c[4] = {10000000,100000,1000,100};
string s[4] = {"kuti", "lakh", "hajar", "shata"};

void rec(long long int n)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(n>=c[i])
        {
            rec(n/c[i]);
            cout << " " << s[i];
            n%=c[i];
        }
    }
    if(n)
    {
        cout << " " << n;
    }
}

int main ()
{
	freopen("out-p10101.txt","w",stdout);
    t = 1;
    while(cin >> num)
    {
        
        cout << setw(4) << t++ << ".";
        if(num == 0)
        {
            cout << " 0\n";
            continue;
        }
        rec(num);
        //999999999999999
        //’kuti’ (10000000), ’lakh’ (100000), ’hajar’ (1000), ’shata’ (100)
        cout << "\n";
    }
}
