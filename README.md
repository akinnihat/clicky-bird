# ClickyBird

ClickyBird is a Flappy Bird clone developed in C++ using the Raylib library.


## Installation

1. Clone the project
```bash
git clone https://github.com/akinnihat/clicky-bird.git
```

2. Build the project (or you can simply play the pre-compiled version at `release/ClickyBird/ClickyBird.exe`)

    Open the project folder in a terminal and build the project:
    - Remove `-mwindows` flag on Linux
    - On Windows, you can just double click the `.bat` file (make sure the g++ path is included in Windows environment variables)
    ```bash
    g++ -o ClickyBird.exe -Iinclude src/*.cpp -lraylib -lgdi32 -lwinmm -mwindows
    ```



## Project Structure

```
ClickyBird/
├── include/
│   ├── Common.h
│   ├── Environment.h
│   ├── Game.h
│   ├── Pipe.h
│   ├── PipeManager.h
│   ├── Player.h
│   ├── ScreenManager.h
│   └── SoundManager.h
│   
├── src/            
│   ├── Environment.cpp
│   ├── Game.cpp
│   ├── Main.cpp
│   ├── Pipe.cpp
│   ├── PipeManager.cpp
│   ├── Player.cpp
│   ├── ScreenManager.cpp
│   └── SoundManager.cpp
│
├── resources/      
│   ├── images
│   └── sounds
   
```

## Gameplay


https://github.com/user-attachments/assets/dd4c8f59-6df2-4b22-b5f7-e4654ca68c77



## Credits

I don't own any of the assets used in this game.

- Images (I edited some of them): https://megacrash.itch.io/flappy-bird-assets

- Sounds

  - Jump: https://freesound.org/people/combine2005/sounds/488275/

  - Score: https://freesound.org/people/The-Sacha-Rush/sounds/336933/

  - Death: https://freesound.org/people/NearTheAtmoshphere/sounds/676466/
