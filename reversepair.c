
int tmp[50010];

int mergeRev(int* nums, int lo, int hi)
{
    int mi = (lo + hi) / 2;
    // printf("lo:%d hi:%d mi:%d\n", lo, hi, mi);
    int revCount = (lo != mi) ? mergeRev(nums, lo, mi) + mergeRev(nums, mi, hi) : 0;
    int i = lo, plo = lo, phi = mi;
    while (plo < mi && phi < hi) {
        if (nums[plo] <= nums[phi]) {
            tmp[i++] = nums[plo++];
            revCount += phi - mi;
        } else {
            tmp[i++] = nums[phi++];
        }
    }
    while (plo < mi) {
        tmp[i++] = nums[plo++];
        revCount += phi - mi;
    }
    while (phi < hi) {
        tmp[i++] = nums[phi++];
    }
    memcpy(nums + lo, tmp + lo, (hi - lo) * sizeof(int));
    return revCount;
}
int reversePairs(int* nums, int numsSize)
{
    return mergeRev(nums, 0, numsSize);
}
