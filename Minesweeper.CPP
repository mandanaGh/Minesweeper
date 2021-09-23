#include <graphics.h>

#include <conio.h>

#include <string.h>

#include <dos.h>

#include <stdlib.h>

#include <time.h>

void func22();
void graph();
REGS r;
union REGS z;

class min {
  public:
    int st[8][8];
  int st1[8][8];
  int ma, mi;
  min() {
    int i, j;
    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++) {
        st[i][j] = 0;
        st1[i][j] = 0;
      }
    ma = 0;
    mi = 10;
  }
  void init();
  void func1(int a);
  void func3(int x, int y, int a);
  void draw_flag(int x, int y);
  void erase_flag(int x, int y);
  void number(int b);
  void func2(int x, int y, int a);
  void bomb(int x, int y);
  void open(int x, int y);
  void opensquare(int i, int j);
  void openzero(int i, int j);
  void cheaker();
};
//*****************************************************************
void min::init() {
  int z[10] = {
    0
  }, i, j, k, r, a, m, n;

  randomize();
  z[0] = random(63) + 1;
  k = 0;
  while (k < 10) {
    a = random(63) + 1;
    j = 0;
    for (i = 0; i <= k; i++)
      if (z[i] == a) j = 1;
    if (j == 0) {
      k++;
      z[k] = a;
    }
  }

  for (i = 0, r = 1; i < 8; i++)
    for (j = 0; j < 8; j++) {
      for (k = 0; k < 10; k++)
        if (r == z[k]) st[i][j] = -1;
      r++;
    }

  for (i = 0, r = 1; i < 8; i++)
    for (j = 0; j < 8; j++)
      if (st[i][j] == -1) {
        if ((r % 8 != 0) && ((r - 1) % 8 != 0)) {
          for (m = -8; m <= 8; m += 8)
            for (n = -1; n <= 1; n++) {
              a = r + m + n;
              func1(a);
            }
        }

        if (r % 8 == 0) {
          for (m = -8; m <= 8; m += 8)
            for (n = -1; n <= 0; n++) {
              a = r + m + n;
              func1(a);
            }
        }

        if ((r - 1) % 8 == 0) {
          for (m = -8; m <= 8; m += 8)
            for (n = 0; n <= 1; n++) {
              a = r + m + n;
              func1(a);
            }
        }
        r++;
      }
  else r++;
}
//*****************************************************************
void min::func1(int a) {
  int p, q, s, b = 0;
  if ((a >= 1) && (a <= 64)) {
    for (p = 0, s = 1; p < 8; p++) {
      for (q = 0; q < 8; q++)
        if (a == s) {
          b = 1;
          if (st[p][q] != -1) {
            st[p][q] += 1;
            s++;
          }
          if (st[p][q] == -1) s++;
        }
      else s++;
      if (b == 1) break;
    }
  }
}
//*****************************************************************
void min::func3(int x, int y, int a) {
  if (ma == 0) {
    int b = 0, i, j, r, s, d = 0, m, n;
    for (i = 0, r = 1; i < 8; i++) {
      for (j = 0; j < 8; j++)
        if (a == r) {
          b = 1;
          m = i;
          n = j;
          if (st1[i][j] == 0) st1[i][j] = 1;
          else st1[i][j] = 0;
          s = st1[i][j];
          r++;
        }
      else r++;
      if (b == 1) break;
    }
    if (st[m][n] == -2) {
      d++;
      st1[m][n] = 0;
    }
    if ((s == 1) && (d == 0)) {
      draw_flag(x, y);
      number(-1);
    }
    if ((s == 0) && (d == 0)) {
      erase_flag(x, y);
      number(1);
    }

  }
}
//*****************************************************************
void min::draw_flag(int x, int y) {

  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(RED);
  rectangle(x + 5, y + 4, x + 7, y + 6);
  setfillstyle(SOLID_FILL, RED);
  floodfill(x + 6, y + 5, RED);
  line(x + 8, y + 4, x + 8, y + 11);
  line(x + 5, y + 12, x + 10, y + 12);

  z.x.ax = 1;
  int86(0x33, & z, & z);
}
//*****************************************************************
void min::erase_flag(int x, int y) {
  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(LIGHTGRAY);
  rectangle(x + 4, y + 3, x + 11, y + 13);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  floodfill(x + 5, y + 4, LIGHTGRAY);

  z.x.ax = 1;
  int86(0x33, & z, & z);

}
//*****************************************************************
void min::number(int b) {
  char str[10];
  mi += b;
  itoa(mi, str, 10);

  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(RED);
  rectangle(251, 147, 277, 168);
  setfillstyle(SOLID_FILL, RED);
  floodfill(255, 150, RED);

  setcolor(LIGHTGRAY);
  rectangle(251, 147, 277, 168);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  floodfill(255, 150, LIGHTGRAY);

  setcolor(1);
  if (strlen(str) == 1) outtextxy(261, 154, str);
  if (strlen(str) == 2) outtextxy(257, 154, str);
  if (strlen(str) == 3) outtextxy(252, 154, str);

  z.x.ax = 1;
  int86(0x33, & z, & z);
}
//*****************************************************************
void min::func2(int x, int y, int a) {
  if (ma == 0) {
    int b = 0, i, j, r;

    for (i = 0, r = 1; i < 8; i++) {
      for (j = 0; j < 8; j++)
        if (a == r) {
          b = 1;
          if ((st[i][j] == -1) && (st1[i][j] == 0)) bomb(x, y);

          if ((st[i][j] != -1) && (st[i][j] != -2) && (st[i][j] != 0) && (st1[i][j] == 0))
            opensquare(i, j);

          if ((st[i][j] != -1) && (st[i][j] != -2) && (st[i][j] == 0) && (st1[i][j] == 0))
            openzero(i, j);

          cheaker();
          r++;
        }
      else r++;
      if (b == 1) break;
    }
  }
}
//*****************************************************************
void min::open(int x, int y) {
  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(LIGHTBLUE);
  rectangle(x, y, x + 14, y + 15);
  setfillstyle(SOLID_FILL, LIGHTBLUE);
  floodfill(x + 2, y + 2, LIGHTBLUE);

  setcolor(LIGHTGRAY);
  rectangle(x, y, x + 14, y + 15);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  floodfill(x + 2, y + 2, LIGHTGRAY);

  setcolor(DARKGRAY);
  line(x, y + 15, x + 14, y + 15);
  line(x + 14, y, x + 14, y + 15);

  z.x.ax = 1;
  int86(0x33, & z, & z);
}
//*****************************************************************
void min::bomb(int x, int y) {
  int i, j, p, q;
  open(x, y);

  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(RED);
  rectangle(x, y, x + 13, y + 14);
  setfillstyle(SOLID_FILL, RED);
  floodfill(x + 2, y + 2, RED);

  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++) {
      if ((st[i][j] == -1) && (st1[i][j] == 0)) {
        p = 235 + (j * 15);
        q = 182 + (i * 16);
        if ((p != x) || (q != y)) open(p, q);
        setcolor(BLACK);
        line(p + 4, q + 5, p + 10, q + 11);
        line(p + 10, q + 5, p + 4, q + 11);
        line(p + 7, q + 4, p + 7, q + 12);
        line(p + 3, q + 8, p + 11, q + 8);
        circle(p + 7, q + 8, 2);
      }

      if ((st[i][j] != -1) && (st1[i][j] == 1)) {
        p = 235 + (j * 15);
        q = 182 + (i * 16);
        erase_flag(p, q);
        open(p, q);
        setcolor(RED);
        line(p, q, p + 14, q + 15);
        line(p + 14, q, p, q + 15);
      }
    }
  ma = 1;
  setcolor(LIGHTGREEN);
  settextstyle(1, 0, 0);
  outtextxy(215, 50, "game over");

  z.x.ax = 1;
  int86(0x33, & z, & z);
}
//*****************************************************************
void min::opensquare(int i, int j) {
  if (st[i][j] != -2) {
    int p, q;
    char str[5];
    p = 235 + (j * 15);
    q = 182 + (i * 16);
    open(p, q);

    switch (st[i][j]) {
    case 1:
      setcolor(BLUE);
      break;
    case 2:
      setcolor(LIGHTGREEN);
      break;
    case 3:
      setcolor(RED);
      break;
    case 4:
      setcolor(MAGENTA);
      break;
    default:
      setcolor(LIGHTBLUE);
    }

    z.x.ax = 2;
    int86(0x33, & z, & z);

    itoa(st[i][j], str, 10);
    outtextxy(p + 4, q + 5, str);
    st[i][j] = -2;

    z.x.ax = 1;
    int86(0x33, & z, & z);
  }
}
//*****************************************************************
void min::openzero(int i, int j) {
  int p, q;
  p = 235 + (j * 15);
  q = 182 + (i * 16);
  open(p, q);
  st[i][j] = -2;

  if ((i - 1 >= 0) && (j - 1 >= 0) && (st[i - 1][j - 1] != -1) && (st[i - 1][j - 1] != -2) &&
    (st1[i - 1][j - 1] == 0)) {
    if (st[i - 1][j - 1] == 0) openzero(i - 1, j - 1);
    if (st[i - 1][j - 1] != 0) opensquare(i - 1, j - 1);
  }

  if ((i - 1 >= 0) && (st[i - 1][j] != -1) && (st[i - 1][j] != -2) && (st1[i - 1][j] == 0)) {
    if (st[i - 1][j] == 0) openzero(i - 1, j);
    if (st[i - 1][j] != 0) opensquare(i - 1, j);
  }

  if ((i - 1 >= 0) && (j + 1 <= 7) && (st[i - 1][j + 1] != -1) && (st[i - 1][j + 1] != -2) &&
    (st1[i - 1][j + 1] == 0)) {
    if (st[i - 1][j + 1] == 0) openzero(i - 1, j + 1);
    if (st[i - 1][j + 1] != 0) opensquare(i - 1, j + 1);
  }

  if ((j - 1 >= 0) && (st[i][j - 1] != -1) && (st[i][j - 1] != -2) && (st1[i][j - 1] == 0)) {
    if (st[i][j - 1] == 0) openzero(i, j - 1);
    if (st[i][j - 1] != 0) opensquare(i, j - 1);
  }

  if ((j + 1 <= 7) && (st[i][j + 1] != -1) && (st[i][j + 1] != -2) && (st1[i][j + 1] == 0)) {
    if (st[i][j + 1] == 0) openzero(i, j + 1);
    if (st[i][j + 1] != 0) opensquare(i, j + 1);
  }

  if ((i + 1 <= 7) && (j - 1 >= 0) && (st[i + 1][j - 1] != -1) && (st[i + 1][j - 1] != -2) &&
    (st1[i + 1][j - 1] == 0)) {
    if (st[i + 1][j - 1] == 0) openzero(i + 1, j - 1);
    if (st[i + 1][j - 1] != 0) opensquare(i + 1, j - 1);
  }

  if ((i + 1 <= 7) && (st[i + 1][j] != -1) && (st[i + 1][j] != -2) && (st1[i + 1][j] == 0)) {
    if (st[i + 1][j] == 0) openzero(i + 1, j);
    if (st[i + 1][j] != 0) opensquare(i + 1, j);
  }

  if ((i + 1 <= 7) && (j + 1 <= 7) && (st[i + 1][j + 1] != -1) && (st[i + 1][j + 1] != -2) &&
    (st1[i + 1][j + 1] == 0)) {
    if (st[i + 1][j + 1] == 0) openzero(i + 1, j + 1);
    if (st[i + 1][j + 1] != 0) opensquare(i + 1, j + 1);
  }
}
//*****************************************************************
void min::cheaker() {
  int b = 0, p, q, i, j;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if ((st[i][j] == -1) || (st[i][j] == -2)) b++;

  if (b == 64) {

    for (i = 0; i < 8; i++)
      for (j = 0; j < 8; j++)
        if ((st[i][j] == -1) && (st1[i][j] == 0)) {
          p = 235 + (j * 15);
          q = 182 + (i * 16);
          draw_flag(p, q);
        }
    setcolor(LIGHTGREEN);
    settextstyle(1, 0, 0);
    outtextxy(225, 50, "you won");
  }
}
//*****************************************************************
//*****************************************************************

