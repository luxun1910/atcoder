#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  unordered_map<int, int> cnt;
  for (int x : A) {
    cnt[x] ++;
  }

  int max_cnt = 0;  // 出現回数の最大値を保持
  int ans = 0;     // 出現回数が最大になる値を保持
  for (auto x : cnt) {
    // 今見ているxの出現回数が、その時点の最大よりも大きければ更新
    if (max_cnt < x.second) {
      max_cnt = cnt.at(x);
      ans = x;
    }
  }

  cout << ans << " " << max_cnt << endl;
}
