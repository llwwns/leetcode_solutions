class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int, vector<int>> stack;
        int i = 0, j, m = 0;
        stack.push(-1);
        for (char c : s) {
            if (c == '(') {
                stack.push(i);
            } else {
                if (stack.size() > 1) {
                    stack.pop();
                    j = i - stack.top();
                    if (j > m) m = j;
                } else {
                    stack.top() = i;
                }
            }
            i++;
        }
        return m;
    }
};
