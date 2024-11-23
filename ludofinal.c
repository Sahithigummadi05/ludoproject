#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
void spaces(int n);
void row1(int x);
void row2(int x);
void row3(int x);
void row4();
void row5(int x);
void row6();
void box1(int x, int s);
void box2(int x, int s, int y, int z);
void box3(int x, int s);
void box4();
void box5();
void box6(int y);
void box7();
void board();
void count(int a, int *l1, int *l2, int *l3);
int dice();
void play(int p, int die);
int put(int p, int die);
void rules();
void ins();
void title();
void start();
void vaib();
int check(int p, int die, int sx);
int temp(int p, int i, int die, int d);
int w, sc = 0, chanc = 0;
char coin[][173] = {{'\0'}, {'\0'}, {'\0'}, {'\0'}};
char *ord[172] = {&coin[1][83], &coin[1][84], &coin[1][85], &coin[1][82], &coin[2][10], &coin[1][86], &coin[1][66], &coin[2][11], &coin[1][102],
                  &coin[1][65], &coin[2][12], &coin[1][103], &coin[1][64], &coin[2][13], &coin[1][104], &coin[1][63], &coin[2][14], &coin[1][105],
                  &coin[1][42], &coin[1][43], &coin[1][59], &coin[1][60], &coin[1][61], &coin[1][62], &coin[1][106], &coin[1][107], &coin[1][108], &coin[1][109], &coin[1][125], &coin[1][126], &coin[1][41], &coin[2][5], &coin[2][6], &coin[2][7], &coin[2][8], &coin[2][9],
                  &coin[2][19], &coin[2][18], &coin[2][17], &coin[2][16], &coin[2][15], &coin[1][127], &coin[1][40], &coin[1][39], &coin[1][23], &coin[1][22], &coin[1][21], &coin[1][20], &coin[1][148], &coin[1][147], &coin[1][146], &coin[1][145], &coin[1][129], &coin[1][128], &coin[1][19], &coin[2][4], &coin[1][149], &coin[1][18], &coin[2][3], &coin[1][150], &coin[1][17], &coin[2][2], &coin[1][151], &coin[1][16], &coin[2][1], &coin[1][152], &coin[1][0], &coin[2][0], &coin[1][168], &coin[1][171], &coin[1][170], &coin[1][169]};
int pos[16][2];
int wc[4] = {0};
int gc[4] = {4, 4, 4, 4};
int kc[4] = {0};
char name[4][20];
int nl[4] = {0};
char *scolour[6] = {"\033[1;0m", "\033[1;31m", "\033[1;32m", "\033[1;33m", "\033[1;34m", "\033[1;35m"};
char *colour[6] = {"\033[1;0m", "\033[1;31m", "\033[1;32m", "\033[1;33m", "\033[1;34m", "\033[1;35m"};
int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < 16; j++)
            {
                coin[i][j] = ' ';
            }
        }
        if (i == 1)
        {
            for (int j = 0; j < 172; j++)
            {
                coin[i][j] = ' ';
            }
        }
        if (i == 2)
        {
            for (int j = 0; j < 20; j++)
            {
                coin[i][j] = ' ';
            }
        }
        if (i == 3)
        {
            for (int j = 0; j < 16; j++)
            {
                coin[i][j] = ' ';
            }
        }
    }

    title();
    printf("\n\n");
    vaib();
    return 0;
}

