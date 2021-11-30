// label_count = global length variable
// would use labels, a char array to fill names
// if this doesn't work then manually create a empty csv file with same filename.csv that you're going to enter as parameter   

void export (char *filename, int **A) {
   filename = strcat(filename, ".csv");
   FILE *fp = fopen(filename, "w+");
   for (int i = 0; i < label_count; i++) {
      fprintf(fp, ",%s", labels[i]);
   }
   fprintf(fp, "\n");
   for (int i = 0; i < label_count; i++) {
      fprintf(fp, "%s", labels[j]);
      for (int j = 0; j < label_count; j++) {
         fprintf(fp, ",%d", A[i][j]);
      }    
      fprintf(fp, "\n");
   }
   fclose(fp);
}
