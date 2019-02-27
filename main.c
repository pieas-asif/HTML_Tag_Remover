#include<stdio.h>

int main() {
    FILE * read = fopen("read.txt", "r");
    FILE * write = fopen("output.txt", "w");
    char line[256];
    int iter = 0;
    int rite = 1;
    while(fgets(line, sizeof(line), read)) {
        printf("%s\n" ,line);
        printf("Iter %d\n", iter);
        for(iter = 0; line[iter] != '\0'; iter++) {
            printf("Iter %d\n", iter);
            if(line[iter] == '<') {
                rite = 0;
            }
            if(rite == 1) {
                fprintf(write, "%c", line[iter]);
            }
            if (line[iter] == '>') {
                rite = 1;
            }


        }
    }

    fclose(read);
    fclose(write);

    return 0;
}
