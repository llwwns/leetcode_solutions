class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        stringstream out;
        auto p = nums.begin();
        int b = *p, c = 1;
        for (p++; p != nums.end(); p++) {
            if (*p == b+c) {
                c++;
            } else {
                out << b;
                if (c > 1) {
                    out << "->" << b + c - 1;
                }
                ans.push_back(out.str());
                out.str("");
                b = *p;
                c = 1;
            }
        }
        out << b;
        if (c > 1) {
            out << "->" << b + c - 1;
        }
        ans.push_back(out.str());
        return ans;
    }
};