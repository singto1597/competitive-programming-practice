#include <bits/stdc++.h>

using namespace std;

vector<int> adj_list[100005];
bool visited[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, edges;
    cin >> n >> edges;

    for (int i = 1; i <= edges; i++){
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }

    int count = 0;

    vector<int> lead_node;

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            lead_node.push_back(i);
            count++;
            visited[i] = 1;

            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int temp = q.front();

                q.pop();

                for (int x : adj_list[temp]){
                    if (!visited[x]){
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
    }
    cout << count - 1<< endl;
    for (int i = 0; i < (int)lead_node.size() - 1; i++){
        cout << lead_node[i] << " " << lead_node[i + 1] << endl;
    }
}
