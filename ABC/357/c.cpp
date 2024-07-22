#include <bits/stdc++.h>
using namespace std;

// 2024/07/22
// 時間かかったけど自力でできた。
// ループカウンタとインデックス番号を対応づけるのが難しい。何度も紙に書いて規則性を見つけないといけなかった
// マスのサイズを動的に取得するようにすればもうちょっと楽にできたかも

int main()
{
    int N;
    cin >> N;

    vector<string> masu = {"#"};

    for (int i = 1; i <= N; i++){
        vector<string> x(pow(3, i), string(pow(3, i), '.'));
        // まずは今のマスで全部埋める
        for (int j = 0; j < pow(3, i); j++){
            for (int k = 0; k < pow(3, i); k++){
                x[j][k] = masu[j % (int)(pow(3, i - 1))][k % (int)(pow(3, i - 1))];  // 何か問題がある
            }
        }

        // 中央のマスを白くする
        for (int j = 0; j < pow(3, i) / 3; j++){
            for (int k = 0; k < pow(3, i) / 3; k++){
                x[pow(3, i) / 3 + j][pow(3, i) / 3 + k] = '.';
            }
        }

        masu = x;
    }

    for (auto a : masu){
        cout << a << endl;
    }

}
