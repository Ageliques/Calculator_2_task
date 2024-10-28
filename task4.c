#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Определяем тип для указателя на функцию
typedef double (*Operation2)(double, double);
typedef double (*Operation1)(double);

// Функции для операций
double add(double a, double b) {
    printf("Result: %.2f\n", a + b);
}

double subtract(double a, double b) {
    printf("Result: %.2f\n", a - b);
}

double multiply(double a, double b) {
    printf("Result: %.2f\n", a*b);
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by 0!\n");
        return 0; 
    }
    printf("Result: %.2f\n", a/b);
}

double add10(double a)
{
    printf("Result: %.2f\n", a + 10);
}

double root(double a)
{
    printf("Result: %.2f\n", sqrt(a));
}

// Структура для хранения операций
typedef struct {
    char *name2;
    Operation2 func2;
} Command2;

// Структура для хранения операций
typedef struct {
    char *name1;
    Operation1 func1;
} Command1;

// Функция для выполнения операции
void execute_command2(Command2 *commands, int command_count) {
    char operation[10];
    double a, b;

    printf("Enter the operation (or 'exit' ): \n");
    scanf("%s", operation);

    if (strcmp(operation, "exit") == 0) {
        exit(0);
    }

    printf("Enter two number: \n");
    printf ("A = ");
    scanf("%lf", &a);
    printf ("B = ");
    scanf("%lf", &b);
    

    for (int i = 0; i < command_count; i++) {
        if (strcmp(operation, commands[i].name2) == 0) {
            double result = commands[i].func2(a, b);
            return;
        }
    }

    printf("Unknown operation: %s\n", operation);
}

void execute_command1(Command1 *command1s, int command_count) {
    char operation[10];
    double a;

    printf("Enter the operation (or 'exit' ): \n");
    scanf("%s", operation);

    if (strcmp(operation, "exit") == 0) {
        exit(0);
    }

    printf("Enter number: \n");
    printf ("A = ");
    scanf("%lf", &a);

    for (int i = 0; i < command_count; i++) {
        if (strcmp(operation, command1s[i].name1) == 0) {
            double result = command1s[i].func1(a);
            return;
        }
    }

    printf("Unknown operation: %s\n", operation);
}
int main() {
    // Массив доступных команд для работы с 2 числами
    Command2 commands[] = 
    {   {"add", add},
        {"subtract", subtract},
        {"multiply", multiply},
        {"divide", divide}
    };

    // Массив доступных команд для работы с 1 числом
    Command1 command1s[] = 
    {   {"root", root},
        {"addplus10", add10}
    };

    int command_count1 = sizeof(command1s) / sizeof(commands[0]);
    int command_count2 = sizeof(commands) / sizeof(commands[0]);
   
    printf("Command for calculator of 1 number\n");
    for (int i=0; i < command_count1; i++)
    {
        printf ("%d command: %s \n", i+1, command1s[i].name1);
    }

    printf("Command for calculator of 2 number\n");
    for (int i=0; i < command_count2; i++)
    {
        printf ("%d command: %s \n", i+1, commands[i].name2);
    }

    while (1) {
        int N;
        printf("Enter 1 (calculator of 1 number) or 2 (calculator of 2 number)");
        scanf("%d", &N);
        if ( (N>2) || (N<0) )
            {
                printf("Error, enter 1 or 2 \n");
               scanf("%d", &N);
            }
         
        if (N==2)
        execute_command2(commands, command_count2);
        else 
        execute_command1(command1s, command_count1);
    }

    return 0;
}
