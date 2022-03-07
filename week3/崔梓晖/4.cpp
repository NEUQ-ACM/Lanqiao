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
} // ��ǰ��˳ʱ��ת90��
void rR(string &s) {
    char tmp;
    tmp = s[5], s[5] = s[7], s[7] = s[8], s[8] = s[6], s[6] = tmp;
    tmp = s[2], s[2] = s[22], s[22] = s[11], s[11] = s[18], s[18] = tmp;
    tmp = s[4], s[4] = s[24], s[24] = s[9], s[9] = s[20], s[20] = tmp;
} // ������˳ʱ��ת90��
void rU(string &s) {
    char tmp;
    tmp = s[17], s[17] = s[19], s[19] = s[20], s[20] = s[18], s[18] = tmp;
    tmp = s[13], s[13] = s[1], s[1] = s[5], s[5] = s[9], s[9] = tmp;
    tmp = s[14], s[14] = s[2], s[2] = s[6], s[6] = s[10], s[10] = tmp;
} // ������˳ʱ��ת90��
void rB(string &s) {
    char tmp;
    tmp = s[9], s[9] = s[11], s[11] = s[12], s[12] = s[10], s[10] = tmp;
    tmp = s[18], s[18] = s[8], s[8] = s[23], s[23] = s[13], s[13] = tmp;
    tmp = s[17], s[17] = s[6], s[6] = s[24], s[24] = s[15], s[15] = tmp;
} // ������˳ʱ��ת90��
void rL(string &s) {
    char tmp;
    tmp = s[13], s[13] = s[15], s[15] = s[16], s[16] = s[14], s[14] = tmp;
    tmp = s[17], s[17] = s[12], s[12] = s[21], s[21] = s[1], s[1] = tmp;
    tmp = s[19], s[19] = s[10], s[10] = s[23], s[23] = s[3], s[3] = tmp;
} // ������˳ʱ��ת90��
void rD(string &s) {
    char tmp;
    tmp = s[21], s[21] = s[23], s[23] = s[24], s[24] = s[22], s[22] = tmp;
    tmp = s[3], s[3] = s[15], s[15] = s[11], s[11] = s[7], s[7] = tmp;
    tmp = s[4], s[4] = s[16], s[16] = s[12], s[12] = s[8], s[8] = tmp;
} // ������˳ʱ��ת90��
set<string> visit;
void visit_put(string &s) {
    // ��ǰ��˳ʱ��ת90�㣬����Ҳ˳ʱ��ת90�㣬�൱�ڽ�����ħ����ǰ��ת��90��
    // �����������תͬ��
    for (int i = 0; i < 4; i++) {
        bool flag = true;
        rF(s), rB(s);
        visit.insert(s);
    }
}
void exist(string &s) {
    // ��ħ����6���涼ת������
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
    // ħ���ĳ�ʼ״̬��0��ʾ��ɫ��1��ʾ��ɫ��2��ʾ��ɫ
    que.push(a);
    exist(a);
    while (!que.empty()) {
        string str = que.front();
        que.pop();
        ans++;
        // һ������š����Է���š��һ���ģ���������ֻ����ǰ���ϵ���ת
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
    // ans��ʾ����ħ��������ת�Ľ����size��ʾ������ħ��������ת�Ľ��
    printf("ans = %d, size = %d\n", ans, visit.size());
    return 0;
}


