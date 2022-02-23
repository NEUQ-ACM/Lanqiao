#include <bits/stdc++.h>
using namespace std;
// https://www.dotcpp.com/oj/problem2571.html
// 用到了C++自带的转换函数，在C语言网的oj能过，但是蓝桥杯的oj跑不了，嘛，当拓展思维了
int ji[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int run[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool judge(string tar) //判断一个日期是否合法
{
    string y = tar.substr(0, 4);
    string m = tar.substr(4, 2);
    string d = tar.substr(6, 2);
    long long year, month, day;
    if (!y.empty())
        year = stoi(y);
    if (!m.empty())
        month = stoi(m);
    if (!d.empty())
        day = stoi(d);
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
    {
        if (month <= 12 && month >= 1)
        {
            if (day <= run[month] && day >= 1)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        if (month <= 12 && month >= 1)
        {
            if (day <= ji[month] && day >= 1)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string now;
    cin >> now;
    int start2 = stoi(now.substr(0, 2));
    int start1 = stoi(now.substr(0, 4));
    for (int i = start1; i <= 9999; i++)
    {

        string front = to_string(i);
        string after = front;
        reverse(after.begin(), after.end());
        string a = front + after;
        if (a <= now)
            continue;
        if (judge(a))
        {
            cout << a << endl;
            break;
        }
    }
    for (int i = start2; i <= 99; i++)
    {
        string front = to_string(i);
        string after = front;
        reverse(after.begin(), after.end());
        string a = front + front;
        a += after;
        a += after;
        if (a <= now)
            continue;
        if (judge(a))
        {
            cout << a;
            break;
        }
    }
    //	cout<<judge(now);
    return 0;
}