void spaces(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        printf(" ");
}
void row1(int x)
{
    int has1 = nl[1] / 2;
    int has2 = nl[2] / 2;
    int has3 = nl[3] / 2;
    int has0 = nl[0] / 2;
    int l1, l2, l3;
    if (x == 1)
    {
        count(0, &l1, &l2, &l3);
    }
    for (int i = 1; i <= 3; i++)
    {
        printf("|");
        if (i == 1)
        {
            spaces(48);
            printf("|");
            if (x == 1)
                box1(l1, 0);
            else
                box1(0, 1);
            box1(0, 1);
            box1(0, 1);
            spaces(48);
        }
        else if (i == 2)
        {
            spaces(48);
            printf("|");
            if (x == 1)
                box2(l2, 0 + l1, 1, 1);
            else
                box2(1, 0, 0, 0);
            box2(1, 0, 0, 0);
            box2(1, 0, 0, 0);
            spaces(48);
        }
        else
        {
            if (x == 1)
            {
                spaces(24 - has0);
                printf("%s%s%s", colour[1], name[0], colour[0]);
                spaces(24 + has0 - nl[0]);
            }
            else
            {
                spaces(24 - has1);
                printf("%s%s%s", colour[2], name[1], colour[0]);
                spaces(24 + has1 - nl[1]);
            }
            printf("|");
            if (x == 1)
                box3(l3, 0 + l1 + l2);
            else
                box3(0, 0);
            box3(0, 0);
            box3(0, 0);
            if (x == 1)
            {
                spaces(24 - has3);
                printf("%s%s%s", colour[4], name[3], colour[0]);
                spaces(24 + has3 - nl[3]);
            }
            else
            {
                spaces(24 - has2);
                printf("%s%s%s", colour[3], name[2], colour[0]);
                spaces(24 + has2 - nl[2]);
            }
        }
        printf("|\n");
    }
}
void row2(int x)
{
    int l1, l2, l3;
    if (x == 1)
    {
        count(86, &l1, &l2, &l3);
    }

    for (int i = 1; i <= 3; i++)
    {

        if (i == 1)
        {
            printf("|");
            spaces(48);
            printf("|");
            box1(0, 83);
            box1(0, 83);
            if (x == 1)
                box1(l1, 86);
            else
                box1(0, 86);
            spaces(48);
            printf("|");
        }
        else if (i == 2)
        {
            printf("|");
            spaces(48);
            printf("|");
            box2(0, 0, 0, 0);
            box2(0, 0, 0, 0);
            if (x)
                box2(l2, 86 + l1, 1, 1);
            else
                box2(0, 0, 0, 0);
            spaces(48);
            printf("|");
        }
        else
        {
            printf("|");
            box4();
            box3(0, 0);
            box3(0, 0);
            if (x == 1)
                box3(l3, 86 + l1 + l2);
            else
                box3(0, 0);
            box4();
        }
        printf("\n");
    }
}
void row3(int x)
{
    int l1, l2, l3;
    if (x == 0)
        count(66, &l1, &l2, &l3);
    else if (x == 1)
        count(152, &l1, &l2, &l3);
    for (int i = 1; i <= 3; i++)
    {
        printf("|");
        if (i == 1)
        {
            box5();
            if (x == 0)
                box1(l1, 66);
            else
                box1(0, 1);
            box1(0, 1);
            if (x == 1)
                box1(l1, 152);
            else
                box1(0, 1);
            box5();
        }
        else if (i == 2)
        {
            switch (x)
            {
            case 0:
                box6(6);
                break;
            case 1:
                box6(0);
                break;
            case 2:
                box6(4);
                break;
            case 3:
                box6(2);
                break;
            }
            if (x == 0)
                box2(l2, 66 + l1, 1, 0);
            else
                box2(1, 0, 0, 0);
            box2(1, 0, 0, 0);
            if (x == 1)
                box2(l2, 152 + l1, 1, 0);
            else
                box2(1, 0, 0, 0);
            switch (x)
            {
            case 0:
                box6(10);
                break;
            case 1:
                box6(12);
                break;
            case 2:
                box6(8);
                break;
            case 3:
                box6(14);
                break;
            }
        }
        else
        {
            box7();
            if (x == 0)
                box3(l3, 66 + l1 + l2);
            else
                box3(0, 1);
            box3(0, 1);
            if (x == 1)
                box3(l3, 152 + l1 + l2);
            else
                box3(0, 1);
            box7();
        }
        printf("\n");
    }
}
void row4()
{
    for (int i = 1; i <= 3; i++)
    {
        printf("|");
        if (i == 1)
        {
            spaces(48);
            printf("|");
            box1(0, 1);
            box1(0, 1);
            box1(0, 1);
            spaces(48);
        }
        else if (i == 2)
        {
            spaces(48);
            printf("|");
            box2(1, 0, 0, 0);
            box2(1, 0, 0, 0);
            box2(1, 0, 0, 0);
            spaces(48);
        }
        else
        {
            for (int i = 1; i <= 48; i++)
            {
                printf("_");
            }
            printf("|");
            box3(0, 1);
            box3(0, 1);
            box3(0, 1);
            for (int i = 1; i <= 48; i++)
            {
                printf("_");
            }
        }

        printf("|\n");
    }
}
void row5(int x)
{
    int l1, l2, l3, m1, m2, m3;
    if (x == 1)
    {
        count(43, &l1, &l2, &l3);
        count(109, &m1, &m2, &m3);
    }

    for (int i = 1; i <= 3; i++)
    {
        printf("|");
        if (i == 1)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (j == 2 && x == 1)
                    box1(l1, 43);
                else
                    box1(0, 43);
            }
            if (x == 1)
            {
                printf(" %c", 219);
                spaces(21);
                printf("%c ", 219);
            }
            else
            {
                spaces(10);
                printf("%c", 219);
                spaces(3);
                printf("%c", 219);
                spaces(10);
            }
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 4 && x == 1)
                    box1(m1, 109);
                else
                    box1(0, 109);
            }
        }
        else if (i == 2)
        {

            for (int j = 1; j <= 6; j++)
            {
                if (j == 2 && x == 1)
                    box2(l2, 43 + l1, 1, 1);
                else
                    box2(1, 0, 0, 0);
            }
            if (x == 1)
            {
                printf("    %c", 219);
                spaces(4);
                for (int s = 0; s < 4; s++)
                {
                    if (coin[3][8 + s] == ' ')
                        printf("  ");
                    else
                        printf("%s%d%s ", colour[3], (coin[3][8 + s] - 97) % 4 + 1, colour[0]);
                }
                spaces(3);
                printf("%c    ", 219);
            }
            else
            {
                for (int s = 0; s < 4; s++)
                {
                    if (coin[3][4 + s] == ' ')
                        printf("  ");
                    else
                        printf(" %s%d%s", colour[2], (coin[3][4 + s] - 97) % 4 + 1, colour[0]);
                }
                printf(" %s%c%s", colour[2],42, colour[0]);
                spaces(2);
                printf("%c", 219);
                spaces(2);
                printf("%s%c%s ", colour[4],42, colour[0]);
                for (int s = 0; s < 4; s++)
                {
                    if (coin[3][12 + s] == ' ')
                        printf("  ");
                    else
                        printf("%s%d%s ", colour[4], (coin[3][12 + s] - 97) % 4 + 1, colour[0]);
                }
            }
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 4 && x == 1)
                    box2(m2, 109 + m1, 1, 0);
                else
                    box2(1, 0, 0, 0);
            }
        }
        else
        {

            for (int j = 1; j <= 6; j++)
            {
                if (j == 2 && x == 1)
                    box3(l3, 43 + l1 + l2);
                else
                    box3(0, 43);
            }
            if (x == 1)
            {
                spaces(7);
                printf("%c", 219);
                spaces(4);
                printf("%s%c%s", colour[3], 42, colour[0]);
                spaces(4);
                printf("%c", 219);
                spaces(7);
            }
            else
            {
                spaces(10);
                printf("%c", 219);
                spaces(3);
                printf("%c", 219);
                spaces(10);
            }
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 4 && x == 1)
                    box3(m3, 109 + m1 + m2);
                else
                    box3(0, 109);
            }
        }
        printf("\n");
    }
}
void row6()
{
    int l1, l2, l3, m1, m2, m3;
    count(23, &l1, &l2, &l3);
    count(129, &m1, &m2, &m3);

    for (int i = 1; i <= 3; i++)
    {
        printf("|");
        if (i == 1)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (j == 3)
                    box1(l1, 23);
                else
                {
                    box1(0, 23);
                }
            }
            spaces(7);
            printf("%c", 219);
            spaces(4);
            printf("%s%c%s", colour[1],42, colour[0]);
            spaces(4);
            printf("%c", 219);
            spaces(7);
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 5)
                    box1(m1, 129);
                else
                    box1(0, 129);
            }
        }
        else if (i == 2)
        {

            for (int j = 1; j <= 6; j++)
            {
                if (j == 3)
                    box2(l2, 23 + l1, 1, 0);
                else
                    box2(1, 0, 0, 0);
            }
            spaces(4);
            printf("%c", 219);
            spaces(4);
            for (int s = 0; s < 4; s++)
            {
                if (coin[3][0 + s] == ' ')
                    printf("  ");
                else
                    printf("%s%d%s ", colour[1], (coin[3][0 + s] - 97) % 4 + 1, colour[0]);
            }
            spaces(3);
            printf("%c", 219);
            spaces(4);
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 5)
                    box2(m2, 129 + m1, 1, 1);
                else
                    box2(1, 0, 0, 0);
            }
        }
        else
        {
            for (int j = 1; j <= 6; j++)
            {
                if (j == 3)
                    box3(l3, 23 + l1 + l2);
                else
                {
                    box3(0, 23);
                }
            }
            printf("_%c", 219);
            for (int j = 1; j <= 21; j++)
                printf("_");
            printf("%c_", 219);
            printf("|");
            for (int j = 1; j <= 6; j++)
            {
                if (j == 5)
                    box3(m3, 129 + m1 + m2);
                else
                {
                    box3(0, 129);
                }
            }
        }
        printf("\n");
    }
}
void box1(int x, int s)
{
    char *t[x + 1];
    t[0] = colour[0];
    for (int i = 0; i < x; i++)
        t[i + 1] = colour[(coin[1][s + i] - 97) / 4 + 1];

    switch (x)
    {
    case 0:
        for (int i = 1; i <= 7; i++)
            printf(" ");
        break;
    case 1:
        printf("   %s%d%s   ", t[1], (coin[1][s] - 97) % 4 + 1, t[0]);
        break;
    case 2:
        printf("  %s%d %s%d%s  ", t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[0]);
        break;
    case 3:
        printf("%s"
               " %d"
               "%s"
               " %d"
               "%s"
               " %d"
               "%s",
               t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[3], (coin[1][s + 2] - 97) % 4 + 1, t[0]);
        break;
    case 4:
        printf("%s"
               "%d"
               "%s"
               " %d"
               "%s"
               " %d"
               "%s"
               " %d"
               "%s",
               t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[3], (coin[1][s + 2] - 97) % 4 + 1, t[4], (coin[1][s + 3] - 97) % 4 + 1, t[0]);
        break;
    case 5:
        printf("%s"
               "  %d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s",
               t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[3], (coin[1][s + 2] - 97) % 4 + 1, t[4], (coin[1][s + 3] - 97) % 4 + 1, t[5], (coin[1][s + 4] - 97) % 4 + 1, t[0]);
        break;
    case 6:
        printf("%s"
               " %d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s",
               t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[3], (coin[1][s + 2] - 97) % 4 + 1, t[4], (coin[1][s + 3] - 97) % 4 + 1, t[5], (coin[1][s + 4] - 97) % 4 + 1, t[6], (coin[1][s + 5] - 97) % 4 + 1, t[0]);
        break;
    case 7:
        printf("%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s"
               "%d"
               "%s",
               t[1], (coin[1][s] - 97) % 4 + 1, t[2], (coin[1][s + 1] - 97) % 4 + 1, t[3], (coin[1][s + 2] - 97) % 4 + 1, t[4], (coin[1][s + 3] - 97) % 4 + 1, t[5], (coin[1][s + 4] - 97) % 4 + 1, t[6], (coin[1][s + 5] - 97) % 4 + 1, t[7], (coin[1][s + 6] - 97) % 4 + 1, t[0]);
        break;
    }
    printf("|");
}
void box2(int x, int s, int y, int z) // x=count
{
    char *u[x + 1];
    char t;
    int e;
    if (z == 0)
    {
        t = '+';
        e = 5;
    }
    else
    {
        t = '*';
        e = s / 43 + 1;
    }

    if (y)
    {
        u[0] = colour[0];
        for (int i = 0; i < x; i++)
            u[i + 1] = colour[(coin[1][s + i] - 97) / 4 + 1];
        switch (x)
        {
        case 0:
            printf("%s"
                   "   %c   "
                   "%s",
                   colour[e], t, u[0]);
            break;
        case 1:
            printf("%s"
                   " %d"
                   "%s"
                   " %c   "
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, colour[e], t, u[0]);
            break;
        case 2:
            printf("%s"
                   " %d"
                   "%s"
                   " %c"
                   "%s"
                   " %d "
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, colour[e], t, u[2], (coin[1][s + 1] - 97) % 4 + 1, u[0]);
            break;
        case 3:
            printf("%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   " %c"
                   "%s"
                   " %d "
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, u[2], (coin[1][s + 1] - 97) % 4 + 1, colour[e], t, u[3], (coin[1][s + 2] - 97) % 4 + 1, u[0]);
            break;
        case 4:
            printf("%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   " %c"
                   "%s"
                   " %d"
                   "%s"
                   "%d"
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, u[2], (coin[1][s + 1] - 97) % 4 + 1, colour[e], t, u[3], (coin[1][s + 2] - 97) % 4 + 1, u[4], (coin[1][s + 3] - 97) % 4 + 1, u[0]);
            break;
        case 5:
            printf("%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   "%c"
                   "%s"
                   " %d"
                   "%s"
                   "%d"
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, u[2], (coin[1][s + 1] - 97) % 4 + 1, u[3], (coin[1][s + 2] - 97) % 4 + 1, colour[e], t, u[4], (coin[1][s + 3] - 97) % 4 + 1, u[5], (coin[1][s + 4] - 97) % 4 + 1, u[0]);
            break;
        case 6:
            printf("%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   "%c"
                   "%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s"
                   "%d"
                   "%s",
                   u[1], (coin[1][s] - 97) % 4 + 1, u[2], (coin[1][s + 1] - 97) % 4 + 1, u[3], (coin[1][s + 2] - 97) % 4 + 1, colour[e], t, u[4], (coin[1][s + 3] - 97) % 4 + 1, u[5], (coin[1][s + 4] - 97) % 4 + 1, u[6], (coin[1][s + 5] - 97) % 4 + 1, u[0]);
            break;
        }
        printf("|");
    }
    else
    {
        if (*ord[w] >= 97)
            printf("%s"
                   "   %d   "
                   "%s",
                   colour[(*ord[w] - 97) / 4 + 1], (*ord[w] - 97) % 4 + 1, colour[0]);
        else
            spaces(7);
        printf("|");
    }
    w++;
}
void box3(int x, int s)
{
    char *u[x + 1];
    if (x)
    {
        u[0] = colour[0];
        for (int i = 0; i < x; i++)
            u[i + 1] = colour[(coin[1][s + i] - 97) / 4 + 1];
    }
    switch (x)
    {
    case 0:
        for (int i = 0; i < 7; i++)
            printf("_");
        break;
    case 1:
        printf("___"
               "%s"
               "%d"
               "%s"
               "___",
               u[1], (coin[1][s] - 97) % 4 + 1, u[0]);
        break;
    case 2:
        printf("__"
               "%s"
               "%d"
               "%s"
               "_"
               "%s"
               "%d"
               "%s"
               "__",
               u[1], (coin[1][s] - 97) % 4 + 1, u[0], u[2], (coin[1][s + 1] - 97) % 4 + 1, u[0]);
        break;
    case 3:
        printf("_"
               "%s"
               "%d"
               "%s"
               "_"
               "%s"
               "%d"
               "%s"
               "_"
               "%s"
               "%d"
               "%s"
               "_",
               u[1], (coin[1][s] - 97) % 4 + 1, u[0], u[2], (coin[1][s + 1] - 97) % 4 + 1, u[0], u[3], (coin[1][s + 2] - 97) % 4 + 1, u[0]);
        break;
    }
    printf("|");
}
void box4()
{
    spaces(8);
    for (int i = 0; i < 7; i++)
        printf("_");
    spaces(9);
    for (int i = 0; i < 7; i++)
        printf("_");
    spaces(17);
    printf("|");
}
void box5()
{

    for (int i = 1; i <= 5; i++)
    {
        if (i == 5)
        {
            spaces(16);
            printf("|");
        }
        else
        {
            printf("       ");
            printf("|");
        }
    }
}
void box6(int y)
{
    for (int i = 1; i <= 5; i++)
    {
        if (i == 2)
            if (coin[0][y] >= 97)
                printf("   %s%d%s   ", colour[(coin[0][y] - 97) / 4 + 1], (coin[0][y] - 97) % 4 + 1, colour[0]);
            else
                spaces(7);
        else if (i == 4)
            if (coin[0][y + 1] >= 97)
                printf("   %s%d%s   ", colour[(coin[0][y + 1] - 97) / 4 + 1], (coin[0][y + 1] - 97) % 4 + 1, colour[0]);
            else
                spaces(7);
        else if (i == 5)
        {
            spaces(16);
        }
        else
            spaces(7);
        printf("|");
    }
}
void box7()
{
    for (int i = 1; i <= 5; i++)
    {
        if (i == 2 || i == 4)
            printf("_______");
        else if (i == 5)
        {
            spaces(16);
        }
        else
            spaces(7);
        printf("|");
    }
}

