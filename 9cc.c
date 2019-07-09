#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void error(char *fmt, ...);

int main(int argc, char **argv) {
    if (argc != 2) {
        error("引数の個数が正しくありません。");
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("    mov rax, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            p++;
            printf("    add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            p++;
            printf("    sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        error("予期しない文字です：'%c'\n", *p);
    }

    printf("    ret\n");

    return EXIT_SUCCESS;
}

void error(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}
