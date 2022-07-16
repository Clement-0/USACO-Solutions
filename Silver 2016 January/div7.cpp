#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, ans, cows[50001], pre[50001], ind[7][2];

int main() {
    ofstream fout("div7.out");
    ifstream fin("div7.in");

    fin >> N;
    for (int i = 0; i<7; ++i) {ind[i][0] = 100000; ind[i][1] = -1;}
    for (ll i = 1; i<=N; ++i) {
        fin >> cows[i];
        pre[i] = (pre[i-1]+cows[i])%7;
        ind[pre[i]][0] = min(ind[pre[i]][0], i);
        ind[pre[i]][1] = max(ind[pre[i]][1], i);
    }

    for (int i = 0; i<N; ++i)
        ans = max(ans, ind[pre[i]][1]-ind[pre[i]][0]);
    fout << ans;
    return 0;
}