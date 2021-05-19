#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
 * n≤39
 * 考点：数组
 * 分析：斐波那契数列 f(n) = f(n-1) + f(n-2),(n>1, n0=0, n1=1)
 * 例如 0 1 1 2 3 5 8 13 21
 */

/**
 * 解法一：斐波那契数列符合大家输入的递归，结束条件为 n==0 || n==1
 * 优点简单直白，缺点效率低
 * 时间复杂度：O(2^n)
 */
class Solution {
   public:
    int Fibonacci(int n) { return recursion(n); }

    int recursion(int n) {
        if (n == 0 || n == 1) {  // 结束条件
            return n;
        } else {
            return recursion(n - 1) + recursion(n - 2);
        }
    }
};

/**
 * 解法二：f(n) = f(n-1) + f(n-2)，那么可以声明变量 temp1 = 0, temp2 = 1
 * 用来存储两个值，遍历n每次将temp2重新赋值为temp2+temp1,temp1赋值为上一次的temp2
 * 即可。 优点思路清晰，效率高 时间复杂度：O(n)
 */
class Solution2 {
   public:
    int Fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        } else {
            int temp1 = 0, temp2 = 1, temp;
            for (int i = 2; i <= n; i++) {
                temp = temp2;
                temp2 = temp1 + temp2;
                temp1 = temp;
            }
            return temp2;
        }
    }
};

/**
 * 解法三：对解法一递归的优化，动态规划，自顶向下备忘录法。
 * 时间复杂度：
 */
class Solution3 {
   public:
    int Fibonacci(int n) {
        vector<int> memo(n + 1, -1);
        return FibMemo(n, memo);
    }

    int FibMemo(int n, vector<int> &memo) {  // 传数组的引用
        if (memo[n] != -1) {                 // 有备忘录，直接返回
            return memo[n];
        }

        if (n < 2)
            memo[n] = n;
        else
            memo[n] = FibMemo(n - 1, memo) + FibMemo(n - 2, memo);

        return memo[n];
    }
};

int main() {
    int n;
    Solution3 s = Solution3();
    cout << "请输入 n:" << endl;
    cin >> n;
    cout << s.Fibonacci(n) << endl;
    return 0;
}