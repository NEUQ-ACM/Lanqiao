#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int m;
        for(int i=0;i<n;i++)//几轮
        {
            cin>>m;//每一轮的询问数
            int c[m];
            int sum=0;
            int max1=0;
            for(int j=0;j<m;j++)//填充提问数
            {
                    cin>>c[j];
                    if(c[j]>max1)//找出最大数，进一步去找最大的1
                    {
                        max1=c[j];
                    }
                    sum^=c[j];
            }
            //平局
            if(sum==0)
            {
                cout<<0;
                continue;
            }else{}
            //争取最高位的1,如果是奇数就是a赢，否则b赢
            int c1=0;
            while(max1>0)
            {
                max1>>=1;
                c1++;
            }
            int c11=0;
            for(int k=0;k<m;k++)//在c1位上有几个1
            {
                c11+=(c[k]>>c1);
            }
            if(!c11%2)
                {
                    cout<<1;
                }
                else
                {
                    cout<<-1;
                }


        }

    return 0;
}
