%{
#include <stdio.h>
#include <string.h>

// List of keywords
char *keywords[] = {"int", "float", "if", "else", "while", "return", "for", "char", "double"};
int isKeyword(char *word) {
    for(int i = 0; i < 9; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}

%%
[0-9]+              { printf("NUMBER: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
                        if(isKeyword(yytext))
                            printf("KEYWORD: %s\n", yytext);
                        else
                            printf("IDENTIFIER: %s\n", yytext);
                      }

"=="|"!="|"<="|">="  { printf("RELATIONAL OPERATOR: %s\n", yytext); }

"+"|"-"|"*"|"/"      { printf("ARITHMETIC OPERATOR: %s\n", yytext); }

"="                  { printf("ASSIGNMENT OPERATOR: %s\n", yytext); }

";"|","|"("|")"|"{"|"}" {
                        printf("SPECIAL SYMBOL: %s\n", yytext);
                      }

[ \t\n]+             { /* Ignore whitespace */ }

.                    { printf("UNKNOWN: %s\n", yytext); }
%%

int main() {
    printf("Enter input:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
