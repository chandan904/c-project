# Simple Traffic System (student)

This is a tiny, beginner-friendly C project that simulates a simple traffic/penalty system using text files as storage.

Project layout
- `include/` : header files (`vehicle.h`, `violation.h`, `penalty.h`, `reports.h`)
- `src/` : source files (`main.c`, `vehicle.c`, `violation.c`, `penalty.c`, `reports.c`)
- Data files created at runtime: `vehicles.txt`, `violations.txt`

Build

Run this from the project root (`/home/chandan/workspace/c-projects`):

```bash
gcc src/*.c -Iinclude -o main
```

Run

Start the program:

```bash
./main
```
