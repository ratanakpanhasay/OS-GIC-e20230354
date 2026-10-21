# Task 3: System Call Tracing

## 1. Objective

The objective of this task is to observe and compare the system calls made by library-based and system-call-based file creator and reader programs using `strace`.

## 2. Commands Used

The following commands were used to trace the programs:

- `strace -e trace=openat,read,write,close`: Displays the selected system calls.
- `strace -c`: Summarizes system-call statistics, including the number of calls and errors.
- `grep "total"`: Extracts the total statistics from the summary files.

The trace outputs were saved in text files for later analysis.

## 3. Results

For the file creator programs, the recorded summaries showed:

| Implementation | Total system-call attempts | Errors |
|---|---:|---:|
| Library version | 38 | 1 |
| System-call version | 34 | 1 |

Both programs successfully created `output.txt` and displayed the confirmation message.

## 4. Analysis

The library-based version uses functions such as `fopen()`, `fprintf()`, and `fclose()`. These library functions handle file operations and may invoke underlying operating-system system calls.

The system-call version uses operations such as `open()`, `write()`, and `close()` more directly.

The observed difference in system-call counts shows that the two implementations can interact with the operating system differently while accomplishing the same task. The single recorded error in each summary should be investigated in the detailed trace before attributing it to a particular operation.

The execution times were extremely small, so the results from one run are insufficient to determine which implementation is faster.

## 5. Conclusion

Using `strace` helped me observe how programs interact with the operating system through system calls. It also demonstrated how library functions and direct system-call operations can produce different system-call patterns for similar file operations.
