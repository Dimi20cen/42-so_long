# so_long

A tiny 2D tile game written in C for the 42 curriculum.  
You move a player around a map, collect all items, then reach the exit — with basic graphics via **MiniLibX**.


## ✨ Features
- Map loading from `.ber` text files
- Full map validation (rectangular, closed by walls, valid chars)
- Collectibles + exit logic (must collect everything before exiting)
- Simple rendering with **MiniLibX** (images/sprites)
- Smooth movement with keyboard input
- Clean exit on `ESC` and window close
- Error messages for invalid maps or runtime failures


## 📦 Dependencies
- **C compiler** (gcc/clang) and **make**
- **MiniLibX** (provided in `mlx/` here, or install separately)
- **Libft** (included as `Libft/`)


## 🚀 Build & Run

```bash
git clone https://github.com/Dimi20cen/42-so_long.git
cd 42-so_long
make            # builds ./so_long
./so_long maps/map1.ber
````

Common Makefile targets:

```bash
make        # build
make clean  # remove objects
make fclean # objects + binary
make re     # rebuild
```


## 🎮 Controls

- **W / A / S / D** or **Arrow keys** – move
- **ESC** – quit
- **Window close (✖)** – quit gracefully

> If your keybindings differ, replace this section with the actual keys you handle in `movement.c`.

## 🗺️ Map Format (`.ber`)

- Must be **rectangular** and surrounded by **walls** (`1`)
- **Exactly one** player `P`, **at least one** exit `E`, **at least one** collectible `C`
- Allowed characters: `0` (floor), `1` (wall), `P`, `E`, `C` (plus any extras you explicitly support)

Example:
```
111111
1P0C01
100001
10C0E1
111111
```

## 📂 Project Structure

```
42-so_long/
├─ Libft/          # utility library
├─ mlx/            # MiniLibX (Linux/macOS X11)
├─ elements/       # sprite assets
├─ maps/           # sample .ber maps
├─ so_long.h       # headers
├─ *.c             # game, parsing, rendering, movement, utils
└─ Makefile
```

## 📖 Learning Outcomes

- Event loops and basic rendering with MiniLibX
- File I/O, validation, and error handling
- Working with 2D grids & path constraints
- Clean resource management (images, window, exit paths)
