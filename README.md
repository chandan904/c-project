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

Example non-interactive smoke test

You can run a scripted interaction to exercise basic flows. Below is an example showing how you might feed input into the program (you may need to adapt timings or inputs depending on prompts):

```bash
# Example (non-interactive) - adjust values if prompts differ
printf "1\n1\nKA01AB1234\nJohn Doe\nCar\n9999999999\n2\nKA01AB1234\nSpeeding\n2025-11-24\n3\n4\n1\n5\n0\n" | ./main
```

Notes for students
- The program stores records in plain text files. To reset state, remove `vehicles.txt` and `violations.txt`.
- The code uses simple file I/O and basic string parsing so it's easy to read and modify.
- If you make changes, recompile with the `gcc` command above.

Next ideas (optional)
- Add a simple `Makefile` to build and clean.
- Add inline comments to each function to explain what it does.
- Implement input validation improvements and more descriptive prompts.

If you want, I can also add a `Makefile`, comments in the sources, or run the automated smoke test now.