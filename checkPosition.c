#include<stdio.h>
#include "header.h"

void position(int height, int width, char *border[], int food[], char input, int head[], int tail[]){
    if(border[head[0]][head[1]] == '>' && input != '>'){
        if(input == '<'){
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if(border[head[0]][head[1]] == input){
            move(height, width, border, food, '<', head, tail);
        }
        else{
            border[head[0]][head[1]] = input;
        }
        
    }
    else if(border[head[0]][head[1]] == '^' && input != '^'){
        if(input == 'v'){
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if(border[head[0]][head[1]] == input){
            move(height, width, border, food, '<', head, tail);
        }
        else{
            border[head[0]][head[1]] = input;
        }
    }
    else if(border[head[0]][head[1]] == '<' && input != '<'){
        if(input == '>'){
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if(border[head[0]][head[1]] == input){
            move(height, width, border, food, '<', head, tail);
        }
        else{
            border[head[0]][head[1]] = input;
        }
    }
    else if(border[head[0]][head[1]] == 'v' && input != 'v'){
        if(input == '^'){
            printf("CAN NOT MOVE BACKWORD.....\n");
        }
        else if(border[head[0]][head[1]] == input){
            move(height, width, border, food, '<', head, tail);
        }
        else{
            border[head[0]][head[1]] = input;
        }
    }
    else{

    }
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
            
    //     }
    //}
}