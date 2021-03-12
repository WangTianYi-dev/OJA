#include <bits/stdc++.h>
using namespace std;

typedef struct Point {
    int x, y;
    Point()
    {
    }
    Point(int x, int y)
        : x(x)
        , y(y)
    {
    }
    Point operator+(const Point& p)
    {
        Point rp;
        rp.x = p.x + x;
        rp.y = p.y + y;
        return rp;
    }
} Point;
typedef Point Vector;
char grid[11][11];
map<char, Vector> move;

void init()
{
    ::move['U'] = Point(-1, 0);
    ::move['D'] = Point(1, 0);
    ::move['L'] = Point(0, -1);
    ::move['R'] = Point(0, 1);
}

bool is_eligible(int x, int y)
{
    if (grid[x][y] == '*') {
        return false;
    } else {
        if (x == 0 || y == 0) {
            return true;
        } else {
            if (grid[x - 1][y] == '*' || grid[x][y - 1] == '*') {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool is_startAcross(Point pt)
{
    int x = pt.x;
    int y = pt.y;
    if (y == 0 || grid[x][y - 1] == '*') {
        // cout << "x:" << x << " true\n" ;
        // cout << "y:" << y << " true\n" ;
        return true;
    } else {
        // cout << "x:" << x << " false\n" ;
        // cout << "y:" << y << " false\n" ;
        return false;
    }
}

bool is_startDown(Point pt)
{
    int x = pt.x;
    int y = pt.y;
    if (x == 0 || grid[x - 1][y] == '*') {
        return true;
    } else {
        return false;
    }
}

bool is_reachable(Point pt, int r, int c)
{
    int x = pt.x;
    int y = pt.y;
    bool rt = (x >= 0) && (y >= 0) && grid[x][y] != '*' && (x < r) && (y < c);
    return rt;
}

int main()
{
    init();
    for (int T = 0;; T++) {
        int r, c;
        scanf("%d", &r);
        if (r == 0) {
            return 0;
        }
        scanf("%d", &c);
        string curRow;
        vector<Point> eligs;
        for (int i = 0; i < r; i++) {
            cin >> curRow;
            for (int j = 0; j < c; j++) {
                grid[i][j] = curRow[j];
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (is_eligible(i, j)) {
                    eligs.push_back(Point(i, j));
                }
            }
        }

        if (T > 0) {
            cout << '\n';
        }
        printf("puzzle #%d:\n", T + 1);
        char tmpchar[20];
        Point tmpPoint;
        vector<string> across, down;
        string tmpstring;

        for (int i = 0; i < eligs.size(); i++) {
            if (is_startAcross(eligs[i])) {
                sprintf(tmpchar, "%3d.", i + 1);
                tmpstring = tmpchar;
                tmpstring += grid[eligs[i].x][eligs[i].y];
                tmpPoint = eligs[i] + ::move['R'];
                while (is_reachable(tmpPoint, r, c)) {
                    tmpstring += grid[tmpPoint.x][tmpPoint.y];
                    tmpPoint = tmpPoint + ::move['R'];
                }
                //printf("debug: eligs[%d]:%s\n", i, tmpstring.c_str());
                across.push_back(tmpstring);
            }
            if (is_startDown(eligs[i])) {
                sprintf(tmpchar, "%3d.", i + 1);
                tmpstring = tmpchar;
                tmpstring += grid[eligs[i].x][eligs[i].y];
                tmpPoint = eligs[i] + ::move['D'];
                while (is_reachable(tmpPoint, r, c)) {
                    tmpstring += grid[tmpPoint.x][tmpPoint.y];
                    tmpPoint = tmpPoint + ::move['D'];
                }
                //printf("debug: eligs[%d]:%s\n", i, tmpstring.c_str());
                down.push_back(tmpstring);
            }
        }
        cout << "Across\n";
        for (auto i = across.begin(); i != across.end(); i++) {
            cout << *i << '\n';
        }
        cout << "Down\n";
        for (auto i = down.begin(); i != down.end(); i++) {
            cout << *i << '\n';
        }
    }
}
