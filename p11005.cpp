#include <iostream>
#include <map>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, cost, Q, x;
    cin >> T;
    for (int Case = 1; Case <= T; Case++){
        if (Case > 1) cout << "\n";
        map <int, int> mp;
        for (int i = 0; i < 36; i++){
            cin >> cost;
            mp[i] = cost;
        }
        cout << "Case " << Case << ":\n";
        cin >> Q;
        while (Q--){
            cin >> x;
            cout << "Cheapest base(s) for number " << x << ":";
            int mn =  0x7FFFFFFF;
            map <int,int> ans;
            for (int i = 2; i <= 36; i++){
                int n = x;
                cost = 0;
                while (n){
                    cost += mp[n % i];
                    n /= i;
                }
                ans[i] = cost;
                mn = min(mn, cost);
            }
            for (int i = 2; i <= 36; i++){
                if (ans[i] == mn) cout << " " << i;
            }
            cout << "\n";
        }
    }
    return 0;
}