void board()
{
    int i;
    w = 0;
    for (int i = 1; i <= 123; i++)
    {
        printf("_");
    }
    printf("\n");

    row1(0);
    row2(1);
    row3(0);
    row2(0);
    row3(2);
    row4();
    row5(1);
    row5(0);
    row6();
    row2(0);
    row3(3);
    row2(0);
    row3(1);
    row1(1);
    row4();
}

int dice()
{
    int num;
    srand(time(0));
    num = rand();
    num = (num % 6) + 1;
    if (sc > 15)
    {
        num = 6;
        sc = 0;
    }
    printf("Rolling dice....\n");
    sleep(rand() % 2 + 0.5);
    printf(" ___________");
    printf("\n|");
    spaces(11);
    printf("|\n");
    switch (num)
    {
    case 1:
    case 2:
    case 3:
        printf("|");
        spaces(11);
        printf("|\n");
        printf("|");
        if (num == 1)
        {
            spaces(5);
            printf("*");
            spaces(5);
            printf("|\n");
        }
        else if (num == 2)
        {
            printf("   *   *   |\n");
        }
        else
        {
            printf("  *  *  *  |\n");
        }
        printf("|");
        spaces(11);
        printf("|\n");
        break;
    case 4:
    case 5:
        printf("|   *   *   |\n");
        if (num == 4)
        {
            printf("|");
            spaces(11);
            printf("|\n");
        }
        else
        {
            printf("|");
            spaces(5);
            printf("*");
            spaces(5);
            printf("|\n");
        }
        printf("|   *   *   |\n");
        break;
    case 6:
        printf("|  *  *  *  |\n");
        printf("|");
        spaces(11);
        printf("|\n");
        printf("|  *  *  *  |\n");
        break;
    }
    printf("|");
    printf("___________");
    printf("|\n");
    return num;
}

