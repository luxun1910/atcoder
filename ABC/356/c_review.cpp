#include <bits/stdc++.h>
using namespace std;

// 2024/07/17
// ビット全探索まで自力で実装したが結局解けない。
// 問題文をちゃんと理解できていない気がする。

// ビット全探索という発想は合っていたけど、どうやって試行結果と突き合わせるか、というところがうまくいってなかった。
// 具体的には、1つのビットパターンが、すべての試行結果と矛盾しないか、という点を考える必要があった。
// 1つの結果と一致していても、他の結果と矛盾する可能性ある。
// また、ビット全探索の際にpowを使うと、powが浮動小数点を返す関係で誤差が生じることがあるっぽい

// 1<<Nは(int)(pow(2, N))と等しい

int main()
{

    // N:鍵の本数、M:試行回数、K:鍵をK本以上差し込んだ時扉が開く
    int N, M, K;
    cin >> N >> M >> K;

    // key:その試行で差した鍵のパターン（A[i][j]が1なら、試行結果i番目では番号jの鍵が使われた、ということ）
    // R:その試行の結果
    vector<vector<int>> key(M,vector<int>(N,0));
    vector<char> R(M);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++){
            int a;
            cin >> a;
            key[i][a-1] = 1;
        }
        cin >> R[i];
    }


    int ans = 0;

    // 各カギを選ぶか選ばないかをビット探索
    for (int bit = 0; bit < (int)(pow(2, N)); bit++){
        // bitパターンを数値の配列に変換
        vector<int> tf(N);
        int bitTemp = bit;
        for (auto i = 0; i < N; i++){
            /*
            同じ書き方だけど、ちゃんとビット演算慣れてたらこっちの方がわかりやすいはず
            bitTemp = bitとかいうパット見意味不明な記述もしなくていい
            if(bit&(1<<i))
            */
            if(bitTemp % 2 == 1){
                tf[i] = 1;
            }else{
                tf[i] = 0;
            }
            bitTemp /= 2;
        }

        bool judge = true;

        // そのビットパターンが、すべての試行結果（j番目の試行結果）と矛盾しないか確認する
        for (int j = 0; j < M; j++){
            int ck = 0;
            for (int p = 0; p < N; p++){
                if(key[j][p]==1 && tf[p] == 1){
                    ck++;
                }
            }

            // 試行結果と選んだ鍵が一致する回数がK以上であっても、結果が×だったら矛盾
            if(ck >= K && R[j] =='x'){
                judge = false;
            }
            // 試行結果と選んだ鍵が一致する回数がKより少なく、結果が〇だった場合、矛盾
            // 例えば、3つ以上の鍵が必要で、1,2,3の時〇なのに、ビットパターンが1,2の場合
            if(ck < K && R[j] == 'o'){
                judge = false;
            }
        }

        if(judge){
            ans ++;
        }
    }

     cout << ans << endl;

}
