#include "Player.h"


Player::Player()
	: playerTexture(LoadTexture("resources/images/Bird.png")), position({ 30, 60 }), speed(125.0f), velocity(0.0f), rotation(0.0f),
	isAlive(true), currentFrame(0), frameRect({ 0.0f, 0.0f, (float)playerTexture.width / 4, (float)playerTexture.height }),
	hitboxRadius(8), score(0), gravity(0)
{
    Log("Player has been spawned!");
}

Player::~Player()
{
	Log("Player has been destroyed!");
	UnloadTexture(playerTexture);
}

void Player::UpdateAndDrawPlayer(float dt, SoundManager& sm)
{
    Vector2 origin = { frameRect.width/2, frameRect.height/2 };
    Rectangle destRect = { position.x, position.y, frameRect.width, frameRect.height };
    
    if (isAlive)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
        {
            sm.PlayJumpSound();
            velocity = speed; 
        }
        position.y -= velocity * dt;
        velocity += gravity * dt;
        rotation = velocity >= -90 ? velocity : -90;

    }
    DrawTexturePro(playerTexture, frameRect, destRect, origin, -rotation, WHITE);
}

void Player::DrawPlayerHitbox()
{
	DrawCircleLines(position.x, position.y, hitboxRadius, RED);
}

void Player::ShowScore()
{
    std::string s = std::to_string(score);
    const char* cstr = s.c_str();
    DrawText(cstr, (screenWidth/6)-10, 20, 20, WHITE);
}

void Player::ResetPlayer()
{
    position = { 30, 60 };
    velocity = 0.0f;
    isAlive = true;
    currentFrame = 0;
    score = 0;
}