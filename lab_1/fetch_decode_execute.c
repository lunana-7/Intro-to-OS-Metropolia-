#include <stdio.h>

/* Opcodes */
#define LOAD 1
#define ADD 2
#define STORE 3

int main(void) {
    int accumulator = 0; /* Temporary storage */
    int pc = 0;          /* Program Counter */

    /* Instructions: {opcode, operand} */
    int instructions[][2] = {
        {LOAD, 5},  /* LOAD 5 into accumulator */
        {ADD, 10},  /* ADD 10 to accumulator */
        {STORE, 0}  /* STORE result (just display it here) */
    };

    int instruction_count = sizeof(instructions) / sizeof(instructions[0]);

    printf("Simulating Fetch-Decode-Execute Cycle:\n");

    while (pc < instruction_count) {
        int opcode = instructions[pc][0];
        int operand = instructions[pc][1];

        if (opcode == LOAD) {
            accumulator = operand;
            printf("LOAD: Accumulator = %d\n", accumulator);
        } else if (opcode == ADD) {
            accumulator += operand;
            printf("ADD: Accumulator = %d\n", accumulator);
        } else if (opcode == STORE) {
            printf("STORE: Result = %d\n", accumulator);
        }

        pc++;
    }

    return 0;
}
