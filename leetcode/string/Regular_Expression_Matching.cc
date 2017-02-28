/*
 * Filename   Regular_Expression_Matching.cc
 * CreateTime 2017-02-27 18:51:05
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

/*
 这道求正则表达式匹配的题和那道 Wildcard Matching 通配符匹配的题很类似，
 不同点在于*的意义不同，在之前那道题中，*表示可以代替任意个数的字符，而
 这道题中的*表示之前那个字符可以有0个，1个或是多个，就是说，字符串a*b，
 可以表示b或是aaab，即a的个数任意，这道题的难度要相对之前那一道大一些，
 分的情况的要复杂一些，需要用递归Recursion来解，大概思路如下：

 - 若p为空，若s也为空，返回true，反之返回false
 - 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
 - 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，
   且从各自的第二个字符开始调用递归函数匹配
 - 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个
   字符的p，若匹配返回true，否则s去掉首字母
 - 返回调用递归函数匹配s和去掉前两个字符的p的结果
 */

#include <iostream>
using namespace std;


