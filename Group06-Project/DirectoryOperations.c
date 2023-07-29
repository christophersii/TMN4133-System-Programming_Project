// Function to create a directory with the given name and path
void create_directory(char *filename, char *path)
{
    char dir_path[1024];
    snprintf(dir_path, sizeof(dir_path), "%s/%s", path, filename);
    int status = mkdir(dir_path, 0777);
    if (status == 0) {
        printf("Successfully created directory %s\n", dir_path);
    }
    else {
        perror("Error creating directory\n");
    }
    // closedir(dir_path);
}

// Function to delete a directory with the given name and path
void delete_directory(char *filename, char *path)
{
    char dir_path[1024];
    snprintf(dir_path, sizeof(dir_path), "%s/%s", path, filename);
    int status = rmdir(dir_path);
    if (status == 0) {
        printf("Successfully deleted directory %s\n", dir_path);
    }
    else {
        perror("Error deleting directory\n");
    }
}

// Function to get the current working directory
void get_current_working_directory()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s \n", cwd);
    } else {
        perror("Error getting current working directory\n");
    }
}

// Function to list the files in the current directory
void list_current_directory()
{
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening current directory\n");
        return;
    }
    printf("List of Item in Current Directory:\n");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
