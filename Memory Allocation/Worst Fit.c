#include <stdio.h>

void allocateMemory(int blocks[], int numBlocks, int processes[], int numProcesses) {
    int i, j;

    // Step 3: Repeat the process for every process
    for (i = 0; i < numProcesses; i++) {
        int maxBlockSize = -1;
        int maxBlockIndex = -1;

        // Find the block with the maximum size that can accommodate the process
        for (j = 0; j < numBlocks; j++) {
            if (blocks[j] >= processes[i] && blocks[j] > maxBlockSize) {
                maxBlockSize = blocks[j];
                maxBlockIndex = j;
            }
        }

        // Step 3: If a suitable block is found, allocate the process
        if (maxBlockIndex != -1) {
            printf("Process %d of size %d allocated to Block %d of size %d\n",
                   i + 1, processes[i], maxBlockIndex + 1, blocks[maxBlockIndex]);
            blocks[maxBlockIndex] -= processes[i];  // Reduce the block size after allocation
        } else {
            // Step 3: If no block can accommodate the process, show the message
            printf("Memory not enough for Process %d of size %d\n", i + 1, processes[i]);
        }
    }
}

int main() {
    int numBlocks, numProcesses;

    // Step 1: Read the number of blocks and block sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    int blocks[numBlocks];

    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < numBlocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    // Step 2: Read the number of processes and process sizes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int processes[numProcesses];

    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // Step 3-4: Call the function to allocate memory
    printf("Allocation of Processes using Worst Fit is as follows: \n");
    allocateMemory(blocks, numBlocks, processes, numProcesses);

    // Step 5: Stop
    return 0;
}
