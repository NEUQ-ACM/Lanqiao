- 第十二届蓝桥杯省赛（软件类真题)  C&C++大学B组



----

- A  空间

  结果：67108864







----

- B  卡片  

  ```c++
  #include <iostream>
  #include<vector>
  using namespace std;
  int main() {
      vector<int> array(10, 2021);
      for (int i = 1; ; i++) 
      {
          int t = i;
          while (t) 
          {
              int a = t % 10;
              if (array[a] > 0) 
              {
                  array[a]--;
              }
              else 
              {
                  break;
              }
              t /= 10;
          }
          if (t)                                                                                          
          {
              cout << i-1 << endl;
              break;
          }
      }
      return 0;
  }
  ```

  





----

- C  直线   

  ```c++
  #include<iostream>
  #include<set>
  using namespace std;
  set<pair<double, double> > line_set;
  
  int main()
  {
      int x1, y1, x2, y2;
      for (x1 = 0; x1 < 20; x1++) {
          for (y1 = 0; y1 < 21; y1++) {
              for (x2 = 0; x2 < 20; x2++) {
                  for (y2 = 0; y2 < 21; y2++) {
                      if (x1 != x2 && y1 != y2) {
                          double k = (y2 - y1) * 1.0 / (x2 - x1);
                          double b = (y2 * (x2 - x1) - (y2 - y1) * x2) * 1.0 / (x2 - x1);
                          pair<double, double> newline;
                          newline.first = k;
                          newline.second = b;
                          line_set.insert(newline);
                      }
                  }
              }
          }
      }
      printf("%d", line_set.size() + 20 + 21);
      return 0;
  }
  //40257
  ```

  









-----

- D     货物摆放

  ```c++
  - #include<iostream>
    #include<set>
    #include<map>
    #include<iomanip>
    #include<vector>
    #include<cmath>
    using namespace std;
    typedef long long ll;
    int main()
    {
        ll n = 2021041820210418;
        ll en1 = sqrt(n);
        ll ans = 0;
        for (ll a = 1; a <= en1; a++) {
            if (n % a == 0) {
                ll nn = n / a;
                ll en2 = sqrt(nn);
                for (ll b = 1; b <= en2; b++) {
                    if (nn % b == 0) {
                        ll c = nn / b;
                        if (c >= b && b >= a) {
                            set<int> s;
                            s.insert(a);
                            s.insert(b);
                            s.insert(c);
  
  
                      if (s.size() == 1)ans++;
                      else if (s.size() == 2)ans += 3;
                      else if (s.size() == 3)ans += 6;
                  }
              }
          }
      }
  }
  printf("%lld", ans);
  return 0;
  
  
  }
  ```

  



------

- E     路径

  ```c++
  #include<iostream>
  #include<set>
  #include<map>
  #include<iomanip>
  #include<vector>
  #include<cmath>
  using namespace std;
  long long gcd(long long a, long long b) { 
      int t;
      if (a < b) {
          t = b;
          b = a;
          a = t;
      }
      while (b) {
          t = a % b;
          a = b;
          b = t;
      }
      return a;
  }
  int main() {
      vector<vector<long long>> array(2022, vector<long long>(2022, INT_MAX));                   
      for (long long i = 1; i <= 2021; i++) { 
          for (long long j = i + 1; j <= i + 21; j++) {
              array[i][j] = i * j / gcd(i, j);
          }
      }
      for (long long i = 1; i <= 2021; i++) {
          for (long long j = i + 1; j <= 2021; j++) {
              for (long long k = i + 1; k < j; k++) { 
                  array[i][j] = fmin(array[i][j], (array[i][k] + array[k][j]));
              }
          }
      }
      cout << array[1][2021] << endl;
      return 0;
  }
  ```

  











------

- F    时间显示

  ```c++
  #include<iostream>
  #include<set>
  #include<map>
  #include<iomanip>
  #include<vector>
  #include<cmath>
  using namespace std;
  typedef long long ll;
  int main()
  {
      ll n;
      scanf("%lld", &n);
      n /= 1000;
      n %= (24 * 60 * 60);
      int ss = n % 60;
      n /= 60;
      int mm = n % 60;
      n /= 60;
      int hh = n % 60;
      n /= 60;
      printf("%02d:%02d:%02d", hh, mm, ss);
      return 0;
  }
  ```

  

  









------

