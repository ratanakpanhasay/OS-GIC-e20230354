
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[256];

    int fd = open("output.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        ssize_t totalWritten = 0;

        while (totalWritten < bytesRead) {
            ssize_t n = write(
                1,
                buffer + totalWritten,
                bytesRead - totalWritten
            );

            if (n <= 0) {
                perror("Error writing to terminal");
                close(fd);
                return 1;
            }

            totalWritten += n;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
