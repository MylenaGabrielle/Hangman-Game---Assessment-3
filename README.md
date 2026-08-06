# Hangman Game

PRG1006 – Programming II

Assessment 3

---

## Project Overview

This project is a console-based Hangman game developed in C++ using Object-Oriented Programming (OOP) principles.

The game allows players to choose between Solo Mode and Two-Player Mode, select a topic, and guess letters or the complete word while earning points and managing a limited number of attempts.

---

## Gameplay

Players must guess the hidden word by entering individual letters or the complete word.

Correct letter guesses reveal all matching letters and award **10 points**.

Correctly guessing the complete word awards an additional **50 points**.

Each player starts with **4 attempts**. The game ends when the hidden word is completely revealed or when a player has no remaining attempts.

---

## Features

- Main Menu
- How to Play screen
- Solo Mode
- Two-Player Mode
- Three word categories:
  - Fruits
  - Countries
  - Colours
- Random word selection
- Letter guessing
- Complete word guessing
- Score system
- Attempt tracking
- Guessed letters display
- Win detection
- Game Over detection
- Leave Game confirmation

---

## Object-Oriented Concepts

This project demonstrates:

- Encapsulation
- Information Hiding
- Inheritance
- Polymorphism
- Abstract Base Class
- Function Overriding
- Constructors
- Dynamic Memory Allocation
- STL Vector
- STL Set

---

## Project Structure

```text
Hangman-Game---Assessment-3
│
├── include
│   ├── ConsoleDisplay.h
│   ├── GameMode.h
│   ├── HangmanGame.h
│   ├── Player.h
│   ├── SoloMode.h
│   ├── TwoPlayerMode.h
│   └── WordBank.h
│
├── src
│   ├── ConsoleDisplay.cpp
│   ├── HangmanGame.cpp
│   ├── Player.cpp
│   ├── SoloMode.cpp
│   ├── TwoPlayerMode.cpp
│   ├── WordBank.cpp
│   └── main.cpp
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## How to Compile

Compile all source files:

```bash
g++ -Iinclude src/*.cpp -o hangman
```

---

## How to Run

### Linux / GitHub Codespaces

```bash
./hangman
```

### Windows

```bash
hangman.exe
```

---

## Game Controls

### Main Menu

```text
[1] Play Hangman
[2] How to Play
[3] Exit
```

### During the Game

```text
[1] Guess a Letter
[2] Guess the Word
[3] Leave Game
```

---

## Scoring System

| Action | Points |
|---------|-------:|
| Correct Letter | +10 |
| Correct Word | +50 |
| Wrong Letter | Lose 1 attempt |
| Wrong Word | Lose 1 attempt |

Each player starts with **4 attempts**.

---

## Requirements

- C++11 or later
- g++ compiler
- Linux, GitHub Codespaces or Windows

---

## Author

Mylena Gabrielle Silveira da Silva

PRG1006 – Programming II

Assessment 3

Developed in C++