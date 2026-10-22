# Operating Systems Lab 2 Report

## 1. Linux Navigation and Paths

In this lab, I practised navigating the Linux file system using absolute and relative paths.

An absolute path starts from the root directory `/` and identifies a location independently of the current directory. A relative path starts from the current directory.

The command `pwd` displays the current working directory, and `cd` changes directories. The special path `..` refers to the parent directory, while `.` refers to the current directory.

## 2. Creating and Managing Directories

I created the TechCorp department directories for Legal, Engineering, and Marketing. I also created an `archive` directory inside Legal.

The command `mkdir -p` creates directories, including any required parent directories.

## 3. Moving and Copying Files

I moved `cash flow.txt` and `vendor list.txt` from `incoming/` to `reports/`.

The `mv` command moves files from one location to another. The `cp` command creates copies while preserving the original files.

I copied both reports into `TechCorp/Legal/` and copied the first report to `TechCorp/Legal/archive/first-original.txt`.

I used `cmp` to compare the original reports with their copies. No output from `cmp` indicated that the compared files were identical.

## 4. Understanding Path Errors

I intentionally attempted to read a report using an incorrect relative path from the Engineering directory. The command returned a "No such file or directory" error because the path was interpreted relative to the current directory.

I corrected the path by moving up two directory levels with `..` and then entering `reports/`.

This demonstrated that a relative path depends on the current working directory, whereas an absolute path starts from `/`.

## 5. Evidence and Checkpoint

The `evidence/paths.txt` file records the paths, commands, and path-error correction required by the lab.

The `evidence/tree.txt` file records the resulting file listing. The `evidence/checkpoint.txt` file contains the output read from the checkpoint's target file.

The final `oslab check lab2` result showed that all six milestones passed.

## Conclusion

This lab helped me practise Linux navigation, directory creation, moving and copying files, comparing file contents, and diagnosing path errors. I also learned how to document my work and verify the result using the provided lab checker.
