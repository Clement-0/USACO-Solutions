#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair

struct Edge {
    int a, b, w;
    Edge(int beg, int end, int weight) { a=beg; b=end; w=weight; }
    bool operator<(const Edge &e) const { return w<e.w; };
};

const int MAX_N=1000;
int N;
pi cows[MAX_N+1];
vector<Edge> adj[MAX_N+1];
int visited[MAX_N+1];

void dfs(int v, int X) {
    visited[v]=1;
    for (Edge e : adj[v])
        if (!visited[e.b] && e.w<=X)
            dfs(e.b, X);
}

bool test(int X) {
    for (int i=0; i<N; ++i)
        visited[i]=0;
    dfs(0, X);
    for (int i=0; i<N; ++i)
        if (!visited[i]) return false;
    return true;
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> N;
    for (int i=0; i<N; ++i) fin >> cows[i].f >> cows[i].s;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j)
            if (i!=j) adj[i].push_back(Edge(i, j, (cows[j].f-cows[i].f)*(cows[j].f-cows[i].f) + 
                                                  (cows[j].s-cows[i].s)*(cows[j].s-cows[i].s)));
        sort(adj[i].begin(), adj[i].end());
    }
    // for (int i=0; i<N; ++i) {
    //     for (Edge e : adj[i])
    //         cout << e.a << " " << e.b << " " << e.w << " | ";
    //     cout << endl;
    // }
    int l=0, h=1500000000;
    while (l<h) {
        int m=l+(h-l)/2;
        // cout << l << " " << m << " " << h << " " << test(m) << endl;
        if (test(m)) h=m;
        else l=m+1;
    }
    fout << l;
    return 0;
}
