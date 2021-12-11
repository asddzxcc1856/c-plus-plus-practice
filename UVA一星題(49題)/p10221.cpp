#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double ans1,ans2,s,a;
string str;

int main()
{
    while(cin >> s >> a >> str)
    {
        s += 6440;
        if(str == "deg")
        {
            if(a>180)
            {
                ans1 = 2.0 * s * M_PI * ((360-a)/360);
            }
            else
            {
                ans1 = 2.0 * s * M_PI * (a/360);
            }
            
            ans2 = sqrt(s*s+s*s-2*s*s*cos(a * (M_PI/180)));
            cout << fixed << setprecision(6) << ans1 << " " << ans2 << "\n";
        }
        else if (str == "min")
        {
            if(a>180)
            {
                ans1 = 2.0 * s * M_PI * ((360-a)/21600);
            }
            else
            {
                ans1 = 2.0 * s * M_PI * (a/21600);
            }
            ans2 = sqrt(s*s+s*s-2*s*s*cos(a * (M_PI/10800)));
            cout << fixed << setprecision(6) << ans1 << " " << ans2 << "\n";
        }
    }
    return 0;
}
