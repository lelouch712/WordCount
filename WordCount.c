#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    int in_word = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        char_count++;

        if (c == ' ' || c == '\t' || c == '\n') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("×Ö·ûÊý£º%d\n", char_count);
    } else if (strcmp(parameter, "-w") == 0) {
        if (in_word) {
            word_count++;
        }
        printf("µ¥´ÊÊý£º%d\n", word_count);
    } else {
        printf("Invalid parameter, please use -c or -w.\n");
        return 1;
    }

    return 0;
}
