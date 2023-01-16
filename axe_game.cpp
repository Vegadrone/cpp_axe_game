#include "raylib.h"

int h = 750;


int main(){
    
    int w; 
    w = 900;

    bool equal {4 == 9}; //false
    bool notEqual{4 != 9}; //true
    bool less{4 < 9}; //true
    bool great{4 > 9};//false
    bool lessEqual{4 <= 9};//true
    bool greatEqual{4 >= 9};//false

    InitWindow(h, w, "POPUP");
}