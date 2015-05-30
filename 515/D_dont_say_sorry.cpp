#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;

char a[2005][2005], tile[] = {"^<v>"};
int n, m, cnt = 0, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};


bool inb(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m ? 0 : 1;
}

queue<P> que;

void Push(queue<P> *que, int x, int y) {
  if (!inb(x, y) || a[x][y] != '.') return;
  int aj = 0;
  for (int i = 0; i < 4; i++) {
    int X = x + dx[i], Y = y + dy[i];
    if (inb(X, Y) && a[X][Y] == '.') aj++;
  }
  if (aj == 1) (*que).push(make_pair(x, y));
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt += (a[i][j] == '.');
      Push(&que, i, j);
    }
  }
  while (que.size()) {
    int x = que.front().first, y = que.front().second; que.pop();
    for (int i = 0; i < 4; i++) {
      int X = x + dx[i], Y = y + dy[i];
      if (!inb(X, Y) || a[X][Y] != '.') continue;
      cnt -= 2;
      a[x][y] = tile[(i + 2) % 4];
      a[X][Y] = tile[i];
      for (int j = 0; j < 4; j++) {
        Push(&que, X + dx[j], Y + dy[j]);
      }
      break;
    }
  }
  if (cnt) {
    puts("Not unique");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    puts(a[i]);
  }
}
