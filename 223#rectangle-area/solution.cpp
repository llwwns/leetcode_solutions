class Solution {
public:
    void cmp(int &a, int &b) {
        if (a > b) swap(a, b);
    }
    int join(int a, int b, int c, int d) {
        if (c > b || a > d) return 0;
        return min(b, d) - max(a, c);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        cmp(A, C);
        cmp(B, D);
        cmp(E, G);
        cmp(F, H);
        return (C - A)*(D - B) - join(A, C, E, G) * join(B, D, F, H) + (G - E)*(H - F);
    }
};