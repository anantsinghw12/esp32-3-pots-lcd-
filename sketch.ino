     #include <Wire.h>
     #include <LiquidCrystal_I2C.h>
     #include <Adafruit_GFX.h>
     #include <Adafruit_SSD1306.h>

     // --- Pin Definitions ---
     const int potPinA = 34; // Potentiometer 1 (A)
     const int potPinB = 35; // Potentiometer 2 (B)
     const int potPinC = 32; // Potentiometer 3 (C)

     // --- Displays Setup ---
     // 1. LCD Setup (Address: 0x27, 16 columns, 2 rows)
     LiquidCrystal_I2C lcd(0x27, 16, 2);

     // 2. OLED Setup (Width: 128, Height: 64, I2C Address: 0x3C)
     #define SCREEN_WIDTH 128
     #define SCREEN_HEIGHT 64
     #define OLED_RESET    -1
     Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

     void setup() {
       // Serial Monitor start karein
         Serial.begin(115200);

           // I2C Communication initialize karein (ESP32 Default: SDA = GPIO 21, SCL = GPIO 22)
             Wire.begin(21, 22);

               // LCD Initialize karein
                 lcd.init();                      
                   lcd.backlight();
                     lcd.setCursor(0, 0);
                       lcd.print("System Starting...");

                         // OLED Initialize karein (Address 0x3C)
                           if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
                               Serial.println(F("OLED allocation failed!"));
                                   for(;;); // Agar OLED connect na ho toh yahin ruk jaye
                                     }

                                         display.clearDisplay();
                                           display.setTextSize(1);
                                             display.setTextColor(SSD1306_WHITE);
                                               display.setCursor(0,0);
                                                 display.println("OLED Connected!");
                                                   display.display();
                                                     delay(1000);
                                                     }

                                                     void loop() {
                                                       // 1. Teeno potentiometers ki values read karein (0 to 4095)
                                                         int valA = analogRead(potPinA);
                                                           int valB = analogRead(potPinB);
                                                             int valC = analogRead(potPinC);

                                                               // Optional: Values ko map kar sakte hain agar 0-100 ya voltage me dekhna ho
                                                                 int mappedA = map(valA, 0, 4095, 0, 230);
                                                                   int mappedB = map(valB, 0, 4095, 0, 100);

                                                                     // 2. Serial Monitor par print karein
                                                                       Serial.print("Pot A: "); Serial.print(valA);
                                                                         Serial.print(" | Pot B: "); Serial.print(valB);
                                                                           Serial.print(" | Pot C: "); Serial.println(valC);

                                                                             // 3. LCD par data show karein
                                                                               lcd.clear();
                                                                                 lcd.setCursor(0, 0);
                                                                                   lcd.print("A:"); lcd.print(valA);
                                                                                     lcd.print(" B:"); lcd.print(valB);

                                                                                         lcd.setCursor(0, 1);
                                                                                           lcd.print("C:"); lcd.print(valC);
                                                                                             lcd.print(" Good");

                                                                                               // 4. OLED Display par data show karein
                                                                                                 display.clearDisplay();
                                                                                                   display.setCursor(0, 0);
                                                                                                     display.setTextSize(1);
                                                                                                       display.println("--- SENSOR DATA ---");

                                                                                                           display.setCursor(0, 20);
                                                                                                             display.print("Pot A Val: "); display.println(valA);

                                                                                                                 display.setCursor(0, 35);
                                                                                                                   display.print("Pot B Val: "); display.println(valB);

                                                                                                                       display.setCursor(0, 50);
                                                                                                                         display.print("Pot C Val: "); display.println(valC);

                                                                                                                             display.display(); // Buffer ko screen par bhejta hai

                                                                                                                               delay(500); // Thoda gap taaki display flicker na kare
                                                                                                                               }
                                                                                                                                  