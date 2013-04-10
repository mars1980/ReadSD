///Customized sketch from the SD library that reads a file
//sometimes, you have to pull the card in and out of the slot
//if it can't be read.
//4.10.12

#include <SD.h>
const int chipSelect = 10;


void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
  readSd();
}

void loop()
{
}

void readSd()
{

  File dataFile = SD.open("datalog1.csv");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog1.csv");
  }
}
  



