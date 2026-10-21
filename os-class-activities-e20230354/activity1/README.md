# Operating Systems Class Activity 1

## Task 3: System Call Tracing

### Objective

The objective of this task is to use `strace` to observe and compare the system calls made by library functions and POSIX system calls when creating and reading files.

### 1. File Creator

I traced two programs using `strace`:

- `file_creator_lib`: uses library functions such as `fopen()`, `fprintf()`, and `fclose()`.
- `file_creator_sys`: uses POSIX system calls such as `open()`, `write()`, and `close()`.

Both programs successfully created `output.txt`, wrote the required message into the file, and displayed the confirmation message in the terminal.

### 2. File Reader

I also traced both file reader programs.

- `file_reader_lib` uses `fopen()`, `fgets()`, `printf()`, and `fclose()`.
- `file_reader_sys` uses `open()`, `read()`, `write()`, and `close()`.

Both programs successfully read and displayed the contents of `output.txt`.

### 3. System Call Comparison

The results from `strace -c` were:

| Program | Total system calls |
|---|---:|
| Library file creator | 38 |
| POSIX system-call file creator | 34 |

The POSIX system-call version made four fewer system calls in this experiment. These totals include program startup and runtime activity, not just file operations.

### 4. Important System Calls

- `openat()`: Opens or creates a file.
- `read()`: Reads data from a file.
- `write()`: Writes data to a file or displays data in the terminal.
- `close()`: Closes an open file descriptor.
- `mmap()`: Maps memory into a process's address space.
- `fstat()`: Retrieves information about a file.

### 5. What I Learned

Library functions make file operations easier to write and use. They handle some details internally and use operating-system services to perform input and output.

POSIX system calls give the programmer more direct control over file operations. However, the program must handle details such as file descriptors and error checking.

The `strace` tool helped me observe the system calls made by each program and compare their behavior.

### Conclusion

Both implementations successfully performed the required file operations. This activity helped me understand the relationship between library functions, POSIX system calls, and the operating system.
