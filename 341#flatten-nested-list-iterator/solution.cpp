/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    NestedIterator* nextItr;
    vector<NestedInteger>::iterator crr, end;
public:
    void checkNext() {
        while(nextItr != NULL && !nextItr->hasNext()) {
            delete nextItr;
            nextItr = NULL;
            crr++;
            if (crr != end) {
                if (!crr->isInteger()) {
                    nextItr = new NestedIterator(crr->getList());
                }
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        crr = nestedList.begin();
        end = nestedList.end();
        nextItr = crr == end || crr->isInteger() ? NULL : new NestedIterator(crr->getList());
        checkNext();
    }

    int next() {
        int val;
        if (nextItr != NULL) {
            val = nextItr->next();
            checkNext();
        } else {
            val = crr->getInteger();
            crr++;
            nextItr = crr == end || crr->isInteger() ? NULL : new NestedIterator(crr->getList());
            checkNext();
        }
        return val;
    }

    bool hasNext() {
        return nextItr != NULL && nextItr->hasNext() || nextItr == NULL && crr != end;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
