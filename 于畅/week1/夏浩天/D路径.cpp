//答案：10266837
//floyed算法（会超时，问题不大）

#include <iostream>
using namespace std;
int en[2030][2030];
int fff(int x, int y)
{
    if (y == 0)
        return x;
    else
        return fff(y, x % y);
}
int main()
{
    memset(en, 0x3f, sizeof(en));
    for (int i = 1; i <= 2021; i++)
        for (int j = i + 1; j <= 2021; j++)
        {
            if (j - i > 21)
                continue;
            int cost = i / fff(i, j) * j;
            en[i][j] = cost;
            en[j][i] = cost;
        }
    for (int k = 1; k <= 2021; k++)
        for (int i = 1; i <= 2021; i++)
            for (int j = 1; j <= 2021; j++)
            {
                en[i][j] = min(en[i][k] + en[k][j], en[i][j]);
            }
    cout << en[1][2021];
    return 0;
}