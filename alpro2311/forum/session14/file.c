#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("File tidak dapat dibuka...\n");
        return 1;
    }

    printf("NIM\tNAMA\t\tIPK\n");
    
    char line[100]; 
    while (fgets(line, sizeof(line), file) != NULL) {
        unsigned int nim;
        char nama[50];
        float ipk;
        
        
        sscanf(line, "%u %49[^\t] %f", &nim, nama, &ipk);
        
        printf("%u\t%s\t%.2f\n", nim, nama, ipk);
    }

    fclose(file);

    return 0;
}
