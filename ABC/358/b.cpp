#include <bits/stdc++.h>
using namespace std;

// 2024/07/10
// 思ったより時間かかった
// 規則性をプログラムで表現するのに時間がかかった。具体的には、次の人が並んだ際、前の人が購入前か購入後かで場合分けすればよいというのはわかっていたが、そのif文をどのように書けばいいかに詰まった

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }

  T.at(0) += A;

  for(int i = 1; i < N; i++){
    // 1つ手前の人が購入完了する前に並んだ場合
    if(T.at(i) <= T.at(i-1)){
      T.at(i) = T.at(i-1) + A;
    }
    // 1つ手前の人が購入完了する後に並んだ場合
    else{
      T.at(i) += A;
    }
  }

  for (auto i : T){
  cout << i << endl;
  }
}
