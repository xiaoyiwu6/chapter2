#ifndef LEETCODE_H
#define LEETCODE_H

#include <string>

//找出最长不重复字符的子串长度
int lengthOfLongestSubstring(std::string s)
{
    size_t pos = 0;
    size_t begin, end;
    int max = 1;
    if (s.empty())
        return 0;
    while (pos < s.size() - 1)
    {
        begin = end = pos;
        //寻找后续字符串中出现当前子串部分字符的位置
        size_t ix = s.find_first_of(s.substr(begin, end - begin + 1), end+1);
        while (ix != end+1 && end < s.size() - 1)
        { //保证不越界，同时如果搜到末尾返回npos也比end大可增加
            ++end;
            //更新最长子串
            if (end - begin + 1 > max)
                max = end - begin + 1;
            ix = s.find_first_of(s.substr(begin, end - begin + 1), end+1);
        }
        if (end - begin + 1 > max)
            max = end - begin + 1;
        pos++;
    }
    return max;
}

#endif