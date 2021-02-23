#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 5
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 240

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB);
const uint8_t brightness = 100; //0 -- 255 for brightness setting.
const short set_time = 60;    //0 -- 1000 for timing changes.
short pos = 0;                //position in time

//values in R,G,b,ΔT
const uint16_t color_chart[208][4]{
    {0, 1, 1, 2000},
    {0, 5, 7, 2000},
    {0, 8, 10, 2000},
    {0, 11, 14, 2000},
    {0, 14, 18, 2000},
    {0, 17, 23, 2000},
    {0, 21, 27, 2000},
    {0, 24, 31, 2000},
    {0, 27, 36, 2000},
    {0, 29, 38, 2000},
    {0, 32, 41, 2000},
    {0, 36, 46, 2000},
    {0, 40, 50, 2000},
    {0, 48, 60, 2000},
    {3, 62, 75, 2000},
    {4, 67, 82, 2000},
    {7, 75, 92, 2000},
    {8, 79, 97, 2000},
    {9, 80, 98, 2000},
    {10, 84, 102, 2000},
    {11, 85, 104, 2000},
    {12, 88, 107, 2000},
    {13, 90, 110, 2000},
    {255, 255, 255, 2000},
    {17, 96, 115, 2000},
    {255, 255, 255, 2000},
    {23, 105, 125, 2000},
    {255, 255, 255, 2000},
    {27, 111, 132, 2000},
    {30, 115, 137, 2000},
    {33, 11, 139, 2000},
    {38, 122, 144, 2000},
    {40, 125, 146, 2000},
    {44, 131, 152, 2000},
    {49, 136, 158, 2000},
    {51, 139, 161, 2000},
    {53, 140, 165, 2000},
    {60, 146, 168, 2000},
    {63, 149, 171, 2000},
    {67, 152, 174, 2000},
    {71, 156, 178, 2000},
    {73, 158, 179, 2000},
    {76, 161, 182, 2000},
    {79, 164, 185, 2000},
    {82, 167, 188, 2000},
    {87, 170, 193, 2000},
    {90, 172, 192, 2000},
    {96, 176, 196, 2000},
    {101, 179, 199, 2000},
    {109, 186, 205, 2000},
    {113, 189, 208, 2000},
    {117, 192, 219, 2000},
    {124, 197, 215, 2000},
    {132, 200, 218, 2000},
    {139, 205, 222, 2000},
    {143, 207, 223, 2000},
    {146, 209, 225, 2000},
    {153, 213, 228, 2000},
    {159, 218, 232, 2000},
    {166, 220, 233, 2000},
    {169, 222, 235, 2000},
    {173, 223, 236, 2000},
    {177, 225, 238, 2000},
    {182, 228, 239, 2000},
    {189, 231, 242, 2000},
    {195, 233, 243, 2000},
    {198, 235, 245, 2000},
    {201, 236, 245, 2000},
    {204, 236, 245, 2000},
    {207, 237, 245, 2000},
    {209, 238, 245, 2000},
    {212, 238, 245, 2000},
    {217, 239, 245, 2000},
    {220, 240, 245, 2000},
    {222, 240, 245, 2000},
    {223, 240, 245, 2000},
    {234, 242, 250, 2000},
    {238, 242, 252, 2000},
    {240, 244, 253, 2000},
    {245, 246, 255, 2000},
    {249, 251, 255, 2000},
    {250, 253, 255, 2000},
    {255, 255, 255, 2000},
    {255, 255, 255, 2000},
    {255, 251, 233, 2000},
    {255, 244, 206, 2000},
    {255, 241, 195, 2000},
    {255, 241, 191, 2000},
    {255, 236, 171, 2000},
    {255, 231, 151, 2000},
    {255, 228, 137, 2000},
    {255, 224, 118, 2000},
    {255, 220, 102, 2000},
    {255, 215, 80, 2000},
    {255, 209, 54, 2000},
    {255, 204, 34, 2000},
    {255, 201, 18, 2000},
    {255, 199, 10, 2000},
    {255, 198, 6, 2000},
    {255, 189, 6, 2000},
    {255, 181, 6, 2000},
    {255, 176, 6, 2000},
    {255, 173, 6, 2000},
    {255, 170, 6, 2000},
    {255, 167, 6, 2000},
    {255, 165, 6, 2000},
    {255, 163, 6, 2000},
    {255, 170, 6, 2000},
    {255, 161, 6, 2000},
    {245, 157, 5, 2000},
    {243, 155, 5, 2000},
    {240, 154, 5, 2000},
    {237, 152, 5, 2000},
    {233, 150, 5, 2000},
    {230, 148, 5, 2000},
    {228, 146, 5, 2000},
    {229, 147, 5, 2000},
    {229, 117, 5, 2000},
    {229, 114, 5, 2000},
    {229, 110, 5, 2000},
    {229, 110, 5, 2000},
    {229, 110, 5, 2000},
    {229, 110, 5, 2000},
    {229, 110, 5, 2000},
    {229, 106, 5, 2000},
    {229, 101, 5, 2000},
    {229, 95, 5, 2000},
    {229, 89, 5, 2000},
    {224, 87, 5, 2000},
    {220, 84, 4, 2000},
    {217, 83, 4, 2000},
    {213, 80, 4, 2000},
    {209, 79, 3, 2000},
    {202, 76, 3, 2000},
    {196, 74, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {189, 71, 3, 2000},
    {182, 69, 3, 2000},
    {181, 67, 2, 2000},
    {175, 65, 2, 2000},
    {166, 63, 2, 2000},
    {159, 60, 2, 2000},
    {152, 57, 2, 2000},
    {146, 54, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {138, 51, 1, 2000},
    {132, 49, 1, 2000},
    {124, 46, 1, 2000},
    {119, 44, 1, 2000},
    {110, 41, 1, 2000},
    {105, 39, 1, 2000},
    {98, 36, 1, 2000},
    {94, 35, 1, 2000},
    {84, 31, 0, 2000},
    {74, 27, 0, 2000},
    {68, 26, 0, 2000},
    {65, 24, 0, 2000},
    {60, 22, 0, 2000},
    {53, 19, 0, 2000},
    {47, 17, 0, 2000},
    {43, 16, 0, 2000},
    {38, 14, 0, 2000},
    {37, 13, 0, 2000},
    {34, 12, 0, 2000},
    {30, 11, 0, 2000},
    {25, 10, 0, 2000},
    {20, 10, 0, 2000},
    {17, 9, 0, 2000},
    {15, 8, 0, 2000},
    {12, 7, 0, 2000},
    {255, 198, 6, 2000},
    {255, 189, 6, 2000},
    {255, 181, 6, 2000},
    {255, 176, 6, 2000},
    {255, 173, 6, 2000},
    {255, 173, 6, 2000},
    {255, 173, 6, 2000},
    {217, 239, 245, 2000},
    {212, 238, 245, 2000},
    {190, 238, 245, 2000},
    {170, 200, 200, 2000},
    {150, 150, 245, 2000},
    {130, 110, 110, 2000},
    {75, 98, 107, 2000},
    {11, 85, 104, 2000},
    {0, 65, 72, 2000},
    {0, 48, 60, 2000},
    {0, 40, 50, 2000},
    {10, 34, 72, 2000},
    {255, 255, 255, 2000},
    {0, 29, 38, 2000},
    {0, 27, 36, 2000},
    {255, 255, 255, 2000},
    {0, 21, 27, 2000},
    {0, 17, 23, 2000},
    {0, 14, 18, 2000},
    {0, 11, 14, 2000},
    {0, 1, 1, 2000},

};

uint8_t R = 0;
uint8_t G = 0;
uint8_t B = 0;
uint8_t Rnext = 0;
uint8_t Gnext = 0;
uint8_t Bnext = 0;

void setup()
{
  pixels.begin();
  pixels.clear();
  delay(500);
}

void loop(){
  displayNext();
  if (pos == 208){
    pos = 0;}
  else{
    pos++;}
}

void displayNext()
{
  R = color_chart[pos][0];
  G = color_chart[pos][1];
  B = color_chart[pos][2];
  R = map(R, 0, 255, 0, brightness);
  G = map(G, 0, 255, 0, brightness);
  B = map(B, 0, 255, 0, brightness);

  pos++;

  Rnext = color_chart[pos][0];
  Gnext = color_chart[pos][1];
  Bnext = color_chart[pos][2];
  Rnext = map(Rnext, 0, 255, 0, brightness);
  Gnext = map(Gnext, 0, 255, 0, brightness);
  Bnext = map(Bnext, 0, 255, 0, brightness);

  pos--;

  for (int time = 0; time < color_chart[pos][3]; time++){
    for (int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(R, G, B));
    }
    R = map(time, 0, color_chart[pos][3], R, Rnext);
    G = map(time, 0, color_chart[pos][3], G, Gnext);
    B = map(time, 0, color_chart[pos][3], B, Bnext);
    pixels.show();
    delay(set_time);
  }
}
