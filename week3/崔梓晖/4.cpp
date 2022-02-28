#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;
queue<string> que;
void rF(string &s) {
    char tmp;
    tmp = s[1], s[1] = s[3], s[3] = s[4], s[4] = s[2], s[2] = tmp;
    tmp = s[19], s[19] = s[16], s[16] = s[22], s[22] = s[5], s[5] = tmp;
    tmp = s[20], s[20] = s[14], s[14] = s[21], s[21] = s[7], s[7] = tmp;
} // 将前面顺时针转90°
void rR(string &s) {
    char tmp;
    tmp = s[5], s[5] = s[7], s[7] = s[8], s[8] = s[6], s[6] = tmp;
    tmp = s[2], s[2] = s[22], s[22] = s[11], s[11] = s[18], s[18] = tmp;
    tmp = s[4], s[4] = s[24], s[24] = s[9], s[9] = s[20], s[20] = tmp;
} // 将右面顺时针转90°
void rU(string &s) {
    char tmp;
    tmp = s[17], s[17] = s[19], s[19] = s[20], s[20] = s[18], s[18] = tmp;
    tmp = s[13], s[13] = s[1], s[1] = s[5], s[5] = s[9], s[9] = tmp;
    tmp = s[14], s[14] = s[2], s[2] = s[6], s[6] = s[10], s[10] = tmp;
} // 将顶面顺时针转90°
void rB(string &s) {
    char tmp;
    tmp = s[9], s[9] = s[11], s[11] = s[12], s[12] = s[10], s[10] = tmp;
    tmp = s[18], s[18] = s[8], s[8] = s[23], s[23] = s[13], s[13] = tmp;
    tmp = s[17], s[17] = s[6], s[6] = s[24], s[24] = s[15], s[15] = tmp;
} // 将背面顺时针转90°
void rL(string &s) {
    char tmp;
    tmp = s[13], s[13] = s[15], s[15] = s[16], s[16] = s[14], s[14] = tmp;
    tmp = s[17], s[17] = s[12], s[12] = s[21], s[21] = s[1], s[1] = tmp;
    tmp = s[19], s[19] = s[10], s[10] = s[23], s[23] = s[3], s[3] = tmp;
} // 将左面顺时针转90°
void rD(string &s) {
    char tmp;
    tmp = s[21], s[21] = s[23], s[23] = s[24], s[24] = s[22], s[22] = tmp;
    tmp = s[3], s[3] = s[15], s[15] = s[11], s[11] = s[7], s[7] = tmp;
    tmp = s[4], s[4] = s[16], s[16] = s[12], s[12] = s[8], s[8] = tmp;
} // 将底面顺时针转90°
set<string> visit;
void visit_put(string &s) {
    // 将前面顺时针转90°，后面也顺时针转90°，相当于将整个魔方绕前面转了90°
    // 其它方向的旋转同理
    for (int i = 0; i < 4; i++) {
        bool flag = true;
        rF(s), rB(s);
        visit.insert(s);
    }
}
void exist(string &s) {
    // 将魔方的6个面都转至正面
    visit_put(s);
    rU(s), rD(s);
    visit_put(s);
    rU(s), rD(s);
    visit_put(s);
    rU(s), rD(s);
    visit_put(s);
    rU(s), rD(s), rL(s), rR(s);
    visit_put(s);
    rL(s), rL(s), rR(s), rR(s);
    visit_put(s);
    rL(s), rR(s);
}
int main() {
    int ans = 0;
    string a = "u000011112222111122220000";
    // 魔方的初始状态，0表示橙色，1表示绿色，2表示黄色
    que.push(a);
    exist(a);
    while (!que.empty()) {
        string str = que.front();
        que.pop();
        ans++;
        // 一个方向拧和相对方向拧是一样的，所以我们只考虑前右上的旋转
        for (int i = 0; i < 4; i++) {
            rF(str);
            if (visit.find(str) == visit.end()) {
                que.push(str);
                exist(str);
            }
        }
        for (int i = 0; i < 4; i++) {
            rU(str);
            if (visit.find(str) == visit.end()) {
                que.push(str);
                exist(str);
            }
        }
        for (int i = 0; i < 4; i++) {
            rR(str);
            if (visit.find(str) == visit.end()) {
                que.push(str);
                exist(str);
            }
        }
    }
    // ans表示考虑魔方整体旋转的结果，size表示不考虑魔方整体旋转的结果
    printf("ans = %d, size = %d\n", ans, visit.size());
    return 0;
}


