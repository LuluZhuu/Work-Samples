#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

void processLongWords(const char* inputFile, char words[MAX_WORDS][MAX_WORD_LENGTH], int* count)
{
    FILE *input = fopen(inputFile,"r");
    if (!input){
        printf("Failed to open the file. ");
        return;
    }

    char word[MAX_WORD_LENGTH];
    *count = 0;
    // while(*count < MAX_WORDS && !feof(input)){
    //     if(fscanf(input, "%99s", word > 0 && strlen(word) > 5)){
    //         strcpy(words[*count], word);
    //         (*count)++;
    //     }
    // }
    while(*count < MAX_WORDS && !feof(input)){
        if(fscanf(input, "%99s", word) == 1 && strlen(word) > 5){
            strcpy(words[*count], word);
            (*count)++;
        }
    }
    fclose(input);
}

int main(){
    char longWords[MAX_WORDS][MAX_WORD_LENGTH];
    int count, i;

    processLongWords("input_words.txt", longWords, &count);
    printf("Words longer than 5 characters:\n");
    for(i = 0; i < count; i++){
        printf("%s\n", longWords[i]);
    }
    printf("Number of words longer than 5 characters: %d\n", count);

    FILE *output = fopen("word_addresses.txt", "w");
    if(!output){
        printf("Failed to open file for writing.\n");
        return 1;
    }

    for(i = 0; i < count; i++)
    {
        fprintf(output, "0x%p\n", (void*)&longWords[i]);
    }

    fclose(output);

    return 0;

}

