#include <bits/stdc++.h>
using namespace std;

// 2024/07/22
// ちょっと時間かかってる。途中。

int main()
{
    int N;
    cin >> N;

    vector<string> masu = {"#"};

    for (int i = 1; i <= N; i++){
        vector<string> x(pow(3, i));
        // まずは今のマスで全部埋める
        for (int j = 0; j < 3 * i; j++){
            x[j] += masu[j % 3];  // 何か問題がある
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
