#include <stdio.h>
#include <string.h>

int colemanLiau(int letters, int words, int sentences);

int main(void)
{
	char text[10000];
	printf("Enter a text: ");
	scanf("%[^\n]", text);

	int totalLetters = 0;
	int totalSentences = 0;
	int totalWords = 1;

	const int textSize = strlen(text);

	for (int i = 0; i < textSize; i++)
	{

		char letter = text[i];

		if (letter != ' ')
		{

			int nLetter = (int)letter;

			if (
				!((nLetter >= 34 && nLetter <= 45) && (nLetter >= 123 && nLetter <= 127) && (nLetter >= 91 && nLetter <= 96) && (nLetter >= 47 && nLetter <= 62) && (letter != '@')))
			{
				if (letter == '!' || letter == '.' || letter == '?')
				{
					totalSentences++;
				}
				else
				{
					totalLetters++;
				}
			}
		}
		else
		{
			totalWords++;
		}
	}

	printf("\nTotal letters: %i\n", totalLetters);
	printf("Total words: %i\n", totalWords);
	printf("Total sentences %i\n: ", totalSentences);

	const int CLI = colemanLiau(totalLetters, totalWords, totalSentences);

	if (CLI < 16)
	{
		printf("Coleman Liau Index: %i", CLI);
	}
	else
	{
		printf("Coleman Liau Index: +16");
	}

	return 0;
}

int colemanLiau(int letters, int words, int sentences)
{
	int index;

	float L = ((float)letters / words) * 100;
	float S = ((float)sentences / words) * 100;

	index = (int)(0.0588 * L - 0.296 * S - 15.8);

	return index;
}