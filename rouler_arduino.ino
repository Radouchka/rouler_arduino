#include <M5_Encoder.h>
M5_Encoder monEncodeur;
#include <MicroOscSlip.h>
    MicroOscSlip<128> monOsc(&Serial); 

void setup() {
   Wire.begin(); //active le I2C
   monEncodeur.begin(); //par default c 64
}

void loop() {
    monEncodeur.update();  // Mise à jour des valeurs de l’encodeur. 

     int changementEncodeur = monEncodeur.getEncoderChange();
    if(changementEncodeur != 0) {
        monOsc.sendInt("/enc/rot", changementEncodeur);
    }

    if(monEncodeur.wasPressed()) {
        monOsc.sendInt("/enc/but", 1);
    }

    if(monEncodeur.wasReleased()) {
        monOsc.sendInt("/enc/but", 0);
    }
}
