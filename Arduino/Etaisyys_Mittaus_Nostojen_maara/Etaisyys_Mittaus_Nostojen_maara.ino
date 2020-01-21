// Määritetllään pinnit
 const int GNDPin = 11; // ultraäänianturin maa-napa
 const int echoPin = 10; // Echo Pin (kaiku, eli vastaanotinpuoli)
 const int trigPin = 9; // Trigger Pin (ultraääni-lähtetin)
 const int VccPin = 8; // Anturin käyttöjännite

//Määritellään tarkistus funktio ennen pääkoodia
void muutos();

// Määritetllään muuttujat
long kesto;
float etaisyys;
float edellinen_mittaus;

float Min;
int Keskiarvo;
float Max = 0.0;

float Energia[];
int e = 0;    // Energian kerroin  

int Nostot;

float alapinta = 4;
float ylapinta = 17;

int raja1 = 0, raja2 = 0;

unsigned long aika = 0;

void setup() 
{
     pinMode(GNDPin, OUTPUT); // Maadoitus; tämäkin on output-napa joka antaa 0V:n jännitteen
     pinMode(echoPin, INPUT);
     pinMode(trigPin, OUTPUT);
     pinMode(VccPin, OUTPUT); // Käyttöjännite
     Serial.begin(9600); 

     digitalWrite(VccPin, HIGH);
     delayMicroseconds(2); 
     digitalWrite(GNDPin, LOW); 
     delayMicroseconds(2); 
     Serial.println("Valmiina. Mittaukset oteaan puolen sekunnin välein.");
}


void loop() 
{             
              aika = millis();

              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);    
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              
              // Lukee Echopinnin arvon, palauttaa ääniaallon matkustus ajan mikrosekuntteina.   
              kesto = pulseIn(echoPin, HIGH);
              
              // Lasketaan etäisyys
              etaisyys = kesto*0.034/2;

              Min = etaisyys;
              
              do
              {    
              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              
              // Lukee Echopinnin arvon, palauttaa ääniaallon matkustus ajan mikrosekuntteina.   
              kesto = pulseIn(echoPin, HIGH);
              
              // Lasketaan etäisyys
              etaisyys = kesto*0.034/2;
           
            if (edellinen_mittaus < alapinta && alapinta < etaisyys )
            {
              raja1 = 1;
            }

            edellinen_mittaus = etaisyys;

            if (raja1 == 1 && etaisyys > ylapinta)
            {
              raja2 = 1;
            }

            if (Min > etaisyys)
            {
              Min = etaisyys; 
            }

            // Tarkistetaan onko nykyinen mittaus (etäisyys) suurempi kuin Maximi 
            if (Max < etaisyys)
            {
              Max = etaisyys;
            }

            // Jos molemmat rajat toteutuvat, lisätään nostoihin 1. 
            if (raja1 == 1 && raja2 == 1)    // 
            {
                Nostot++;
                raja1 = 0;
                raja2 = 0;
            }
  
            Energia[e] = 5000 * 9.81 (Max - Min);
            e = ++; 
            } while (etaisyys < Max);
            
            Serial.println ("Mittaus arvot otettu.");
            Serial.print ("Aika: ");
            Serial.println (aika);
            Serial.print ("Etäisyys: ");
            Serial.println(etaisyys);
            Serial.print("Nostojen määrä: ");
            Serial.println(Nostot);
            Serial.print("Energian kulutus: ");
            Serial.println(Energia[e]);
            Serial.print("Max korkeus: ");
            Serial.println(Max);
            Serial.print("Min korkeus");
            Serial.println(Min);
            Serial.println("");            
}



