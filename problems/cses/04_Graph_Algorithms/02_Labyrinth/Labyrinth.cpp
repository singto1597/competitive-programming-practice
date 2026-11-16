#include <bits/stdc++.h>

using namespace std;

struct Pigad{
    int x, y;
};

char dc[4] = {'L', 'R', 'U', 'D'};
int  dx[4] = {-1 ,  1 ,  0 ,  0 };
int  dy[4] = { 0 ,  0 ,  1 , -1 };

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    Pigad start, end;

    char table[n][m];

    pair<char, Pigad> visited[n][m];


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> table[i][j];
            if (table[i][j] == 'A'){
                start.x = j;
                start.y = i;
            }
            if (table[i][j] == 'B'){
                end.x = j;
                end.y = i;
            }
            visited[i][j] = {'Z',{-1, -1}};
        }
    }

    queue<Pigad> q;
    q.push({start.x, start.y});
    visited[start.y][start.x] = {'S', {-1, -1}};

    bool isFound = false;

    while(!q.empty()){
        int temp_x = q.front().x;
        int temp_y = q.front().y;

        q.pop();

        if (table[temp_y][temp_x] == 'B'){
            isFound = true;
            break;
        }

        for (int k = 0; k < 4; k ++){
            int x = temp_x + dx[k];
            int y = temp_y + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (table[y][x] != '#' && visited[y][x].first == 'Z'){
                    q.push({x, y});
                    visited[y][x] = {dc[k], {temp_x, temp_y}};
                }
            }
        }


    }

    if (!isFound){
        cout << "NO";
        return 0;
    }

    



}
