#include "Game.h"


Game::Game() {}
Game::~Game() {}

void Game::DebugCamera(Camera2D& camera)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 delta = GetMouseDelta();
		delta = Vector2Scale(delta, -1.0f / camera.zoom);
		camera.target = Vector2Add(camera.target, delta);
	}

	// Zoom based on mouse wheel
	float wheel = GetMouseWheelMove();

	// Get the world point that is under the mouse
	Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
	Log("Mouse X Position:" << mouseWorldPos.x << " Mouse Y Position:" << mouseWorldPos.y);

	if (wheel != 0)
	{
		// Set the offset to where the mouse is
		camera.offset = GetMousePosition();

		// Set the target to match, so that the camera maps the world space point 
		// under the cursor to the screen space point under the cursor at any zoom
		camera.target = mouseWorldPos;

		// Zoom increment
		// Uses log scaling to provide consistent zoom speed
		float scale = 0.2f * wheel;
		camera.zoom = Clamp(expf(logf(camera.zoom) + scale), 0.125f, 64.0f);
		Log("Camera Zoom: " << camera.zoom);
	}
}

void Game::StartGameLoop()
{
	SetTargetFPS(60);
	InitWindow(screenWidth, screenHeight, "ClickyBird");
	InitAudioDevice();

	Camera2D camera = { 0 };
	camera.zoom = 3.0f;

	int framesCounter = 0;
	int framesSpeed = 8;

	ScreenManager screenManager;
	SoundManager soundManager;
	Player player;
    Environment environment;
	PipeManager pipeManager;
	pipeManager.CreatePipes();

	float dt = 0.0f;

	// Game Loop
	while (!WindowShouldClose())
	{
        //DebugCamera(camera);
		
		dt = GetFrameTime();
        framesCounter++;

		if (player.isAlive)
		{
			if (framesCounter >= (60 / framesSpeed))
			{
				framesCounter = 0;
				player.currentFrame++;

				if (player.currentFrame > 3) { player.currentFrame = 0; }

				player.frameRect.x = (float)player.currentFrame * (float)player.playerTexture.width / 4;
			}
		}

		// Drawing
		BeginDrawing();
		BeginMode2D(camera);
		
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		environment.ScrollEnvironment();
		pipeManager.UpdateAndDrawPipes(environment);
		player.UpdateAndDrawPlayer(dt, soundManager);
		player.ShowScore();

		if (pipeManager.firstStart)
		{
			screenManager.ShowStartScreen();
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				player.gravity = -175;
				pipeManager.firstStart = false;
			}
		} 
		
		if (!player.isAlive) 
		{ 
			environment.backgroundSpeed = 0.0f;
			environment.groundSpeed = 0.0f;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				player.ResetPlayer(); 
				pipeManager.ResetPipes();
			}
			screenManager.ShowGameOverScreen(dt);
		}
		else
		{
			screenManager.ResetDeathEffect();
			environment.groundSpeed = 1.0f;
			environment.backgroundSpeed = 0.125f;
			player.isAlive = !pipeManager.CheckCollisionWithPlayer(player, soundManager);
		}
		EndMode2D();
		EndDrawing();
	}
	CloseAudioDevice();
	CloseWindow(); 
}