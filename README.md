# 数据结构和算法

## 数据结构

什么是数据结构？
> 数据结构（data struct）是带有结构特性的数据元素的集合，它研究的是数据的逻辑结构和数据的物理结构以及它们之间的相互关系。
---

## 算法

什么是算法？
> 算法是用代码解决实际问题的实现。

实际使用代码解决问题的方法不止一种，算法有好有坏，衡量算法的优劣是算法的复杂度，常用下边两个指标表示：  

+ **时间复杂度T(n)**：算法程序在执行时消耗的时间长度，一般与输入数据的规模n有关。
+ **空间复杂度S(n)**：算法程序在执行时占用的存储单元长度，同样与数据的输入规模n有关，大部分情况下，我们都是采取空间换时间的算法。  

为了便于表示，使用**大O符号**来表示复杂度。

+ **大O符号（big O notation）**：是用于描述函数渐进行为的数学符号。

> 使用冒泡排序，需要进行两次轮询，两次轮询的次数大概为 *(n-1)(n-1)* ，最终大概需要执行n的平方次，这种算法的时间复杂度为O(n^2)。

在不同的复杂度下，n比较小时，算法之间的差距不大，而随着n的数量级逐渐增加，不同复杂度之间的差距越来越大。常用函数的增长曲线：
![算法复杂度图片](https://www.yuque.com/api/filetransfer/images?url=https%3A%2F%2Fs2.loli.net%2F2022%2F07%2F09%2FTr6jI5uPzy2NeDd.png&sign=528ff02914c2fa46f992bf5af210617b80a2f26b1d799e287c2b3c530caa05c2)  

所以在设计算法时，一定要考虑时间和空间复杂度的问题，这里列出常用函数的增长表：
函数|类型|解释
:--:|:--:|:--:
O(1)|常数阶|如果算法能够优化到这个程度，那么基本上算是最快的算法了。
O(\log_{2}n)|对数阶|仅次于常数阶的速度，我们后面会介绍的二分搜索算法，就能够到达这个级别。
O(n)|线性阶|我们后面介绍的线性表插入、删除数据，包括动态规划类算法能够达到线性阶。
O(n\log_{2}n)|线性对数阶|相当于在对数阶算法外层套了一层线性阶循环。
O(n^2)|平方阶|我们前面学习的冒泡排序，需要进行两重循环，实际上就是平方阶。
O(n^3)|立方阶|从立方阶开始，时间复杂度就开始变得有点大了。
O(2^n)|指数阶|我们前面介绍的斐波那契数列递归算法，就是一个指数阶的算法，因为它包含大量的重复计算。
O(n!)|阶乘|这个增长速度比指数阶还恐怖，但是一般很少有算法能达到这个等级。
---