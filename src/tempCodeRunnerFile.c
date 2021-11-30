void export (char *filename, int A[length][length]) {  
//    filename = strcat(filename, ".csv");
//    FILE *fp = fopen(filename, "w+");
//    for (int i = 0; i < length; i++) {
//       fprintf(fp,",%s", sites[i]);
//    }
//    fprintf(fp,"\n");
//    for (int i = 0; i < length; i++) {
//       fprintf(fp,"%s", sites[i]);
//       for (int j = 0; j < length; j++) {
//          fprintf(fp,",%d", A[i][j]);
//       }    
//       fprintf(fp,"\n");
//    }
//    plot(filename);
//    fclose(fp);
// }