#include <algorithm>
#include <stdio.h>
using namespace std;
pair<int, int> box[6];

bool Judge() {
  bool isSame = true;
  for (int i = 0; i < 6; i += 2) {
    if (box[i] != box[i + 1]) {
      isSame = false;
      break;
    }
  }
  // 0, 2, 4 are not same
  // 这道题需要用到长方体的性质。
  // 先对输入数据进行排序，使每个矩形都按（宽，长）的方式记录，使宽小于长，
  // 以宽的长度为优先，对六个面排序。如果POSSIBLE，那么每两组矩形应该相同，
  // 这样只需要比较第0，2，4个。因为要形成长方体，这三个矩形的边应该两两配对。
  // 其中，第0个的宽必然为所有边中最小的，与其配对的必然是其他矩形的边中最小的，即第2个的宽。
  // 两个矩形之间只能有一条边相连，所以第0个的长必然和第4个相连，第2个的长也必然和第4个相连。
  // 因为第0个的宽与第2个的宽相连，即相等，而第0个又在第2个前面，所以第0个的长必然小于第2个的长。
  // 所以第0个的长必然与第4个的宽相连，第2个的长必然与第4个的长相连，
  bool isCube;
  isCube = (box[0].first == box[2].first && box[0].second == box[4].first &&
            box[2].second == box[4].second);
  return isSame && isCube;
}

int main() {
  int i;
  while (1) {
    for (i = 0; i < 6; i++) {
      if (scanf("%d%d", &box[i].first, &box[i].second) != 2)
        return 0;
      if (box[i].first > box[i].second)
        swap(box[i].first, box[i].second);
    }
    sort(box,
         box + 6); //我试了一下，此处排序是按照先first递增，其次second递增排序
    puts(Judge() ? "POSSIBLE" : "IMPOSSIBLE");
  }
}
