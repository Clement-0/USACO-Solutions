#include <bits/stdc++.h>
using namespace std;

int N, M, comps, comp[3001];
vector<int> adj[3001];
int removed[3001];

void dfs(int u, int color) {
    comp[u]=color;
    for (int v : adj[u])
        if (!removed[v] && !comp[v]) dfs(v, color);
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    fin >> N >> M;
    for (int i=0; i<M; ++i) {
        int a, b; fin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<N; ++i)
        if (!comp[i]) dfs(i, ++comps);
    if (comps==1) fout << "YES\n";
    for (int i=0; i<N-1; ++i) {
        int temp; fin >> temp;
        adj[temp-1].clear();
        removed[temp-1]=1;
        comps=0;
        for (int i=0; i<N; ++i) comp[i]=0;
        for (int i=0; i<N; ++i)
            if (!removed[i] && !comp[i]) dfs(i, ++comps);
        if (comps==1) fout << "YES\n";
        else fout << "NO\n";
    }
    return 0;
}