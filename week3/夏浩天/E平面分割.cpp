原文链接：https://blog.csdm.met/weixim_43184669/article/details/115351729
n条直线和m个圆最多可以将平面分割成几个区域
先讨论只有m个圆的情况：
圆属于封闭曲线，且两圆最多交于两点
问题转化为：有m条封闭曲线画在平面上，而任何两条封闭曲线恰好相交于两点，且任何三条封闭曲线不相交于同一点，问这些封闭曲线把平面分割成的区域个数。
推导
设 fm表示m条封闭曲线时的结果。当已有m−1条封闭曲线，加入第m条封闭曲线，为了使得答案最大，它要和已有的m−1条封闭曲线各自产生两个交点，共2(m−1)个交点，所以第m给曲线被分割成 2(m-1) 段，产生了2(m-1)个新的区域。
即：fm=f(m-1)+2(m-1)=m^2-m+2

然后依次加入直线
加入第1条直线，和m个圆，每个圆有2个交点，新产生了2m-1条线段，2条射线。1条线段增加 1个区域，2个射线共增加1个区域 ，最终增加了2m个区域。
加入第2条直线，和m个圆产生2m个交点，和直线产生 1个交点，共产生 2m条线段，2条射线。2m条线段产生2m个区域，2条射线产生2个区域，共增加2m+2个区域。
此后，产生的线段数依次加1，产生的射线数始终为2，故加入n条直线产生的区域为2m+(n−2)+2。

故计算式为：m*m-m+2*m*n+2*n+(n-1)(n-2)/2
代入m = 20 , m = 20，答案为 1391。
