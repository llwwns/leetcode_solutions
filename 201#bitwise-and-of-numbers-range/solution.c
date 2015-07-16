int rangeBitwiseAnd(int m, int n) {
    register int s = n ^ m;
    s |= s >> 1;
    s |= s >> 2;
    s |= s >> 4;
    s |= s >> 8;
    s |= s >> 16;
    return m & ~s;
}