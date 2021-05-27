#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
/**
 * 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 * 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
 * 输入：如果当前字符流没有存在出现一次的字符，返回#字符。
 * 考点：字符串
 * 分析：想起了数组中第一次的出现的数，或者只出现一次的数。
 * 用 map 来存储出现次数，然后在一个有序列表里对比map中次数即可。
 */

/**
 * 解法一：辅助 queue 和 map
 * 时间复杂度：O(n)
 */

class Solution {
   public:
    // Insert one char from stringstream
    queue<char> queue;
    unordered_map<char, int> map;

    void Insert(char ch) {
        if (map.find(ch) == map.end()) {  // 第一次出现加入到队列
            queue.push(ch);
        }
        map[ch]++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!queue.empty()) {
            char c = queue.front();
            if (map[c] == 1) {
                return c;
            } else {
                queue.pop();
            }
        }

        return '#';
    }
};

/**
 * 解法二：直接存在string
 * 时间复杂度：
 */
class Solution2 {
   public:
    // Insert one char from stringstream
    string string;
    unordered_map<char, int> map;

    void Insert(char ch) {
        string += ch;
        map[ch]++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (char c : string) {
            if (map[c] == 1) {
                return c;
            }
        }

        return '#';
    }
};

int main() {
    Solution2 s = Solution2();
    s.Insert('g');
    s.Insert('o');
    s.Insert('o');
    s.Insert('g');
    s.Insert('l');
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;
    return 0;
}