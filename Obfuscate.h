#ifndef Obfuscate_h
#define Obfuscate_h
#include <Arduino.h>
class Obfuscate
{
    public:
        Obfuscate();                  // Constructor
        String parse(String message); // Parser
    private:
        char rot13(char letter); // Transcribed letters
};
#endif