#include <stdio.h>

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

void makecoordinate(coordinate *p)
{
    p->x = 1;
    p->y = 1;
}

void left(coordinate *p, int n) // 좌측함수
{
    if (p->y > 1)
    {
        p->y--;
    }
}

void right(coordinate *p, int n) // 우측함수
{
    if (p->y == n) // n의 크기제한에 걸렸을때
    {
        return;
    }
    else
    {
        p->y++;
    }
}

void up(coordinate *p, int n) // 상단함수
{
    if (p->x > 1)
    {
        p->x--;
    }
}

void down(coordinate *p, int n) // 하단함수
{
    if (p->x == n)
    {
        return;
    }
    else
    {
        p->x++;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    coordinate p; // x좌표 , y좌표 1로 세팅
    makecoordinate(&p);
    getchar();

    while (1)
    {
        char command;
        scanf("%c", &command);
        if (command == '\n') // 엔터 입력받으면 탈출
        {
            break;
        }
        else if (command == 'L') // 좌측
        {
            left(&p, n);
        }
        else if (command == 'R') // 우측
        {
            right(&p, n);
        }
        else if (command == 'U') // 위
        {
            up(&p, n);
        }
        else if (command == 'D') // 아래
        {
            down(&p, n);
        }
    }
    printf("%d %d", p.x, p.y);

    return 0;
}
