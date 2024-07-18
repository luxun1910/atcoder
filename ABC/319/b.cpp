#include <bits/stdc++.h>
using namespace std;

// 2024/07/18
// charのvectorとかいうそれstringでいいじゃんなデータ構造にしてしまったせいで時間がかかった
// また、char→数値を暗黙の型変換すると文字コードになるっぽい。
// ちゃんと数値にしたい場合はj + '0'みたいにすること

int main()
{
    int N;
    cin >> N;

    string answer;

    for (int i = 0; i <= N; i++){
        string temp = "-";

        // 1 以上9以下のNの約数j 
        for (int j = 1; j <= 9; j++){
            if(N % j == 0){
                if(i % (N / j) == 0){
                    temp = to_string(j);
                    break;
                } 
            }
        }
        answer += temp;
    }

    cout << answer << endl;
}
