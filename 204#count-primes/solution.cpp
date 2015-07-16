class Solution {
public:
    int countPrimes(int n) {
        static int BIT_SIZE = sizeof(long) * 4;
        static int BIT_SHIFT = BIT_SIZE == 32 ? 5 : 6;
        static int BIT_MASK = (1 << BIT_SHIFT) - 1;
        if (n <= 2) 
        {
            return 0;
        }
        long * prime_map = new long[n / BIT_SIZE + 1];
        memset(prime_map, -1, sizeof(long) * n / BIT_SIZE + 1);
        int c = 1, p;
        for (p = 3; p * p < n; p+=2)
        {
            if (prime_map[p >> BIT_SHIFT] & (1<<(p & BIT_MASK)))
            {
                c++;
                for (int i = p + (p << 1); i < n; i += p << 1)
                {
                    prime_map[i >> BIT_SHIFT] &= ~(1 << (i & BIT_MASK));
                }
            }
        }
        for (; p < n; p+=2)
        {
            if (prime_map[p >> BIT_SHIFT] & (1<<(p & BIT_MASK)))
            {
                c++;
            }
        }
        delete [] prime_map;
        return c;
    }
};