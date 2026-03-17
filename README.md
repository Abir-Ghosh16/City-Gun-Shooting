# City-Gun-Shooting-Game

A 2D city-themed shooting game built with **OpenGL (GLUT)** in C++. Take on the role of a sharpshooter defending the city — eliminate military threats while protecting civilians to rack up the highest score across 3 increasingly challenging levels.

---

## 🖥️ Built With

- **C++**
- **OpenGL / GLUT** (Graphics rendering)
- **Windows Multimedia API** (`mmsystem.h`) — Background music
- **File I/O** (`fstream`) — High score persistence

---

## 🎮 Gameplay Overview

### Main Menu

When the game launches, a main menu is displayed with the following options:

| Key | Action |
|-----|--------|
| `1` | Start Level 1 |
| `2` | Start Level 2 |
| `3` | Start Level 3 |
| `4` | Toggle Background Music ON / OFF |
| `ESC` | Quit Game |

![Main Menu](https://github.com/Abir-Ghosh16/City-Gun-Shooting/blob/main/README_IMAGES/Screenshot%20(467).png)

---

## 🏙️ Levels

### Level 1 — Basic Combat
Shoot military targets moving across the city skyline. Protect the ambulance at all costs.

| Target | Action | Score |
|--------|--------|-------|
| 🚁 Helicopter | Shoot it | **+50** |
| 🚗 Army Vehicle | Shoot it | **+20** |
| 🚑 Ambulance | Shoot it | **GAME OVER** |

![Level 1](https://github.com/Abir-Ghosh16/City-Gun-Shooting/blob/main/README_IMAGES/Screenshot%20(469).png)

#### Game Over

![Game over](https://github.com/Abir-Ghosh16/City-Gun-Shooting/blob/main/README_IMAGES/Screenshot%20(470).png)

### Level 2 — Urban Warfare
Military targets mix with civilian traffic. Discrimination is key — collateral damage hurts your score.

| Target | Action | Score |
|--------|--------|-------|
| 🚁 Helicopter | Shoot it | **+50** |
| 🚗 Army Vehicle | Shoot it | **+20** |
| 🚕 Taxi (Public Transport) | Shoot it | **−20** |
| 🚑 Ambulance | Shoot it | **GAME OVER** |

![Level 2](https://github.com/Abir-Ghosh16/City-Gun-Shooting/blob/main/README_IMAGES/Screenshot%20(472).png)

### Level 3 — High Speed Pursuit
Same rules as Level 2 but all targets move at **increased speed**, requiring quicker reflexes.

| Target | Action | Score |
|--------|--------|-------|
| 🚁 Helicopter | Shoot it | **+50** |
| 🚗 Army Vehicle | Shoot it | **+20** |
| 🚕 Taxi (Public Transport) | Shoot it | **−20** |
| 🚑 Ambulance | Shoot it | **GAME OVER** |

![Level 3](https://raw.githubusercontent.com/Abir-Ghosh16/City-Gun-Shooting/main/README_IMAGES/Screenshot%20(475).png)

---

## 📊 Score System

```
Helicopter Hit    →  +50 points
Army Vehicle Hit  →  +20 points
Taxi Hit          →  −20 points
Ambulance Hit     →  GAME OVER (score saved if it's a new high score)
```

- The **High Score** is saved to `highscore.txt` and persists between sessions.
- Your score is updated to high score automatically if it surpasses the previous record upon game over.

---

## 🕹️ Controls

| Input | Action |
|-------|--------|
| **Mouse Move** | Aim crosshair |
| **Left Click** | Shoot |
| `1` / `2` / `3` | Select level from main menu |
| `4` | Toggle background music |
| `R` | Restart after Game Over |
| `M` | Return to Main Menu |
| `ESC` | Exit game |

---

## 📁 Project Structure

```
📦 City-Gun-Shooting-Game
 ┣ 📄 main.cpp          # Main game source code
 ┣ 📄 g.cbp             # Code::Blocks project file
 ┣ 🎵 PUBG.wav          # Background music file
 ┣ 📄 highscore.txt     # Auto-generated high score file
 ┗ 📄 README.md
```

---

## ⚙️ Setup & Build Instructions

### Prerequisites

- [Code::Blocks IDE](https://www.codeblocks.org/) with MinGW compiler
- OpenGL and GLUT libraries configured
- Windows OS (uses `mmsystem.h` for audio)

### Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/city-gun-shooting-game.git
   cd city-gun-shooting-game
   ```

2. **Open the project**
   - Open `g.cbp` in **Code::Blocks**

3. **Configure GLUT libraries** (if not already set up)
   - Add `freeglut` or `glut` headers to your compiler's include path
   - Link against: `-lfreeglut -lopengl32 -lglu32 -lwinmm`

4. **Update the high score file path**
   - In `main.cpp`, locate `loadHighScore()` and `saveHighScore()` functions
   - Update the hardcoded path to match your system:
     ```cpp
     // Change this line in both functions:
     ifstream file("C:\\Users\\YourName\\path\\to\\highscore.txt");
     ```
   - Or place `highscore.txt` in the same directory as the executable and use a relative path:
     ```cpp
     ifstream file("highscore.txt");
     ```

5. **Place `PUBG.wav`** in the same directory as the compiled executable

6. **Build & Run**
   - Press `F9` in Code::Blocks to build and run

---

## 🐛 Known Issues / Notes

- The high score file path is currently hardcoded — update it before building (see setup step 4).
- Audio playback requires `PUBG.wav` to be present in the executable's directory; missing file causes silent playback.
- The game window is fixed at **1450 × 750** pixels.

---

## 📜 License

This project is for educational purposes. Feel free to use and modify it.
