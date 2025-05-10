#include "ScreenManager.h"



ScreenManager::ScreenManager() : m_Alpha(255), m_DeltaCounter(0) {}
ScreenManager::~ScreenManager() {}

void ScreenManager::ShowStartScreen()
{
    DrawText("GET READY!", (screenWidth/6)-66, 50, 20, WHITE);	
    DrawText("TAP TO START!", (screenWidth/6)-50, 80, 10, WHITE);
}

void ScreenManager::ShowDeathEffect(float dt)
{		
    if (m_Alpha - (int)std::floor(m_DeltaCounter) > 0)
    {
        m_DeltaCounter+=std::pow(1 - m_Alpha*dt*0.4, 2); // easeOutQuart easing function
        m_Alpha-=(int)std::floor(m_DeltaCounter);
    } else { m_Alpha = 0; }
}

void ScreenManager::ResetDeathEffect()
{ 
    m_Alpha = 255;
    m_DeltaCounter = 0;
}

void ScreenManager::ShowGameOverScreen(float dt)
{
    ShowDeathEffect(dt);
    DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 255, 255, 255, (uint8_t)m_Alpha });	
    DrawText("GAME OVER!", (screenWidth/6)-66, 50, 20, RED);	
    DrawText("TAP TO RESTART!", (screenWidth/6)-52, 80, 10, WHITE);
}