void play(int p, int die)
{
    int ch, c, ra, ht, hx, d, temp = die;
    int i, j, x, in, mult[16] = {0, 16, 23, 39, 43, 59, 66, 82, 86, 102, 109, 125, 129, 145, 152, 168};
    ch = put(p, die);
    c = 97 + 4 * (p - 1) + ch - 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; coin[i][j] != '\0'; j++)
        {
            if (coin[i][j] == c)
                break;
        }
        if (coin[i][j] == c)
            break;
    }

    if (i == 0)
    {
        if (temp == 6)
        {
            x = 43 * (p - 1);
            while (1)
            {
                if (coin[1][x] == ' ')
                {
                    coin[1][x] = c;
                    pos[c - 97][0] = 1;
                    pos[c - 97][1] = 43 * (p - 1);
                    coin[0][j] = ' ';
                    gc[p - 1]--;
                    break;
                }
                else
                    x++;
            }
        }
        else
        {
            printf("\nChosen coin cannot be moved except for 6\n");
            play(p, temp);
            return;
        }
    }
    else if (i == 1)
    {
        x = j;
        if (p == 1)
            in = 170;
        else
            in = 43 * (p - 1) - 2;
        while (die > 0)
        {
            for (ht = 0; ht < 8; ht++)
            {
                if (mult[2 * ht] <= x && x < mult[2 * ht + 1])
                {
                    x = mult[2 * ht + 1];
                    die--;
                    break;
                }
            }
            if (ht < 8)
                continue;

            if (x == in)
            {
                x = 5 * (p - 1);
                die--;
                while (die > 0)
                {
                    x++;
                    die--;
                }
                if (x == 5 * p)
                {
                    coin[3][c - 97] = c;
                    pos[c - 97][0] = 3;
                    pos[c - 97][1] = c - 97;
                    wc[p - 1]++;
                    for (ht = 0; ht < 8; ht++)
                    {
                        if (mult[2 * ht] <= j && j < mult[2 * ht + 1])
                        {
                            for (int v = j; v < mult[2 * ht + 1]; v++)
                            {
                                coin[1][v] = coin[1][v + 1];
                            }
                            coin[1][mult[2 * ht + 1] - 1] = ' ';
                            return;
                        }
                    }
                    coin[1][j] = ' ';
                    return;
                }
                if (coin[2][x] == ' ')
                {
                    coin[2][x] = c;
                    pos[c - 97][0] = 2;
                    pos[c - 97][1] = x;
                    for (ht = 0; ht < 8; ht++)
                    {
                        if (mult[2 * ht] <= j && j < mult[2 * ht + 1])
                        {
                            for (int v = j; v < mult[2 * ht + 1]; v++)
                            {
                                coin[1][v] = coin[1][v + 1];
                            }
                            coin[1][mult[2 * ht + 1] - 1] = ' ';
                            return;
                        }
                    }
                    coin[1][j] = ' ';
                    return;
                }
                else
                {
                    printf("\nCoin cannot be moved\nEnter another choice\n");
                    play(p, temp);
                    return;
                }
            }
            else
            {
                x = (x + 1) % 172;
                die--;
            }
        }
        for (hx = 0; hx < 8; hx++)
        {
            if (x == mult[2 * hx])
            {
                while (1)
                {
                    if (coin[1][x] == ' ')
                    {
                        coin[1][x] = c;
                        pos[c - 97][0] = 1;
                        pos[c - 97][1] = mult[2 * hx];
                        for (ht = 0; ht < 8; ht++)
                        {
                            if (mult[2 * ht] <= j && j < mult[2 * ht + 1])
                            {
                                for (int v = j; v < mult[2 * ht + 1]; v++)
                                {
                                    coin[1][v] = coin[1][v + 1];
                                }
                                coin[1][mult[2 * ht + 1] - 1] = ' ';
                                break;
                            }
                        }
                        if (ht == 8)
                        {
                            coin[1][j] = ' ';
                            break;
                        }
                    }
                    else
                        x++;
                }
                return;
            }
        }
        if (coin[1][x] != ' ')
        {
            int h = (coin[1][x] - 97) / 4 + 1;
            if (h != p)
            {
                coin[0][coin[1][x] - 97] = coin[1][x];
                pos[coin[1][x] - 97][0] = 0;
                pos[coin[1][x] - 97][1] = coin[1][x] - 97;
                gc[h - 1]++;
                kc[p - 1]++;
                chanc++;
                coin[1][x] = c;
                pos[c - 97][0] = 1;
                pos[c - 97][1] = x;
                for (ht = 0; ht < 8; ht++)
                {
                    if (mult[2 * ht] <= j && j < mult[2 * ht + 1])
                    {
                        for (int v = j; v < mult[2 * ht + 1]; v++)
                        {
                            coin[1][v] = coin[1][v + 1];
                        }
                        coin[1][mult[2 * ht + 1] - 1] = ' ';
                        return;
                    }
                }
                coin[1][j] = ' ';
                return;
            }
            else
            {
                printf("\nCoin cannot be moved\nEnter another choice\n");
                play(p, temp);
                return;
            }
        }
        coin[1][x] = c;
        pos[c - 97][0] = 1;
        pos[c - 97][1] = x;
        for (ht = 0; ht < 8; ht++)
        {
            if (mult[2 * ht] <= j && j < mult[2 * ht + 1])
            {
                for (int v = j; v < mult[2 * ht + 1]; v++)
                {
                    coin[1][v] = coin[1][v + 1];
                }
                coin[1][mult[2 * ht + 1] - 1] = ' ';
                return;
            }
        }
        coin[1][j] = ' ';
        return;
    }
    else if (i == 2)
    {
        int x = j;
        if (die < (5 - (j % 5)))
        {
            x += die;
            if (coin[2][x] == ' ')
            {
                coin[2][x] = coin[2][j];
                pos[c - 97][0] = 2;
                pos[c - 97][1] = x;
                coin[2][j] = ' ';
                return;
            }
            else
            {
                printf("\nCoin cannot be moved\nEnter another choice\n");
                play(p, temp);
                return;
            }
        }
        else if (die == (5 - (j % 5)))
        {
            coin[3][coin[i][j] - 97] = coin[2][j];
            pos[c - 97][0] = 3;
            pos[c - 97][1] = c - 97;
            wc[p - 1]++;
            coin[2][j] = ' ';
            return;
        }
        else
        {
            printf("\nChosen coin cannot be moved!\nEnter another choice: ");
            play(p, temp);
            return;
        }
    }
    else
    {
        printf("\nChosen coin cannot be moved!\nEnter another choice: ");
        play(p, temp);
        return;
    }
}

