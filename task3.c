#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определяем тип для указателя на функцию
typedef double (*Operation)(double, double);

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

// Структура для хранения операций
typedef struct {
    char *name;
    Operation func;
} Command;

// Функция для выполнения операции
void execute_command(Command *commands, int command_count) {
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
        if (strcmp(operation, commands[i].name) == 0) {
            double result = commands[i].func(a, b);
            return;
        }
    }

    printf("Unknown operation: %s\n", operation);
}

int main() {
    // Массив доступных команд
    Command commands[] = 
    {   {"add", add},
        {"subtract", subtract},
        {"multiply", multiply},
        {"divide", divide}
    };

    int command_count = sizeof(commands) / sizeof(commands[0]);

    for (int i=0; i < command_count; i++)
    {
        printf ("%d command: %s \n", i+1, commands[i].name);
    }
    while (1) {
        execute_command(commands, command_count);
    }

    return 0;
}
