#include "dcl.h"

/* undcl: convert word descriptions to declarations */
int main()
{
	int type;
	char temp[MAXTOKEN];
	extern int gettoken(void);
	int prev;

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS)
				if(prev == '*'){
					sprintf(temp, "(%s)%s", out, token);
					strcpy(out, temp);
				}
				else
					strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "*%s", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
				printf("%s\n", out);
			} else
				printf("invalid input at %s\n", token);
			prev = type;
		}
	}
	return 0;
}