int put(int p, int die)
{
    int n;
    char c;
    printf("\nTurn of %s\nEnter choice for %d on die: ", name[p - 1], die);
    scanf(" %c", &c);
    if (c > 48 && c < 53)
        n = c - 48;
    else
    {
        n = put(p, die);
    }
    return n;
}
void count(int a, int *l1, int *l2, int *l3)
{
    int n = 0;
    for (int i = 0; i < 16; i++)
    {
        if (coin[1][a + i] == ' ')
        {
            break;
        }
        n++;
    }
    switch (n)
    {
    case 0:
        *l1 = 0;
        *l2 = 0;
        *l3 = 0;
        break;
    case 1:
        *l1 = 0;
        *l2 = 1;
        *l3 = 0;
        break;
    case 2:
        *l1 = 0;
        *l2 = 2;
        *l3 = 0;
        break;
    case 3:
    case 5:
    case 6:
    case 7:
    case 4:
        *l2 = 2;
        *l1 = n - *l2;
        *l3 = 0;
        break;
    case 8:
        *l2 = 3;
        *l1 = n - *l2;
        *l3 = 0;
        break;
    case 9:
    case 10:
        *l2 = 4;
        *l1 = n - *l2;
        *l3 = 0;
        break;
    case 11:
    case 12:
        *l2 = 5;
        *l1 = n - *l2;
        *l3 = 0;
        break;
    case 13:
    case 14:
    case 15:
    case 16:
        *l2 = 6;
        *l1 = 7;
        *l3 = n - *l2 - *l1;
        break;
    }
}