- G    砝码称重

  ```c++
  #include<iostream>
  #include<set>
  #include<map>
  #include<iomanip>
  #include<vector>
  #include<cmath>
  using namespace std;
  const int N = 110, M = 200010;
  int main() {
      int n;
      int sum = 0;  
      vector<int>w(N);
      vector<vector<bool> > dp(N, vector<bool>(M, false)); 
      scanf("%d", &n); 
      for (int i = 1; i <= n; i++) {
          scanf("%d", &w[i]);
          sum += w[i];
      }
      dp[0][0] = true;
      for (int i = 1; i <= n; i++) { 
          for (int j = 0; j <= sum; j++) { 
              dp[i][j] = dp[i - 1][j] || dp[i - 1][fabs(j - w[i])] || dp[i - 1][j + w[i]];
          }
      }
      long long ans = 0;
      for (int i = 1; i <= sum; i++) {
          if (dp[n][i]) {  
              ans++;
          }
      }
      cout << ans << endl;
      return 0;
  }
  ```

  





-----

- H   杨辉三角形

  ```c++
  - #include<iostream>
    #include<set>
    #include<map>
    #include<iomanip>
    #include<vector>
    #include<cmath>
    using namespace std;
    int n;
    long long C(int a, int b) { 
        long long res = 1;
        for (int i = a, j = 1; j <= b; i--, j++) {
            res = res * i / j;
            if (res > n) {
                return res;
            }
        }
        return res;
    }
  
  bool check(int k) {
      long long l = k * 2;
      long long r = fmax(l, n);
      while (l < r) {
          long long mid = l + r >> 1;
          if (C(mid, k) >= n) {
              r = mid;
          }
          else {
              l = mid + 1;
          }
      }
      if (C(r, k) != n) {
          return false;
      }
      cout << r * (r + 1) / 2 + k + 1 << endl;
      return true;
  }
  
  int main() {
      cin >> n;
      for (int k = 16; ; k--) { 
          if (check(k)) { 
              break;
          }
      }
      return 0;
  }
  ```

  



------

- I      双向排序

  ```c++
  #include<iostream>
  #include<set>
  #include<map>
  #include<iomanip>
  #include<vector>
  #include<cmath>
  using namespace std;
  const int N = 100010;
  vector<pair<int, int> > act(N); 
  vector<int> ans(N);
  int main() {
      int n, m;
      int count = 0;
      cin >> n >> m;
      while (m--) {
          int p, q;
          cin >> p >> q;
          if (!p) {
              while (count && act[count].first == 0) { 
                  q = max(q, act[count--].second);
              }
              while (count >= 2 && act[count - 1].second <= q) {
                  count -= 2;
              }
              act[++count] = { 0, q };
          }
          else if (count) {
              while (count && act[count].first) { 
                  q = min(q, act[count--].second);
              }
              while (count >= 2 && act[count - 1].second >= q) {
                  count -= 2;
              }
              act[++count] = { 1, q };
          }
      }
      int left = 1;
      int right = n;
      int k = n;
      for (int i = 1; i <= count; i++) { 
          if (act[i].first == 0) {
              while (right > act[i].second && left < right + 1) {
                  ans[right--] = k--;
              }
          }
          else {
              while (left < act[i].second && left < right + 1) {
                  ans[left++] = k--;
              }
          }
          if (left > right) {
              break;
          }
      }
      if (count % 2) { 
          while (left < right + 1) {
              ans[left++] = k--;
          }
      }
      else {
          while (left < right + 1) {
              ans[right--] = k--;
          }
      }
      for (int i = 1; i <= n; i++) {
          cout << ans[i] << " ";
      }
      return 0;
  }
  ```

  







------

-  J      括号排序

  ```c++
  - #include<iostream>
    #include<set>
    #include<map>
    #include<iomanip>
    #include<vector>
    #include<cmath>
    using namespace std;
    const int N = 5010;
    const int mod = 1e9 + 7;
    int n;
    char str[N];
    long long dp[N][N];
  
  long long compute() {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;
      for (int i = 1; i <= n; i++) {
          if (str[i] == '(') {
              for (int j = 1; j <= n; j++) {
                  dp[i][j] = dp[i - 1][j - 1];
              }
          }
          else {
              dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
              for (int j = 1; j <= n; j++) {
                  dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % mod;
              }
          }
      }
      for (int i = 0; i <= n; i++) {
          if (dp[n][i]) {
              return dp[n][i];
          }
      }
      return -1;
  }
  
  int main() {
      scanf("%s", str + 1); 
      n = strlen(str + 1); 
      long long l = compute();
      reverse(str + 1, str + n + 1); 
      for (int i = 1; i <= n; i++) { 
          if (str[i] == '(') {
              str[i] = ')';
          }
          else {
              str[i] = '(';
          }
      }
      long long r = compute();
      cout << l * r % mod << endl;
      return 0;
  }
  ```

  
