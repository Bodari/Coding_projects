const int VccPin2 = A0;               // Virta
const int xpin = A1;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A3;                  // z-axis (only on 3-axis models)
const int GNDPin2 = A4;               // Maa

int sisaanmeno = 0;

int X;
int Y;
int Z;

float AX;
float AY;
float AZ;

float KK;  // Kokonaiskiihtyvyys
float KK_taulukko[250];
float KK_summa = 0.0;
float KK_keskiarvo = 0.0;

double Lepo, Aktiivinen = 0;

float RMS;

/*
unsigned long aika = millis();
unsigned long aloitus_aika = millis();
unsigned long nykyinen_aika = millis();
unsigned long kulunut_aika = nykyinen_aika - aloitus_aika;
*/

double AXtaulu[50];
double AYtaulu[50];
double AZtaulu[50];


void setup() 
{
     Serial.begin(9600);
     pinMode(VccPin2, OUTPUT);     // Kiihtyvyysanturin käyttöjännite Vcc
     pinMode(GNDPin2, OUTPUT);     // Kiihtyvyysanturin GND
     digitalWrite(GNDPin2, LOW); 
     digitalWrite(VccPin2, HIGH);
 
     Serial.print ("Lepo (s)");
     Serial.print ("\t");
     Serial.println ("Aktiivinen (s)");
}

void loop() 
{
     unsigned long aloitus_aika = millis();
     
     if (sisaanmeno == 0)
     {
        delay(1000);
     }

     
     for (int a = 0; a < 250; a++)
     {
         int X = analogRead(xpin);  //read from xpin
         
         int Y = analogRead(ypin);  //read from ypin
         
         int Z = analogRead(zpin);  //read from zpin
        
         AX = 0.1411 * X - 47.218; //Kalibrointiyhtälö x-akselin sensoriarvosta x-suunnan kiihtyvyydeksi.
         AY = 0.1411 * Y - 47.218;
         AZ = 0.1411 * Z - 47.218;
    
         KK = pow((pow(AX,2)+pow(AY,2)+pow(AZ,2)),0.5);   // Kokonaiskiihtvyys
         KK = pow(KK,2);
         
         KK_summa = KK_summa - KK_taulukko[a];
         KK_taulukko[a] = KK;
         KK_summa = KK_summa + KK;
         KK_keskiarvo = KK_summa / 250;
     }
     
    unsigned long nykyinen_aika = millis();
    double kulunut_aika = nykyinen_aika - aloitus_aika;
    kulunut_aika = kulunut_aika / 1000;   // Muutos sekunneiksi
    
    RMS = pow(KK_keskiarvo, 0.5);

    if (RMS >= 9.85 && RMS <= 10.5)
    {
      Lepo = Lepo + kulunut_aika;
    }
    else
    {
      Aktiivinen = Aktiivinen + kulunut_aika;
    }
    Serial.print (Lepo);
    Serial.print ("\t\t");
    Serial.println (Aktiivinen);

}
