/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        string::iterator p = s.begin();
        return parseNestedInteger(p, s.end());
    }
private:
    NestedInteger parseInt(string::iterator &p, string::iterator e) {
        int r = 0;
        bool m = false;
        if (*p == '-') {
            m = true;
            p++;
        }
        for (; p != e && *p <= '9' && *p >= '0'; p++) {
            r = r * 10 + *p - '0';
        }
        return NestedInteger(m ? -r : r);
    }
    NestedInteger parseList(string::iterator &p, string::iterator e) {
        NestedInteger lst;
        for (p++; *p != ']';) {
            lst.add(parseNestedInteger(p, e));
            if (*p == ',') p++;
        }
        p++;
        return lst;
    }
    NestedInteger parseNestedInteger(string::iterator &p, string::iterator e) {
        if (*p == '[') {
            return parseList(p, e);
        } else {
            return parseInt(p, e);
        }
    }
};