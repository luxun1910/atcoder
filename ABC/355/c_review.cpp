#include <bits/stdc++.h>
using namespace std;

// 2024/07/17
// TLEした。解説見た。

// 発想が天才過ぎんだろ...。
// 慣れるしかないのかね
// マス目番号を二次元配列のインデックスに変換する発想は今後も大事そう。

// 数字が書かれているマスを含む列に対して，その列に含まれるマスの個数を更新します．Bingo を達成したかどうかの判定はそのマスが含まれる列のみをチェックすれば十分です．数字が書かれているマスを含む列は高々4しかないため，この更新は O(1) で行うことができます．

int main()
{
    int N, T;
    cin >> N >> T;
    vector<int> A(T);
    for (int i = 0; i < T; i++) {
        cin >> A[i];
        // マス目番号を0始まりにすると後で楽
        A[i]--;
    }

    // それぞれ横、縦、斜めに含まれるマスの個数を表す
    vector<int> row(N, 0), col(N, 0), diag(2, 0);
    
    for (int i = 0; i < T; i++){
        // マス目の番号を2次元配列のインデックスに変換
        int x = A[i] / N, y = A[i] % N;

        // 横
        row[x]++;
        if (row[x] == N){
            cout << i + 1 << endl;
            return 0;
        }

        // 縦
        col[y]++;
        if (col[y] == N) {
            cout << i + 1 << endl;
            return 0;
        }

        // 左上ー右下の斜め
        if (x == y){
            diag[0] ++;
            if(diag[0] == N){
                cout << i + 1 << endl;
                return 0;
            }
        }

        // 右上ー左下の斜め
        if (x + y == N - 1){
            diag[1] ++;
            if(diag[1] == N){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
