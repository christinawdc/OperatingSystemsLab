#include <stdio.h>

void allocateMemory(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int i, j, bestIndex;
    
    for (i = 0; i < numProcesses; i++) {
        int bestBlockSize = -1;
        bestIndex = -1;

        // Step 3: Search for the best memory block that is small enough
        for (j = 0; j < numBlocks; j++) {
            if (blocks[j] >= processes[i]) {
                if (bestBlockSize == -1 || blocks[j] < bestBlockSize) {
                    bestBlockSize = blocks[j];
                    bestIndex = j;
                }
            }
        }

        // Step 5-7: If a best block was found, allocate the process
        if (bestIndex != -1) {
            printf("Process %d allocated to block %d (Block size: %d, Process size: %d)\n",
                   i + 1, bestIndex + 1, blocks[bestIndex], processes[i]);
            blocks[bestIndex] -= processes[i];  // Decrease the block size after allocation
        } else {
            // Step 8: If no suitable block is found
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

    // Step 3: Get the sizes of the memory blocks
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // Step 4: Get the sizes of the processes
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Step 5-8: Call the function to allocate memory
    printf("Allocation of Processes using Best Fit is as follows: \n");
    allocateMemory(blocks, numBlocks, processes, numProcesses);

    // Step 9: End of program
    return 0;
}
