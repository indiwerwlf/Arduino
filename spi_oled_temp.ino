//This code belongs to Andrew Stott and is based on code
//provided by Adafruit Industries under an open source license.
//Likewise this code is open sorce and can be used and modified.
//I simply ask that you let me know so that we can learn together.

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define XPOS 0
#define YPOS 1
#define DELTAY 2

void setup()   {                
  Serial.begin(9600);
  
  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
}
void loop() {
  // write temperature
  temperatureDisplay();
  delay(2000);
  display.clearDisplay();  
  display.display();
  
  //serial
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);
}
void temperatureDisplay(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.println("Temp");
  display.println(mlx.readObjectTempF()); display.print((char)247); display.println("F");
  display.display();
}
