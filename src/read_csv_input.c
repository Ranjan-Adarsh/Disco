#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int total_websites_limit = 1e3, name_length_of_each_website_limit = 1e2;

int main () {
   FILE *stream = fopen("SampleInput.csv", "r");
   char line[1024];  //buffer
   char labels[total_websites_limit][name_length_of_each_website_limit]; 
   int label_count = 0;
   /* reading and counting labels/names of the websites */
   if (fgets(line, sizeof(line), stream)) {
      int i = 0;
      char *token;
      token = strtok(line, " ");
      while (token != NULL) {
         if (i != 0) {
            strcpy(labels[i - 1], token);
         }
         token = strtok(NULL, " ");
         i++;
      }
      label_count = i;
   }
   /* filling the graph as a 2d-matrix */
   int graph[label_count][label_count];
   int row = 0;
   while (fgets(line, sizeof(line), stream)) {
      char* tmp = strdup(line);
      char *token;
      token = strtok(tmp, " ");
      int column = 0;
      while (token != NULL) {
         if (column != 0) {
            char c[100];
            strcpy(c, token);
            graph[row][column - 1] = (c[0] - '0');
         }   
         token = strtok(NULL, " ");
         column++;
      }
      free(tmp);
      row++;
   }
   fclose(stream);
   return 0;
}  