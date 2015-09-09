class Solution {
public:
    int countPrimes(int n) {
        static_assert(sizeof(long) == 4 || sizeof(long) == 8, "size of long is not support");
        static const long BIT_SIZE = sizeof(long) * 8;
        static const long BIT_SHIFT = BIT_SIZE == 32 ? 5 : 6;
        static const long BIT_MASK = (1 << BIT_SHIFT) - 1;
        if (n <= 2) 
        {
            return 0;
        }
        long * prime_map = new long[n / BIT_SIZE + 1];
        memset(prime_map, -1, sizeof(long) * n / BIT_SIZE + 1);
        int c = 1, p;
        for (p = 3; p * p < n; p+=2)
        {
            if (prime_map[p >> BIT_SHIFT] & (1l<<(p & BIT_MASK)))
            {
                c++;
                for (long i = p + (p << 1); i < n; i += p << 1)
                {
                    prime_map[i >> BIT_SHIFT] &= ~(1l << (i & BIT_MASK));
                }
            }
        }
        for (; p < n; p+=2)
        {
            if (prime_map[p >> BIT_SHIFT] & (1l<<(p & BIT_MASK)))
            {
                c++;
            }
        }
        delete [] prime_map;
        return c;
    }
};