#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }

  int answer = 0;

  for (auto i : S){
    if (i == "Takahashi"){
        answer ++;
    }
  }

  cout << answer << endl;
}
