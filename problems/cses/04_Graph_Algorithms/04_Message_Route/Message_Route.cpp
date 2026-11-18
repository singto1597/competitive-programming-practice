#include <bits/stdc++.h>

using namespace std;

int visited[100005];
vector<int> adj_list[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    queue<int> q;
    q.push(1);

    visited[1] = -1;

    while (!q.empty()){
        int temp = q.front();
        q.pop();

        for (int x : adj_list[temp]){
            if (visited[x] <= 0){
                q.push(x);
                visited[x] = temp;
            }
        }
    }

    if (visited[n] <= 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int count = 1;

    int temp = n;

    stack<int> s;

    while (temp != 1){
        count++;
        s.push(temp);
        temp = visited[temp];
    }
    s.push(1);
    cout << count << endl;

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
