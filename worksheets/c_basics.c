/*
 * c_basics.c
 * A comprehensive single-file tutorial covering the fundamentals of
 * the C programming language.
 * Compile with: gcc c_basics.c -o c_basics -lm
 * Run with:     ./c_basics
 */

#include <stdio.h>   // Standard Input/Output (printf, scanf)
#include <stdlib.h>  // Standard Library (malloc, free, atoi)
#include <string.h>  // String functions (strcpy, strlen, strcmp)

// ============================================================================
// SECTION 1: PREPROCESSOR DIRECTIVES & CONSTANTS
// ============================================================================

// Define a constant macro (text replacement before compilation)
#define PI 3.14159265
#define MAX_STRING_SIZE 100
#define ARRAY_SIZE 5

// ============================================================================
// SECTION 2: STRUCTURE DEFINITION (user-defined data type)
// ============================================================================

// A struct groups related variables together into a single unit.
struct Student {
    char name[MAX_STRING_SIZE];
    int  id;
    float grade;
};

// ============================================================================
// SECTION 3: FUNCTION PROTOTYPES (forward declarations)
// ============================================================================

// Declaring functions before use allows the compiler to check types.
// -----------------------------------------
void demo_variables_and_types(void);
void demo_operators(void);
void demo_conditionals_and_loops(void);
void demo_arrays(void);
void demo_strings(void);
void demo_functions_with_parameters(int a, float b);
void demo_structures_and_typedef(void);

// Functions can have return values other than void.
int  square(int num);

// ============================================================================
// SECTION 4: THE main() FUNCTION
// ============================================================================
// Every C program starts execution at main(). It can take arguments:
//   int main(int argc, char *argv[])
// Here we use the simplest form with no arguments.

int main() {
    printf("========================================\n");
    printf("  C PROGRAMMING BASICS TUTORIAL\n");
    printf("========================================\n\n");

    // --- Call each demo function in order ---
    demo_variables_and_types();
    demo_operators();
    demo_conditionals_and_loops();
    demo_arrays();
    demo_strings();
    demo_structures_and_typedef();

    // Return 0 signals successful execution to the operating system.
    return 0;
}

// ============================================================================
// SECTION 5: FUNCTION IMPLEMENTATIONS
// ============================================================================

// ----------------------------------------------------------------------------
// 5.1 Variables and Data Types
// ----------------------------------------------------------------------------
void demo_variables_and_types(void) {
    printf("--- VARIABLES & DATA TYPES ---\n");

    // Integer types with different sizes and signedness.
    char letter = 'C';                // Typically 1 byte, -128 to 127
    short small_num = 2500;           // Typically 2 bytes
    int age = 25;                     // Typically 4 bytes (most common integer type)
    long big_population = 7800000000; // Typically 8 bytes
    unsigned int positive_only = 100; // Only positive values, extends range

    // Floating-point types for real numbers.
    float pi_approx = 3.14f;          // Typically 4 bytes, single precision (note the 'f')
    double precise_pi = 3.14159265359; // Typically 8 bytes, double precision

    // We typically don't use booleans,
    // instead we use integers (0 for false, 1 for true).
    int is_completed = 1;

    // Constants cannot be modified after declaration.
    const int BIRTH_YEAR = 1999;

    // Print using format specifiers that match the data type.
    printf("char:        %c\n", letter);
    printf("short:       %hd\n", small_num);
    printf("int:         %d\n", age);
    printf("long:        %ld\n", big_population);
    printf("unsigned:    %u\n", positive_only);
    printf("float:       %.2f\n", pi_approx);    // .2 limits decimals
    printf("double:      %.10f\n", precise_pi);
    printf("const int:   %d\n", BIRTH_YEAR);

    // Type casting: temporarily treat a variable as another type.
    int numerator = 5, denominator = 2;
    float result = (float)numerator / denominator; // Cast int to float
    printf("Casting:     %d / %d = %.2f\n\n", numerator, denominator, result);
}

// ----------------------------------------------------------------------------
// 5.2 Operators
// ----------------------------------------------------------------------------
void demo_operators(void) {
    printf("--- OPERATORS ---\n");

    // Arithmetic operators: +, -, *, /, %
    int a = 10, b = 3;
    printf("Arithmetic:\n");
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    printf("  %d / %d = %d  (integer division)\n", a, b, a / b);
    printf("  %d %% %d = %d  (remainder)\n", a, b, a % b);  // %% prints a single %

    // Assignment operators: =, +=, -=, *=, /=, %=
    int x = 5;
    x += 3;  // Same as x = x + 3;
    printf("\nAssignment:  x started at 5, x += 3 gives x = %d\n", x);

    // Increment/Decrement: ++, --
    int pre = 0, post = 0;
    printf("Increment:\n");
    printf("  ++pre (pre-increment):  %d\n", ++pre);  // Adds then uses value
    printf("  post++ (post-increment): %d then becomes %d\n\n", post++, post);

    // Relational operators: ==, !=, <, >, <=, >=
    printf("Relational (0=false, 1=true):\n");
    printf("  10 == 10 : %d\n", 10 == 10);
    printf("  10 != 5  : %d\n", 10 != 5);
    printf("  10 > 5   : %d\n\n", 10 > 5);

    // Logical operators: && (AND), || (OR), ! (NOT)
    printf("Logical:\n");
    printf("  (1 && 1) = %d\n", 1 && 1);
    printf("  (1 || 0) = %d\n", 1 || 0);
    printf("  !1       = %d\n\n", !1);

    // Bitwise operators: &, |, ^, ~, <<, >>
    printf("Bitwise (binary):\n");
    printf("  5 & 3  = %d  (0101 & 0011 = 0001)\n", 5 & 3);
    printf("  5 | 3  = %d  (0101 | 0011 = 0111)\n", 5 | 3);
    printf("  5 << 1 = %d  (left shift by 1)\n\n", 5 << 1);

    // sizeof() operator: returns the memory size in bytes.
    printf("Memory sizes (bytes) on this machine:\n");
    printf("  sizeof(int):   %zu\n", sizeof(int));
    printf("  sizeof(char):  %zu\n", sizeof(char));
    printf("  sizeof(double): %zu\n\n", sizeof(double));
}