void start()
{
    int p, d,r,sum=0, col, lockd;
    char nam[20];
    char *tc;
    do
    {
        printf("Enter the number of players: ");
        scanf(" %d", &p);
    } while (!(p > 0 && p <= 4));

    printf("\nEnter the names of players:\n");
    for (int pl = 0; pl < p; pl++)
    {
        printf("\nPlayer %d: ", pl + 1);
        scanf(" %[^\n]s", nam);
        strcpy(name[pl], nam);
        nl[pl] = strlen(name[pl]);
    }

    printf("\n1. Red\n2. Green\n3. Yellow\n4. Blue\nChoose the colour of your coin\n");
    for (int pl = 0; pl < p; pl++)
    {
        printf("%s: ", name[pl]);
        scanf(" %d", &col);
        if (p == 4)
        {
            colour[pl + 1] = scolour[col];
            continue;
        }
        tc = colour[pl + 1];
        colour[pl + 1] = scolour[col];
        colour[col] = tc;
    }

    int first[4] = {0}, di, e, g = 0;
    char xq;
    printf("\nRoll die to know who plays first\n");
    for (int l = 0; l < p; l++)
    {
        while (1)
        {
            printf("\nTurn of %s\n", name[l]);
            printf("\nPress any key to roll die: ");
            scanf(" %c", &xq);
            di = dice();
            for (e = 0; first[e] != 0; e++)
            {
                if (first[e] == di)
                    break;
            }
            if (first[e] == 0)
            {
                first[l] = di;
                break;
            }
            else
            {
                printf("\nRoll die again to break tie");
            }
        }
    }

    for (e = 0; e < p; e++)
    {
        if (first[g] < first[e])
        {
            g = e;
        }
    }
    printf("\n%s scored highest and will be starting the game", name[g]);
    printf("\nPress any key to continue: ");
    scanf(" %c", &xq);

    int aturn[4] = {1, 2, 3, 4}, f = p, turn = aturn[g];
    int win[4] = {0};
    char u;

    for (int i = 0; i < 4 * p; i++)
    {
        coin[0][i] = 97 + i;
        pos[i][0] = 0;
        pos[i][1] = i;
    }
    while (1)
    {
        board();
        printf("%s\n", name[turn - 1]);
        chanc = 0;
        while (chanc >= 0)
        {
            d = dice();
            if (!check(turn, d, 0) && d != 6)
            {
                printf("\nNo coin can be moved\n");
                printf("Press any key to continue ");
                scanf(" %c", &u);
            }
            else if (d == 6)
            {
                if (check(turn, 0, 1))
                {
                    d = dice();
                    if (!check(turn, d, 1) && d != 6)
                    {
                        printf("\nNo coin can be moved\n");
                        printf("Press any key to continue ");
                        scanf(" %c", &u);
                    }
                    else if (d == 6)
                    {
                        if (check(turn, 0, 2))
                        {
                            d = dice();
                            if (d == 6)
                            {
                                printf("\n3 consecutive SIXES\nTurn goes to next player\n");
                                sleep(1);
                            }
                            else if (!check(turn, d, 2))
                            {
                                printf("\nNo coin can be moved\n");
                                printf("Press any key to continue ");
                                scanf(" %c", &u);
                            }
                            else
                            {
                                play(turn, 6);
                                play(turn, 6);
                                play(turn, d);
                            }
                        }
                        else
                        {
                            printf("\nNo coin can be moved\n");
                            printf("Press any key to continue ");
                            scanf(" %c", &u);
                        }
                    }
                    else
                    {
                        play(turn, 6);
                        play(turn, d);
                    }
                }
                else
                {
                    printf("\nNo coin can be moved\n");
                    printf("Press any key to continue ");
                    scanf(" %c", &u);
                }
            }
            else
            {
                play(turn, d);
            }
            if (wc[turn - 1] == 4)
            {
                board();
                printf("\n_____________");
                spaces(42);
                printf("_____________");
                printf("\n%c %c %c %c %c %c %c", 219, 219, 219, 219, 219, 219, 219);
                spaces(42);
                printf("%c %c %c %c %c %c %c", 219, 219, 219, 219, 219, 219, 219);
                printf("\n %c %c %c %c %c %c ", 219, 219, 219, 219, 219, 219);
                printf("         Hurray! You won the game         ");
                printf(" %c %c %c %c %c %c ", 219, 219, 219, 219, 219, 219);
                printf("\n%c_%c_%c_%c_%c_%c_%c", 219, 219, 219, 219, 219, 219, 219);
                spaces(42);
                printf("%c_%c_%c_%c_%c_%c_%c", 219, 219, 219, 219, 219, 219, 219);
                if (f - 1 > 1)
                {
                    for (int i = g; i < f - 1; i++)
                    {
                        aturn[i] = aturn[i + 1];
                    }
                    f--;
                    win[p - f - 1] = turn;
                    printf("\nGame continues with other players\n");
                }
                else
                {
                    win[p - f] = turn;
                    break;
                }
            }
            if (chanc > 0)
            {
                printf("\nExtra chance to %s.. Play again\n", name[turn - 1]);
            }
            chanc--;
        }
        if (chanc < 0)
        {
            g = (g + 1) % f;
            turn = aturn[g];
            sc++;
        }
        else
        {
            break;
        }
    }
    if (win[1] == 0)
    {
        board();
        printf("\n\n%s wins", name[turn - 1]);
    }
    else
    {
        printf("\n\n\nHurray!!\n\n");
        printf("Ranking order");
        for (r = 0; win[r] != 0; r++)
        {
            printf("\n%d. %s", r+1, name[win[r] - 1]);
            sum+=win[r];
        }
        printf("\n%d. %s", r+1, name[p*(p+1)/2 - sum -1]);
    }
    printf("\n\n---------Game ends---------");
}

