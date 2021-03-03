#include <DueTimer.h>

uint8_t row = 0;
const uint8_t sun = 5, D1 = 1, D2 = 2, D3 = 3, D4 = 4, D5 = 6, D6 = 7, D7 = 8, D8 = 9, D9 = 10, D10 = 11;   //led pin numbers
struct leds{
  uint8_t color_temp;   //x10 for real temp
  bool D1;              //other monochrome leds
  bool D2;
  bool D3;
  bool D4;
  bool D5;
  bool D6;
  bool D7;
  bool D8;
  bool D9;
  bool D10;
};
struct leds data_list[13] = {
  {100,0,0,0,0,0,0,0,0,0,0},
  {100,0,0,0,0,0,0,0,0,0,0},
  {100,1,0,1,1,0,0,0,0,1,0},
  {100,1,1,1,1,1,0,0,0,1,0},
  {100,1,1,1,1,1,1,1,1,1,0},
  {100,1,0,1,1,1,1,1,0,1,0},
  {100,1,0,1,1,1,1,1,0,1,0},
  {100,0,0,1,0,0,1,0,0,1,0},
  {100,0,0,1,0,0,1,0,0,1,0},
  {100,1,1,1,1,1,1,1,1,1,0},
  {100,1,1,1,1,1,1,1,1,1,0},
  {100,1,1,0,1,1,0,1,0,0,0},
  {100,1,1,0,1,1,0,1,0,0,0}
};

void next_row(){
  row++;
  if(row >=13){
    row = 0;
  }

  
	digitalWrite(D1, data_list[row].D1);
  digitalWrite(D2, data_list[row].D2);
  digitalWrite(D3, data_list[row].D3);
  digitalWrite(D4, data_list[row].D4);
  digitalWrite(D5, data_list[row].D5);
  digitalWrite(D6, data_list[row].D6);
  digitalWrite(D7, data_list[row].D7);
  digitalWrite(D8, data_list[row].D8);
  digitalWrite(D9, data_list[row].D9);
  digitalWrite(D10, data_list[row].D10);
}

void setup(){
  pinMode(sun, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);

	Timer0.attachInterrupt(next_row);
	//Timer0.start(30000000);   //30S timer interrupt
 Timer0.start(100000);   //3S timer interrupt
}

void loop(){
  while(1){
	}
}
