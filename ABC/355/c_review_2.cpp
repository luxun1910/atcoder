#include <bits/stdc++.h>
using namespace std;

// 2024/07/22
// またダメだった...。
// 発想は結構惜しいところまで行っているが、テスト結果と矛盾しないかの判定を書けなかった。

int main()
{
    // N:鍵の本数, M:テスト回数,K:K本以上差し込めばOK
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> C(M);
    vector<int> A(M);
    vector<char> R(M);

    for (int i = 0; i < M; i++){
        cin >> C[i];
        vector<int> temp(C[i]);
        for (int j = 0; j < C[i]; j++){
            cin >> temp[j];
        }
        // 2進数に変換
        int a = 0;
        for (auto x : temp){
            a += (int)pow(2, x-1);
        }
        A[i] = a;
        cin >> R[i];
    }

    int answer = 0;


// この部分から書けなかった。
    for (int bit = 0; bit < pow(2, N); bit++){
        bool jud = true;
        for(int i = 0; i < M; i++){
            int ok = __popcount(bit & A[i]);
            if(ok >= K && R[i] == 'x'){
                jud = false;
                break;
            }

            if(ok < K && R[i] == 'o'){
                jud = false;
                break;
            }
        }

        if(jud){
            answer ++;
        }


/*
        // その組み合わせがテスト結果と矛盾しないかチェック
        bool hasProblem = false;
        if(__popcount(bit) < K){
            continue;
        }

        // 合ってそうで間違ってるやつ



        for (int i = 0; i < M; i++){
            if(R[i] == 'x'){
                if((bit & A[i]) == A[i]){
                    hasProblem = true;
                    break;
                }
            }
        }

        if(hasProblem){
            continue;
        }

        answer++;

        */
    }

    cout << answer << endl;
}
