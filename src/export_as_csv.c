// label_count = global length variable

void export (char *filename, int A[][label_count]) {
   filename = strcat(filename, ".csv");
   FILE *fp = fopen(filename, "w+");
   for (int i = 0; i < label_count; i++) {
      fprintf(",%s", labels[i]);
   }
   fprintf("\n");
   for (int i = 0; i < label_count; i++) {
      fprintf("%s", labels[j]);
      for (int j = 0; j < label_count; j++) {
         fprintf(",%d", A[i][j]);
      }    
      fprintf("\n");
   }
   fclose(fp);
}
