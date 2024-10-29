#include <stdio.h>

void reverse(int coordinate[5][5], int x, int y)
{
    // (x-1, y)
    if (x - 1 >= 1 && x - 1 <= 3)
    {
        coordinate[x - 1][y] = 1 - coordinate[x - 1][y];
    }

    // (x, y)
    coordinate[x][y] = 1 - coordinate[x][y];

    // (x+1, y)
    if (x + 1 >= 1 && x + 1 <= 3)
    {
        coordinate[x + 1][y] = 1 - coordinate[x + 1][y];
    }

    // (x, y+1)
    if (y + 1 >= 1 && y + 1 <= 3)
    {
        coordinate[x][y + 1] = 1 - coordinate[x][y + 1];
    }

    // (x, y-1)
    if (y - 1 >= 1 && y - 1 <= 3)
    {
        coordinate[x][y - 1] = 1 - coordinate[x][y - 1];
    }
}

int main(void)
{
    int coordinate[5][5] = {0}; // 코드를 단순하게 하기 위해서 3x3 배열을 둘러싸는 임의의 5x5 배열 추가 (전부 0으로 시작)
    int a, answer = -1;

    // 초기 상태 입력
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int n;
            scanf("%d", &n);
            coordinate[i][j] = n;
        }
    }

    scanf("%d", &a);

    for (int i = 0; i < a; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        reverse(coordinate, x, y);

        int count = 0;
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                count += coordinate[j][k];
            }
        }

        if ((count == 0 || count == 9) && answer == -1)
        {
            answer = i + 1;
        }
    }

    // 결과 출력
    printf("%d\n", answer);

    return 0;
}
