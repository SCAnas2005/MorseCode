
#include <string.h>

#define LET_NUMBER 26
#define MORSE_NUMBER 26

#define BUZZ_FREQ 1500

#define BIP_TIME 100
#define TIME_BETWEEN_BIP 200
#define TIME_BETWEEN_LETTERS 1000

char led = 7;
char buzz = 8;

// 26 alphabet letters 
char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// morse code (A to Z)
char *morseCode[26] = {"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", 
                       "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", 
                       "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"};

void setup()
{
    // init buzz and led to output mode
    pinMode(led, OUTPUT);
    pinMode(buzz, OUTPUT);
}

int getLetterPos(char letter)
{
    for (int i = 0; i < LET_NUMBER; i++)
    {
        if (letter == letters[i])
            return i;
    }
}

void playBipCode(char *morseCode)
{
    int morseLen = strlen(morseCode);
    for (int i = 0; i < morseLen; i++)
    {
        tone(buzz, BUZZ_FREQ);
        digitalWrite(led, HIGH);
        if (morseCode[i] == '*')
        {
            delay(BIP_TIME);
        }
        else if (morseCode[i] == '-')
        {
            delay(BIP_TIME*3);   
        }
        noTone(buzz);
        digitalWrite(led, LOW);
        delay(TIME_BETWEEN_BIP);
    }

    delay(TIME_BETWEEN_LETTERS);
}

void playMorseCode(char letter)
{
    int letterPos = getLetterPos(letter);
    playBipCode(morseCode[letterPos]);
}

void playFullMorseCode(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
      playMorseCode(string[i]);
    }
}

void loop()
{
    playFullMorseCode("Cristiano Ronaldo siuuuu");
    delay(10000);
}