// ----------------------------------------------------------------------------
// 5.3 Conditionals and Loops (Control Flow)
// ----------------------------------------------------------------------------
void demo_conditionals_and_loops(void) {
    printf("--- CONDITIONALS & LOOPS ---\n");

    int score = 85;

    // --- if, else if, else ---
    printf("if/else if/else (score = %d): ", score);
    if (score >= 90) {
        printf("Grade A\n");
    } else if (score >= 80) {
        printf("Grade B\n");
    } else if (score >= 70) {
        printf("Grade C\n");
    } else {
        printf("Grade F\n");
    }

    // --- Ternary Operator (shorthand if-else) ---
    int age = 20;
    const char *status = (age >= 18) ? "Adult" : "Minor";
    printf("Ternary: age %d -> %s\n", age, status);

    // --- switch statement ---
    char day = '3';
    printf("switch (day = '%c'): ", day);
    switch (day) {
        case '1': printf("Monday"); break;
        case '2': printf("Tuesday"); break;
        case '3': printf("Wednesday"); break;
        default:  printf("Other day"); break; // Without 'break', fall-through occurs
    }
    printf("\n"); // New line after whichever case was printed

    // --- for loop ---
    printf("\nfor loop (i from 0 to 3): ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // --- while loop ---
    printf("while loop (countdown): ");
    int count = 3;
    while (count > 0) {
        printf("%d ", count);
        count--;
    }
    printf("Lift off!\n");

    // --- break and continue ---
    printf("break/continue demo (odd numbers < 7): ");
    for (int i = 1; i <= 10; i++) {
        if (i == 7) break;      // Exit loop completely
        if (i % 2 == 0) continue; // Skip even numbers
        printf("%d ", i);
    }
    printf("\n\n");
}

// ----------------------------------------------------------------------------
// 5.4 Arrays
// ----------------------------------------------------------------------------
void demo_arrays(void) {
    printf("--- ARRAYS ---\n");

    // Declare and initialize an array of integers.
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};

    // Access elements by index (0-based).
    printf("Integer array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Partially initialized arrays: rest set to 0.
    // int partial[5] = {1, 2}; // [1, 2, 0, 0, 0]

    // Multi-dimensional arrays.
    int matrix[2][3] = {
        {1, 2, 3},  // Row 0
        {4, 5, 6}   // Row 1
    };
    printf("2D array (matrix):\n");
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    // Arrays and memory: the array name is a pointer to the first element.
    printf("Address of numbers[0] = %p\n", (void*)numbers);
    printf("Value of numbers[0]  = %d\n\n", *numbers); // Dereference to get value
}

// ----------------------------------------------------------------------------
// 5.5 Strings (Character Arrays)
// ----------------------------------------------------------------------------
void demo_strings(void) {
    printf("--- STRINGS ---\n");

    // C strings are null-terminated character arrays.
    char greeting[MAX_STRING_SIZE] = "Hello, world!";

    printf("String: %s\n", greeting);
    printf("Length: %lu characters\n", strlen(greeting)); // #include <string.h>

    // Important string functions from <string.h>
    char copy[MAX_STRING_SIZE];
    strcpy(copy, greeting);               // Copy
    printf("Copy:   %s\n", copy);

    strcat(copy, " How are you?");        // Concatenate
    printf("Concat: %s\n", copy);

    printf("Compare 'hello' and 'hello': %d (0 = equal)\n",
           strcmp("hello", "hello"));

    char *token = strtok(copy, " ");      // Tokenize (WARNING: modifies string)
    printf("First token: %s\n\n", token); // Prints the string up to the first space
}

// ----------------------------------------------------------------------------
// 5.6 Structures and typedef
// ----------------------------------------------------------------------------
void demo_structures_and_typedef(void) {
    printf("--- STRUCTURES & TYPEDEF ---\n");

    // typedef creates an alias for an existing type.
    // It is commonly used with structs to avoid writing 'struct' everywhere.
    typedef struct Student Student_t;
    // Alternatively, combine:
    // typedef struct {
    //     char name[MAX_STRING_SIZE];
    //     int id;
    //     float grade;
    // } Student_t;

    // Declare and initialize a struct variable.
    Student_t student1;
    strcpy(student1.name, "Ada Lovelace");
    student1.id = 101;
    student1.grade = 97.5f;

    // Access members using the dot (.) operator.
    printf("Student 1:\n");
    printf("  Name:  %s\n", student1.name);
    printf("  ID:    %d\n", student1.id);
    printf("  Grade: %.1f%%\n", student1.grade);

    // Pointers to structs. Access members with arrow (->) operator.
    Student_t *ptr_to_student = &student1;
    printf("\nAccess via pointer:\n");
    printf("  Name:  %s\n", ptr_to_student->name);
    printf("  ID:    %d\n", ptr_to_student->id);
    printf("  Grade: %.1f%%\n\n", ptr_to_student->grade);
}
