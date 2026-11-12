
# Lab 4 — Redirection and Pipelines

## 1. Objective

- Understand stdin, stdout, and stderr.
- Practice output redirection using >, >>, and 2>.
- Use pipelines to filter, extract, and count CSV records.
- Test exact matching, changed inputs, and missing files.

## 2. Environment

- Operating System: Linux
- Server: i4gic-os
- Workspace: ~/oslab-work/lab4
- Tools: Bash, grep, cut, wc, tee, cat, diff

## 3. Core 1 — Select, Extract, and Count

Personal values:
- Status: clear
- Other: shipped

Commands:

```bash
grep '^clear,' data/events.csv | tee evidence/selected.txt
grep '^clear,' data/events.csv | cut -d, -f2 | tee evidence/fields.txt
grep '^clear,' data/events.csv | wc -l > evidence/normal.txt
```

Results:
- Matching records: 3
- Extracted quantities: 9, 3, 4

The pattern `^clear,` matches only records beginning with `clear,`. It excludes `clear-late,55`.

## 4. Core 2 — Changed and Missing Inputs

No-match test:
- Matching records: 0

Changed-input test:
- Matching records: 4

The changed input added one matching record. The `clear-late` record was excluded.

Missing-file test:
- stdout.txt: Empty
- stderr.txt: Contains the missing-file diagnostic
- status.txt: 1

This demonstrates that normal output and error messages use separate streams.

## 5. Pipeline Exit Status

Command:

```bash
cat data/missing.csv | wc -l
echo $?
```

Results:
- wc -l printed 0.
- Pipeline exit status was 0.

The pipeline reported success because its final command, `wc -l`, succeeded even though `cat` failed.

## 6. Checkpoint

Checkpoint file: data/forest.csv

Selected records:
- clear,8
- clear,11

Matching record count: 2

The checkpoint evidence was saved in:
- evidence/checkpoint-selected.txt
- checkpoint.txt

## 7. Conclusion

In this lab, I learned how to redirect normal output and error messages, connect commands using pipelines, and process CSV records using grep, cut, and wc.

I also learned that exact matching is important and that a pipeline can return exit status 0 even when an earlier command fails.

Final verification: 5/5 milestones passed.
