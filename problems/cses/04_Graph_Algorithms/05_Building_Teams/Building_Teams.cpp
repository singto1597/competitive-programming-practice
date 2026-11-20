#include <bits/stdc++.h>

using namespace std;

int teams[100005];

vector<int> adj_list[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (teams[i]){
            continue;
        }

        queue<int> q;
        q.push(i);
        teams[i] = 1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for (int x : adj_list[temp]){
                if (teams[temp] == teams[x]){
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
                if (teams[x]) continue;
                q.push(x);
                if (teams[temp] == 1){
                    teams[x] = 2;

                }
                else{
                    teams[x] = 1;
                }




            }
        }


    }

    for (int i = 1; i <= n; i++){
        cout << teams[i] << " ";
    }

}
