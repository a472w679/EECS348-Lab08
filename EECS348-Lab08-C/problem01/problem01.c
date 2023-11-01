#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MONTHCNT 12
#define MONTHLEN "9"

const char *MONTHS[] = {
    "January"  , "February", "March"   , "April"   ,  
    "May"      , "June"    , "July"    , "August"  , 
    "September", "October" , "November", "December"
};

void monthlyReport(double *sales);
void salesSummary(double *sales);
void movingAverage(double *sales);
void salesReport(double *sales);

int main(int argc, char **argv) {

    /**
     * Note, you can pass the name of the file 
     * you want to parse as an argument to the 
     * program. The default is "input.txt".
     */

    // Check if file was passed as arg
    char *inputFile = "input.txt"; // default
    if (argc >= 2) inputFile = argv[1];

    // Open file for reading
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) return 1;

    // Read file into line array
    char line[16], *end;
    double sales[MONTHCNT];
    for (short i = 0; i < MONTHCNT; i++) {
        if (fgets(line, sizeof(line), file) == NULL) return 1;
        sales[i] = strtod(line, &end);
    }
    fclose(file);

    // Call sales functions
    monthlyReport(sales);
    salesSummary(sales);
    movingAverage(sales);
    salesReport(sales);

    return 0;
}

void printHeader() {
    // Print table header
    printf("Month     Sales\n");
}

void monthlyReport(double *sales) {
    printf("Monthly sales report for 2023:\n");
    printHeader();

    // Print each month alongside its sales
    for (short i = 0; i < MONTHCNT; i++)
        printf("%-"MONTHLEN"s $%.2f\n", MONTHS[i], sales[i]);
    printf("\n");
}

void salesSummary(double *sales) {
    printf("Sales Summary:\n");
    short minIndex, maxIndex;
    double min = DBL_MAX, max = 0, sum = 0;
    for (short i = 0; i < MONTHCNT; i++) {

        // Update minimum
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }

        // Update maximum
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }

        // Accumulate sum
        sum += sales[i];
    }

    // Print minimum, maximum, and average sales
    printf("Minimum sales: $%.2f (%s)\n", min, MONTHS[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, MONTHS[maxIndex]);
    printf("Average sales: $%.2f\n", sum / MONTHCNT);
    printf("\n");
}

void movingAverage(double *sales) {
    printf("Six-Month Moving Average Report:\n");
    const short frame = 6;
    for (short i = 0; i <= frame; i++) {
        double sum = 0;

        // Compute sum across moving frame
        for (short j = i; j < i + frame; j++)
            sum += sales[j];
        
        // Print average
        printf(
            "%-"MONTHLEN"s - %-"MONTHLEN"s $%.2f\n", 
            MONTHS[i], 
            MONTHS[i + frame - 1], 
            sum / (double) frame
        );
    }
    printf("\n");
}

volatile double *compValues;
int comp(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return compValues[*y] - compValues[*x];
}

void salesReport(double *sales) {
    printf("Sales Report (Highest to Lowest):\n");
    printHeader();

    // Create an unsorted month index map
    int monthMap[MONTHCNT];
    for (int i = 0; i < MONTHCNT; i++)
        monthMap[i] = i;

    // Sort index map by monthly sales so that both
    // month and sales can be indexed in sorted order.
    compValues = sales;
    qsort(monthMap, MONTHCNT, sizeof(*monthMap), comp);

    // Print monthly sales in order of sales descending.
    for (int i = 0; i < MONTHCNT; i++) {
        int mapIndex = monthMap[i];
        printf("%-"MONTHLEN"s $%.2f\n", MONTHS[mapIndex], sales[mapIndex]);
    }
    printf("\n");
}
