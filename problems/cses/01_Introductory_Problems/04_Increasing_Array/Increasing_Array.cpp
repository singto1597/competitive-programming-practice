#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    // long long arr[n + 5] = {};
    long long sum = 0;
    long long prev = 0;
    long long pres = 0;

    cin >> prev;

    for (int i = 1; i < n; i++){
        cin >> pres;
        if (pres < prev){
            sum += prev - pres;
        }
        else{
            prev = pres;
        }
    }
    cout << sum;


}
