class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> count = {0};
        for (char c : magazine) {
            count[c - 'a']++;
        }
        for (char c : ransomNote) {
            count[c - 'a']--;
        }
        return all_of(count.begin(), count.end(), [](int i) {return i >= 0;});
    }
};