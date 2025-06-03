#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (pairs.count(c)) {
                if (stk.empty() || stk.top() != pairs[c])
                    return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
