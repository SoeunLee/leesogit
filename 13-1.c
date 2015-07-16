#include <stdio.h>

#define STR_LENGTH 100

void make_secret_key();
void solve_secret_key();

void main(void) {
	char menu_num;

	printf("1. 암호화\n");
	printf("2. 복호화\n");
	printf("메뉴 선택 : ");

	switch(menu_num = getc(stdin)) {
		case '1': make_secret_key();	break;
		case '2': solve_secret_key();	break;
		default: return;
	}
}

char input_key() {
	char key;

	printf("키 입력 : ");
	getchar();
	scanf("%c", &key);

	return key - 'a' + 1;
}

void make_secret_key() {
	char key = input_key();
	char str[STR_LENGTH + 1];
	int i = -1;

	printf("암호화 할 문장 : ");
	getchar();
	fgets(str, sizeof(str), stdin);

	while (str[++i] != '\0') {
		if (str[i] == ' ') {}
		else if (str[i] + key > 'z')
			str[i] = str[i] + key - ('z' - ('a' - 1));
		else str[i] = str[i] + key;
	}

	printf("암호화 된 문장 : %s\n", str);
}

void solve_secret_key() {
	char key = input_key();
	char str[STR_LENGTH + 1];
	int i = -1;

	printf("복호화 할 문장 : ");
	getchar();
	fgets(str, sizeof(str), stdin);
	
	while (str[++i] != '\0') {
		if (str[i] == ' ') { }
		else if (str[i] - key < 'a')
			str[i] = str[i] - key + ('z' - ('a' - 1));
		else str[i] = str[i] - key;
	}

	printf("복호화 된 문장 : %s\n", str);
}
