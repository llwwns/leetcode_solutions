class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string word;
        string map['z' + 1];
        set<string> set;
        auto current = pattern.begin();
        while (ss >> word) {
            if (current == pattern.end()) {
                return false;
            }
            if (!map[*current].empty()) {
                if (map[*current] != word) {
                    return false;
                }
            } else {
                if (!set.insert(word).second) {
                    return false;
                }
                map[*current] = move(word);
            }
            current++;
        }
        return current == pattern.end();
    }
};
