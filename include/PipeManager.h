#ifndef PIPEMANAGER_HEADER
#define PIPEMANAGER_HEADER

#include "Common.h"
#include "Pipe.h"
#include "Player.h"
#include "SoundManager.h"
#include "Environment.h"


class PipeManager
{
private:
	int m_PipeCount;
	std::vector<Pipe> m_Pipes;

public:
    bool firstStart;

	PipeManager();
	PipeManager(int pipeCount);
	~PipeManager();

	void CreatePipes();	
	void ResetPipes();
	void UpdateAndDrawPipes(const Environment& env);
	bool CheckCollisionWithPlayer(Player& player, SoundManager& sm);
};

#endif