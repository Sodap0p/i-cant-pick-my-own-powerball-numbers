#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_powerball(int numbers[5], int *powerball) {
    int i, j;

    srand(time(NULL)); 

    // generate 5 random numbers between 1 and 69
    for (i = 0; i < 5; i++) {
        numbers[i] = rand() % 69 + 1;
        for (j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                i--;
                break;
            }
        }
    }

    // generate the powerball numb between 1 and 26
    *powerball = rand() % 26 + 1;
}

int main() {
    int numbers[5], powerball;
    int i;
    
    generate_powerball(numbers, &powerball);
    
    printf("Powerball numbers: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("Powerball: %d\n", powerball);
    
    return 0;
}
