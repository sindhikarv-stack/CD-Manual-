%{
#include <stdio.h>
int line = 1;
%}

%%
^.*\n     { printf("%d: %s", line++, yytext); }
.         { /* ignore */ }
%%

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        printf("Usage: ./line <file>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file\n");
        return 1;
    }

    yyin = fp;
    yylex();

    fclose(fp);
    return 0;
}

int yywrap() {
    return 1;
}
