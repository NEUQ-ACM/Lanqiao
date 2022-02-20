#include<iostream>
#include<vector>
using namespace std;

int maxn = 2021;
int rest_num[10] = {0};

vector<int> split(int x)
{
    vector<int> re;
    if(x == 0)
    {
        re.push_back(0);
        return re;
    }
}

bool sub(const vector<int> &x)
{
    for(unsigned int i = 0;i<x.size();i++)
    {
        rest_num[x[i]]--;
        if(rest_num[x[i]] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for(int i=0;i<10;i++)
    {
        rest_num[i] = maxn;
    }
    int ans = 1;
    while(1)
    {
        vector<int> need = split(ans);
        bool succFlag = sub(need);
        if(!succFlag)
        {
            break;
        }
        ans++;
    }
    cout<<ans - 1;

    return 0;
}