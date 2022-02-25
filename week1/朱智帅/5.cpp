
#include <bits/stdc++.h>
using namespace std;

const int maxn = 21;
long long int dp[1 << maxn][maxn];

bool IsPosVis(int state, int pos) {
  if ((state & (1 << pos)) != 0) {
    return true;
  } else {
    return false;
  }
}

bool IsConnect(int x, int y) {
  if (x == 0 || y == 0) {
    return true;
  }
  if (__gcd(x + 1, y + 1) == 1) {
    return true;
  } else {
    return false;
  }
}

long long int f(int state, int finalPos) {
  if (dp[state][finalPos] != -1) {
    return dp[state][finalPos];
  }
  if (!IsPosVis(state, finalPos)) {
    return dp[state][finalPos] = 0;
  }

  long long int ret = 0;

  for (int net = 0; net < maxn; net++) {
    if (!IsPosVis(state, net)) {
      continue;
    }
    if (!IsConnect(net, finalPos)) {
      continue;
    }
    ret += f(state - (1 << finalPos), net);
  }

  return dp[state][finalPos] = ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  long long int ans = 0;
  int finalState = (1 << (maxn)) - 1;
  dp[1][0] = 1;

  for (int i = 0; i < maxn; i++) {
    long long int temp = f(finalState, i);
    printf("%d %d %d %lld\n", IsConnect(i, 0), finalState, i, temp);
    ans += temp;
  }
  printf("ans = %lld\n", ans);
  return 0;
}