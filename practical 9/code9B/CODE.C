%{
#include <stdio.h>

int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]    { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] { consonants++; }
\n              { /* ignore */ }
.               { /* ignore */ }
%%

int main() {
    printf("Enter text:\n");
    yylex();

    printf("\nVowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}

int yywrap() {
    return 1;
}
