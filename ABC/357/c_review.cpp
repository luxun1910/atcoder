#include <bits/stdc++.h>
using namespace std;

// 2024/07/15
// 再帰使えばいけそうな気もするけどなんもわからん。解説見た。

// 普通にfor文でいけた
// stringの配列でいく
// stringの文字の長さ=横、配列のサイズ=縦のイメージ


int main()
{
    int N;
    cin >> N;

    // N=0の時はこれで答えになる
    vector<string> s = {"#"};

    for (auto i = 0; i < N; i++){
        // 前のマスのサイズ
        int m = s.size();
        int m3 = m*3;

        // 回答となる新たなマスを作成する
        // 縦（配列のサイズ）横（stringの文字の長さ）の数は3倍ずつ増えていく
        // stringのコンストラクタにはどの文字で埋めるかも指定する必要があり、とりあえず.で埋める
        vector<string> t(m3, string(m3, '.'));

        // 新しく作成するマスを埋める
        for(auto j = 0; j < m3; j++){
            for (auto k = 0; k < m3; k++){
                // 以前のマスで埋めていく
                // 以前のマスのサイズの周期で当てはめる
                t[j][k] = s[j%m][k%m];
            }
        }

        // 真ん中を白で埋める
        for(auto j = 0; j < m; j++){
            for (auto k = 0; k < m; k++){
                // 真ん中のサイズは以前のマスのサイズと同じ
                t[m + j][m + k] = '.';
            }
        }

        // s（1つ前のマス）をt（今のマス）に置き換える
        swap(s, t);
    }


    for(auto i : s){
        cout << i << endl;
    }
}
