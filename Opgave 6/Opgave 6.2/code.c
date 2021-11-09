#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIME_GRANULARITY 3
#define SEC_PR_SEC 1
#define SEC_PR_MIN 60
#define SEC_PR_HOU 3600
const long TC[] = {SEC_PR_HOU, SEC_PR_MIN, SEC_PR_SEC};
const char TimeName[TIME_GRANULARITY][16] = {"Time", "Minut", "Sekund"};
const char TimeNamePlural[TIME_GRANULARITY][16] = {"Timer", "Minutter", "Sekunder"};

int main(void) {
  //Initializes useful arrays
  
  
  long total_time = 0;
  long hour = 0;
  long min = 0;
  long sec = 0;

  //Get seconds from user.
  GetInputFromUser(&total_time);
  
  //Calculates time intervals
  CalculateTime(total_time, &hour, &min, &sec);

  //Print the result
  PrintResult(hour, min, sec);
  

  return EXIT_SUCCESS;
}

void GetInputFromUser (long *total_time) {
  printf("Indtast antal sekunder som et helt tal:\n");
  scanf(" %ld", total_time);
  fflush(stdin);
}

void CalculateTime (long total_time, long *hour, long *min, long *sec) {
  long remaining_time = total_time;
  long result[TIME_GRANULARITY];
  int noneZeroResults = 0;
  for (int i = 0; i < TIME_GRANULARITY; i++) {
    result[i] = remaining_time / TC[i];
    remaining_time = remaining_time % TC[i];
    if (result[i] != 0) {
      noneZeroResults++;
    }
  }
}

void PrintResult (long hour, long min, long sec) {
  char charResult[TIME_GRANULARITY][20];
  int offset = 0;
  int noneZeroResults = (hour == 0) + (min == 0) + (sec == 0);
  for (int i = 0; i < noneZeroResults; i++) {
    while (result[i+offset] == 0) {
      offset++;
    }
    int index = i + offset;
    char format[15];
    if (i == 0) {
      //Change the format depending on how many results was not 0.
      if (noneZeroResults == 1) {
        strcpy(format, "%llu %s.\n");
      } else if (noneZeroResults == 2) {
        strcpy(format, "%llu %s");
      } else {
        strcpy(format, "%llu %s,");
      }
    } else if (i == noneZeroResults - 1) {
      strcpy(format, " og %llu %s.\n");
    } else {
      strcpy(format, " %llu %s,");
    }
    printf(format, result[index], result[index] == 1 ? TimeName[index] : TimeNamePlural[index]);
  }

}