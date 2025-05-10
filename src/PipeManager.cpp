#include "PipeManager.h"


PipeManager::PipeManager() : m_PipeCount(7), firstStart(true) { m_Pipes.reserve(7); }
PipeManager::PipeManager(int pipeCount) : m_PipeCount(pipeCount), firstStart(true) { m_Pipes.reserve(pipeCount); }
PipeManager::~PipeManager() {}


void PipeManager::CreatePipes()
{
	float pipeXValue = 240.0f;
	int pipeXDistance = 120;
	for (int i=0; i<m_PipeCount; i++)
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(60, 240);

		float randomY = dis(gen);
		m_Pipes.emplace_back(Pipe({ pipeXValue, randomY }));
		pipeXValue += pipeXDistance;
	}
}

void PipeManager::ResetPipes()
{
	m_Pipes.clear();
	CreatePipes();
}

void PipeManager::UpdateAndDrawPipes(const Environment& env)
{
	if (!firstStart)
	{
		for (Pipe& pipe : m_Pipes)
		{
			pipe.lowerPipePosition.x -= env.groundSpeed;
			pipe.upperPipePosition.x -= env.groundSpeed;
	
			if (pipe.lowerPipePosition.x < -360)
			{
				pipe.lowerPipePosition.x += 840;
				pipe.upperPipePosition.x = pipe.lowerPipePosition.x;
	
				static std::random_device rd;
				static std::mt19937 gen(rd());
				std::uniform_int_distribution<> dis(60, 240);
				float randomY = dis(gen);
	
				pipe.lowerPipePosition.y = randomY;
				pipe.upperPipePosition.y = pipe.lowerPipePosition.y-316;
	
			}
			pipe.UpdateAndDrawOnePipe();
		}
	}
}

bool PipeManager::CheckCollisionWithPlayer(Player& player, SoundManager& sm)
{
	bool collidedLower = false;
	bool collidedUpper = false;

	for (Pipe& pipe : m_Pipes)
	{
		if (player.position.x == pipe.lowerPipePosition.x) 
		{ 
			player.score++; 
			sm.PlayScoreSound();
		}
		collidedLower = CheckCollisionCircleRec(player.position, player.hitboxRadius, pipe.lowerHitbox);
		collidedUpper = CheckCollisionCircleRec(player.position, player.hitboxRadius, pipe.upperHitbox);
		
		if (collidedLower or collidedUpper or player.position.y >= 232 or player.position.y <= 8 ) 
		{ 
			sm.PlayDeathSound();
			return true; 
		}
	}
	return false;
}