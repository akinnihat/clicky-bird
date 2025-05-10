#include "Pipe.h"

	
Pipe::Pipe()
    : pipeTexture(LoadTexture("resources/images/PipeLong.png")), 
    lowerPipePosition({ 120, 150 }), upperPipePosition({ 120, -150 }),
    lowerHitbox(Rectangle{ 120.0f, 150.0f, 32.0f, 256.0f }), upperHitbox(Rectangle{ 120.0f, -150.0f, 32.0f, 256.0f }) {}

Pipe::Pipe(Vector2 position)
    : pipeTexture(LoadTexture("resources/images/PipeLong.png")), 
    lowerPipePosition({ position.x, position.y }), upperPipePosition({ position.x, position.y-316 }),
    lowerHitbox(Rectangle{ (float)position.x, (float)position.y, 32.0f, 256.0f }), 
    upperHitbox(Rectangle{ (float)position.x, (float)position.y-316, 32.0f, 256.0f }) {}

Pipe::Pipe(const Pipe& other)
    : pipeTexture(LoadTexture("resources/images/PipeLong.png")), 
    lowerPipePosition(other.lowerPipePosition), upperPipePosition(other.upperPipePosition),
    lowerHitbox(Rectangle{ (float)other.lowerPipePosition.x, (float)other.lowerPipePosition.y, 32.0f, 256.0f} ), 
    upperHitbox(Rectangle{ (float)other.upperPipePosition.x, (float)other.upperPipePosition.y, 32.0f, 256.0f} ) {}

Pipe::~Pipe()
{
    Log("Pipes have been destroyed!");
    UnloadTexture(pipeTexture);
}

void Pipe::UpdateAndDrawOnePipe()
{

    lowerHitbox.x = (float)lowerPipePosition.x;
    lowerHitbox.y = (float)lowerPipePosition.y; 
    upperHitbox.x = (float)upperPipePosition.x;
    upperHitbox.y = (float)upperPipePosition.y;

    //DrawRectangleLines(lowerHitbox.x, lowerHitbox.y, 
    //				   lowerHitbox.width, lowerHitbox.height, RED);
    
    //DrawRectangleLines(upperHitbox.x, upperHitbox.y, 
    //				   upperHitbox.width, upperHitbox.height, RED);

    DrawTextureEx(pipeTexture, lowerPipePosition, 0, 1.0f, WHITE);
    DrawTextureEx(pipeTexture, upperPipePosition, 0, 1.0f, WHITE);
}
