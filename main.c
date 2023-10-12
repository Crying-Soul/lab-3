#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** split_text(char* text, int* num_sentences, const char* spliters);

int main(void){
	char ch;
	int capacity = 1, size = 0;
	const char* spliters = ".;?";
	const char* end_symbol = "\n";
	char* text = malloc(capacity*sizeof(char));
	
	while((ch = getchar()) != *end_symbol){
		if (size >= capacity){
		       	capacity *= 2;
			text = (char *)realloc(text, capacity*sizeof(char));
		}
		text[size++] = ch;	
			
	}

    //char **splitted_text = malloc(sizeof(char*));
     int num_sentences;
     char** splitted_text = split_text(text, &num_sentences, spliters);

    // Печать результатов
    for (int i = 0; i < num_sentences; i++) {
        printf("Предложение %d: %s\n", i + 1, splitted_text[i]);
        free(splitted_text[i]);
    }

    free(splitted_text);
    free(text);
    return 0;
}

char** split_text(char* text, int* num_sentences, const char* spliters) {
	int count_sentences = 0;
   	int end_index = 0;
   	char** splitted_text = malloc(sizeof(char*));

   	 for (int i = 0; i < strlen(text); i++) {
        	if (strchr(spliters, text[i]) != NULL) {
            	count_sentences++;
            	printf("%d", count_sentences);

            	splitted_text = realloc(splitted_text, count_sentences * sizeof(char*));
            	splitted_text[count_sentences - 1] = malloc((end_index + 1) * sizeof(char));

            	int chr_counter = 0;
            	for (int j = end_index; j >= 0; j--) {
                	splitted_text[count_sentences - 1][chr_counter++] = text[i - j];
            }
           	   splitted_text[count_sentences - 1][chr_counter] = '\0';
 	           end_index = 0;
            	continue;
        }
        	end_index++;
	 }
	 *num_sentences = count_sentences;
	return splitted_text;

}
