/************************************************************************
*file: argz.c
*synopsis: The argz functions use malloc/realloc to allocate/grow argz vectors, and so any argz
* vector creating using these functions may be freed by using free; conversely, any argz
* function that may grow a string expects that string to have been allocated using malloc
* (those argz functions that only examine their arguments or modify them in place will work
* on any sort of memory). All argz functions that do memory allocation have a return type
* of error_t, and return 0 for success, and ENOMEM if an allocation error occurs.
* These functions are declared in the include file "argz.h".
*related files: none
*author: sentimental
*written: 23/09/2019
*last modified: 04/10/2019
************************************************************************/
#include "argz.h"

/*
The argz_create_sep function converts the null-terminated string string into an
argz vector (returned in argz and argz len) by splitting it into elements at every
occurrence of the character sep.
*/
error_t argz_create_sep(const char* string, int sep, char** argz, size_t* argz_len) {
	if (!string) return ERROR;
	*argz_len = strlen(string) + 1;
	*argz = (char*)malloc((*argz_len));
	if (NULL != *argz){
		for (size_t i = 0; i < *argz_len; i++) {
			(*argz)[i] = string[i];
			if (sep == string[i]) {
				(*argz)[i] = '\0';
			}
		}
		return OK;
	}
}

//Returns the number of elements in the argz vector.
size_t argz_count(const char* argz, size_t arg_len) {
	if ((!argz)||(!arg_len)) return 0;
	int count = 0;
	for (size_t i = 0; i < arg_len; i++){
		if ((argz[i] == '\0') && ( i > 0 ) && (argz[i - 1] != '\0')) count++; 
	}
	return count;
}

//The argz_add function adds the string str to the end of the argz vector // *argz, and updates *argz and *argz_len accordingly.
error_t argz_add(char** argz, size_t* argz_len, const char* str) {
	char* tmp = *argz, * new_argz, * copy_pos;
	int  i, count;
	if ((!str)||(!strlen(str))) return ERROR;
	if ((!argz) || (!argz_len)) return ERROR;
	count = argz_count(*argz, *argz_len);
	*argz_len += strlen(str) + 1;
	new_argz = (char*)malloc(*argz_len);
	copy_pos = new_argz;
	new_argz[*argz_len - 1] = 0;
	tmp = *argz;
	for (i = 0; i < count; i++) {
		strcpy(copy_pos, tmp);
		copy_pos += strlen(tmp) + 1;
		tmp += strlen(tmp) + 1;
	}
	strcpy(copy_pos, str);
	free(*argz);
	*argz = new_argz;
	return OK;
}

char* find_el(char* argz, size_t* argz_len, const char* entry) {
	if((!entry) || (!strlen(entry))) return NULL;
	char* tmp = argz;
	for (int i = 0; i < argz_count(argz, argz_len); i++) {
		if (0 == strcmp(tmp, entry)) return tmp;
		else tmp += strlen(tmp) + 1;
	}
	return NULL;
}

/*If entry points to the beginning of one of the elements in the argz vector *argz, 
the argz_delete function will remove this entry and reallocate *argz, 
modifying *argz and *argz_len accordingly. Note that as destructive argz functions 
usually reallocate their argz argument, pointers into argz vectors such as entry 
will then become invalid.
*/

void argz_delete(char** argz, size_t* argz_len, char* entry) {
	char* tmp = *argz, * new_argz, * copy_pos;
	int  i, count;
	if ((!entry) || (!find_el(*argz, *argz_len, entry)))return;
	if ((!argz) || (!argz_len)) return;
	count = argz_count(*argz, *argz_len);
	*argz_len -= strlen(entry) + 1;
	new_argz = (char*)malloc(*argz_len);
	new_argz[*argz_len - 1] = 0;
	copy_pos = new_argz;
	tmp = *argz;
	for (i = 0; i < count; i++) {
		if (strcmp(tmp, entry)) {
			strcpy(copy_pos, tmp);
			copy_pos += strlen(tmp) + 1;
		}
		tmp += strlen(tmp) + 1;
	}
	free(*argz);
	*argz = new_argz;
}

/*
The argz_insert function inserts the string entry into the argz vector 
*argz at a point just before the existing element pointed to by before,
reallocating *argz and updating *argz and *argz_len. If before is 0, entry 
is added to the end instead (as if by argz_add). Since the first element is in 
fact the same as *argz, passing in *argz as the value of before will result in entry
being inserted at the beginning.
*/
error_t argz_insert(char** argz, size_t* argz_len, char* before, const char* entry) {
	char* tmp = *argz, * new_argz, * copy_pos;
	int  i, count;
	if (!entry)return ERROR;
	if (!before) {
		argz_add(argz, argz_len, entry);
		return OK;
	}
	if (!find_el(*argz, *argz_len, before)) return ERROR;
	if ((!argz) || (!argz_len)) return ERROR;
	count = argz_count(*argz, *argz_len);
	*argz_len += strlen(entry) + 1;
	new_argz = (char*)malloc(*argz_len);
	new_argz[*argz_len - 1] = 0;
	copy_pos = new_argz;
	tmp = *argz;
	for (i = 0; i < count; i++) {
		if (0 == strcmp(tmp, before)) {
			strcpy(copy_pos, entry);
			copy_pos += strlen(entry) + 1;

		}
		strcpy(copy_pos, tmp);
		copy_pos += strlen(tmp) + 1;
		tmp += strlen(tmp) + 1;
	}
	free(*argz);
	*argz = new_argz;
	return OK;
}

/*
The argz_next function provides a convenient way of iterating over the elements in the argz vector argz. 
It returns a pointer to the next element in argz after the element entry, or 0 if there are no elements 
following entry.7 If entry is 0, the first element of argz is returned.
This behavior suggests two styles of iteration:
char *entry = 0;
while ((entry = argz_next (argz, argz_len, entry)))
					action;
(the double parentheses are necessary to make some C compilers shut up about what they 
consider a questionable while-test) and:
char *entry;
for (entry = argz; entry; entry = argz_next (argz, argz_len, entry))
				action;
Note that the latter depends on argz having a value of 0 if it is empty (rather than 
a pointer to an empty block of memory); this invariant is maintained for argz vectors 
created by the functions here.
*/

char* argz_next(char* argz, size_t argz_len, const char* entry) {
	char* tmp = argz;
	int  i, count;
	if (!entry) return argz;
	if ((!argz) || (!argz_len)||(!find_el(argz, argz_len, entry))) return NULL;
	count = argz_count(argz, argz_len);
	for (i = 0; i < count - 1; i++) {
		if (0 == strcmp(tmp, entry)) {
			return tmp + strlen(tmp) + 1;
		}
		tmp += strlen(tmp) + 1;
	}
	return NULL;
}

/*
Replace the string str in argz with string with, reallocating argz as
necessary.
*/
error_t argz_replace(char** argz, size_t* argz_len, const char* str, const char* with) {
	if ((!str)||(!with)||(!argz)||(!argz_len))return ERROR;
	else {
		argz_insert(argz, argz_len, str, with);
		argz_delete(argz, argz_len, str);
		return OK;
	}
	
}
/*prints argz vector */
void argz_print(const char* argz, size_t argz_len) {
	if ((argz_len == NULL)||(argz == NULL)) return;
	for (int i = 0; i < argz_len; i++) {
		if (argz[i] == '\0') {
			printf("'\\0'");
			continue;
		}
		printf("%c", argz[i]);
	}
	printf("\n");
}
