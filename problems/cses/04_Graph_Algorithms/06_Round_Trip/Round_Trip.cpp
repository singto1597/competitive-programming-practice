#include <bits/stdc++.h>

using namespace std;

int visited[100005];

vector<int> adj_list[100005];

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

    bool isFound = false;

    for (int i = 1; i <= n; i++){
        stack<int> s;
        s.push(i);
        visited[i] = -1;

        int count = 1;

        vector<int> path;

        while(!s.empty() && !isFound){
            int temp = s.top();
            s.pop();

            for (int x : adj_list[temp]){
                if (visited[x] != 0){
                    if (x != visited[temp]){

                        isFound = true;
                        cout << path.size() << endl;
                        visited[i] = temp;
                        int temp_p = x;

                        while(visited[temp_p] != -1){
                            cout << temp_p << " " << visited[temp_p] << endl;
                            temp_p = visited[temp_p];
                        }


                        return 0;
                        break;

                    }
                    else{
                        continue;
                    }
                }
                s.push(x);

                visited[x] = temp;
            }
        }

        if (isFound) break;
    }




}
