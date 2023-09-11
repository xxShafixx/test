%{
	 // c declarations 
	 int count = 0;
	 void myprint(char*, char*);
%}

OCTAL [0-7]
DECIMAL [0-9]
HEXADECIMAL [0-9a-e]
INVALID [f-z]

%%

{DECIMAL}+ 								{myprint("decimal", yytext);}
{OCTAL}+								{myprint("octal", yytext);}
{HEXADECIMAL}+ 							{myprint("hexadecimal", yytext);}
{INVALID}+                              {myprint("invalid", yytext);}

. ;

%%

int main()
{
	 yylex();
	 return 0;
}

void myprint(char* token, char* lexeme){

	printf("\n %s %s\n", token, lexeme);

}
