int reverse(int x) {
    int a = 0;
    while (x != 0) {
        if (a > 214748364 || a == 214748364 && x > 7 || a < -214748364 || a == -214748364 && x < -8) {
            return 0;
        }
        a = a * 10 + x % 10;
        x /= 10;
    }
    return a;
}