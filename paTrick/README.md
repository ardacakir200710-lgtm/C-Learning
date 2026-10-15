# Raylib C++ Project

A 2D game/application built with C++17 and the Raylib library on macOS.

---

## Prerequisites

Before building and running this project, ensure you have the following installed on your system:

- **macOS**
- **Clang++** (included with Xcode Command Line Tools)
- **Homebrew**
- **Raylib**

### Installing Dependencies

If you don't have Raylib installed via Homebrew, run:

```bash
brew install raylib
```

---

## Building the Project

To compile the project using `clang++`, run the following command in your terminal:

```bash
clang++ main.cpp -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -o game
```

---

## Running the Executable

Once compilation is complete, run the generated binary:

```bash
./game
```

---

## Controls

- **Left / Right Arrow Keys:** Move character horizontally
- **Up Arrow Key:** Jump
