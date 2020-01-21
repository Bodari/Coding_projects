// Sisällytetään kirjastot
#include <IRremote.h>

// Määritellään funktiot ennen pääkoodia
void kaasu();
void kaannos_oikealle();
void kaannos_vasemmalle();
void pakki();
void tyhjakaynti();

// Määritellään muuttujat/vakiot
const int OutPin6 = 6;                          // Oikea rengas        
const int OutPin7 = 7;
const int OutPin8 = 8;                          // Vasen rengas
const int OutPin9 = 9;
const int Speaker3 = 3;                         // Kaiutin amispoppia varten 
const int LedPin2 = 2;


int Receiver_Pin = 11;                          // Määritetään IR vastaanottimen pinni paikka.
IRrecv irrecv(Receiver_Pin);                    // Käytetään kirjaston koodia IRrecv jolla pystytään vastaanottamaan & ja lukemaan koodi IR kaukosäätimestä.
decode_results results;                         // Tulkitsee vastaanotetun koodin.
unsigned long edellinen_koodi;                  // Muuttuja tietotyyppi edellistä koodia varten.


void setup()
{
  Serial.begin(9600);                           // Käynnistetään sarjamonitori (datanopeus bitteinä sekunnissa) 

  pinMode(LedPin2, OUTPUT);                     // Valot
  
  pinMode(OutPin6, OUTPUT);                     // Määritellään moottorin pinnit ulostuloiksi. 
  pinMode(OutPin7, OUTPUT);

  pinMode(OutPin8, OUTPUT);
  pinMode(OutPin9, OUTPUT);

  pinMode(Speaker3, OUTPUT);                    // Kaiutin

  irrecv.enableIRIn();                          // Käynnistää vastaanottimen
}

// Toisto silmukka
void loop()   
{

  //Bluetooth
  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());

        switch (data)
        {
          
              case '1': // Kaasu
              digitalWrite (OutPin6, LOW);
              digitalWrite (OutPin7, HIGH);
              digitalWrite (OutPin8, LOW);
              digitalWrite (OutPin9, HIGH);
              break;
            
              case '2': //Pakki
              digitalWrite (OutPin6, HIGH);
              digitalWrite (OutPin7, LOW);          
              digitalWrite (OutPin8, HIGH);
              digitalWrite (OutPin9, LOW);
              break;
            
              case '3': // Vasemmalle
              digitalWrite (OutPin6, LOW);
              digitalWrite (OutPin7, HIGH);          
              digitalWrite (OutPin8, HIGH);
              digitalWrite (OutPin9, LOW);
              break;
            
              case '4': //Oikealle
              digitalWrite (OutPin6, HIGH);
              digitalWrite (OutPin7, LOW);          
              digitalWrite (OutPin8, LOW);
              digitalWrite (OutPin9, HIGH);
              break;
                   
              default: //Jos Bluetooth ei vastaanota mitään arvoa
              digitalWrite (OutPin6, LOW);
              digitalWrite (OutPin7, LOW);
              digitalWrite (OutPin8, LOW);
              digitalWrite (OutPin9, LOW);  
        }
  }

  if (irrecv.decode(&results))                  // Jos vastaanotin saa tuloksen ->
  {
              Serial.println(results.value, HEX);         // Tulostaa sarjamonitoriin koodin arvon HEX-muodossa. (Heksadesimaali)
              irrecv.resume();                            // Palauttaa vastaanottimen ottamaan uutta koodia vastaan.
            
                  
                  if(results.value == 0xFFFFFFFF)         // Jos tulos on FFFFFFFF...
                  {
                    results.value = edellinen_koodi;      // Menee funktioon -> edellinen_koodi() 
                  }
          
                  // Kaasu
                  if (results.value == 0xFF18E7)          // Jos tulos on FF18E7...
                  {     
                    kaasu();                              // Menee funktioon -> kaasu()
                  }
          
                  // Oikealle
                  if(results.value == 0xFF5AA5)           // Jos tulos on FF5AA5...
                  {
                    kaannos_oikealle();                   // Menee funktioon -> kaannos_oikealle()
                  }
          
                  // Vasemmalle
                  if(results.value == 0xFF10EF)           // Jos tulos on FF10EF...
                  {
                    kaannos_vasemmalle();                 // Menee funktioon -> kaannos_vasemmalle()
                  }
                  
                  // Pakki
                  if(results.value == 0xFF4AB5)           // Jos tulos on FF4AB5...
                  {
                    pakki();                              // Menee funktioon -> pakki()
                  }

                  //Biisit
                  if(results.value == 0xFFE01F)
                  {
                      
                  }


 }
  
} 


// Määritellään funktion toiminnot.

void edellinen_koodi_f()
{
          edellinen_koodi = results.value; 
}

void kaasu()
{
          edellinen_koodi_f();
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, HIGH);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, HIGH);
          delay(200);
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, LOW);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, LOW);          
}

void kaannos_oikealle()
{
          edellinen_koodi_f();
          digitalWrite (OutPin6, HIGH);
          digitalWrite (OutPin7, LOW);          
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, HIGH);
          delay(200);
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, LOW);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, LOW);         
}

void kaannos_vasemmalle()
{
          edellinen_koodi_f();
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, HIGH);          
          digitalWrite (OutPin8, HIGH);
          digitalWrite (OutPin9, LOW);
          delay(200);
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, LOW);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, LOW);  
}

void pakki()
{
          edellinen_koodi_f();
          digitalWrite (OutPin6, HIGH);
          digitalWrite (OutPin7, LOW);          
          digitalWrite (OutPin8, HIGH);
          digitalWrite (OutPin9, LOW);
          digitalWrite (LedPin2, HIGH);
          delay(200);
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, LOW);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, LOW); 
          digitalWrite (LedPin2, LOW); 
}

void tyhjakaynti ()
{
          digitalWrite (OutPin6, LOW);
          digitalWrite (OutPin7, LOW);
          digitalWrite (OutPin8, LOW);
          digitalWrite (OutPin9, LOW);  
}


// Biisit





