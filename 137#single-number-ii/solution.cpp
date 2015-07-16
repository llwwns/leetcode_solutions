class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long temp = 0;
        long long a ,b;
        for (unsigned int i : nums) {
            b = 0;
            a = 1;
            while (i > 0 || temp > 0)
            {
                b += (temp + i) % 3 * a;
                a = a * 3;
                i /= 3;
                temp /= 3;
            }
            temp = b;
        }
        return temp;

    }
};