#include <stdio.h>

int main(int argc, char *argv[]) {

  // TODO: Parse cmdline for input file
  
    FILE *text_file, *binary_file;
    char ch;

    text_file = fopen("a.txt", "r");
    binary_file = fopen("gig.bin", "wb");

    while ((ch = fgetc(text_file)) != EOF) {
        fwrite(&ch, sizeof(char), 1, binary_file);
    }

    fclose(text_file);
    fclose(binary_file);

    return 0;
}
