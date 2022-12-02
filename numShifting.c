#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int arr2[][4], int m, int n)
{
    int i, j;

    printf("\n\n---------------------\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == m && j == n)
            {
                printf("|    ");
            }
            else
            {
                printf("| %2d ", arr2[i][j]);
            }
        }
        printf("|\n");
    }
    printf("---------------------\n\n");
}

void generateRandomNo(int arr[], int arr2[][4], int row, int column)
{
    int i, j, k = 0;

    srand(time(NULL));

    for (i = 0; i < 15; i++)
    {
        arr[i] = rand() % 15 + 1;

        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                i--;
                break;
            }
        }
    }

    k = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (i == 3 && j == 3)
            {
                arr2[i][j] = ' ';
            }
            else
            {
                arr2[i][j] = arr[k];
                k++;
            }
        }
    }
}

void printMainArray(int arr1[][4], int row, int column)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 3 && j == 3)
            {
                printf(" %2c ", arr1[i][j]);
            }
            else
            {
                printf(" %2d ", arr1[i][j]);
            }
        }
        printf("\n");
    }
}

void ruleOfGame()
{
    system("cls");
    printf("           RULE OF THIS GAME             \n\n");
    printf("\n1. You can move only 1 step at a time by arrow key \n\n");
    printf("             Move Up     : by Up arrow key\n");
    printf("             Move Down   : by Down arrow key\n");
    printf("             Move Left   : by Left arrow key\n");
    printf("             Move right  : by Right arrow key\n\n\n");

    printf("           Winning situtation:       \n\n");
    printf("  1   2   3   4\n");
    printf("  5   6   7   8\n");
    printf("  9   10  11  12\n");
    printf("  13  14  15    \n");

    printf("\n\n5. You can exit the game at any time by pressing 'E' and 'e' \n\n\n");
    printf("So try to win in minimum number of move\n");

    printf("\n\n            Happy Gameing , Good Luck            \n\n\n\n");
}

int main()
{
    int arr1[4][4], arr2[4][4];
    int arr[15];
    int i, j, k = 0;
    int m = 3, n = 3;
    int count = 0;
    int move = 1000;

    char name[30], a;

    for (int i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 3 && j == 3)
            {
                arr1[i][j] = ' ';
            }
            else
            {
                k++;
                arr1[i][j] = k;
            }
        }
    }

    printf("Enter your name\n");
    fgets(name, 30, stdin);

    ruleOfGame();

    printf("Enter any key to start the game   ");
    getch();

    generateRandomNo(arr, arr2, 4, 4);
    while (1)
    {
        system("cls");

        printf("\n\nUser Name  : %s    Total move = %d\n\n\n", name, move);

        if (move == 0)
        {
            printf("Game Over\n\n you lost \n");

            printf("\nIf you want to play again please enter 'y' ");
            scanf("%c", &a);
            fflush(stdin);

            if (a == 'y')
            {
                system("cls");
                generateRandomNo(arr, arr2, 4, 4);
                move = 1000;
            }
            else
            {
                exit(0);
            }
        }

        printArr(arr2, m, n);

        getch();
        a = getch();

        switch (a)
        {
        case 77:
            n--;
            if (m + n < 7 && m >= 0 && n >= 0 && m <= 3 && n <= 3)
            {
                arr2[m][n + 1] = arr2[m][n];
                arr2[m][n] = ' ';
                move--;
            }
            else
            {
                n++;
            }
            // printf("right");
            break;
        case 80:
            m--;
            if (m + n < 7 && m >= 0 && n >= 0 && m <= 3 && n <= 3)
            {
                arr2[m + 1][n] = arr2[m][n];
                arr2[m][n] = ' ';
                move--;
            }
            else
            {
                m++;
            }
            // printf("down");
            break;
        case 75:
            n++;
            if (m + n < 7 && m >= 0 && n >= 0 && m <= 3 && n <= 3)
            {
                arr2[m][n - 1] = arr2[m][n];
                arr2[m][n] = ' ';
                move--;
            }
            else
            {
                n--;
            }

            // printf("left");
            break;
        case 72:
            m++;
            if (m + n < 7 && m >= 0 && n >= 0 && m <= 3 && n <= 3)
            {
                arr2[m - 1][n] = arr2[m][n];
                arr2[m][n] = ' ';
                move--;
            }
            else
            {
                m--;
            }

            // printf("up");
            break;
        case 101:
            exit(0);
            break;
        default:
            printf("Please enter a arrow key to move number\n");
            getch();
            break;
        }

        count = 0;
        for (i = 0; i < 4; i++)
        {
            k++;
            for (j = 0; j < 4; j++)
            {
                if (arr1[i][j] == arr2[i][j])
                {
                }
                else
                {
                    count++;
                }
            }
            if (count == 1)
            {
                break;
            }
        }

        if (count == 0)
        {
            printf("game over\n\nYou win this match\n");

            printf("\n\nIf you want to play again please enter 'y' ");
            scanf("%c", &a);
            if (a == 'y')
            {
                system("cls");
                generateRandomNo(arr, arr2, 4, 4);
                move = 1000;
            }
            else
            {
                exit(0);
            }
        }
    }
    return 0;
}
