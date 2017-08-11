package template;

import java.awt.datatransfer.Transferable;

public class DP的模板 {
//DP的题型在leetcode里一共有几种
//1.矩阵DP matrix（eg 机器人左上到右下 triangle）
//2. 1维DP sequence （eg word break ， jump game）
//3. 2维DP 2sequence （eg edit distan等把A词变成B词的）
//4. Interval (eg merge interval, insert interval)
//
//所以 这几类题 要怎么做呢
//1. status  
// Matrix      : f[i][j] 从1,1走到i,j ...
// Sequence    : f[i] 前i个 ***
// 2 Sequences : f[i][j] word1前i个匹配上word前j个 *** 
// Interval    : f[i][j] 表示区间i-j ***

//2.Transfer  DP 推导过程
//LCS: f[i][j] = max(f[i-1][j], f[i][j-1], f[i-1][j-1] + 1)  longest common sequence
// LIS: f[i] = max(f[j] + 1, a[i] >= a[j])   longest increasing sequence
// 分析最后一次划分/最后一个字符/最后***

//3. initialize  初始状态
// f[i][0] f[0][i]
// f[0]
// LIS: f[1..n] = 1;

//4. answer  
// LIS: max{f[i]}
// LCS: f[n][m]


//5. loop   
// Interval: 区间从小到大，先枚举区间长度. Palindrome Patitioning II 



}
