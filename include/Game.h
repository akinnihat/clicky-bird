#ifndef GAME_HEADER
#define GAME_HEADER

#include "Common.h"
#include "Environment.h"
#include "Pipe.h"
#include "PipeManager.h"
#include "Player.h"
#include "ScreenManager.h"
#include "SoundManager.h"

class Game
{
private:
public:
    Game();
    ~Game();
    
    void DebugCamera(Camera2D& camera);
    void StartGameLoop();
};

#endif