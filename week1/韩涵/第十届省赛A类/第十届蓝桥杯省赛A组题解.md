# 第十届蓝桥杯省赛A组题解

## B 数列求值

##### 填空题，但是需要使用代码。进行暴力破解即可。注意余数。

## C 最大降雨量

##### 填空题，思路为创建一个7 * 7的表格。将数字填入，使得右面的数比左面的数大，且上面的数比下面的数大。之后表格最中间的数就是祈雨结果。将此格右面和下面的格子随机选取格子从大到小数字填入，中间的值，即为最大值，是34。

## F 完全二叉树权值

##### 根据二叉树的性质，可以用数组进行存储。每一层的节点下标为[2^lev,2^(lev+1)-1]。遍历判断即可。