#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    int capacity = 4; // Initial capacity

    printf("Enter a string: ");

    // Read characters until newline or EOF
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Check if reallocation is needed
        if (i >= capacity - 1) {
            capacity *= 2; // Double the capacity
            str = realloc(str, capacity);
            if (str == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                exit(1);
            }
        }

        str[i++] = c;
    }

    // Add null terminator
    str[i] = '\0';

    printf("You entered: %s\n", str);

    // Free memory
    free(str);

    return 0;
}
