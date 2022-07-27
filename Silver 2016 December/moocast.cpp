#include <bits/stdc++.h>
using namespace std;

struct cow { int i, j, p; };

int N;
cow cows[201];
vector<int> adj[201];
int vis[201];
int cnt = 0;

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    ++cnt;
    for (int c: adj[v])
        dfs(c);
}

int main() {
    ofstream fout("moocast.out");
    ifstream fin("moocast.in");

    fin >> N;
    for (int i=0; i<N; ++i)
        fin >> cows[i].i >> cows[i].j >> cows[i].p;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) if (i!=j) {
            if ((cows[j].i-cows[i].i)*(cows[j].i-cows[i].i)+(cows[j].j-cows[i].j)*(cows[j].j-cows[i].j) <= cows[i].p*cows[i].p)
                adj[i].push_back(j);
        }
    }

    int ans=0;
    for (int i=0; i<N; ++i) {
        dfs(i);
        ans = max(ans, cnt);
        cnt = 0;
        for (int j=0; j<N; ++j)
            vis[j] = 0;
    }
    fout << ans;
    return 0;
}
