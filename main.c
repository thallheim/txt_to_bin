/*
  TODO:
- Add parsing for output path
- Add usage string(s)
- ???

*/

#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {

  
    FILE *text_file, *binary_file;
    char ch;

    if (!argv[1]) {
      printf("ERROR: No input file provided. Exiting.");
    } else {

      text_file = fopen(argv[1], "r");
      if (text_file == NULL) {
	printf("ERROR: Failed to open input file: %s", argv[1]);
      }
        
      binary_file = fopen("OUTPUT.bin", "wb");
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
