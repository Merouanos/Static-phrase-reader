#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char phrase[51], t[51][24], word[49];
    int lloc,imin, j, c, l, i = 1, lmax = 0, imax=0;
    bool veri;

    do
    {
        veri = true;
        printf("Please give me a phrase : \n");
        gets(phrase);
        l = strlen(phrase);
        if (phrase[0] == ' ' || phrase[l - 1] == ' ')
            veri = false;
        while (i < l - 1 && veri)
            if ((phrase[i] < 'A' || (phrase[i] > 'Z' && phrase[i] < 'a') || phrase[i] > 'z') && phrase[i] != ' ')  //Checks if it is a phrase that doesn't begin or end with aspace
                veri = false;
            else
                i++;
    } while (!veri);




    j = 0;
    while (phrase[j] != ' ' && j < l)
    {
        t[0][j] = phrase[j];                                        //Saving the first word
        j++;
    }
    t[0][j] = '\0';
    lmax = strlen(t[0]);                                     //Saving the length of the first word
    i = 0;
    while (j < l)
    {
        while (phrase[j] == ' ')
            j++;                                                    //Moving to a blank
        c = 0;
        while (j < l && phrase[j] != ' ')
        {
            word[c] = phrase[j];                                    //Getting the word
            c++;
            j++;
        }
        word[c] = '\0';
        c = 0;
        veri = true;
        while (c <= i && veri)
            if (strcmp(word, t[c]) != 0)
                c++;                                            //Checking if repeated 
            else
                veri = false;       
        if (veri)
        {
            i++; 
            strcpy(t[i], word);                    //Saving the word if not repeated
            lloc = strlen(t[i]);
            if (lloc > lmax)
            {
                lmax = lloc;                    //Getting it's length if not repeated
                imax=i;
            }
        }
    }
    printf("There is a total of %d non repeated words that are :\n", i + 1);
    for (c = 0; c <= i; c++)
        puts(t[c]);                                                    //Showing all non repeated words
    for (c = 0; c < i; c++)
    {
        imin = c;
        for (j = c + 1; j <= i; j++)
            if (strcmp(t[imin], t[j]) > 0)
                imin = j;
        if (imin != c)
        {
            
            strcpy(word, t[imin]);
            strcpy(t[imin], t[c]);
            strcpy(t[c], word);                                         //Sorting the words
            if(imin==imax)imax=c;
            else if(c==imax)imax=imin;
        }
    }

    printf("They can be sorted into the following order :\n");
    for (c = 0; c <= i; c++)
        puts(t[c]);                                                          //Showing the sorted words
    printf("The longest of which has %d words and its : ", lmax-1);
    puts(t[imax]);                                                             //Showing the longest word and it's length
}