void rules()
{
    char sh;
    printf("1. Each player chooses one of the 4 colours (green, yellow, red or blue) and places the 4 pieces of that colour in the corresponding starting square. A single die is thrown to determine the movement of coins.\n\n2. Players take turns in a clockwise order, highest throw of the die starts.\n\n3. Each throw, the player decides which piece to move. A piece simply moves in a clockwise direction around the track given by the number thrown. If no piece can legally move according to the number thrown, play passes to the next player.\n\n4. A player must throw a 6 to move a piece from the starting square onto the first square on the track.\n\n5. A throw of 6 gives another turn.\n\n6. If a piece lands on a piece of a different colour, the piece jumped upon is returned to its starting circle and the player gets a chance to roll die again.\n\n7. When a piece has circumnavigated the board, it proceeds up the home column. A piece can only be moved onto the home triangle by an exact throw.\n\n8. The first person to move all 4 pieces into the home triangle wins.\n\n9. If a coin lands on safe squares(marked by a star), it cannot be captured by another player. Multiple coins of same or different players can stay in the safe boxes simultaneously. Starting squares of each player too act as safe boxes.");
    printf("\n\nPress any key to continue: ");
    scanf(" %c", &sh);
    vaib();
}

void ins()
{
    char sh;
    printf("1. Game can be played by 2-4 players and each player chooses a colour of their choice.\n\n2. Player 1 will be starting from the starting square in bottom left most corner of the ludo board, and the subsequent players will be occupying the starting squares in a clockwisse order. So the players can give their names in an order according to which starting square they want to start from.\n\n3. The coins of each player are represented by numbers from 1 to 4 in the respective colour of the player. The starting squares of each player on the track are marked with a '+' and the safe boxes with a '*'.\n\n4. Each time a player gets a turn, he rolls a die and enters which coin (1/2/3/4) is to be moved.\n\n5. The player first moving all 4 of his coins into the home square wins and the game continues with remaining players.");
    printf("\n\nPress any key to continue: ");
    scanf(" %c", &sh);
    vaib();
}

