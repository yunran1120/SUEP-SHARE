/* c9-3-2.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char keyword[100];
    char line[1024];
    char sentence[4096];
    FILE *fp_in, *fp_out;
    int found = 0;

    printf("请输入查找关键字：");
    gets(keyword);

    fp_in = fopen("使命与担当.txt", "r");
    if (fp_in == NULL)
    {
        printf("无法打开 使命与担当.txt\n");
        return 1;
    }

    fp_out = fopen("学习笔记.txt", "w");
    if (fp_out == NULL)
    {
        printf("无法创建 学习笔记.txt\n");
        fclose(fp_in);
        return 1;
    }

    sentence[0] = '\0';    
    const char *endmarks[] = {"。", "！", "？", "；", "\n"};
    int num_marks = sizeof(endmarks) / sizeof(endmarks[0]);

    while (fgets(line, sizeof(line), fp_in))
    {
        strcat(sentence, line);

        char *start = sentence;
        while (*start)
        {
            int min_pos = -1;
            int mark_len = 0;
            for (int k = 0; k < num_marks; k++)
            {
                char *pos = strstr(start, endmarks[k]);
                if (pos)
                {
                    int offset = pos - start;
                    if (min_pos == -1 || offset < min_pos)
                    {
                        min_pos = offset;
                        mark_len = strlen(endmarks[k]);
                    }
                }
            }

            if (min_pos == -1)
                break;
            char saved = start[min_pos + mark_len];
            start[min_pos + mark_len] = '\0';
            if (strstr(start, keyword) != NULL)
            {
                fputs(start, fp_out);
                fputc('\n', fp_out); 
                found = 1;
            }

            start[min_pos + mark_len] = saved;
            start += min_pos + mark_len;
        }

        strcpy(sentence, start);
    }

    if (strlen(sentence) > 0)
    {
        if (strstr(sentence, keyword) != NULL)
        {
            fputs(sentence, fp_out);
            fputc('\n', fp_out);
            found = 1;
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    if (found)
        printf("查找完成，结果已写入 学习笔记.txt\n");
    else
        printf("未找到包含关键字的句子。\n");

    return 0;
}