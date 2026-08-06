# Hangman-Game---Assessment-3

## Project Overview

This project is a console-based Hangman game developed in C++ using Object-Oriented Programming (OOP) principles.

The game allows players to choose between Solo Mode and Two-Player Mode, select a topic, and guess letters or the complete word while earning points and managing a limited number of attempts.

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
- Dynamic Memory Allocation
- STL Vector
- STL Set

---

## Project Structure

```
ConsoleDisplay
GameMode
SoloMode
TwoPlayerMode
HangmanGame
Player
WordBank
main.cpp
```

---

## How to Compile

Compile all source files:

```Bash g++ -Iinclude src/*.cpp -o hangman```

---

## How to Run

Linux / Codespaces

```bash ./hangman```

Windows

```bash hangman.exe```

---

## Game Controls

### Main Menu

```
[1] Play Hangman
[2] How to Play
[3] Exit
```

### During the Game

```
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
| Wrong Letter | -1 Attempt |
| Wrong Word | -1 Attempt |

Each player starts with **4 attempts**.

---

## Author

**Mylena Gabrielle Silveira da Silva**

PRG1006 – Programming II

Assessment 3

Developed using C++

---

## Requirements

- C++ compiler (g++)
- C++11 or later