void title()
{
    spaces(32);
    printf("%c      ", 220);
    printf("   ");
    printf("%c       %c", 219, 219);
    printf("   ");
    printf("%c %c %c   ", 254, 254, 220);
    printf("   ");
    printf("   %c%c%c   ", 220, 223, 220);
    printf("\n");
    spaces(32);
    printf("%c      ", 219);
    printf("   ");
    printf("%c       %c", 219, 219);
    printf("   ");
    printf("%c     %c ", 219, 223);
    printf("   ");
    printf(" %c%c   %c%c", 220, 223, 223, 220);
    printf("\n");
    spaces(32);
    printf("%c      ", 219);
    printf("   ");
    printf("%c       %c", 219, 219);
    printf("   ");
    printf("%c      %c", 219, 219);
    printf("   ");
    printf("%c       %c", 219, 219);
    printf("\n");
    spaces(32);
    printf("%c      ", 219);
    printf("   ");
    printf(" %c%c   %c%c ", 223, 220, 220, 223);
    printf("   ");
    printf("%c     %c ", 219, 254);
    printf("   ");
    printf(" %c%c   %c%c", 223, 220, 220, 223);
    printf("\n");
    spaces(32);
    printf("%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223);
    printf("   ");
    printf("   %c%c%c   ", 223, 223, 223);
    printf("   ");
    printf("%c %c %c   ", 254, 254, 223);
    printf("   ");
    printf("   %c%c%c   ", 223, 220, 223);
    printf("\n");
    printf("\n");
    for (int y = 0; y < 128; y++)
    {
        printf("_");
    }
}

void vaib()
{
    int choice;
    printf("1. Start playing\n2. Help\n3. Ludo rulebook");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        start();
        break;
    case 2:
        ins();
        break;
    case 3:
        rules();
        break;
    default:
        printf("Invalid choice");
        vaib();
        break;
    }
    return;
}

int check(int p, int d, int sx)
{
    int in, x, ht, mult[16] = {0, 16, 23, 39, 43, 59, 66, 82, 86, 102, 109, 125, 129, 145, 152, 168}, t = 0;
    int die = d + 6 * sx, die1, die2, die3;
    for (int i = 4 * (p - 1); i < 4 * p; i++)
    {
        if (temp(p, i, die, d))
            return 1;
    }

    if (sx == 1 && d != 0 || sx == 2)
    {
        die1 = 6, die2 = d + 6 * (sx - 1);
        for (int i = 4 * (p - 1); i < 4 * p; i++)
        {
            for (int j = 4 * (p - 1); j < 4 * p; j++)
            {
                if (i != j)
                {
                    if (temp(p, i, die1, d) && temp(p, j, die2, d))
                        return 1;
                    if (sx == 2 && d > 0)
                    {
                        if (temp(p, i, 12, d) && temp(p, i, d, d))
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    if (sx == 2 && d > 0)
    {
        for (int i = 4 * (p - 1); i < 4 * p; i++)
        {
            for (int j = 4 * (p - 1); j < 4 * p; j++)
            {
                for (int h = 4 * (p - 1); h < 4 * p; h++)
                {
                    if (i != j && j != h && i != h)
                    {
                        if (temp(p, i, 6, d) && temp(p, j, 6, d) && temp(p, h, d, d))
                            return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int temp(int p, int i, int die, int d)
{
    int in, x, ht, mult[16] = {0, 16, 23, 39, 43, 59, 66, 82, 86, 102, 109, 125, 129, 145, 152, 168}, t = 0;

    if (pos[i][0] == 0 && die < 6 || pos[i][0] == 3)
    {
        return 0;
    }
    if (pos[i][0] == 0 && die >= 6)
    {
        x = 43 * (p - 1);
        die -= 6;
        if (p == 1)
            in = 170;
        else
            in = 43 * (p - 1) - 2;
        while (die > 0)
        {
            for (ht = 0; ht < 8; ht++)
            {
                if (mult[2 * ht] <= x && x < mult[2 * ht + 1])
                {
                    x = mult[2 * ht + 1];
                    die--;
                    break;
                }
            }
            if (ht < 8)
                continue;
            x = (x + 1) % 172;
            die--;
        }

        for (ht = 0; ht < 8; ht++)
        {
            if (x == mult[2 * ht])
            {
                return 1;
            }
        }
        if (coin[1][x] != ' ')
        {
            int h = (coin[1][x] - 97) / 4 + 1;
            if (h != p)
            {
                return 1;
            }
            else
            {
                if (d == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else if (pos[i][0] == 1)
    {
        x = pos[i][1];
        if (p == 1)
            in = 170;
        else
            in = 43 * (p - 1) - 2;
        while (die > 0)
        {
            for (ht = 0; ht < 8; ht++)
            {
                if (mult[2 * ht] <= x && x < mult[2 * ht + 1])
                {
                    x = mult[2 * ht + 1];
                    die--;
                    break;
                }
            }
            if (ht < 8)
                continue;

            if (x == in)
            {
                x = 5 * (p - 1);
                die--;
                while (die > 0)
                {
                    x++;
                    die--;
                }
                if (x == 5 * p)
                {
                    return 1;
                }
                else if (x > 5 * p)
                {
                    return 0;
                }
                if (coin[2][x] == ' ')
                {
                    return 1;
                }
                else
                {
                    if (d == 0)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            else
            {
                x = (x + 1) % 172;
                die--;
            }
        }
        for (ht = 0; ht < 8; ht++)
        {
            if (x == mult[2 * ht])
            {
                return 1;
            }
        }
        if (coin[1][x] != ' ')
        {
            int h = (coin[1][x] - 97) / 4 + 1;
            if (h != p)
            {
                return 1;
            }
            else
            {
                if (d == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else if (pos[i][0] == 2)
    {
        int x = pos[i][1];
        if (die < (5 - (pos[i][1] % 5)))
        {
            x += die;
            if (coin[2][x] == ' ')
            {
                return 1;
            }
            else
            {
                if (d == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else if (die == (5 - (pos[i][1] % 5)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
