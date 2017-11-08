#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int table[n][n / 2 + 1];
    int count = 0;
    int result = 0;
    int i, j, k;

    printf("求%d 有幾種解法？", n);
    // 初始化
    for (i = 0; i < n; i++) {
        table[i][0] = 1; // 任何数以0以下的数拆解必只有1种
        table[i][1] = 1; // 任何数以1以下的数拆解必只有1种
    }
    // 动态规划
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= i; j++) {
            printf("%d %d\n", i, j);
            if (i + j > n) {
                // 大于NUM
                continue;
            }
            count = 0;
            //printf("k:%d\n", k);
            for (k = 1; k <= j; k++) {
                printf("k:%d\n", k);
                // count += table[i - k][(i - k >= k) ? k : i - k];
                if (i - k >= k) {
                    count += table[i - k][k];
                } else
                    count += table[i - k][i - k];
                printf("count:%d\n", count);
            }
            table[i][j] = count;
        }
    }
    // 计算并显示结果
    for (k = 1; k <= n; k++) {
        //result += table[n - k][(n - k >= k) ? k : n - k];
        if (n - k >= k) {
            result += table[n - k][k];
        } else {
            result += table[n - k][n - k];
        }
    }
    printf("\n\nresult: %d\n", result);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #define NUM 10 // 要拆解的数字
// #define DEBUG 0
// int main(void)
// {
//   int table[NUM][NUM / 2+1] =
//   {
//     0
//   }; // 动态规画表格
//   int count = 0;
//   int result = 0;
//   int i, j, k;
//   printf("数字拆解\n");
//   printf("3 = 2+1 = 1+1+1 所以3有三种拆法\n");
//   printf("4 = 3 + 1 = 2 + 2 = 2 + 1 + 1 = 1 + 1 + 1 + 1");
//   printf("共五种\n");
//   printf("5 = 4 + 1 = 3 + 2 = 3 + 1 + 1");
//   printf(" = 2 + 2 + 1 = 2 + 1 + 1 + 1 = 1 + 1 +1 +1 +1");
//   printf("共七种\n");
//   printf("依此类推，求%d 有几种拆法？", NUM);
//   // 初始化
//   for (i = 0; i < NUM; i++)
//   {
//     table[i][0] = 1; // 任何数以0以下的数拆解必只有1种
//     table[i][1] = 1; // 任何数以1以下的数拆解必只有1种
//   }
//   // 动态规划
//   for (i = 2; i <= NUM; i++)
//   {
//     for (j = 2; j <= i; j++)
//     {
//       if (i + j > NUM)
//       // 大于NUM
//         continue;
//       count = 0;
//       for (k = 1; k <= j; k++)
//       {
//         count += table[i - k][(i - k >= k) ? k : i - k];
//       }
//       table[i][j] = count;
//     }
//   }
//   // 计算并显示结果
//   for (k = 1; k <= NUM; k++)
//     result += table[NUM - k][(NUM - k >= k) ? k : NUM - k];
//   printf("\n\nresult: %d\n", result);
//   if (DEBUG)
//   {
//     printf("\n除错资讯\n");
//     for (i = 0; i < NUM; i++)
//     {
//       for (j = 0; j < NUM / 2+1; j++)
//         printf("%2d", table[i][j]);
//       printf("\n");
//     }
//   }
//   return 0;
// }

