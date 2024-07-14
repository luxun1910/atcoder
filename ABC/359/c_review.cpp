#include <bits/stdc++.h>
using namespace std;

// 2023/07/13
// 要復習
// むずすぎる。解説見た。
// Sx, Syを原点に移動するようにしてTx、Tyも移動し、第1象限のみで考えるようにする
// ↑これをどう表すか考えるのに時間かかった。というか解説見た。確かにとは思う。

int main()
{
  long long Sx, Sy, Tx, Ty;

  cin >> Sx >> Sy >> Tx >> Ty;
  // タイルの左下の座標を基準に考えるようにする。すなわち、x + yが奇数なら、xを1減らしてタイルの左下に移す

  if((Sx + Sy) % 2 == 1){
    Sx--;
  }

  if((Tx + Ty) % 2 == 1){
    Tx--;
  }

  // Sx, Syを原点に移動するようにしてTx、Tyも移動し、第1象限のみで考えるようにする
  // その移動は、（移動先-移動元）の絶対値で行える

  long long Ax = abs(Tx-Sx);
  long long Ay = abs(Ty-Sy);


  // y=xの直線より上にある点（y > x）へ移動する場合は、yの座標の差分

  long long ans = 0;

  if(Ay > Ax){
    ans = Ay;
  }

  // y=xの直線上またはそれより下にある点（y <= x）へ移動する場合は、(x + y) / 2

  else{
    ans = (Ax + Ay) / 2;
  }

  cout << ans << endl;
}
