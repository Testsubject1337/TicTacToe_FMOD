// TikTacToe_FMOD.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include "TicTacToeFMOD.h"
#include "AudioCoreEngine.h"
#include <fmod.h>

int main()
{

    TicTacToeFMOD t = TicTacToeFMOD();
    t.run();

    return 0;
}
