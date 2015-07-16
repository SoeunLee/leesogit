/***
 * heading : Program getting strings from keyboard and print the strings to console
 * last update : 2015-07-17
 * author : SoeunLee
 * purpose : studying dynamic memory allocation and coding convention
 * usage : submitting assignment(or practice)
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBER 10//max number of strings is 10
#define MAX_LENGTH 99//max length of a string is 99

char *new();
/***
 *  function description : while the new string is a string "end",
 * 		or the number of existing strings is smaller than [MAX_NUMBER + 1],
 *  	new(); return newly allocated memory to save the new string.
 */
int main (void) {
	char *ptr[MAX_NUMBER + 1] = { 0 };
	int i = -1;

	while (++i < MAX_NUMBER) {
		ptr[i] = new();
		if(ptr[i] == NULL) break;
	}

	i = -1;
	while (ptr + ++i != NULL)
		printf("%s", *(ptr + i));

	return 0;
}
/***
 * author : SoeunLee
 * function description : new(); gets a string and take strlen(); of the string.
 */
char *new (void) {
	char tmp_str[MAX_LENGTH + 1] = { 0 };//get a string to take strlen();
	char *new_str = NULL;

	printf("입력 : ");
	fgets(tmp_str, sizeof(tmp_str), stdin);//fgets(); gets '\n' too.

	if(strcmp("end\n", tmp_str) != 0) {
		new_str = (char *) malloc (strlen(tmp_str) + 1);
		strcpy(new_str, tmp_str);
	}
	return new_str;
}
