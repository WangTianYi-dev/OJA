#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define ALL(x) x.begin(), x.end()

#define INS(x) inserter(x, x.begin())
//插入迭代器，用于后面的取并集、交集以及合并后返回一个set<int>，详见第43至49行的详细使用。

map<set<int>, int> IDdata; //   将集合映射成数，具体为什么用set<int>相信每一位了解stl的C党都明白。
// IDdata[x]中存放了setdata中x的序号，即ID
vector<set<int>> setdata; //可以理解为集合的检索表，用于对集合ID的分配与对已知ID的集合的查询。

int ID(set<int> x)
//查找给定集合x的ID。若找不到，分配一个新ID。
{
    // 如果存在此集合
    if (IDdata.count(x))
        return IDdata[x];
    // 如果不存在
    // 将x存入setdata且IDdata[x]存放了setdata中x的序号
    setdata.push_back(x);
    return IDdata[x] = setdata.size() - 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        stack<int> s;
        // s中存放的是集合的ID
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            string instruct;
            cin >> instruct;
            if (instruct == "PUSH")
            // PUSH：将空集{}压栈。
                s.push(ID(set<int>()));
            else if (instruct == "DUP")
            // DUP：将栈顶元素复制一份压入栈中。
                s.push(s.top());
            else {
                set<int> x1 = setdata[s.top()];
                s.pop();
                set<int> x2 = setdata[s.top()];
                s.pop();
                set<int> x;
                if (instruct == "UNION")
                // UNION：先进行两次弹栈，将获得的集合A和B取并集，将结果压栈。
                    set_union(ALL(x1), ALL(x2), INS(x));
                else if (instruct == "INTERSECT")
                // INTERSECTION：先进行两次弹栈，将获得的集合A和B取交集，将结果压栈。
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                else if (instruct == "ADD") {
                // ADD：先进行两次弹栈，将获得的集合A和B中，先出栈的集合（如A先）加入到后出栈的集合，将结果压栈
                    x = x2;
                    x.insert(ID(x1));
                // x中包含了x1的ID
                }
                s.push(ID(x));
            }
            cout << setdata[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}