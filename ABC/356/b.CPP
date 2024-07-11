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

    vector<int> A(M);

    for(auto i = 0; i < M; i++){
        cin >> A.at(i);
    }

    vector<vector<int>> X(N, vector<int>(M));

    for(auto i = 0; i < N; i++){
        for (auto j = 0; j < M; j++){
            cin >> X.at(i).at(j);
        }
    }

    auto answer = "Yes";

    for(auto i = 0; i < M; i++){
        auto mokuhyo = A.at(i);
        auto gokei = 0;
        for (auto j = 0; j < N; j++){
            gokei += X.at(j).at(i);
        }

        if(gokei < mokuhyo){
            answer = "No";
            break;
        }
    }

    

    cout << answer << endl;
}
