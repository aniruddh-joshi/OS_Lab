#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

void main()
{
    int gd=DETECT, gm, count, i, j, mid, cir_x;
    char fname[10][20];

    clrscr();
    initgraph(&gd, &gm, "c:/tc/bgi");
    cleardevice();
    setbkcolor(GREEN);

    printf("Enter the number of files: ");
    scanf("%d", &count);

    if (count > 0)
    {
        cleardevice();
        setbkcolor(GREEN);
        printf("Enter file names:\n");

        for (i = 0; i < count; i++)
        {
            printf("File %d: ", i + 1);
            scanf("%s", fname[i]);
        }

        setfillstyle(1, MAGENTA);
        mid = 640 / count;
        cir_x = mid / 3;

        bar3d(270, 100, 370, 150, 0, 0);

        settextstyle(2, 0, 4);
        settextjustify(1, 1);
        outtextxy(320, 125, "Root Directory");

        setcolor(BLUE);

        for (j = 0; j < count; j++, cir_x += mid)
        {
            line(320, 150, cir_x, 250);
            fillellipse(cir_x, 250, 30, 30);
            outtextxy(cir_x, 250, fname[j]);
        }
    }

    getch();
}
