#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair

map<char, vector<int>> cdir = {{'N', {0, -1}}, {'E', {1, 0}}, {'S', {0, 1}}, {'W', {-1, 0}}};
int N, farm[2005][2005];

void dfs(int i, int j) {
    queue<pi> q;
    q.push(mp(i, j));
    while (!q.empty()) {
        pi cur = q.front();
        q.pop();
        if (cur.f<0 || cur.s<0 || cur.f>=2005 || cur.s>=2005) continue;
        if (farm[cur.f][cur.s]) continue;
        farm[cur.f][cur.s] = 1;
        q.push(mp(cur.f+1, cur.s));
        q.push(mp(cur.f-1, cur.s));
        q.push(mp(cur.f, cur.s+1));
        q.push(mp(cur.f, cur.s-1));
    }
    return;
}

int main() {
    ofstream fout("gates.out");
    ifstream fin("gates.in");

    fin >> N;
    int r = 1002, c = 1002, ans = -1;
    for (int i = 0; i<N; ++i) {
        farm[r][c] = 1;
        char temp; fin >> temp;
        r += cdir[temp][1];
        c += cdir[temp][0];
        farm[r][c] = 1;
        r += cdir[temp][1];
        c += cdir[temp][0];
    }

    for (int i = 0; i<2005; ++i)
        for (int j = 0; j<2005; ++j)
            if (farm[i][j]==0) {
                ++ans;
                dfs(i, j);
            }

    fout << ans;
    return 0;
}