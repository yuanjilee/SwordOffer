#include <iostream>
#include <vector>
using namespace std;
/**
 * 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * 输入："123.45e+6"   输出：true
 * 考点：字符串
 * 分析：1. 只能以 + - 数字 开头
 * 2. 之后只能出现 + - . e E 数字，且除数字外只能出现一次
 * 3. 并且 + - 只能出现在 e E 之后，且不能出现 .
 * 4. .只能出现在数字之后
 */

/**
 * 解法一：等有空整理下答案，有点乱
 * 时间复杂度：
 */

class Solution {
   public:
    bool isNumeric(string str) {
        if (str.size() == 1) {
            return isdigit(str[0]);
        }
        if (!isdigit(str[str.size() - 1])) {
            return false;
        }

        bool hasD = false;
        bool hasE = false;

        for (int i = 0; i < str.size() - 1; i++) {
            char c = str[i];
            char c_1 = str[i + 1];
            if (i == 0) {
                if (c == '+' || c == '-' || isdigit(c)) {
                    if (c == '+' || c == '-') {
                        if (isdigit(c_1) || c_1 == '.') {
                        } else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            } else if (c == '+' || c == '-' || isdigit(c) || c == '.' ||
                       c == 'e' || c == 'E') {
                if (hasE) {
                    if (c == 'e' || c == 'E' || c == '.') {
                        return false;
                    }
                }
                if (hasD) {
                    if (c == '.') {
                        return false;
                    }
                }
                if (c == 'e' || c == 'E') {
                    hasE = true;
                    if (c_1 == '+' || c_1 == '-' || isdigit(c_1)) {
                    } else {
                        return false;
                    }
                } else if (c == '.' || c == '+' || c == '-') {
                    if (c == '.') {
                        hasD = true;
                    } else {
                        if (isdigit(c_1) &&
                            (str[i - 1] == 'e' || str[i - 1] == 'E')) {
                        } else {
                            return false;
                        }
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * 解法二：
 * 时间复杂度：
 */
class Solution2 {
   public:
};

int main() {
    cout << Solution().isNumeric("123.45e+6") << endl;
    return 0;
}