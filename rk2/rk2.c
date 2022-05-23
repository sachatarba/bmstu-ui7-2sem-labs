// вариант 1
#include <stdio.h>
#include <string.h>

#define max_words 5
#define len_word 5

typedef struct
{
	int N;
	char words[max_words][max_words][len_word];
} dict;


void input_words(dict *words);

void output_words(dict * words);

int count_in_col(dict *words);

int main(void)
{

	dict words;
	input_words(&words);
	output_words(&words);
	printf("%d", count_in_col(&words));
	return 0;
}

void input_words(dict *words)
{
	scanf("%d", &(words->N));
	for (int i = 0; i < words->N; ++i)
		for (int j = 0; j < words->N; ++j)
			scanf("%s", words->words[i][j]);
}

void output_words(dict *words)
{
        for (int i = 0; i < words->N; ++i)
	{
                for (int j = 0; j < words->N; ++j)
                        printf("%s ", words->words[i][j]);
		printf("\n");
	}
}

int count_in_col(dict *words)
{
	int count = 0;
	for (int  i = 0; i < max_words; ++i)
	{
		int flag = 1;
		int len = strlen(words->words[0][i]);
		for (int j = 1; j < max_words; ++j)
			if (len != strlen(words->words[j][i]))
				flag = 0;
		if (flag)
			++count;
	}

	return count;
}
