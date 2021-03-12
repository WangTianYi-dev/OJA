#include <bits/stdc++.h>

using namespace std;

const int GSize = 5;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0)
        : x(x)
        , y(y)
    {
    }
    Point(const Point& p)
        : x(p.x)
        , y(p.y)
    {
    }
    Point operator+(Point p)
    {
        Point rp;
        rp.x = this->x + p.x;
        rp.y = this->y + p.y;
        return rp;
    }
};

typedef Point Vector;
vector<string> grid;
Point ePos;
map<char, Vector> DIRS;

inline bool valid(const Point& p)
{
    return p.x >= 0 && p.x < GSize && p.y >= 0 && p.y < GSize;
}

void printGrid()
{
    for (int i = 0; i < GSize; i++) {
        for (int j = 0; j < GSize; j++) {
            if (j) {
                cout << ' ';
            }
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

bool tryMove(char cmd)
{
    // cout << "move " << cmd << ":" << endl;
    if (!DIRS.count(cmd)) {
        //cout << "False1" << endl;
        return false;
    } else {
        Point p = ePos.operator+(DIRS[cmd]);
        if (!valid(p)) {
            //cout << "False2" << endl;
            return false;
        }
        swap(grid[p.x][p.y], grid[ePos.x][ePos.y]);
        ePos = p;
        //printGrid();
        return true;
    }
}

int main()
{
    int t = 1;
    string line;
    DIRS['A'] = Vector(-1, 0);
    DIRS['B'] = Vector(1, 0);
    DIRS['L'] = Vector(0, -1);
    DIRS['R'] = Vector(0, 1);
    while (true) {
        grid.clear();
        ePos.x = -1;
        ePos.y = -1;
        for (int i = 0; i < GSize; i++) {
            getline(cin, line);
            line.push_back(' ');
            if (line == "Z ") {
                return 0;
            }
            // assert(line.size() == GSize);
            for (int j = 0; j < GSize; j++) {
                if (line[j] == ' ') {
                    // assert(ePos.x == -1 && ePos.y == -1);
                    ePos.x = i;
                    ePos.y = j;
                }
            }
            if (line.length() == GSize) {
                grid.push_back(line);
            } else {
                grid.push_back(line.substr(0,GSize));
            }
        }
        // cout << "debug: " << endl;
        // printGrid();
        char move;
        string moves;
        while (true) {
            getline(cin, line);
            assert(!line.empty());
            bool end = ((*line.rbegin()) == '0');
            if (!end) {
                moves.append(line);
            } else {
                moves.append(line, 0, line.size() - 1);
                break;
            }
        }
        bool legal = true;
        for (int i = 0; i < moves.size(); i++) {
            if (!tryMove(moves[i])) {
                legal = false;
                break;
            }
        }
        if (t > 1) {
            cout << '\n';
        }
        cout << "Puzzle #" << t++ << ":" << endl;
        if (legal) {
            printGrid();
        } else {
            cout << "This puzzle has no final configuration." << endl;
        }
    }
    return 0;
}
