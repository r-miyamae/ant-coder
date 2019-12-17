#include <cstdio>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> field;
bool visited[10][10];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

void dfs(int x, int y) {
    visited[y][x] = true;
    for(int i = 0; i< 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[ny][nx]) {
            continue;
        }
        if(0 <= ny && ny < H && 0 <= nx && nx < W && field[ny][nx] != '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> H >> W;
    field.resize(H);
    for(int i=0; i < H; i++) {
        cin >> field[i];
    }
    for(int x = 0; x < W; x++) {
        for(int y = 0; y < H; y++) {
            if(field[y][x] == 's') {
                dfs(x, y);
            }
        }
    }
    for(int x = 0; x < W; x++) {
        for(int y = 0; y < H; y++) {
            if(field[y][x] == 'g') {
                if(visited[y][x]) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}