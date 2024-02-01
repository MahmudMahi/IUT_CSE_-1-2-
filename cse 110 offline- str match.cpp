#include <stdio.h>
char *strstr(char *str1, char *str2) {
    if (*str2 == '\0') return str1; 
	while (*str1!='\0') {
        char *start = str1;
        char *pattern = str2;
        while (*str1!='\0' && *pattern!='\0' && *str1 == *pattern) {
            str1++;
            pattern++;
        }
        if (*pattern=='\0') return start;
        str1 = start + 1;
    }
    return nullptr;  
	}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char s1[256], s2[256];
	gets(s1);
	gets(s2);
	printf("%s\n", strstr(s1, s2));
	return 0;
}
