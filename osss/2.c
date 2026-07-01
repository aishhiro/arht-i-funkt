#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("need 2 files // from /where \n");
        return 1;
    }
    char *src = argv[1]; 
    char *dst = argv[2]; 

    FILE *in = fopen(src, "rb");
    if (in == NULL) {
        printf("cant open input file\n");
        return 1;
    }
    FILE *out = fopen(dst, "wb");
    if (out == NULL) {
        printf("cant open output file\n");
        fclose(in); 
        return 1;
    }

    while (1) {
        unsigned char b;
        int n = fread(&b, 1, 1, in);
        if (n != 1) {
            break;  //error кончились байты
        }
        fwrite(&b, 1, 1, out);
    }

    if (ferror(in)) {
        printf("error with read \n");
        fclose(in);
        fclose(out);
        return 1;
    }
    if (ferror(out)) {
        printf("error with write \n");
        fclose(in);
        fclose(out);
        return 1;
    }
    fclose(in);
    fclose(out);

    printf("copy complete\n");
    return 0;
}



/*
r  read — открыть для чтения (файл должен существовать) 
w  write — открыть для записи (создаёт новый файл или стирает старый) 
b binary — бинарный режим 
*/
