#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtbl.h"

static void usage()
{
    printf("Usage: wordcount DICO [FILE]...\n\n"
           "DICO is a single-word-per-line dictionnary file.\n"
           "If no FILE is given, the standard input is used instead.\n\n");
}

static void parse_files(FILE *dico, FILE **filelst)
{
    /* FIXME: parse & hashtbl init & job */
}

static void parse_input(FILE *dico)
{
    /* FIXME: parse & hashtbl init & job */
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage();
        return -EINVAL;
    }

    FILE *dico = fopen(argv[1], "r");

    if (!dico) {
        perror(argv[1]);
        return -ENOENT;
    }
    argc -= 2;

    printf("%d", argc);

    if (argc > 0) {
        FILE **filelst = malloc(sizeof(FILE *) * argc);

        if (!filelst) {
            perror("error");
            return -ENOMEM;
        }
        for (int i = 0; i < argc; ++i) {
            filelst[i] = fopen(argv[i + 2], "r");
            if (!filelst[i]) {
                perror(argv[i + 1]);
                return -ENOENT;
            }
        }
        parse_files(dico, filelst);
    } else {
        parse_input(dico);
    }

    /* Streams are flushed and freed on exit */
    return 0;
}
