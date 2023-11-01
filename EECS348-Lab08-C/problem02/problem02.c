#include <stdio.h>
#include <string.h>

#define PLAYCOUNT 5
const char* PLAYS[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};

void combinations(int target, int score, int *prevScoreComposition, int depth) {
    /**
     * Note that an iterative for-loop based approach will have 
     * superior performance over this recursive solution due to
     * the smaller number of memory operations needed. However,
     * quintuple nesting (and thus sextuple indentation) strikes
     * me as crude, especially when compared to the elegance of
     * recursion in this particular situation. 
     */

    /**
     * For additional performance, dynamic programming could be
     * applied in order to cache and reuse the branches beneath
     * each score encountered at a given depth. If memory usage
     * is ignored, this DP approach might be able to contend w/
     * the naive iterative approach in terms of performance. 
    */

    // Instantly discard overshoots
    if (score > target) return;

    // Create a new score composition array 
    int scoreComposition[PLAYCOUNT];
    memcpy(scoreComposition, prevScoreComposition, PLAYCOUNT * sizeof(int));
    scoreComposition[depth] += score && 1;

    // Check if the score is target
    if (score == target) {
        for (int i = 0; i < PLAYCOUNT; i++) // Print score line
            printf("%s%d %s", i ? ", " : "", scoreComposition[i], PLAYS[i]);
        printf("\n");
        return;
    }

    // Recursive waterfall
    switch (depth) {
        case 0: // TD + 2pt
            combinations(target, score + 8, scoreComposition, 0);
        case 1: // TD + FG
            combinations(target, score + 7, scoreComposition, 1);
        case 2: // TD
            combinations(target, score + 6, scoreComposition, 2);
        case 3: // FG
            combinations(target, score + 3, scoreComposition, 3);
        case 4: // Safety
            combinations(target, score + 2, scoreComposition, 4);
        
            /**
             * Note that this last depth could be preemptively
             * pruned at the cost of a subtraction and bitwise
             * right-shift. I have omitted this optimization to
             * maintain clarity and scalability. 
             */
    }
}

int main() {
    // Prompt user for score
    int score;
    printf("Score: ");
    scanf("%d", &score);

    // Exit if score is 1 or 0
    if (score <= 1) return 0;

    // Begin recursive combination finding
    int initComposition[] = {0,0,0,0,0};
    combinations(score, 0, initComposition, 0);

    // Repeat program
    printf("\n");
    main();
}