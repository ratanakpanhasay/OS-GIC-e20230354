
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    const char *text = "Hello from Operating Systems class!\n";
    const char *msg = "File created successfully!\n";

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, text, strlen(text)) == -1) {
        perror("Error writing file");
        close(fd);
        return 1;
    }

    close(fd);

    write(1, msg, strlen(msg));

    return 0;
}
