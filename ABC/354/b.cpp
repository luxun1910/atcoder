#include <bits/stdc++.h>
using namespace std;

// 2024/07/12
// 思ったより時間がかかった
// 二次元配列の入力とか、扱うときのインデックス（二重ループでどっちのインデックスを使用するんだっけ、ETC）にまだ慣れていない
// C++では、例えばA[2][3]とすると、2行目の3列目、という意味

int main()
{
    int N,M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    for(auto i = 0; i < N; i++){
        cin >> A.at(i);
    }

    for(auto i = 0; i < M; i++){
        cin >> B.at(i);
    }

    // BにAを合成してソート
    B.insert(B.end(), A.begin(), A.end());
    sort(B.begin(), B.end());
    // Aもソート
    sort(A.begin(), A.end());
    
    auto answer = "No";

    for(auto i = 1; i < N; i++){
        for(auto j = 1; j < N + M; j++){
            if(B.at(j-1) == A.at(i-1) && B.at(j) == A.at(i)){
                answer = "Yes";
                break;
            }
        }
    }

    cout << answer << endl;
}
