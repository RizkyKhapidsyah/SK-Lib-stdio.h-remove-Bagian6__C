#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    FILE* fp = fopen("file1.txt", "w"); // create file
    if (!fp) {
        perror("file1.txt"); 
        return 1; 
    }

    puts("Created file1.txt");
    fclose(fp);

    int rc = remove("file1.txt");
    if (rc) { 
        perror("remove"); 
        return 1; 
    }

    puts("Removed file1.txt");

    fp = fopen("file1.txt", "r"); // Failure: file does not exist
    if (!fp) {
        perror("Opening removed file failed");
    }

    rc = remove("file1.txt"); // Failure: file does not exist
    if (rc) {
        perror("Double-remove failed");
    }

    _getch();
    return 0;
}