#include <bits/stdc++.h>
using namespace std;

// 2024/07/12
// 無理にmapを使わず素直に配列を使ったほうが解きやすかった。
// stringの配列はsortすれば辞書順にできる

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i];
    }

    auto rateAmount = 0;

    for (auto i : C){
        rateAmount += i;
    }

    auto mod = rateAmount % N;

    sort(S.begin(), S.end());

    cout << S[mod] << endl;
}
