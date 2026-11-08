#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;

    long long size = s.size();

    long long max_long = 0;
    long long long_s = 0;

    if (size < 2){
        cout << size << endl;
        return 0;
    }

    for (int i = 0; i < size - 1; i++){
        if (s[i] == s[i + 1]){
            long_s++;
            max_long = max(max_long, long_s);
        }
        else{
            long_s = 0;
        }
    }

    cout << max_long + 1 << endl;

}
