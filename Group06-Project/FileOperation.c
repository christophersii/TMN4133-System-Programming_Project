// Function to create or open a new file
void createOrOpenFile(char *filename, char *path) {
    // Construct the full file path
    char filepath[256];
    sprintf(filepath, "%s/%s", path, filename);
    // Open the file in read/write mode, creating it if it doesn't exist
    int fd = open(filepath, O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("Error creating or opening file\n");
        exit(1);
    }
    else{
        printf("File has been created or opened successfully\n");
    }
    // Close the file descriptor
    close(fd);

}

// Function to change the permission of a file
void changePermission(char *filename, char *path, mode_t mode) {
    // Construct the full file path
    char filepath[256];
    sprintf(filepath, "%s/%s", path, filename);
    // Change the permission of the file
    int result = chmod(filepath, mode);
    if (result == -1) {
        perror("Error changing file permission\n");
        exit(1);
    }
    else{
        printf("File permission has been changed successfully\n");
    }
}

// Function to read from a file and print to standard output
void readAndPrintFile(char *filename, char *path) {
    // Construct the full file path
    char filepath[256];
    int result;
    sprintf(filepath, "%s/%s", path, filename);
    result= access(filename, F_OK);
    // Open the file in read mode
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading\n");
        exit(1);
    }
    else{
        printf("File has been opened successfully\n");
    }

    // Read from the file and print to standard output
    char c;
    while (read(fd, &c, 1) > 0) {
        printf("%c", c);
    }

    // Close the file descriptor
    close(fd);
}

// Function to remove or delete a file
void removeFile(char *filename, char *path) {
    // Construct the full file path
    char filepath[256];
    sprintf(filepath, "%s/%s", path, filename);
    // Remove the file
    int result = unlink(filepath);
    if (result == -1) {
        perror("Error deleting file\n");
        exit(1);
    }
    else{
        printf("File has been deleted successfully\n");
    }
}