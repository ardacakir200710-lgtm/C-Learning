/*

Name           : Arda Muhammed
Surname        : Cakir
Student Number : 2500005468

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCE_COUNT 100
#define MAX_SENTENCE_LEN 1000
#define MAX_PARAGRAPH_LEN 1000

#define VOWEL_COUNT 5

#define NOT_VOWEL -1
#define A 0
#define E 1
#define I 2
#define O 3 
#define U 4

#define TAB "\t\t"

// function prototypes

// splits given paragraph into sentences.
void split_paragraph(int *total_sentence_count,char paragraph[], char sentences[][MAX_SENTENCE_LEN]);
// checks if the given char is a vowel letter or not.
int is_vowel(char ch);
// counts vowels in given sentence.
void count_sentence_vowels(int *max_vowel_count, int *max_vowel_sentence_no,int sentence_no ,char sentences[][MAX_SENTENCE_LEN], int sentence_vowel_counts[VOWEL_COUNT]);
// counts total vowel count in given paragraph.
void count_total_vowels(int *max_vowel_count, int *max_vowel_sentence_no, int *total_sentence_count,char sentences[][MAX_SENTENCE_LEN],int total_vowel_counts[VOWEL_COUNT]);


int main(void)
{
    int i = 0;
    int total_sentence_count = 0;

    int max_vowel_count = 0;
    int max_vowel_sentence_no = 0;

    /* INDEXES | 0: a, 1: e, 2: i, 3: o, 4: u */

    // initilazing arrays.
    int sentence_vowel_counts[VOWEL_COUNT] = { 0 }; 
    int total_vowel_counts[VOWEL_COUNT] = { 0 };

    char paragraph[MAX_PARAGRAPH_LEN] = { 0 };
    char sentences[MAX_SENTENCE_COUNT][MAX_SENTENCE_LEN] = { 0 };

    char ch;

    printf("Enter the paragraph:\n");

    // reading and saving into paragraph array., MAX_PARAGRAPH - 1 because we will add \0.
    while((ch = getchar()) != '\n' && i < MAX_PARAGRAPH_LEN -1){
        paragraph[i++] = ch;
    }

    // we are holding a string. adding null terminator manually.
    paragraph[i] = '\0';

    split_paragraph(&total_sentence_count, paragraph, sentences);
    
    // printing each sentence here
    for (int i = 0; i < total_sentence_count; i++)
    {
        // resetting sentence vowel counts to start new sentence.
        for (int j = 0; j < VOWEL_COUNT; j++) {sentence_vowel_counts[j] = 0;}
        
        // counting vowels for i. sentence
        count_sentence_vowels(&max_vowel_count, &max_vowel_sentence_no, i, sentences, sentence_vowel_counts);
        printf(TAB "Sentence %d vowel count list:\n",i + 1);

        printf(TAB "a: %d\n" TAB "e: %d\n" TAB "i: %d\n" TAB "o: %d\n" TAB "u: %d\n\n",
            sentence_vowel_counts[A],
            sentence_vowel_counts[E],
            sentence_vowel_counts[I],
            sentence_vowel_counts[O],
            sentence_vowel_counts[U]);
    }

    // printing total here + drawing the result table
    count_total_vowels(&max_vowel_count, &max_vowel_sentence_no, &total_sentence_count, sentences, total_vowel_counts);
    
    printf("*************Vowel Count in Paragraph*************\n");
    
    // printing max here

    printf(" ____________________________________\n");

    printf("|    a|     e|      i|      o|      u|\n");

    printf("|____________________________________|\n");

    printf("|%5d|%6d|%7d|%7d|%7d|\n",
        total_vowel_counts[A],
        total_vowel_counts[E],
        total_vowel_counts[I],
        total_vowel_counts[O],
        total_vowel_counts[U]);

    printf("|____________________________________|\n\n");

    // printing the max values

    printf("Sentence %d with the most vowels, has %d vowels.\n", max_vowel_sentence_no + 1, max_vowel_count);

    return 0;
}

void split_paragraph(int *total_sentence_count,char paragraph[], char sentences[][MAX_SENTENCE_LEN])
{
    // holds the point where to start strcat proccess.
    int sentence_start_point = 0;

    for (int i = 0; i < strlen(paragraph); i++)
    {
        // check if end of the sentence
        if(paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?'){
            // i - sentence_start_point + 1 ensures taking thje punctiation (. ! and ?)
            int current_sentence_len = i - sentence_start_point + 1;
            
            // copying the selected sentence into "sentences" array using strncpy.
            strncpy(sentences[*total_sentence_count], &paragraph[sentence_start_point], current_sentence_len);
            // adding null terminator manually.
            sentences[*total_sentence_count][current_sentence_len] = '\0';
            (*total_sentence_count)++;

            // shifting the sentence start position forward. (+1 is for passing the punctiaton, going to the new sentence.)
            sentence_start_point = i + 1;
        }

    }
}

int is_vowel(char ch)
{
    // returning indexes of vowels.
    switch (tolower(ch))
    {
    case 'a': return A;
    case 'e': return E;
    case 'i': return I;
    case 'o': return O;
    case 'u': return U;

    default: break;
    }

    return NOT_VOWEL;
}

void count_sentence_vowels(int *max_vowel_count, int *max_vowel_sentence_no, int sentence_no ,char sentences[][MAX_SENTENCE_LEN], int sentence_vowel_counts[VOWEL_COUNT])
{
    int check; // variable for holding is_vowel's return valure (returns index)
    int vowel_counter = 0; // vaeriable for countig total vowels in a sentence. (used for checking max)
    for (int i = 0; sentences[sentence_no][i] != '\0'; i++)
    {
        check = is_vowel(sentences[sentence_no][i]);
        if ( check != NOT_VOWEL ){
            sentence_vowel_counts[check]++;
            vowel_counter++;
        }

    }

    // checking if we have a new max value.

    if (vowel_counter > *max_vowel_count){
        *max_vowel_count = vowel_counter;
        *max_vowel_sentence_no = sentence_no;
    }
}

void count_total_vowels(int *max_vowel_count, int *max_vowel_sentence_no,int *total_sentence_count,char sentences[][MAX_SENTENCE_LEN],int total_vowel_counts[VOWEL_COUNT])
{
    // using cont_sentence_vowels function for each sentence using for loop. total_vowel_counts array is given to hold total amounts of vowels each.
    for (int i = 0; i < *total_sentence_count; i++)
    {
        count_sentence_vowels(max_vowel_count, max_vowel_sentence_no ,i, sentences, total_vowel_counts);
    }  
}