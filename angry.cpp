#include <bits/stdc++.h>
using namespace std;

int N, K;
int bales[50001];

bool test(int R) {
    int closest = bales[0];
    int j=0;
    for (int i=0; i<K; ++i) {
        while (bales[j] <= closest+2*R && j<N) ++j;
        closest = bales[j];
    }
    if (j>=N) return true;
    return false;
}

int main() {
    ofstream fout("angry.out");
    ifstream fin("angry.in");

    fin >> N >> K;
    for (int i=0; i<N; ++i)
        fin >> bales[i];
    sort(bales, bales+N);
    int l=0, h=1000000001;
    while (l<h) {
        int m = (l+h)/2;
        if (test(m)) h = m;
        else l = m+1;
    }
    fout << l;
    fout.close();
    return 0;
}