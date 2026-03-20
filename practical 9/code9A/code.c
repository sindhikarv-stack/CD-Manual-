%{
#include <stdio.h>

int chars = 0, words = 0, lines = 0;
%}

%%
\n              { lines++; chars++; }
[ \t]+          { chars += yyleng; }
[^ \t\n]+       { words++; chars += yyleng; }
%%

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        printf("Usage: ./count <filename>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Cannot open file\n");
        return 1;
    }

    yyin = fp;
    yylex();

    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);

    fclose(fp);
    return 0;
}

int yywrap() {
    return 1;
}
