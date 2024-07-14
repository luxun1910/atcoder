#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    cin >> A.at(i);
  }

  int answer = 0;

  int candidate = A[0];

  for (int i = 2; i < 2 * N; i+=2){
    if (candidate == A.at(i)){
        answer ++;
    }
    candidate = A.at(i);
  }

  candidate = A[1];

    for (int i = 3; i < 2 * N; i+=2){
    if (candidate == A.at(i)){
        answer ++;
    }
    candidate = A.at(i);
  }

  cout << answer << endl;
}
