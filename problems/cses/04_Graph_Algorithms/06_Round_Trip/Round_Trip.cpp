#include <bits/stdc++.h>

using namespace std;

int visited[100005];

vector<int> adj_list[100005];

bool isFound = false;

// ข้อนี้น่าจะไม่สามารถใช้ Stack DFS ได้ เพราะถ้าเจอ
//
// 1----2
// |    |
// |    |
// 3----4
//
// แล้วตอนวิ่งจาก 1 -> 3 -> 4
// แล้วไปเจอ 2 ในตอนเช็ค x
// มันจะเจอว่า 2 มีพ่อเป็น 1
// มันเลยบั๊ค เพราะ 2 ความจริงต้องมีพ่อเป็น 4 ถ้าต้องการปิดล้อมจริงๆ

int head, tail;

void dfs(int u, int p){


    visited[u] = p;

    for (int v : adj_list[u]){
        if (isFound){
            return;
        }
        if (visited[v]){
            if (v != visited[u]){
                isFound = true;
                // visited[v] = u;
                head = v;
                tail = u;
                return;
            }
            continue;
        }
        dfs(v, u);
    }
}

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

    vector<int> ans;

    for (int i = 1; i <= n; i ++){
        if (visited[i]){
            continue;
        }

        dfs(i, -1);
        if (isFound){

            break;
        }
    }

    if (!isFound){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int temp = tail;
    // cout << temp << endl;

    while(temp != head){
        ans.push_back(temp);
        temp = visited[temp];
    }
    ans.push_back(temp);
    ans.push_back(tail);

    cout << ans.size() << endl;

    for(int x : ans){
        cout << x << " ";
    }



}
