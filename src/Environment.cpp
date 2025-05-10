#include "Environment.h"


Environment::Environment()
    : backgroundTexture(LoadTexture("resources/images/Background.png")), backgroundWidth(backgroundTexture.width), 
    backgroundPosition({ (-(float)backgroundWidth), 0 }), backgroundSpeed(0.125f),
    groundTexture(LoadTexture("resources/images/Tiles.png")), groundWidth(groundTexture.width/2), 
    groundPosition({ (-(float)groundWidth), 248 }), groundTextureRect({ 64, 48, 64, 20 }), groundSpeed(1.0f)
{
    Log("Background has been created!");
}

Environment::~Environment()
{
    Log("Environment has been destroyed!");
    UnloadTexture(backgroundTexture);
}

void Environment::ScrollEnvironment()
{
    // Scroll background
    if (backgroundPosition.x == (-2)*backgroundWidth) { backgroundPosition.x = -backgroundWidth; }
    Vector2 newBackgroundPosition = backgroundPosition;
    for (int i=0; i<4; i++)
    {
        DrawTextureEx(backgroundTexture, newBackgroundPosition, 0.0f, 1.0f, WHITE);
        newBackgroundPosition.x += backgroundWidth;
    }
    backgroundPosition.x -= backgroundSpeed;

    // Scroll ground
    if (groundPosition.x == (-2)*groundWidth) { groundPosition.x = -groundWidth; }
    Vector2 newGroundPosition = groundPosition;
    for (int i=0; i<10; i++)
    {
        DrawTextureRec(groundTexture, groundTextureRect, newGroundPosition, WHITE);
        newGroundPosition.x += groundWidth;
    }
    groundPosition.x -= groundSpeed;
}
