#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int skipNullBytes = 0;
    int printEvery = 1;

    int opt;
    while ((opt = getopt(argc, argv, "ns:")) != -1) {
        switch (opt) {
            case 'n':
                skipNullBytes = 1;
                break;
            case 's':
                printEvery = atoi(optarg);
                break;
            default:
                fprintf(stderr, "For documentation, read the source");
                exit(EXIT_FAILURE);
        }
    }

    int i = 0;
    while (1) {
        int c = getchar();
        if (c == EOF)
            break;

        if (skipNullBytes && c == 0)
            continue;

        if (++i != printEvery)
            continue;
        i = 0;

        putchar(c);
    }
}
