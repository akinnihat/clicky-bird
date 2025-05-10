#ifndef PIPE_HEADER
#define PIPE_HEADER

#include "Common.h"


class Pipe
{
private:
public:
	Texture2D pipeTexture;
	Vector2 lowerPipePosition;
	Vector2 upperPipePosition;
	Rectangle lowerHitbox;
	Rectangle upperHitbox;
	
	Pipe();
	Pipe(Vector2 position);
	Pipe(const Pipe& other);
	~Pipe();

	void UpdateAndDrawOnePipe();
};

#endif