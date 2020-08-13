#include <stdio.h>
#include <cs50.h>
int main(void)
{
    string name = get_string("Say your name: \n "); //here the computer asks the user for a name.
    printf("hello, %s\n", name); //here I show the message with a given name. 
}
