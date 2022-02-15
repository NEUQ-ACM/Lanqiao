#include<iostream>
#include<vector>
 
using namespace std;
int GCD(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}
 
int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}
 
int MinDist(vector<vector<int>>& graph, int i)
{
 
    if (graph[i][1])
    {
        //cout << graph[i][1] << endl;
        return graph[i][1];
    }
    int min_dist = 99999999;
    for (int j = 1; j < 2022; j++)
    {
        if (graph[i][j] == 0)
        {
            continue;
        }
        //cout<<i<<" "<<j<<" "<<graph[i][j]<<endl;
        int temp = MinDist(graph, j) + graph[i][j];
        if (temp < min_dist)
        {
            min_dist = temp;
        }
    }
    //cout << min_dist << endl;
    return min_dist;
}
 
int main()
{
    cout << LCM(15, 55) << endl;
    vector<vector<int>> graph(2022, vector<int>(2022, 0));
    for (int i = 1; i < 2022; i++)
    {
        for (int j = i - 1; j >= i - 21 && j > 0; j--)
        {
            graph[i][j] = LCM(i, j);
        }
        for (int j = i + 1; j <= i + 21 && j < 2022; j++)
        {
            graph[i][j] = LCM(i, j);
        }
    }
    int ret = MinDist(graph, 2021);
    cout << ret << endl;
    return 1;
}