#include <bits/stdc++.h>
using namespace std;

// 2024/07/18
// ちょい時間かかったけど解けた
// bitの1が立ってる数を数えるときは__popcount関数を使うヨロシ

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }

  // bit全探索
  // S[0...N]のそれぞれを選ぶか選ばないかを2進数で表す

  int answer = INFINITY;

  for (int bit = 0; bit < (1 << N); bit++){
    vector<bool> res(M);

    for (int i = 0; i < N; i++){
        if(bit & (1 << i)){
            for (int j = 0; j < M; j++){
                if(S[i][j] == 'o'){
                    res[j] = true;
                }
            }
        }
    }

    if(count(res.begin(), res.end(), true) == M){
        answer = min(__popcount(bit), answer);
    }
  }

      cout << answer << endl;
}
