//��������� ��������� ����������� ���������� �����, ����������� ��� ����������� ���������� ���� �� ������� pos1 � pos2. ���������� � ������� �������. 

#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

bool overlap(int mx, int my, int nx, int ny)
{
    if (mx < 0 || mx > 7) return false;
    if (my < 0 || my > 7) return false;
    if (nx < 0 || nx > 7) return false;
    if (ny < 0 || ny > 7) return false;
    return
        mx == nx && my == ny;
}

int knight(string pos1, string pos2) {
    int nx, ny, mx, my;
    nx = pos1[0] - 'a'; 
    ny = pos1[1] - '1';
    mx = pos2[0] - 'a'; 
    my = pos2[1] - '1';

    queue<int> runX;
    queue<int> runY;
    int dx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
    int dy[] = { -1,  1, -2,  2, -2,  2, -1,  1 };
    runX.push(nx);
    runY.push(ny);
    int j = 1;

    for (int i = 0; i < 8; i++) {

        runX.push(runX.front() + dx[i]);
        runY.push(runY.front() + dy[i]);
        if (overlap(runX.back(), runY.back(), mx, my)) {
            break;
        }
        if (i == 7) {
            runX.pop();
            runY.pop();
            if (pow(8, j) <= runX.size()) { ++j; }
            i = -1;
        }
    }

    return j;
}

int main()
{
    setlocale(0, "rus");

    while (true) {
        string r, t;
        cout << "������� ������� ����: ";
        cin >> r;
        cout << "������� ������� �����: ";
        cin >> t;
        cout <<"�����: " << knight(r, t) << endl;;
    }

    cin.get();
    return 0;
}
