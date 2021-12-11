#include <iostream>
#include <vector>
using namespace std;

long long int a,b;
bool ok;
vector<long long int> v;
bool fi;

int main()
{
    while(cin >> a >> b)
    {
        if(a == 0 || a<b || a<=1 || b <= 1)
            ok = false;
        else
            ok = true;
        v.clear();
        while(a>0&&ok)
        {
            if(a == 1)
            {
                v.push_back(a);
                break;
            }
            else if(a%b==0)
            {
                v.push_back(a);
                a/=b;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            for(int i = 0 ; i < v.size() - 1; i++)
            {
                cout << v[i] << " ";
            }
            cout << v[v.size() - 1];
        }
        else
        {
            cout << "Boring!";
        }
        cout << "\n";
    }
    return 0;
}
