#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin >> n;

    long long sum_all = (n * (n + 1)) / 2;
    long long sum_a = 0;

    for (int i = 0; i < n - 1; i++){
        int a;
        cin >> a;
        sum_a += a;
    }
    cout << sum_all - sum_a << endl;

}
