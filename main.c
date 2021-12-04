#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOOP  "++++++++++[>+++++++>++++++++++>+++>+<<<<-]"

int cells[5] = {0,70,100,30,10};


int char_to_cell(char c, int current){
    int target;
    int reltarget;

    if(c <'A') target = 3;
    if(c>='a' && c<='z') target = 2;
    if(c>='A' && c<='Z') target = 1;
    if(c == '\n') target = 4;
    reltarget = target - current;
    c = reltarget < 0 ? '<' : '>';
    for(int i = 0; i < abs(reltarget); i++) putchar(c);
    return target;
}

int char_to_nr(char c, int cell_nr){
    int a = c - cells[cell_nr];
    for(int i = 0; i < abs(a); i++) {
        (a<0) ? (putchar('-') && cells[cell_nr]--) : (putchar('+') && cells[cell_nr]++);
    }
    putchar('.');
    return 1;
}

int char_to_bf(char c, int index){
    index = char_to_cell(c, index);
    char_to_nr(c,index);
    return index;
}

int text_to_brainfuck(const char* text, int index){
    for(int i = 0; text[i] != 0; i++){
        index = char_to_bf(text[i], index);
    }
    return index;
}



int main(int argc, char const *argv[])
{
    if(argc >= 2){
        int index = 1;

        printf(LOOP);
        putchar('>');
        for(int i = 1; i < argc; i++){
            index = text_to_brainfuck(argv[i],index);
            index = char_to_bf(' ', index);
        }
        char_to_bf('\n', index);

    }
    return 0;
}
