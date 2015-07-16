class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        int *arr = ratings.data();
        int *end = ratings.data() + ratings.size();
        int sum = 1, ll, lr;
        do {
            ll = 0;
            while (arr+1 != end && *arr == *(arr + 1)) {
                sum++;
                arr++;
            }
            while(arr+1 != end && *arr < *(arr+1)) {
                ll++;
                arr++;
            }
            lr = 0;
            while (arr+1 != end && *arr > *(arr+1)) {
                lr++;
                arr++;
            }
            sum += max(ll, lr) + ((ll * ll + ll) >> 1) + ((lr * lr + lr) >> 1);
        } while (arr+1 != end);
        return sum;
    }
};