class Solution {
public:
    int minDistance(string word1, string word2) {
        const char *s1 = word1.c_str(), *s2 = word2.c_str();
        int l1 = word1.length(), l2 = word2.length();
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        int* dis = new int[(l1+1) * (l2+1)];
        int len=l2+1;

        int i, j, m;
        for (j = 0; j <= l2; j++) {
            dis[j] = j;
        }
        for (i = 1; i <= l1; i++) {
            dis[i * len] = i;
            for (j = 1; j <= l2; j++) {
                m = dis[(i-1) * len + j - 1] + (s1[i-1] == s2[j-1] ? 0 : 1);
                m = min(m, dis[(i-1) * len + j] + 1);
                m = min(m, dis[i * len + j- 1] + 1);
                dis[i*len+j] = m;
            }
        }
        m = dis[(l1+1) * (l2+1) - 1];
        delete [] dis;
        return m;
    }
};