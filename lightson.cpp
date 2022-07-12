#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int lit[101][101];
int visited[101][101];
vector<pi> switches[101][101];
int N, M;

void bfs() {
    queue<pi> q;
    q.push(mp(0, 0));
    visited[0][0] = lit[0][0] = 1;
    while (!q.empty()) {
        pi cur = q.front();
        q.pop();
        for (auto sw : switches[cur.f][cur.s])
            lit[sw.f][sw.s] = 1;
        for (auto d : dir) {
            if (cur.f+d[0]>=0 && cur.f+d[0]<N && cur.s+d[1]>=0 && cur.s+d[1]<N &&
                lit[cur.f+d[0]][cur.s+d[1]] && !visited[cur.f+d[0]][cur.s+d[1]]) {
                visited[cur.f+d[0]][cur.s+d[1]] = 1;
                q.push(mp(cur.f+d[0], cur.s+d[1]));
            }
        }
    }
}

int main() {
    ofstream fout("lightson.out");
    ifstream fin("lightson.in");

    fin >> N >> M;
    for (int i = 0; i<M; ++i) {
        int x, y, a, b; 
        fin >> x >> y; --x; --y;
        fin >> a >> b; --a; --b;
        switches[x][y].push_back(mp(a, b));
    }

    // for (int i = 0; i<N; ++i) {
    //     for (int j = 0; j<N; ++j) {
    //         if (switches[i][j].empty()) cout << "    | ";
    //         else cout << (switches[i][j])[0].f << " " << (switches[i][j])[0].s << " | ";
    //     }
    //     cout << endl;
    // }

    
    for (int i = 0; i<N*40; ++i) {
        for (int j = 0; j<N; ++j)
            for (int k = 0; k<N; ++k)
                visited[j][k] = 0;
        bfs();
    }

    // for (int i = 0; i<N; ++i) {
    //     for (int j = 0; j<N; ++j)
    //         cout << visited[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i<N; ++i) {
    //     for (int j = 0; j<N; ++j)
    //         cout << lit[i][j] << " ";
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<N; ++j)
            if (lit[i][j]) ++ans;
    fout << ans;
    return 0;
}