
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> lst;
        lst.reserve(n);
        lst.push_back(1);
        int len = primes.size();
        vector<vector<int>::iterator> ps(primes.size(), lst.begin());
        for (int i = 2; i <= n; i++) {
            int m = *ps.front() * primes[0];
            for (int i = 1; i < len; i++) {
                m = min(*ps[i] * primes[i], m);
            }
            lst.push_back(m);
            for (int i = 0; i < len; i++) {
                if (*ps[i] * primes[i] == m) {
                    ps[i]++;
                }
            }
        }
        return lst.back();
    }
};