#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN

// Buttons
const int rght = 4; /* Right Attack */
const int lft = 5; /* Left Attack */
const int fwd = 6; /* Forward */
const int bckwd = 7; /* Backward */ 
const byte address[6] = "00001";

// Define messages to send over radio
const char rghtM[] = "Right";
const char lftM[] = "Left";
const char fwdM[] = "Forward";
const char bckwdM[] = "Backward";


void setup() {
  pinMode(rght, INPUT);
  pinMode(lft, INPUT);
  pinMode(fwd, INPUT);
  pinMode(bckwd, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  // Read the state of all buttons
  rghtState = digitalRead(rght);
  lftState = digitalRead(lft);
  fwdState = digitalRead(fwd);
  bckwdState = digitalRead(bckwd);
  if (rghtState == HIGH)
  {
    radio.write(&rghtM, sizeof(rghtM));
  }
  if (lftState == HIGH)
  {
    radio.write(&lftM, sizeof(lfttM));
  }
  if (fwdState == HIGH)
  {
    radio.write(&fwdM, sizeof(fwdM));
  }
  if (bckwdState == HIGH)
  {
    radio.write(&bckwdtM, sizeof(bckwdM));
  }
  delay(1000);
}
