#include "SoundManager.h"


SoundManager::SoundManager() : m_JumpSound(LoadSound("resources/sounds/jump.wav")), 
					           m_ScoreSound(LoadSound("resources/sounds/score.wav")), 
					           m_DeathSound(LoadSound("resources/sounds/hit.wav")) {}

SoundManager::~SoundManager()
{
    UnloadSound(m_JumpSound);
    UnloadSound(m_ScoreSound);
    UnloadSound(m_DeathSound);
}
	
void SoundManager::PlayJumpSound()  { PlaySound(m_JumpSound);  }
void SoundManager::PlayScoreSound() { PlaySound(m_ScoreSound); }
void SoundManager::PlayDeathSound() { PlaySound(m_DeathSound); }