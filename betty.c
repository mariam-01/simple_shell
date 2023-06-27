#include <unistd.h>
#include <stdlib.h>

#define STDOUT_FILENO 1
#define MAX_LENGTH 100

void print_message(const char *message)
{
    size_t length = 0;
    while (message[length] != '\0')
        length++;

    write(STDOUT_FILENO, message, length);
}

int calculate_sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    char input[MAX_LENGTH];
    int number1, number2, sum;

    print_message("Enter two numbers: ");
    ssize_t bytesRead = read(STDIN_FILENO, input, sizeof(input));

    if (bytesRead > 0)
    {
        input[bytesRead - 1] = '\0';
        sscanf(input, "%d %d", &number1, &number2);

        sum = calculate_sum(number1, number2);
        print_message("The sum is: ");

        char sum_str[MAX_LENGTH];
        int length = sprintf(sum_str, "%d\n", sum);
        write(STDOUT_FILENO, sum_str, length);
    }

    return 0;
}
