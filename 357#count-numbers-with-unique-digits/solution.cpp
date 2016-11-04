class Solution {
    static array<int, 10> arr;
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n < 1) {
            return 1;
        }
        if (n > 10) {
            n = 10;
        }
        return arr[n-1];
    }
};
array<int, 10> Solution::arr = {{
        10,
        91,
        739,
        5275,
        32491,
        168571,
        712891,
        2345851,
        5611771,
        8877691
}};