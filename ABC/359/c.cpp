#include <bits/stdc++.h>
using namespace std;

// 2024/07/18
// スムーズに解けた。

int main() {
  long long Sx, Sy, Tx, Ty;
  cin >> Sx >> Sy >> Tx >> Ty;

  // わかりやすくするために、タイルの左下に座標を移動させる
  if((Sx + Sy) % 2 == 1){
    Sx--;
  }
  if((Tx + Ty) % 2 == 1){
    Tx--;
  }

  // わかりやすくするために、Sx,Syを原点に移動させたうえで、第1象限だけで考えるようにする
  long x,y;

  x = abs(Tx-Sx);
  y = abs(Ty-Sy);

  // y = xの直線より下の場合
  if(y < x){
    cout << (x+y)/2 << endl;
  }else{
    // 上の場合
    cout << y <<endl;
  }

}
