#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Common.h"
#include "SoundManager.h"


class Player
{
private:
public:
	Texture2D playerTexture;
	Vector2 position;
	float speed;
	float velocity;
	float rotation;
	bool isAlive;
	int currentFrame;
	Rectangle frameRect;
	float hitboxRadius;
	int score;
    int gravity;
	bool firstStart;
	
	Player();
	~Player();

	void UpdateAndDrawPlayer(float dt, SoundManager& sm);
	void DrawPlayerHitbox(); // Just for debugging purposes
	void ShowScore();
	void ResetPlayer();
};

#endif