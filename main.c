#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void){
	char ch;
	int capacity = 1;
	int size = 0;
	char* text = malloc(capacity*sizeof(char));
	
	while((ch = getchar()) != '\n'){
		if (size >= capacity){
		       	capacity *= 2;
			text = (char *)realloc(text, capacity*sizeof(char));
			}
		text[size++] = ch; 
			
			
	}	
	printf("%s\n", text);
	free(text);
	return 0;
}
