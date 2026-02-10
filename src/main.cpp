#include <Arduino.h>
//r1 g1 b1 r2 g2 b2
int piny[15] = {26,27,14,32,33,25,1,22,23,19,21,3,17,5,18};

const int b1 = 34; // program 
const int b2 = 35;// przerwa

// int program[5][15] ={
//     {143,0,255, 173,255,2, 255,0,109, 255,221,0, 1,190,254},
//     {173,255,2, 255,0,109, 255,221,0, 1,190,254, 143,0,255},
//     {255,0,109, 255,221,0, 1,190,254, 143,0,255, 173,255,2},
//     {255,221,0, 1,190,254, 143,0,255, 173,255,2, 255,0,109},
//     {1,190,254, 143,0,255, 173,255,2, 255,0,109, 255,221,0},
// };
int program1[5][15] ={
{255,255,0, 255,0,0, 255,0,255, 0,0,255, 0,255,0},
{255,0,0, 255,0,255, 0,0,255, 0,255,0, 255,255,0},
{255,0,255, 0,0,255, 0,255,0, 255,255,0, 255,0,0},
{0,0,255, 0,255,0, 255,255,0, 255,0,0, 255,0,255},
{0,255,0, 255,255,0, 255,0,0, 255,0,255, 0,0,255},
};

int program2[3][15] ={
{255,0,0, 0,0,0, 0,0,0, 255,0,0, 0,0,0},
{0,0,0, 0,255,0, 0,0,0, 0,0,0, 0,255,0},
{0,0,0, 0,0,0, 0,0,255, 0,0,0, 0,0,0},
};

int program3[5][15] ={
{255,0,0, 0,255,0, 0,0,255, 0,0,0, 0,0,0},
{0,0,0, 255,0,0, 0,255,0, 0,0,255, 0,0,0},
{0,0,0,0,0,0, 255,0,0, 0,255,0, 0,0,255},
{0,0,255,0,0,0,0,0,0, 255,0,0, 0,255,0},
{0,255,0, 0,0,255,0,0,0,0,0,0,255,0,0}
};


int bialy[15] = {
    110,150,255,
    140,60,255,
    110,150,255,
    140,70,255,
    110,150,255
};


int kolory(int numer, int kolor){
    return floor(kolor*bialy[numer]/255);
    if(numer%3==0)
        return floor(kolor*120/255);
    if(numer%3==1)
        return floor(kolor*140/255);
    if(numer%3==2)
        return kolor;
}




void setup() {
    for(int i = 0; i<15; i++){
        pinMode(piny[i], OUTPUT);
        ledcAttachPin(piny[i], i);
        ledcSetup(i, 5000, 8);
    }
    pinMode(b1, INPUT);
    pinMode(b2, INPUT);
}

bool ost_stan_b1 = 0;
bool ost_stan_b2 = 0;


int prze[5] = {100,175,250,500,1000};
short prz_i = 0;
int k = 0;
short prog = 0;
void loop() {

    if(digitalRead(b1) == HIGH and ost_stan_b1 == 0){
        prog++;
        prog%=4;
    }
    if(digitalRead(b2) == HIGH and ost_stan_b2 == 0){
        prz_i++;
        prz_i%=5;
    }
    ost_stan_b1 = digitalRead(b1);
    ost_stan_b2 = digitalRead(b2);

    for(int i = 0; i<15; i++){
        if(prog==0){
            ledcWrite(i, kolory(i,program1[k%5][i]));
        }if(prog==1){
            ledcWrite(i, kolory(i,program2[k%3][i]));            
        }if(prog==2){
            ledcWrite(i, kolory(i,program3[k%5][i]));
        }if(prog==3){
            ledcWrite(i, rand()%255);
        }
    }
    delay(prze[prz_i]);
    k++;
    
}
