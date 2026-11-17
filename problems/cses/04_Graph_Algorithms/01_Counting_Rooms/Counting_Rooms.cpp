#include <bits/stdc++.h>

using namespace std;

// bool visited[1005][1005];

int  dx[4] = {-1 ,  1 ,  0 ,  0 };
int  dy[4] = { 0 ,  0 ,  1 , -1 };

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    char table[n][m];

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j++){
            cin >> table[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j++){
            if (table[i][j] == '.'){
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                table[i][j] = '#';
                while (!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0 ; k < 4; k ++){
                        int temp_y = y + dy[k];
                        int temp_x = x + dx[k];
                        if (temp_y >= 0 && temp_y < n){
                            if (temp_x >= 0 && temp_x < m){
                                if (table[temp_y][temp_x] == '.'){
                                    q.push({temp_y, temp_x});
                                    table[temp_y][temp_x] = '#';
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
}
