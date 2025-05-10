#ifndef SCREENMANAGER_HEADER
#define SCREENMANAGER_HEADER

#include "Common.h"


class ScreenManager
{
private:
	int m_Alpha;
	float m_DeltaCounter;
public:
	ScreenManager();
    ~ScreenManager();

	void ShowStartScreen();
	void ShowDeathEffect(float dt);
	void ResetDeathEffect();
	void ShowGameOverScreen(float dt);
};

#endif