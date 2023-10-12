#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void){
	char* all_text = malloc(100*sizeof(char));
	int char_counter = 1;
	while(getchar() != '!'){
		//all_text = malloc(char_counter*sizeof(char));
		scanf("%c", &all_text[char_counter-1]);
	//	printf("%d", char_counter);
		char_counter++;
	}	
	printf("%s\n", all_text);

	return 0;
}
