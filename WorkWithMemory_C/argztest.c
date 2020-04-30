#include "argz.h"

int main() {

	char* const string = "SHELL=/bin/bash:usr=monty:PWD=/bin/monty:LANG=en_US.UTF-8";
	char* argz = NULL;
	char* entry = NULL;
	int argz_len = NULL;

	//tests
	printf("\n Test 'argz_create_sep':\n");
	argz_create_sep(string, 58, &argz, &argz_len);
	printf(" Result:  ");
	argz_print(argz, argz_len);
	printf(" argz_len = %d\n", argz_len);
    
	printf("\n Test 'argz_count':\n");
	printf(" Count = %d\n", argz_count(argz, argz_len));

	printf("\n Test 'argz_add':\n");
	argz_add(&argz, &argz_len, "Add-Valu/e");
	printf(" Result:  ");
	argz_print(argz, argz_len);
	printf(" argz_len = %d\n", argz_len);
	
	
	printf("\n Test 'argz_delete':\n");
	argz_delete(&argz, &argz_len, "Add-Valu/e");
	printf(" Result:  ");
	argz_print(argz, argz_len);
	printf(" argz_len = %d\n", argz_len);
	
	printf("\n Test 'argz_insert':\n");
	argz_insert(&argz, &argz_len, argz, "SENTI");
	printf(" Result:  ");
	argz_print(argz, argz_len);
	printf(" argz_len = %d\n", argz_len);
	
	printf("\n Test 'argz_replace':\n");
	argz_replace(&argz, &argz_len, "SENTI", "SENTIMENTAL=VALUE");
	printf(" Result:  ");
	argz_print(argz, argz_len);
	printf(" argz_len = %d\n", argz_len);

	printf("\n Test 'argz_next':\n");
	for (entry = argz; entry; entry = argz_next(argz, argz_len, entry)) {
		printf("\t\t  %s\n", entry);
	}
	return 0;
}