#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
#define f first
#define s second
#define mp make_pair

struct cmp { bool operator() (pi a, pi b) { return a.s<b.s; } };

int main() {
    ofstream fout("split.out");
    ifstream fin("split.in");

    ll N; fin >> N;
    ll top[N+1], bot[N+1], lef[N+1], rig[N+1];
    pi cows[N];
    for (pi &cow : cows)
        fin >> cow.f >> cow.s;
    sort(cows, cows+N);
    
    ll t=2147483647, b=0, l=2147483647, r=0;
    top[0] = 0;
    // top[1] = 1;
    for (ll i=1; i<=N; ++i) {
        t = min(t, cows[i-1].f);
        b = max(b, cows[i-1].f);
        l = min(l, cows[i-1].s);
        r = max(r, cows[i-1].s);
        top[i] = (b-t)*(r-l);
        // cout << i << ": " << t << " " << b << " " << l << " " << r << endl;
    }
    t=2147483647, b=0, l=2147483647, r=0;
    bot[N] = 0;
    for (ll i=N-1; i>=0; --i) {
        t = min(t, cows[i].f);
        b = max(b, cows[i].f);
        l = min(l, cows[i].s);
        r = max(r, cows[i].s);
        bot[i] = (b-t)*(r-l);
    }

    sort(cows, cows+N, cmp());
    // for (pi c : cows)
    //     cout << c.f << " " << c.s << endl;

    t=2147483647, b=0, l=2147483647, r=0;
    lef[0] = 0;
    for (ll i=1; i<=N; ++i) {
        t = min(t, cows[i-1].f);
        b = max(b, cows[i-1].f);
        l = min(l, cows[i-1].s);
        r = max(r, cows[i-1].s);
        lef[i] = (b-t)*(r-l);
    }
    t=2147483647, b=0, l=2147483647, r=0;
    rig[N] = 0;
    for (ll i=N-1; i>=0; --i) {
        t = min(t, cows[i].f);
        b = max(b, cows[i].f);
        l = min(l, cows[i].s);
        r = max(r, cows[i].s);
        rig[i] = (b-t)*(r-l);
    }

    // for (ll i : top) cout << i << " "; cout << endl;
    // for (ll i : bot) cout << i << " "; cout << endl;
    // for (ll i : lef) cout << i << " "; cout << endl;
    // for (ll i : rig) cout << i << " "; cout << endl;

    ll minA = 9223372036854775807;
    for (ll i=0; i<=N; ++i) {
        minA = min(minA, top[i]+bot[i]);
        minA = min(minA, lef[i]+rig[i]);
    }
    fout << bot[0]-minA;
    fout.close();
    return 0;
}
