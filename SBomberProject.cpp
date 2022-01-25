
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"

int MyTools::LoggerSingleton::n_page = 1;

using namespace std;

//========================================================================================================================

int main(void)
{
    MyTools::LoggerSingleton::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    MyTools::LoggerSingleton::getInstance().CloseLogFile();

    return 0;
}
