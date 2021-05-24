#include "leetcode.h"

class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &arr) {
        int l = arr.size(), w = arr[0].size();
        int first_sum = 0, second_sum = 0, first_pos = -1;
        for (int i = 0; i < l; i++) {
            int tfs = INT_MAX, tss = INT_MAX;
            for (int j = 0; j < w; j++) {
                int cur_sum = (j == first_pos) ? second_sum + arr[i][j] : first_sum + arr[i][j];
                if (cur_sum < tfs) {
                    tss = tfs;
                    tfs = cur_sum;
                    first_pos = j;
                } else if (cur_sum < tss) {
                    tss = cur_sum;
                }
            }
            first_sum = tfs;
            second_sum = tss;
        }
        return first_sum;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/solution/xia-jiang-lu-jing-zui-xiao-he-ii-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。