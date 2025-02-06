#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

// struct Point { int x, y; bool broken; };

int dat[1001][1001][1001];
int dis[1001][1001][1001];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        fill(dis[i], dis[i]+M, -1);

    for (int i = 0; i < N; i++) {
        string ln;
        cin >> ln;
        for (int j = 0; j < M; j++) {
            dat[i][j] = ln[j] - '0';
        }
    }

    queue<pair<int, int>> q, wq;
    q.push({0, 0});
    dis[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dis[nx][ny] != - 1) continue;
            if (dat[nx][ny] == 1) {
                wq.push({nx, ny});
                dis[nx][ny] = dis[cur.X][cur.Y] + 1;
                continue;
            }


            q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;

            // cout << nx << ',' << ny << ',' << (false ? "true" : "false") << '\n';
        }
    }

    while (!wq.empty()) {
        pair<int, int> cur = wq.front(); wq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dis[nx][ny] != - 1 || dat[nx][ny] == 1 ) continue;

            // bool broken = cur.broken;
            // if (dat[nx][ny] == 1) {
            //     if (!broken) broken = true;
            //     else         continue;
            // }

            q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;


            // cout << nx << ',' << ny << ',' << (false ? "true" : "false") << '\n';
        }
    }


    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dis[nx][ny] != - 1 || dat[nx][ny] == 1) continue;

            q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            // cout << nx << ',' << ny << ',' << (false ? "true" : "false") << '\n';
        }
    }


    int res = dis[N-1][M-1];
    cout << (res == -1 ? res : res + 1) << '\n';

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

/*
벽을 부순다
6 4
0100
1110
1000
0000
0111
0000

1. bfs 후 벽 부수는 것 처리?
벽에 닿기 전까지 bfs
 이후 각 벽에 대해 다시 bfs 하기?

2. bfs 중 벽 부수기
문제: 한 번 bfs 시행한 뒤로 다른 루트 진행이 어려움움

*/