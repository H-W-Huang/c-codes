O  Mine Sweeping

Time Limit:500MS  Memory Limit:65535K
题型: 编程题   语言: 无限制
描述

The opening ceremony of the 28th Asia Game is coming. In order to prevent the game from being attacked by terrorists, Asia Compete Machinery (ACM) takes lots operations as security measures.



Mine sweeping is one of the most important operations, so a special machine has been invented to detect mines. We assume the fields which need to be detected are configuration as several continuous grids, and there is at most one mine in each grid (See Fig a).



Fig a                                    Fig b

When using the machine to detect the ith grid, the machine will provide the number xi, which means the total number of mines in the ith, (i-1)th and (i+1)th grids. Except the first and last grid, the detect result of the first grid is the number of 1st and 2nd grid, and the result of the last grid is the last and the last but two grids. The approximate detect result for Fig a is as Fig b. However, some of these machines may have bugs and provide unreal result. For example, one of the unreal detect result for Fig a is as Fig c. The red grid is unreal result.



Fig c

It is clearly that Fig b is possible result, but Fig c is not. Now, give you the detect result for a given field, please calculate if this result is possible.


输入格式

The first line of input is an integer T (T <= 100), indicate the number of test cases.

Each test case contains two lines.

The first line of each test case is an integer N (3 <= N <= 1000), indicate the length of the given field. The second line contains N integers Xi (0 <= Xi <= 3), each Xi indicate the detect result for grid i.

输出格式

If the detect result is possible, please output “YES”, otherwise, output “NO”.

输入样例

3
13
1 1 1 1 1 1 1 1 1 0 1 2 2
13
1 1 1 1 1 2 1 1 1 0 1 2 2
7
1 2 3 3 3 2 1
输出样例

YES
NO
YES
Provider

admin
