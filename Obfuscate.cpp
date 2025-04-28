#include "Obfuscate.h"

//Constructor
Obfuscate::Obfuscate(){

}

//Parser
String Obfuscate::parse(String message) {
  String transcribed;

  int messageLength = message.length();
  char arr[messageLength + 1];  //Set up char array
  strcpy(arr, message.c_str());

  for (int i = 0; i <= messageLength; i++) {
    transcribed += rot13(arr[i]);
  }
  return transcribed;
}

//ROT13 characters
char Obfuscate::rot13(char letter) {
  if (letter >= 'A' && letter <= 'Z') {
    letter = letter + 32; //Convert uppercase to lowercase diffrence between A=65 and a=97
    letter = (letter - 'a' + 13) % 26 + 'a';
  }
  else if (letter >= 'a' && letter <= 'z') {
    letter = (letter - 'a' + 13) % 26 + 'a';
  }
  
  //a - a = 0 | Subtract character by itself to get numerical position
  //0 + 13 = 13 | Add shift to number

  //13 % 26 = 13 | Shift modulo 26
  //13 + a = 110 (n) | Convert modulo result into transcribed ascii value
  return letter;
}