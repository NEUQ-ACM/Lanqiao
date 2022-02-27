#include <bits/stdc++.h>

using namespace std;

//判断年份y中是否含有2，如1902、2221都含有2
bool isInclude2(int y){
    while(y){
        if((y%10) == 2) return(true);
        y /= 10;
    }
    return false;
}

//判断某年是否为闰年
bool isLeap(int y){
    //整百年数除以400，无余为闰，有余为平
    if((y%100==0) && (y%400==0)) return true;
    //非整百年数除以4，无余为闰，有余为平
    if((y%100!=0) && (y%4==0)) return true;
    
    return false;
}

int main()
{
    int startYear = 1900;   //起始年份
    int endYear = 9999;     //结束年份
    int numOneYear = 0;     //记录某年中含有2的天数
    int totals = 0;         //记录总的含有2的天数
    int numTenMonths = 120; //1、3、4、5、6、7、8、9、10、11这10个月
                            //一共含有2的天数是固定的，即10*12天 = 120天
    int num12Month = 31;    //12月含有的天数

    for(int y=startYear; y<=endYear; y++){
        //判断该年份是否含有2
        if(isInclude2(y)) {
            //判断是闰年还是平年
            if(isLeap(y)) numOneYear = 366;
            else numOneYear = 365;
        }else {
            if(isLeap(y)){
                //是闰年则2月份为29天
                numOneYear = num12Month + numTenMonths + 29;
            }else{
                //是平年则2月份为28天
                numOneYear = num12Month + numTenMonths + 28;
            }
        }
        totals += numOneYear;
    }

    cout << "totals = " << totals << endl;
    return 0;
}
//1994240 
