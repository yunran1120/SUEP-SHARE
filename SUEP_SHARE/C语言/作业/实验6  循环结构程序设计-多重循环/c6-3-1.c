/* c6-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, op, correct_answer, user_answer;
    int total, correct_count, i;
    char operator_char;
    char choice;
    srand(time(NULL));
    do
    {
        total = 10;
        correct_count = 0;
        printf("\n========== 100以内加减乘除训练 ==========\n");
        printf("本轮共 %d 道题，请认真作答。\n", total);

        for (i = 1; i <= total; i++)
        {
            a = rand() % 100 + 1;
            b = rand() % 100 + 1;
            op = rand() % 4;
            switch (op)
            {
                case 0: 
                    operator_char = '+';
                    correct_answer = a + b;
                    break;
                case 1: 
                    if (a < b) { int temp = a; a = b; b = temp; }
                    operator_char = '-';
                    correct_answer = a - b;
                    break;
                case 2: 
                    operator_char = '*';
                    correct_answer = a * b;
                    break;
                case 3: 
                    b = rand() % 10 + 1;     
                    a = b * (rand() % (100 / b) + 1);
                    operator_char = '/';
                    correct_answer = a / b;
                    break;
            }
            printf("\n第 %d 题: %d %c %d = ? ", i, a, operator_char, b);
            scanf("%d", &user_answer);
            if (user_answer == correct_answer)
            {
                printf("正确！\n");
                correct_count++;
            }
            else
            {
                printf("错误！正确答案是 %d\n", correct_answer);
            }
        }
        printf("\n========== 本轮结束 ==========\n");
        printf("共 %d 题，答对 %d 题，正确率 %.1f%%\n",
               total, correct_count, (float)correct_count / total * 100);
        printf("\n是否进行下一轮训练？(y/n): ");
    } while (choice == 'y' || choice == 'Y');
    printf("\n训练结束，再见！\n");
    return 0;
}