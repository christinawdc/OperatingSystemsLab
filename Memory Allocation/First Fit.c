#include <stdio.h>

void allocateMemory(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int i, j;
    for (i = 0; i < numProcesses; i++) {
        int allocated = 0;
        // Search for the first memory block that is large enough
        for (j = 0; j < numBlocks; j++) {
            if (blocks[j] >= processes[i]) {
                // Allocate the process to this block 
                printf("Process %d of size %d allocated to block %d (Size: %d)\n", i + 1, processes[i], j + 1, blocks[j]);
                blocks[j] -= processes[i];  // Decrease the hole size after allocation
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
    int numBlocks, numProcesses;
    // Step 1: Declare the size
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    // Step 2: Get the number of processes to be inserted
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int blocks[numBlocks], processes[numProcesses];

    // Step 3: Get the sizes of the memory holes
    printf("Enter the sizes of the memory blocks: \n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // Step 4: Get the sizes of the processes
    printf("Enter the sizes of the processes: \n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Step 5: Call the function to allocate memory
    printf("Allocation of Processes using First Fit is as follows: \n");
    allocateMemory(blocks, numBlocks, processes, numProcesses);

    // Step 6: End of program
    return 0;
}
