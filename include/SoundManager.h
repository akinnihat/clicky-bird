#ifndef SOUNDMANAGER_HEADER
#define SOUNDMANAGER_HEADER

#include "Common.h"


class SoundManager
{
private:
	Sound m_JumpSound;
	Sound m_ScoreSound;
	Sound m_DeathSound;
public:
	SoundManager();
	~SoundManager();
	
    void PlayJumpSound();
	void PlayScoreSound();
	void PlayDeathSound();
};

#endif