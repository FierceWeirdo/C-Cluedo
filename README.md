# C-Cluedo

# Cluedo Game

## Introduction
This is a text-based implementation of the classic board game Cluedo (or Clue) written in C. In this game, you will play as a detective trying to solve a murder mystery by making educated guesses about the murderer, the weapon used, and the location of the crime scene.

## Getting Started
To run the game, you'll need a C compiler installed on your system. Here's how to get started:

1. Clone or download the repository to your local machine.
2. Navigate to the directory containing the source code files.
3. Compile the code using your preferred C compiler. For example, using GCC:

   ```bash
   gcc -o cluedo cluedo.c
   ```

4. Run the compiled executable:

   ```bash
   ./cluedo
   ```

## Gameplay
- Upon starting the game, you will be presented with a menu offering options to view instructions, play the game, or exit.
- Choose to view instructions to learn how to play the game and understand its rules.
- Choose to play the game to start solving the mystery.
- You will be prompted to select a difficulty level: Easy or Difficult.
- The game will randomly select a murderer, a weapon, and a crime scene, which you must guess correctly to win.
- Make your guesses for the murderer, the weapon, and the crime scene based on the provided clues and your deductions.
- If your guess is incorrect, the game will progress to the next player's turn (controlled by bots).
- If your guess is correct, you win the game!

## Features
- Random selection of the case file (murderer, weapon, and crime scene).
- Text-based interface for easy interaction.
- Support for two difficulty levels: Easy and Difficult.
- Clues provided based on the difficulty level chosen.
- User-friendly error handling and input validation.
- Clear instructions and guidance provided throughout the game.
