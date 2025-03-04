#include <stdio.h>

void allocateMemory(int holes[], int numHoles, int processes[], int numProcesses) {
    int i, j;
    for (i = 0; i < numProcesses; i++) {
        int allocated = 0;
        // Search for the first hole that is large enough
        for (j = 0; j < numHoles; j++) {
            if (holes[j] >= processes[i]) {
                // Allocate the process to this hole
                printf("Process %d allocated to hole %d (Size: %d)\n", i + 1, j + 1, holes[j]);
                holes[j] -= processes[i];  // Decrease the hole size after allocation
                allocated = 1;
                break;
            }
        }

        // If no suitable hole was found
        if (!allocated) {
            printf("Process %d could not be allocated\n", i + 1);
        }
    }
}

int main() {
    int numHoles, numProcesses;

    // Step 1: Declare the size
    printf("Enter the number of memory holes: ");
    scanf("%d", &numHoles);

    // Step 2: Get the number of processes to be inserted
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int holes[numHoles], processes[numProcesses];

    // Step 3: Get the sizes of the memory holes
    printf("Enter the sizes of the memory holes: \n");
    for (int i = 0; i < numHoles; i++) {
        printf("Hole %d size: ", i + 1);
        scanf("%d", &holes[i]);
    }

    // Step 4: Get the sizes of the processes
    printf("Enter the sizes of the processes: \n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Step 5: Call the function to allocate memory
    allocateMemory(holes, numHoles, processes, numProcesses);

    // Step 6: End of program
    return 0;
}
