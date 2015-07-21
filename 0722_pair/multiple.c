#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LENGTH 512
#define MAX_KEY_LENGTH 256

void make_secret_sentence();
void solve_secret_sentence();

int main(void) {
	char menu_num;

	printf("1. 암호화\n");
	printf("2. 복호화\n");
	printf("메뉴 선택 : ");

	switch(menu_num = getc(stdin)) {
		case '1': make_secret_sentence();	break;
		case '2': solve_secret_sentence();	break;
		default: return 0;
	}
}

char* input_key() {
	char key[MAX_KEY_LENGTH];
	int key_length;
	int i; 
	printf("키 입력 : ");
	getchar();
	fgets(key, sizeof(key), stdin);
	key_length = strlen(key);

	char* malloc_key = (char*)malloc(sizeof(char) * key_length + 1); // include NULL character

	for(i = 0 ; i < key_length; i++){
		key[i] = key[i] - 'a' + 1;
	}
	
	strcpy(malloc_key, key);
	
	return malloc_key;
}

void make_secret_sentence() {
	char* key = input_key();
	char str[MAX_STR_LENGTH + 1];
	int i, key_index = 0;
	int str_length, key_length; 

	printf("암호화 할 문장 : ");
	fgets(str, sizeof(str), stdin);

	str_length = strlen(str);
	key_length = strlen(key);
	for(i = 0 ; i < str_length ; i++){

		if (str[i] == ' ' || str[i] == '\n') { }
		else if (str[i] + key[key_index] > 'z'){
			str[i] = str[i] + key[key_index] - ('z' - ('a' - 1));
		}
		else {
			str[i] = str[i] + key[key_index];
		}
		if(key[key_index++ + 2] == '\0'){
			key_index = 0;
		}
	}

	printf("암호화 된 문장 : %s\n", str);
}

void solve_secret_sentence() {
	char* key = input_key();
	char str[MAX_STR_LENGTH + 1];
	int i, key_index = 0;
	int str_length, key_length;

	printf("복호화 할 문장 : ");
	fgets(str, sizeof(str), stdin);

	str_length = strlen(str);
	key_length = strlen(key);
	for(i = 0 ; i < str_length ; i++){

		if (str[i] == ' ' || str[i] == '\n') { }
		else if (str[i] - key[key_index] < 'a'){
			str[i] = str[i] - key[key_index] + ('z' - ('a' - 1));
		}
		else {
			str[i] = str[i] - key[key_index];
		}
		if(key[key_index++ + 2] == '\0'){
			key_index = 0;
		}
	}

	printf("복호화 된 문장 : %s\n", str);
}