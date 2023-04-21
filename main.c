/*
  TODO:
- Add parsing for output path
- ???

*/

#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char help_flag[] = "help";
      
  FILE *text_file, *binary_file;
  char ch;

 
    if (!argv[1]) { // If launched with no arguments
      printf("ERROR: No input file provided. Exiting.\nFor help: use 't2b help'");
    } else if (strcmp(argv[1], help_flag) == 0) { //If help is invoked
      printf("\nUsage: t2b.exe [Input file]");
    }
    else { // Open input file for reading
      text_file = fopen(argv[1], "r");
      if (text_file == NULL) {
	printf("ERROR: Failed to open input file: %s", argv[1]);
      }
        
      binary_file = fopen("OUTPUT.bin", "wb"); // Open output file for writing
      if (binary_file == NULL) {
	printf("ERROR: Failed to write output binary.");
      }
 
      while ((ch = fgetc(text_file)) != EOF) {
	fwrite(&ch, sizeof(char), 1, binary_file);
      }

      fclose(text_file);
      fclose(binary_file);
      printf("Wrote file: OUTPUT.bin");
    }
    
    return 0;
  
}
