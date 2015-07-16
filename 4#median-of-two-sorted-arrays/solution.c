int getTarget(int t, int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int left = 0, right = nums1Size > (t + 1) ? (t + 1) : nums1Size, middle;
    int a, rb, target;
    if (t == 0 && nums2Size == 0) return *nums1;
    while (left < right) {
        middle = (left >> 1) + (right >> 1) + (left & right & 1);
        a = *(nums1 + middle);
        rb = (t - middle);
        if (rb == 0) {
            if (*nums2 >= a || nums2Size == 0) {
                return a;
            }
            right = middle;
        } else if (nums2Size == rb) {
            if (*(nums2 + rb - 1) <= a) {
                return a;
            }
            left = middle + 1;
        } else if (nums2Size > rb) {
            if (*(nums2 + rb - 1) <= a && *(nums2 + rb) >= a) {
                return a;
            }
            if (*(nums2 + rb - 1) > a) {
                left = middle + 1;
            } else {
                right = middle;
            }
        } else {
            left = middle + 1;
        }
    }
    return getTarget(t, nums2, nums2Size, nums1, nums1Size);
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    if (size & 1) {
        return getTarget(size >> 1, nums1, nums1Size, nums2, nums2Size);
    }
    return (getTarget((size >> 1) - 1, nums1, nums1Size, nums2, nums2Size) + getTarget(size >> 1, nums1, nums1Size, nums2, nums2Size)) / 2.0;
}
