#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const int& a, const int& b) {
        return a>b;
    }
};

int main() {
    ofstream fout("cardgame.out");
    ifstream fin("cardgame.in");

    int N; fin >> N;
    int ElsieF[N/2];
    int ElsieS[N/2];
    vector<int> tempBess;
    set<int> tempEls;
    set<int> BessieL;
    set<int, cmp> BessieS;

    for (int i = 0; i<N/2; ++i) {
        fin >> ElsieF[i];
        tempEls.insert(ElsieF[i]);
    }
    for (int i = 0; i<N/2; ++i) {
        fin >> ElsieS[i];
        tempEls.insert(ElsieS[i]);
    }
    for (auto e : tempEls)
        cout << e << endl;
    for (int i = 1; i<=2*N; ++i)
        if (!tempEls.count(i)) tempBess.push_back(i);
    for (auto e : tempBess)
        cout << e << endl;
    sort(tempBess.begin(), tempBess.end());
    sort(ElsieF, ElsieF+(N/2));
    sort(ElsieS, ElsieS+(N/2));
    // for (int i = 0; i<N/2; ++i)
    //     cout << ElsieS[i] << endl;
    for (int i = 0; i<N/2; ++i)
        BessieS.insert(tempBess[i]);
    for (int i = N/2; i<N; ++i)
        BessieL.insert(tempBess[i]);

    int score = 0;
    for (int i = 0; i<N/2; ++i) {
        if (BessieL.upper_bound(ElsieF[i])!=BessieL.end()) {
            cout << ElsieF[i] << " " << *BessieL.upper_bound(ElsieF[i]) << " win" << endl;
            BessieL.erase(BessieL.upper_bound(ElsieF[i]));
            ++score;
        }
        else {
            cout << ElsieF[i] << " " << *BessieL.begin() << " lose" << endl;
            BessieL.erase(BessieL.begin());
        }
    }
    for (int i = 0; i<N/2; ++i) {
        if (BessieS.upper_bound(ElsieS[i])!=BessieS.end()) {
            cout << ElsieS[i] << " " << *BessieS.upper_bound(ElsieS[i]) << " win" << endl;
            BessieS.erase(BessieS.upper_bound(ElsieS[i]));
            ++score;
        }
        else {
            cout << ElsieS[i] << " " << *BessieS.begin() << " lose" << endl;
            BessieS.erase(BessieS.begin());
        }
    }
    fout << score << endl;
    fout.close();
    return 0;
}