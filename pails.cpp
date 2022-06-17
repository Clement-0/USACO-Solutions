#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define f first
#define s second
#define mp make_pair

int X, Y, K, M, visited[101][101], best=2e9;

void bfs() {
    queue<pi> q;
    q.push(mp(0, 0));
    q.push(mp(-1, -1));
    int k=0;
    while (k<K+1 && !q.empty()) {
        pi v = q.front();
        q.pop();
        if (v.f==-1 && v.s==-1) {
            ++k;
            q.push(mp(-1, -1));
            continue;
        }
        if (visited[v.f][v.s])
            continue;
        visited[v.f][v.s]=1;
        best=min(best, abs(M-(v.f+v.s)));
        // cout << v.f << " " << v.s << endl;
        q.push(mp(X, v.s));
        q.push(mp(v.f, Y));
        q.push(mp(0, v.s));
        q.push(mp(v.f, 0));
        int xf, yf;
        if (v.f+v.s>X) {
            xf=X;
            yf=v.f+v.s-X;
        }
        else {
            xf=v.f+v.s;
            yf=0;
        }
        // cout << v.f << " " << v.s << " " << xf << " " << yf << endl;
        q.push(mp(xf, yf));
        if (v.f+v.s>Y) {
            yf=Y;
            xf=v.f+v.s-Y;
        }
        else {
            yf=v.f+v.s;
            xf=0;
        }
        // cout << v.f << " " << v.s << " " << xf << " " << yf << endl;
        q.push(mp(xf, yf));
    }
}

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    fin >> X >> Y >> K >> M;
    bfs();
    fout << best;
    fout.close();
    return 0;
}