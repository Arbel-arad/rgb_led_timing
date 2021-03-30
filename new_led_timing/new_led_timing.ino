#include <DueTimer.h>
#include <Adafruit_NeoPixel.h>
uint8_t row = 0;
const uint8_t sun = 5, D1 = 1, D2 = 2, D3 = 3, D4 = 4,    D5 = 6, D6 = 7, D7 = 8, D8 = 9, D9 = 10, D10 = 11;   //led pin numbers
struct leds{
  bool D1;     //monochrome leds
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
  {0,0,0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,0,0,1},
  {1,0,1,1,0,0,0,0,1,1},
  {1,1,1,1,1,0,0,0,1,1},
  {1,1,1,1,1,1,1,1,1,1},
  {1,0,1,1,1,1,1,0,1,1},
  {1,0,1,1,1,1,1,0,1,1},
  {0,0,1,0,0,1,0,0,1,1},
  {0,0,1,0,0,1,0,0,1,1},
  {1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,0,0,1},
  {1,1,0,1,1,0,1,0,0,1}
};

Adafruit_NeoPixel pixels(240, sun, NEO_GRB);
const uint8_t color_chart[208][4]{  //values in R,G,b,ΔT
    {0, 1, 1, 20},
    {0, 5, 7, 20},
    {0, 8, 10, 20},
    {0, 11, 14, 20},
    {0, 14, 18, 20},
    {0, 17, 23, 20},
    {0, 21, 27, 20},
    {0, 24, 31, 20},
    {0, 27, 36, 20},
    {0, 29, 38, 20},
    {0, 32, 41, 20},
    {0, 36, 46, 20},
    {0, 40, 50, 20},
    {0, 48, 60, 20},
    {3, 62, 75, 20},
    {4, 67, 82, 20},
    {7, 75, 92, 20},
    {8, 79, 97, 20},
    {9, 80, 98, 20},
    {10, 84, 102, 20},
    {11, 85, 104, 20},
    {12, 88, 107, 20},
    {13, 90, 110, 20},
    {255, 255, 255, 20},
    {17, 96, 115, 20},
    {255, 255, 255, 20},
    {23, 105, 125, 20},
    {255, 255, 255, 20},
    {27, 111, 132, 20},
    {30, 115, 137, 20},
    {33, 11, 139, 20},
    {38, 122, 144, 20},
    {40, 125, 146, 20},
    {44, 131, 152, 20},
    {49, 136, 158, 20},
    {51, 139, 161, 20},
    {53, 140, 165, 20},
    {60, 146, 168, 20},
    {63, 149, 171, 20},
    {67, 152, 174, 20},
    {71, 156, 178, 20},
    {73, 158, 179, 20},
    {76, 161, 182, 20},
    {79, 164, 185, 20},
    {82, 167, 188, 20},
    {87, 170, 193, 20},
    {90, 172, 192, 20},
    {96, 176, 196, 20},
    {101, 179, 199, 20},
    {109, 186, 205, 20},
    {113, 189, 208, 20},
    {117, 192, 219, 20},
    {124, 197, 215, 20},
    {132, 200, 218, 20},
    {139, 205, 222, 20},
    {143, 207, 223, 20},
    {146, 209, 225, 20},
    {153, 213, 228, 20},
    {159, 218, 232, 20},
    {166, 220, 233, 20},
    {169, 222, 235, 20},
    {173, 223, 236, 20},
    {177, 225, 238, 20},
    {182, 228, 239, 20},
    {189, 231, 242, 20},
    {195, 233, 243, 20},
    {198, 235, 245, 20},
    {201, 236, 245, 20},
    {204, 236, 245, 20},
    {207, 237, 245, 20},
    {209, 238, 245, 20},
    {212, 238, 245, 20},
    {217, 239, 245, 20},
    {220, 240, 245, 20},
    {222, 240, 245, 20},
    {223, 240, 245, 20},
    {234, 242, 250, 20},
    {238, 242, 252, 20},
    {240, 244, 253, 20},
    {245, 246, 255, 20},
    {249, 251, 255, 20},
    {250, 253, 255, 20},
    {255, 255, 255, 20},
    {255, 255, 255, 20},
    {255, 251, 233, 20},
    {255, 244, 206, 20},
    {255, 241, 195, 20},
    {255, 241, 191, 20},
    {255, 236, 171, 20},
    {255, 231, 151, 20},
    {255, 228, 137, 20},
    {255, 224, 118, 20},
    {255, 220, 102, 20},
    {255, 215, 80, 20},
    {255, 209, 54, 20},
    {255, 204, 34, 20},
    {255, 201, 18, 20},
    {255, 199, 10, 20},
    {255, 198, 6, 20},
    {255, 189, 6, 20},
    {255, 181, 6, 20},
    {255, 176, 6, 20},
    {255, 173, 6, 20},
    {255, 170, 6, 20},
    {255, 167, 6, 20},
    {255, 165, 6, 20},
    {255, 163, 6, 20},
    {255, 170, 6, 20},
    {255, 161, 6, 20},
    {245, 157, 5, 20},
    {243, 155, 5, 20},
    {240, 154, 5, 20},
    {237, 152, 5, 20},
    {233, 150, 5, 20},
    {230, 148, 5, 20},
    {228, 146, 5, 20},
    {229, 147, 5, 20},
    {229, 117, 5, 20},
    {229, 114, 5, 20},
    {229, 110, 5, 20},
    {229, 110, 5, 20},
    {229, 110, 5, 20},
    {229, 110, 5, 20},
    {229, 110, 5, 20},
    {229, 106, 5, 20},
    {229, 101, 5, 20},
    {229, 95, 5, 20},
    {229, 89, 5, 20},
    {224, 87, 5, 20},
    {220, 84, 4, 20},
    {217, 83, 4, 20},
    {213, 80, 4, 20},
    {209, 79, 3, 20},
    {202, 76, 3, 20},
    {196, 74, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {189, 71, 3, 20},
    {182, 69, 3, 20},
    {181, 67, 2, 20},
    {175, 65, 2, 20},
    {166, 63, 2, 20},
    {159, 60, 2, 20},
    {152, 57, 2, 20},
    {146, 54, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {138, 51, 1, 20},
    {132, 49, 1, 20},
    {124, 46, 1, 20},
    {119, 44, 1, 20},
    {110, 41, 1, 20},
    {105, 39, 1, 20},
    {98, 36, 1, 20},
    {94, 35, 1, 20},
    {84, 31, 0, 20},
    {74, 27, 0, 20},
    {68, 26, 0, 20},
    {65, 24, 0, 20},
    {60, 22, 0, 20},
    {53, 19, 0, 20},
    {47, 17, 0, 20},
    {43, 16, 0, 20},
    {38, 14, 0, 20},
    {37, 13, 0, 20},
    {34, 12, 0, 20},
    {30, 11, 0, 20},
    {25, 10, 0, 20},
    {20, 10, 0, 20},
    {17, 9, 0, 20},
    {15, 8, 0, 20},
    {12, 7, 0, 20},
    {255, 198, 6, 20},
    {255, 189, 6, 20},
    {255, 181, 6, 20},
    {255, 176, 6, 20},
    {255, 173, 6, 20},
    {255, 173, 6, 20},
    {255, 173, 6, 20},
    {217, 239, 245, 20},
    {212, 238, 245, 20},
    {190, 238, 245, 20},
    {170, 200, 200, 20},
    {150, 150, 245, 20},
    {130, 110, 110, 20},
    {75, 98, 107, 20},
    {11, 85, 104, 20},
    {0, 65, 72, 20},
    {0, 48, 60, 20},
    {0, 40, 50, 20},
    {10, 34, 72, 20},
    {255, 255, 255, 20},
    {0, 29, 38, 20},
    {0, 27, 36, 20},
    {255, 255, 255, 20},
    {0, 21, 27, 20},
    {0, 17, 23, 20},
    {0, 14, 18, 20},
    {0, 11, 14, 20},
    {0, 1, 1, 20},

};

const uint8_t brightness = 255; //0 - 255
uint8_t pos = 0;
uint8_t ontime = 0;
uint8_t R = 0;
uint8_t G = 0;
uint8_t B = 0;

void displayNext(){
  R = map(ontime, 0, color_chart[pos][3], color_chart[pos][0], color_chart[pos+1][0]);
  G = map(ontime, 0, color_chart[pos][3], color_chart[pos][1], color_chart[pos+1][1]);
  B = map(ontime, 0, color_chart[pos][3], color_chart[pos][2], color_chart[pos+1][2]);
  for (int i = 0; i < 240; i++){
    pixels.setPixelColor(i, pixels.Color(R, G, B));}
    pixels.show();
  if(ontime < color_chart[pos][3]){ontime++;}
  else{ontime=0;  pos++;    if (pos == 208){pos=0;}}
}

void next_row(){
  row++;
  if(row >=13){row = 0;}
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

  pixels.begin();
  pixels.clear();
	Timer0.attachInterrupt(next_row);
	Timer0.start(138461538);   //30S timer interrupt
 
  Timer1.attachInterrupt(displayNext);
  Timer1.start(432692);   //new time for ~30mins run time "432692" -----0.5S timer interrupt (500000)-----
}
void loop(){
while(true){}
}
