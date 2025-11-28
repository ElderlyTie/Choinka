#include <Arduino.h>
//r1 g1 b1 r2 g2 b2
int piny[15] = {1,22,23,19,21,3,17,5,18,26,27,14,32,33,25};

int program[5][15] ={
    {143,0,255, 173,255,2, 255,0,109, 255,221,0, 1,190,254},
    {173,255,2, 255,0,109, 255,221,0, 1,190,254, 143,0,255},
    {255,0,109, 255,221,0, 1,190,254, 143,0,255, 173,255,2},
    {255,221,0, 1,190,254, 143,0,255, 173,255,2, 255,0,109},
    {1,190,254, 143,0,255, 173,255,2, 255,0,109, 255,221,0},
};

int kolory(int numer, int kolor){
    if(numer%3==0)
        return floor(kolor*120/255);
    if(numer%3==1)
        return floor(kolor*140/255);
    if(numer%3==2)
        return kolor;
}

int przerwa = 1;

void setup() {
    for(int i = 0; i<15; i++){
        pinMode(piny[i], OUTPUT);
        ledcSetup(i, 5000, 8);
        ledcAttachPin(piny[i], i);
    }
}
void loop() {
    for(int j = 0; j<5; j++){
        for(int i = 0; i<15; i++){
            ledcWrite(i, kolory(i, program[j][i]));
        }
        sleep(przerwa);
    }
}
