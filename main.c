#include <stdio.h>
#include <stdbool.h> // For type bool

// Function Prototypes
void questionOne(char);
int questionTwo(int);
void questionThree(int);
void questionFour(int, int);
void questionFive(int, int , int);
bool ifFive(int);
int min(int, int);
int max(int, int);

int main() // Driver code
{
    printf("Type question number here: ");
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        {
            char c;
            printf("Type your character: ");
            scanf(" %c", &c);
            questionOne(c);
            break;
        }
    case 2:
        {
            int y;
            printf("Type your number: ");
            scanf(" %d", &y);
            if (ifFive(y) == 0)
            {
                printf("Number is not five digits long. Exiting...\n");
            }
            else
            {
                printf("%d\n", questionTwo(y));
            }
            break;
        }
    case 3:
        {
            int y;
            printf("Type your number: ");
            scanf(" %d", &y);
            if (ifFive(y) == 0)
            {
                printf("Number is not five digits long. Exiting...\n");
            }
            else
            {
                questionThree(y);
            }
            break;
        }
    case 4:
        {
            int y, z;
            printf("Type width: ");
            scanf(" %d", &y);
            printf("Type breadth: ");
            scanf(" %d", &z);
            questionFour(y, z);
            break;
        }
    case 5:
        {
            int y, z, w;
            printf("Type first number: ");
            scanf(" %d", &y);
            printf("Type second number: ");
            scanf(" %d", &z);
            printf("Type third number: ");
            scanf(" %d", &w);
            printf("%d %d %d\n", y, z, w);
            questionFive(y, z, w);
            break;
        }
    default:
        printf("Invalid selection\n");
    }
    return 0;
}

void questionOne(char c) // Question 1: ASCII Range Check
{
    if (c >= 65 && c <=90) // Upper case letter range
    {
        printf("Upper Case Letter");
    }
    else if (c >= 97 && c <= 122) // Lower case letter range
    {
        printf("Lower Case Letter");
    }
    else if (c >= 48 && c <= 57) // Number range
    {
        printf("Number");
    }
    else // Range for all other symbols. Given that type char only covers 255 values, no checks needed for invalid ASCII values
    {
        printf("Special Symbol");
    }
}

bool ifFive(int x) // Five digit number check is common in both Q2 and Q3. Rather than re-implementing, function is used in conjunction with driver code to ensure only 5 digit numbers end up in Q2 and Q3
{
    if(x > 9999 && x <=100000) // Range check for five digits
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int questionTwo(int x) // Question 2: +1 to each digit
// Was explicitly stated that loops and arrays were not allowed. Code would've been much more efficient with it.
{
    int y = 0;
    int z = 0;
    y = x % 10; // Parse first digit
    if (y == 9)
    {
        y = 0; // Set to 0 if respective digit is 9
    }
    else
    {
        y++; // Add 1 to respective digit
    }
    z += y; // Digit summation
    y = (x % 100) - (x % 10); // Parse second digit
    if (y == 90)
    {
        y = 0; // Set to 0 if respective digit is 9
    }
    else
    {
        y += 10; // Add 1 to respective digit
    }
    z += y; // Digit summation
    y = (x % 1000) - (x % 100); // Parse third digit
    if (y == 900)
    {
        y = 0; // Set to 0 if respective digit is 9
    }
    else
    {
        y += 100; // Add 1 to respective digit
    }
    z += y; // Digit summation
    y = (x % 10000) - (x % 1000); // Parse fourth digit
    if (y == 9000)
    {
        y = 0; // Set to 0 if respective digit is 9
    }
    else
    {
        y += 1000; // Add 1 to respective digit
    }
    z += y; // Digit summation
    y = (x % 100000) - (x % 10000); // Parse fifth digit
    if (y == 90000)
    {
        y = 0; // Set to 0 if respective digit is 9
    }
    else
    {
        y += 10000; // Add 1 to respective digit
    }
    z += y; // Digit summation
    return z;
}

void questionThree(int x) // Question Three: Palindrome
{
    int y = x % 100; // Parse last 2 digits
    int z = (x - (x % 1000)) / 1000; // Parse first two digits
    if (y == z) // Palindrome condition 1: where first two and last two digits are already equal
    {
        printf("This number is a palindrome");
    }
    else if ((y - 9) == z) // Palindrome condition 2: where first two and last two digits are mirrors (-9)
    {
        printf("This number is a palindrome");
    }
    else if (y == (z-9)) // Palindrome condition 2: where first two and last two digits are mirrors (-9)
    {
        printf("This number is a palindrome");
    }
    else // Non-palindrome response
    {
        printf("This number is not a palindrome");
    }

}

void questionFour(int x, int y) // Question 4: Integer comparison
// Was explicitly stated that only the single-selection form of 'if' was to be used. if-else would have worked as well.
{
    if (x == y)
    {
        printf("It's a square");
    }
    if (x != y)
    {
        printf("It's not a square");
    }
}

void questionFive(int x, int y, int z) // Question 5: Three number calculator
{
    printf("Sum is: %d\n", x + y + z); // Evaluates and prints sum
    printf("Average is: %lf\n",(double)(x + y + z) / 3); // Evaluates and prints average. Note: Average value casted to double
    printf("Product is: %d\n", x *y * z); //
    printf("Smallest is: %d\n", min(min(x, y), z));
    printf("Largest is: %d\n", max(max(x, y), z));
}

int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
