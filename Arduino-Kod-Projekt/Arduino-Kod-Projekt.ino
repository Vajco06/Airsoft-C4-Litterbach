// POUŽITÉ KNIHOVNY

#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // Nainstalované knihovny pro LCD displej, keypad a komunikaci po I2C sběrnici
LiquidCrystal_I2C lcd(0x3F,16,2);  // Inicializace LCD displeje s adresou 0x3f a rozměry 16x2 (dva řádky po šestnácti znacích)

int Hours = 00;
int Minutes = 00;
int Seconds = 00;
int trycount = 0;
int keycount = 0;
int i = 0; // Označení hodin, minut, vteřin,...


int redled = A2;     // Pin pro červenou LED
int yellowled = A1;  // Pin pro žlutou LED
int greenled = A3;   // Pin pro zelenou LED

int hourstenscode;
int hoursonescode;
int mintenscode;
int minonescode;
int sectenscode;
int seconescode;

long secMillis = 0;  // Proměnná pro sledování času
long interval = 1000;  // Interval pro časovač

char password[4];
char entered[4]; // Počet polí pro zadané a uložené heslo

// KONFIGURACE KLÁVESNICE

const byte ROWS = 4; // Počet řádků klávesnice 
const byte COLS = 3; // Počet sloupců klávesnice
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {7, 2, 3, 5};  // Piny pro řádky pro 4x3 Keypad
byte colPins[COLS] = {6, 8, 4;      // Piny pro sloupce pro 4x3 Keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(redled, OUTPUT);          // Nastaví pin redled jako výstup
  pinMode(yellowled, OUTPUT);       // Nastaví pin yellowled jako výstup
  pinMode(greenled, OUTPUT);        // Nastaví pin greenled jako výstup
  digitalWrite(redled, HIGH);       // Zapne červenou LED
  digitalWrite(yellowled, HIGH);    // Zapne žlutou LED
  digitalWrite(greenled, HIGH);     // Zapne zelenou LED

  lcd.init();                       // náhrada za lcs.begin();
  lcd.backlight();                  // Zapne podsvícení LCD displeje
  Serial.begin(9600);               // Nastaví sériovou komunikaci na 9600 baudů

  lcd.clear();                      // Vyčistí LCD displej
  lcd.setCursor(0, 0);              // Nastaví kurzor na začátek prvního řádku
  lcd.print("Bomb activated!");     // Vypíše na první řádek 
  lcd.setCursor(0, 1);              // Nastaví kurzor na začátek druhého řádku
  lcd.print("Enter Code:");
 while (keycount < 4)              // Smyčka běží dokud není zadáno 4 znaky kódu
  {
    lcd.setCursor(keycount + 12, 1);
    lcd.blink();                    
    char armcode = keypad.getKey();  // Přečte stisknutou klávesu z klávesnice
    armcode == NO_KEY;               // Kontrola, zda nebyla stisknuta žádná klávesa
    if (armcode != NO_KEY)           // Pokud byla stisknuta klávesa
    {
      if ((armcode != '*') && (armcode != '#')) // Pokud stisknutá klávesa není '*' nebo '#'
      {
        lcd.print(armcode);              // Vypíše stisknutou klávesu na displej
        tone(9, 5000, 100);              // Vydá zvuk na pinu 9 s frekvencí 5000 Hz po dobu 100 ms
        password[keycount] = armcode;    // Uloží stisknutou klávesu do pole "password"
        keycount++;                      // Zvýší počet zadaných znaků
      }
    }
  }

if (keycount == 4)              // Pokud byly zadány 4 znaky kódu
  {
    delay(500);                   
    lcd.noBlink();                
    lcd.clear();                  // Vyčistí LCD displej
    lcd.home();                   // Nastaví kurzor na začátek prvního řádku
    lcd.print("Disarm Code is: "); // Vypíše na první řádek "Disarm Code is:"
    lcd.setCursor(6, 1);          
    lcd.print(password[0]);       // Vypíše první znak kódu
    lcd.print(password[1]);       // Vypíše druhý znak kódu
    lcd.print(password[2]);       // Vypíše třetí znak kódu
    lcd.print(password[3]);       // Vypíše čtvrtý znak kódu
    delay(3000);                  // Pauza 3000 ms
    lcd.clear();                  // Vyčistí LCD displej
  }
  lcd.setCursor(0, 0);            // Nastaví kurzor na začátek prvního řádku
  lcd.print("Timer: HH:MM:SS");   // Vypíše na první řádek "Timer: HH:MM:SS"
  lcd.setCursor(0, 1);            // Nastaví kurzor na začátek druhého řádku
  lcd.print("SET:   :  :");       // Vypíše na druhý řádek "SET:   :  :"
  keycount = 5;                   // Nastaví keycount na 5

  while (keycount == 5)           // Smyčka běží dokud keycount není 5
  {
    char hourstens = keypad.getKey(); // Přečte stisknutou klávesu z klávesnice
    lcd.setCursor(5, 1);          // Nastaví kurzor na šestou pozici druhého řádku
    lcd.blink();                  
    if (hourstens >= '0' && hourstens <= '9') // Pokud stisknutá klávesa je číslice
    {
      hourstenscode = hourstens - '0'; // Uloží hodnotu klávesy do proměnné hourstenscode
      tone(9, 5000, 100);              // Vydá zvuk na pinu 9 s frekvencí 5000 Hz po dobu 100 ms
      lcd.print(hourstens);            // Vypíše číslici na LCD
      keycount++;                      // Zvýší keycount, a takhle se další příkazy vždy o jedno větší opakují
    }
  }

  while (keycount == 6)
  {
    char hoursones = keypad.getKey();
    lcd.setCursor(6, 1);
    lcd.blink();
    if (hoursones >= '0' && hoursones <= '9')
    {
      hoursonescode = hoursones - '0';
      tone(9, 5000, 100);
      lcd.print(hoursones);
      keycount++;
    }
  }

  while (keycount == 7)
  {
    char mintens = keypad.getKey();
    lcd.setCursor(8, 1);
    lcd.blink();
    if (mintens >= '0' && mintens <= '9')
    {
      mintenscode = mintens - '0';
      tone(9, 5000, 100);
      lcd.print(mintens);
      keycount++;
    }
  }

  while (keycount == 8)
  {
    char minones = keypad.getKey();
    lcd.setCursor(9, 1);
    lcd.blink();
    if (minones >= '0' && minones <= '9')
    {
      minonescode = minones - '0';
      tone(9, 5000, 100);
      lcd.print(minones);
      keycount++;
    }
  }

  while (keycount == 9)
  {
    char sectens = keypad.getKey();
    lcd.setCursor(11, 1);
    lcd.blink();
    if (sectens >= '0' && sectens <= '9')
    {
      sectenscode = sectens - '0';
      tone(9, 5000, 100);
      lcd.print(sectens);
      keycount = 10;
    }
  }

  while (keycount == 10)
  {
    char secones = keypad.getKey();
    lcd.setCursor(12, 1);
    lcd.blink();
    if (secones >= '0' && secones <= '9')
    {
      seconescode = secones - '0';
      tone(9, 5000, 100);
      lcd.print(secones);
      keycount = 11;
    }
  }

  if (keycount == 11);
  {
  Hours = (hourstenscode * 10) + hoursonescode; // Vypočítání hodin
  Minutes = (mintenscode * 10) + minonescode; // Vypočítání minut
  Seconds = (sectenscode * 10) + seconescode; // Vypočítání sekund
  delay(100); // Krátké zpoždění
  lcd.noBlink(); // Vypnutí blikání kurzoru
  lcd.clear(); // Vymazání displeje
  lcd.setCursor(0, 0); // Nastavení kurzoru na začátek prvního řádku
  lcd.print("Timer set at:"); // Zobrazení textu

  if (Hours >= 10)
  {
    lcd.setCursor(7, 1); // Nastavení kurzoru pro hodiny >= 10
    lcd.print(Hours); // Zobrazení hodin
  }
  if (Hours < 10)
  {
    lcd.setCursor(7, 1); // Nastavení kurzoru pro hodiny < 10
    lcd.write("0"); // Zobrazení nuly
    lcd.setCursor(8, 1); // Posunutí kurzoru
    lcd.print(Hours); // Zobrazení hodin
  }
  lcd.print(":"); // Zobrazení dvojtečky

    if (Minutes >= 10)
    {
      lcd.setCursor (10, 1);
      lcd.print (Minutes);
    }
    if (Minutes < 10)
    {
      lcd.setCursor (10, 1);
      lcd.write ("0");
      lcd.setCursor (11, 1);
      lcd.print (Minutes);
    }
    lcd.print (":");

    if (Seconds >= 10)
    {
      lcd.setCursor (13, 1);
      lcd.print (Seconds);
    }

    if (Seconds < 10)
    {
      lcd.setCursor (13, 1);
      lcd.write ("0");
      lcd.setCursor (14, 1);
      lcd.print (Seconds);
    }
    delay(3000); // Delší zpoždění
    lcd.clear(); // Vymazání displeje
    lcd.setCursor(0, 0); // Nastavení kurzoru na začátek prvního řádku
    lcd.print("Press # to arm"); // Zobrazení instrukcí
    delay(50); // Krátké zpoždění
    keycount = 12;
  }

  while (keycount == 12)
  {
    char armkey = keypad.getKey();

    if (armkey == '#') // Kontrola, zda je stisknuto '#'
    {
      tone(9, 5000, 100);
      delay(50);
      tone(9, 0, 100);
      delay(50);
      tone(9, 5000, 100);
      delay(50);
      tone(9, 0, 100);
      delay(50);
      tone(9, 5000, 100);
      delay(50);
      tone(9, 0, 100); // Zvuková sekvence
      lcd.clear(); // Vymazání displeje
      lcd.print("Bomb Armed!"); // Zobrazení stavu
      lcd.setCursor(0, 1); // Nastavení kurzoru na začátek druhého řádku
      lcd.print("Countdown start");
      delay(3000); // Delší zpoždění
      lcd.clear(); // Vymazání displeje
      keycount = 0; // Resetování keycount    
    }
  }
}
void loop()
{
  timer();  // Časovač
  char disarmcode = keypad.getKey();

  if (disarmcode == '*')
  {
    tone(9, 5000, 100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Code: ");

    while (keycount < 4)
    {
      timer();

      char disarmcode = keypad.getKey();
      if (disarmcode == '#')
      {
        tone(9, 5000, 100);
        keycount = 0; // Resetuje počítadlo
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Code: ");
      }
      else if (disarmcode != NO_KEY)
      {
        lcd.setCursor(keycount + 7, 0);
        lcd.blink();
        lcd.print(disarmcode);
        entered[keycount] = disarmcode;
        keycount++; // Zvýší počítadlo
        tone(9, 5000, 100);
        delay(100);
        lcd.noBlink();
        lcd.setCursor(keycount + 6, 0);
        lcd.print("*");
        lcd.setCursor(keycount + 7, 0);
        lcd.blink();
      }
    }

    if (keycount == 4)
    {
      if (entered[0] == password[0] && entered[1] == password[1] && entered[2] == password[2] && entered[3] == password[3])
      {
        lcd.noBlink(); // Vypne blikání
        lcd.clear();
        lcd.home();
        lcd.print("Bomb Defused!"); // Vypíše "Bomb Defused!".
        lcd.setCursor(0, 1);
        lcd.print("Well Done!"); // Vypíše "Well Done!".
        keycount = 0; // Resetuje počítadlo.
        digitalWrite(greenled, LOW); // Vypne zelenou LED diodu
        delay(15000); // Čeká 15 vteřin.
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Reset the Bomb"); // Vypíše "Reset the Bomb".
        delay(1000000); // Čeká dlouhou dobu.
      }
      else // Pokud je heslo špatné.
      {
        lcd.noBlink(); // Vypne blikání.
        lcd.clear();
        lcd.home();
        lcd.print("Wrong Password!"); // Vypíše "Wrong Password!".
        trycount++; // Zvýší počítadlo pokusů.

        if (Hours > 0)
        {
          Hours = Hours / 2;
        } // Sníží hodiny na polovinu.

        if (Minutes > 0)
        {
          Minutes = Minutes / 2;
        } // Sníží minuty na polovinu.
        if (Seconds > 0)
        {
          Seconds = Seconds / 2;
        } // Sníží vteřiny na polovinu.
        if (trycount == 2)
        {
          interval = interval / 10;
        } // Sníží interval na desetinu.
        if (trycount == 3)
        {
          Minutes = Minutes - 59;
          Hours = Hours - 59;
          Seconds = Seconds - 59;
        }
        delay(1000); // Pauza 1 vteřinu.
        keycount = 0; // Resetuje počítadlo.
      }
    }
  }
}

void timer()
{
  Serial.print(Seconds);
  Serial.println();

  if (Hours <= 0)
  {
    if ( Minutes < 0 )
    {
      lcd.noBlink();
      lcd.clear();
      lcd.home();
      lcd.print("The Bomb Has ");
      lcd.setCursor (0, 1);
      lcd.print("Exploded!");

      while (Minutes < 0)
      {
        digitalWrite(redled, LOW);
        tone(9, 7000, 100);
        delay(100);
        digitalWrite(redled, HIGH);
        tone(9, 7000, 100);
        delay(100);
        digitalWrite(yellowled, LOW);
        tone(9, 7000, 100);
        delay(100);
        digitalWrite(yellowled, HIGH);
        tone(9, 7000, 100);
        delay(100);
        digitalWrite(greenled, LOW);
        tone(9, 7000, 100);
        delay(100);
        digitalWrite(greenled, HIGH);
        tone(9, 7000, 100);
        delay(100); // Zvuková sekvence
      }
    }
  }
  lcd.setCursor (0, 1);
  lcd.print ("Timer:");

  if (Hours >= 10)
  {
    lcd.setCursor (7, 1);
    lcd.print (Hours);
  }
  if (Hours < 10)
  {
    lcd.setCursor (7, 1);
    lcd.write ("0");
    lcd.setCursor (8, 1);
    lcd.print (Hours);
  }
  lcd.print (":");

  if (Minutes >= 10)
  {
    lcd.setCursor (10, 1);
    lcd.print (Minutes);
  }
  if (Minutes < 10)
  {
    lcd.setCursor (10, 1);
    lcd.write ("0");
    lcd.setCursor (11, 1);
    lcd.print (Minutes);
  }
  lcd.print (":");

  if (Seconds >= 10)
  {
    lcd.setCursor (13, 1);
    lcd.print (Seconds);
  }

  if (Seconds < 10)
  {
    lcd.setCursor (13, 1);
    lcd.write ("0");
    lcd.setCursor (14, 1);
    lcd.print (Seconds);
  }

  if (Hours < 0) // Pokud jsou hodiny menší než 0, zobrazí 0
  {
    Hours = 0;
  }

  if (Minutes < 0)
  {
    Hours --;       // Sníží hodiny o 1
    Minutes = 59;   // Nastaví minuty na 59
  }

  if (Seconds < 1)
  {
    Minutes --;     // Sníží minuty o 1
    Seconds = 59;   // Nastaví sekundy na 59
  }

  if (Seconds > 0)
  {
    unsigned long currentMillis = millis();

    if (currentMillis - secMillis > interval)
    {
      tone(9, 7000, 50);               // generuje tón
      secMillis = currentMillis;       // Uloží aktuální čas millis() do proměnné secMillis
      Seconds --;                      // Sníží sekundy o jedna
      digitalWrite(yellowled, LOW);    // Zapne žlutou LED diodu
      delay(10);                       // Počká 10 ms
      digitalWrite(yellowled, HIGH);   // Vypne žlutou LED diodu
      delay(10);                       // Počká 10 ms
    }
  }
}
