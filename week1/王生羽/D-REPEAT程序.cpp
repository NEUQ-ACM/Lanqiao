 #include<bits/stdc++.h>
string s;
stack<int> sk;
int main() {
  freopen("prog.txt", "r", stdin);
  int ci = 1;
  int res = 0;
  while(getline(cin, s)) {
    int pos = 0, len = s.size(), sj, mid;
    while(pos < len && s[pos] == ' ') ++pos;
    sj = pos / 4;
    while(sk.size() > sj) {
      ci /= sk.top();
      sk.pop();
    }
    if(s[pos] == 'R') {
      pos += 7;
      for(mid = 0; pos < len-1; ++pos) mid = mid * 10 + s[pos]-'0';
      sk.push(mid); ci *= mid;
    } else {
      pos += 8;
      for(mid = 0; pos < len; ++pos) mid = mid * 10 + s[pos]-'0';
      res += mid * ci;
    }
  }
  cout << res;
  return 0;
}
//用栈模拟循环次数。答案： 241830

