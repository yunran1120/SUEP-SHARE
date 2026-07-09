/* c12-2-9.c */
#include <stdio.h>
#include <string.h>

#define N 20
#define LEN 30

typedef struct {
    char name[LEN];
} Person;

void sort_names(Person *arr[], int n);
void print_names(Person *arr[], int n);

int main()
{
    Person people[N] = {
        {"Smith"}, {"Johnson"}, {"Williams"}, {"Brown"}, {"Jones"},
        {"Garcia"}, {"Miller"}, {"Davis"}, {"Rodriguez"}, {"Martinez"},
        {"Hernandez"}, {"Lopez"}, {"Gonzalez"}, {"Wilson"}, {"Anderson"},
        {"Thomas"}, {"Taylor"}, {"Moore"}, {"Jackson"}, {"Martin"}
    };

    Person *p_arr[N];
    int i;
    for (i = 0; i < N; i++)
        p_arr[i] = &people[i];

    printf("排序前的姓名：\n");
    print_names(p_arr, N);

    sort_names(p_arr, N);

    printf("\n按升序排序后的姓名：\n");
    print_names(p_arr, N);

    return 0;
}

void sort_names(Person *arr[], int n)
{
    int i, j;
    Person *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(arr[j]->name, arr[j+1]->name) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print_names(Person *arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", arr[i]->name);
}