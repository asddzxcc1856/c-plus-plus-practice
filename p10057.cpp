#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;

    while (cin >> n){
        vector<int> num;
        
        int tmp;
        for (int i = 0; i < n; i++){
            cin >> tmp;
            num.insert(num.end(), tmp);
        }

        sort(num.begin(), num.end());

        // find the minimum median in the sequence
        int minMedian = 0;
        int maxMedian = 0;
        if (n % 2 == 0){ // if n is even, the median of num is num[n/2] and num[(n/2)-1]
            minMedian = num[(n/2)-1];
            maxMedian = num[n/2];
        } else { // if n is odd, the median of num is num[n/2]
            minMedian = num[n/2];
            maxMedian = num[n/2];
        }

        // find the amount of number equal to the median in the sequence
        int count = 0;
        for (int i = 0; i < n; i++){
            if (num[i] == minMedian || num[i] == maxMedian){
                count++;
            }
        }

        // find the amount of possible different integer can be the median of sequence
        int possibleMedian = 0;
        if (n % 2 == 0){
            possibleMedian = maxMedian - minMedian + 1; // the amount between two medians
        } else {
            possibleMedian = 1;
        }
        
        cout << minMedian << " " << count << " " << possibleMedian << endl;
    }
    return 0;
}
