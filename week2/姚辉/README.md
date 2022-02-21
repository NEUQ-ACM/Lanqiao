# Lanqiao
NEUQ-ACM预备队蓝桥杯题解提交处

**提交格式：**

在本仓库对应周目录下建立一个本人姓名的文件夹，文件夹内放以当场蓝桥杯比赛命名的markdown格式题解

**提交步骤:**

1.右上角fork本仓库至个人私有仓



2.将个人仓库clone至本地开发环境（用**ssh**方式克隆）


```powershell
git clone git@github.com:Henrik-Yao/Lanqiao.git
```

3.新增上游远程分支

先将官方仓库设置为远端分支，以便同步仓库内容

可以通过git branch -vva命令查看分支情况

```powershell
git remote add upstream git@github.com:NEUQ-ACM/Lanqiao.git
git pull upstream master
```

通过git pull upstream master可以将上游远程内容更新至当前分支

**注意，每一次提交前都要执行git pull upstream master更新分支**

4.创建本地仓库的开发分支

```powershell
git checkout -b henrik
git branch
```

其中“henrik”分支名请设置为自己的名字缩写，然后可以用“git branch”查看当前位于哪个分支

----

**此时进入本地对应文件夹提交自己的代码**

---

5.增加修改到本地仓库中

add后面的 . 表示增加所有修改
git status可以查看当前提交状态

```powershell
git add .
git status
```
6.提交至本地仓库


-m参数后跟的是message，简略说明你的修改内容


```powershell
git commit -m "Upload henrik’s homework"
git status
```

7.Push代码到自己的远程仓库
git log可以查看日志


```powershell
git push origin henrik
git log
```

8.回到个人网页提交pr

这里会自动检测到修改的分支，点击绿色按钮即可

![在这里插入图片描述](https://img-blog.csdnimg.cn/2a70e1def77b40e1b3172b175467020e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBASGVucmlrLVlhbw==,size_20,color_FFFFFF,t_70,g_se,x_16)

创建pr

![在这里插入图片描述](https://img-blog.csdnimg.cn/ad133de76f9d4de78ce44e7672f02f19.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBASGVucmlrLVlhbw==,size_20,color_FFFFFF,t_70,g_se,x_16)
提交完成

![在这里插入图片描述](https://img-blog.csdnimg.cn/0bda573d49f044748eb85d646755b77d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBASGVucmlrLVlhbw==,size_20,color_FFFFFF,t_70,g_se,x_16)

