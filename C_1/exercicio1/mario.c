#include <cs50.h>
#include <stdio.h>
// Mario World 1-1

int main(void)
{
int h;
do

{
    //prompt for Input
    h = get_int("height");

}
    //looping
    while (h < 1 || h > 8);

    //pyramid
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            //space
            if (i+j < h - 1)
            {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
    printf("\n");
    }
}
