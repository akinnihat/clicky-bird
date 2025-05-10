#ifndef ENVIRONMENT_HEADER
#define ENVIRONMENT_HEADER

#include "Common.h"


class Environment
{
private:
public:
	// Background
    Texture2D backgroundTexture;
    int backgroundWidth;
    Vector2 backgroundPosition;
    float backgroundSpeed;
    float groundSpeed;

	// Ground
	Texture2D groundTexture;
    int groundWidth;
    Vector2 groundPosition;
    Rectangle groundTextureRect;

    Environment();
    ~Environment();
    
    void ScrollEnvironment();
};

#endif