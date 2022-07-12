/*
ID: Clemmie
TASK: highcard
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int N;
    fin >> N;
    
    vector<int> ePlays(N+1);
    vector<int> bCards;
    vector<bool> tempC(2*N+1, false);

    for (int i = 1; i<=N; ++i) {
        fin >> ePlays[i];
        tempC[ePlays[i]] = true;
    }
    bCards.push_back(0);
    for (int i = 1; i<=(2*N); ++i)
        if (tempC[i] == false)
            bCards.push_back(i);

    int points = 0;

    for (int i = 1; i<=N; ++i) {
        auto card_i = upper_bound(bCards.begin()+1, bCards.end(), ePlays[1]);
        if (card_i != bCards.end()) {
            ++points;
        }
        else card_i = bCards.begin() + 1;

        bCards.erase(card_i);
        ePlays.erase(ePlays.begin()+1);
    }

    fout << points << endl;
    fout.close();
    return 0;
}