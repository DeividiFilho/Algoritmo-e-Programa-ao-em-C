//  programa que recebe duas strings e verifica se a segunda é uma substring da primeira

#include <stdio.h>
#include <string.h>

int main() {
	char str1[100], str2[100];
	int i, j, flag;
	
	printf("Digite a primeira string: ");
	scanf("%s", str1);
	
	printf("\nDigite a segunda string: ");
	scanf("%s", str2);
	
	for(i = 0; i <= strlen(str1) - strlen(str2); i++) {
		flag = 1;
		for (j = 0; j < strlen(str2); j++) {
			if (str1[i + j] != str2[j]) {
				flag = 0;
				break;
			}
		}
		if  (flag == 1) {
			printf("\n'%s' uma substring de '%s'.", str2, str1);
			return 0;
		}
	}
	printf("\n'%s' nao e uma substring de '%s'.", str2, str1);
	return 0;
}

