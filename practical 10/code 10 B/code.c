%{
#include <stdio.h>
%}

%%
"<"[^>]+">"     { printf("HTML Tag: %s\n", yytext); }
.|\n            { /* ignore */ }
%%

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2) {
        printf("Usage: ./html <file>\n");
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

int yywrap() { return 1; }
