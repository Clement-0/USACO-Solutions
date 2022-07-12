#include <bits/stdc++.h>
using namespace std;

int N, Q, pre[100001][3], cnt[3], temp;

int main() {
    ofstream fout("bcount.out");
    ifstream fin("bcount.in");
    
    fin >> N >> Q;
    for (int i = 1; i<=N; ++i) {
        fin >> temp;
        ++cnt[temp-1];
        for (int j = 0; j<3; ++j)
            pre[i][j] = cnt[j];
    }

    for (int i = 0; i<Q; ++i) {
        int a, b; fin >> a >> b; --a;
        fout << pre[b][0]-pre[a][0] << " " << pre[b][1]-pre[a][1] << " " << pre[b][2]-pre[a][2] << endl;
    }
}