void mr() {
  _AX = 0x0;
  __int__(0x33);
}
void me() {
  _AX = 0x1;
  __int__(0x33);
}

void mo(int & x, int & y, int & t)

{
  r.x.ax = 0x3;
  int86(0x33, & r, & r);
  x = r.x.cx;
  y = r.x.dx;
  t = r.x.bx;
}
//*****************************************************************
//*****************************************************************
int main(void) {
  loop1: min ob;
  int i,
  j,
  r,
  x,
  y,
  t,
  b;

  graph();
  ob.init();
  mr();me();
  while (!kbhit()) {
    mo(x, y, t);
    b = 0;
    if ((x >= 309) && (x <= 339) && (y >= 145) && (y <= 170) && (t == 1)) {
      func22();
      delay(300);
      goto loop1;
    }

    if ((t == 1) || (t == 2))
      for (i = 182, r = 1; i <= 294; i += 16) {
        for (j = 235; j <= 340; j += 15)
          if ((x >= j) && (x <= j + 14) && (y >= i) && (y <= i + 15)) {
            b = 1;
            if (t == 1) {
              delay(200);
              ob.func2(j, i, r);
            }
            if (t == 2) {
              delay(500);
              ob.func3(j, i, r);
            }
          }
        else r++;
        if (b == 1) break;
      }
  }

  getch();
  closegraph();
  return 0;
}
//*****************************************************************
//*****************************************************************
void func22() {

  z.x.ax = 2;
  int86(0x33, & z, & z);

  setcolor(DARKGRAY);
  line(309, 145, 339, 145);
  line(309, 145, 309, 170);
  setcolor(WHITE);
  line(309, 170, 339, 170);
  line(339, 145, 339, 170);

  z.x.ax = 1;
  int86(0x33, & z, & z);
}
//*****************************************************************
void graph() {
  int i, j;
  int driver, mode;
  driver = DETECT;
  mode = 0;
  initgraph( & driver, & mode, "c:\\tc\\bgi");
  setcolor(DARKGRAY);
  rectangle(217, 100, 373, 325);
  setfillstyle(SOLID_FILL, LIGHTGRAY);
  floodfill(300, 250, DARKGRAY);
  setcolor(WHITE);
  line(225, 130, 365, 130);
  line(226, 131, 364, 131);
  line(225, 130, 225, 318);
  line(226, 131, 226, 317);

  line(235, 175, 354, 175);
  line(354, 140, 354, 175);

  line(356, 180, 356, 311);
  line(355, 181, 355, 310);
  line(233, 311, 356, 311);
  line(234, 310, 355, 310);
  rectangle(249, 145, 279, 170);
  rectangle(309, 145, 339, 170);
  setcolor(DARKGRAY);
  line(225, 318, 365, 318);
  line(226, 317, 364, 317);
  line(365, 130, 365, 318);
  line(364, 131, 364, 317);

  line(235, 140, 354, 140);
  line(235, 140, 235, 175);

  line(233, 180, 356, 180);
  line(234, 181, 355, 181);
  line(233, 180, 233, 311);
  line(234, 181, 234, 310);

  line(249, 170, 279, 170);
  line(279, 145, 279, 170);
  line(309, 170, 339, 170);
  line(339, 145, 339, 170);
  setcolor(WHITE);
  for (int J = 182; J <= 294; J += 16)
    line(235, J, 354, J);
  for (i = 235; i <= 340; i += 15)
    line(i, 182, i, 309);

  setcolor(BLACK);
  for (i = 249; i <= 354; i += 15)
    line(i, 182, i, 309);
  for (j = 197; j <= 309; j += 16)
    line(235, j, 354, j);

  setcolor(BLUE);
  outtextxy(257, 154, "10");

  settextstyle(0, 0, 0);
  setcolor(DARKGRAY);
  rectangle(217, 100, 373, 120);
  setfillstyle(SOLID_FILL, DARKGRAY);
  floodfill(230, 110, DARKGRAY);
  setcolor(WHITE);
  outtextxy(250, 108, "Minesweeper");

  setcolor(BLACK);
  circle(324, 158, 9);
  setfillstyle(SOLID_FILL, YELLOW);
  floodfill(324, 158, BLACK);
  ellipse(324, 158, 200, 350, 5, 4);
  outtextxy(317, 150, ".");
  outtextxy(324, 150, ".");
}
//*****************************************************************
//*****************************************************************