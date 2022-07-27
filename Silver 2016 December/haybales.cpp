#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout("haybales.out");
    ifstream fin("haybales.in");

    int N, Q;
    fin >> N >> Q;
    int pos[N];
    for (int i=0; i<N; ++i)
        fin >> pos[i];
    sort(pos, pos+N);
    for (int i=0; i<Q; ++i) {
        int A, B;
        fin >> A >> B;
        fout << upper_bound(pos, pos+N, B)-lower_bound(pos, pos+N, A) << endl;
    }
    return 0;
}
