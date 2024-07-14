#include <bits/stdc++.h>
using namespace std;

// 2024/07/13
// なんもわからん。解説見た。

// 本問題のように「N 個のものそれぞれについて選ぶか選ばないかを決める2N通りを全探索する」という状況では、bit 全探索と呼ばれる手法がその実装の容易さから広く用いられています。
// bit全探索完全に理解する必要がある

bool isOK(vector<string> s, int m){
  vector<bool> ok(m);

  for(auto i = 0; i < size(s); i++){
    for (auto j = 0; j < m; j++){
      if(s[i][j] == 'o'){
        ok[j] = true;
      }
    }
  }

  for (auto i : ok){
    if (!i){
      return false;
    }
  }

  return true;

}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for(auto i = 0; i < N; i++){
    cin >> S.at(i);
  }

  int answer = N;

  for (auto bit = 0; bit < pow(2, N) - 1; bit++){
    vector<bool> exists(M);
    int count = 0;

    for (auto i = 0; i < N; i++){
      // ビット（どの店を選ぶかを表すパターン）を0つ右にずらしたとき1桁目が1か、1つ右にずらしたとき1桁目が1か＝ビットを、どの店が選ばれているかのインデックスに変換する
      if (bit >> i & 1){
        count++;
        for(auto j = 0; j < M; j++){
          if (S[i][j] == 'o'){
            exists[j] = true;
          }
        }
      }
    }

    bool allExists = true;

    for (auto i : exists){
      if (i == false){
        allExists = false;
      }
    }

    if(allExists){
      answer = min(answer,count);
    }
  }

  cout << answer << endl;
}
