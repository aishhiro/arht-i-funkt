#include <stdio.h>

int main(int argc, char *argv[])
{
    
    if (argc < 2) {
        printf("enter file path\n");
        return 1;
    }
    char *path = argv[1];
    int data[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int i;
                       // создание файла и записывание
    FILE *f = fopen(path, "wb"); //  write binary
    if (f == NULL) {
        printf("error cant create file\n");
        return 1;
    }

    for (i = 0; i < 11; i++) {
        unsigned char b = data[i];
        fwrite(&b, 1, 1, f);
    }
    fclose(f);

     //  открытие и чтение
    f = fopen(path, "rb");
    if (f == NULL) {
        printf("cant enter to read file\n");
        return 1;
    }

    i = 0;
    while (1) {
        unsigned char b;
        int n = fread(&b, 1, 1, f);
        if (n != 1) {
            break; 
        }

        printf("byte[%d] = %d\n", i, b);

        // вывод состоянии полей file
        printf("   _flags    = %d\n", f->_flags);
        printf("   _fileno   = %d\n", f->_fileno);
        printf("   read_ptr  = %p\n", (void*)f->_IO_read_ptr);
        printf("   read_end  = %p\n", (void*)f->_IO_read_end);
        printf("   buf_base  = %p\n", (void*)f->_IO_buf_base);
        printf("   buf_end   = %p\n", (void*)f->_IO_buf_end);

        i++;
    }
    fclose(f);

    // сдвиг
    f = fopen(path, "rb");
    if (f == NULL) {
        printf("Не удалось открыть файл второй раз\n");
        return 1;
    }

    fseek(f, 3, SEEK_SET);

    unsigned char buf[4];    int got = fread(buf, 1, 4, f);

    printf("\nfread прочитал %d байт: ", got);
    for (i = 0; i < got; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");

    fclose(f);

    return 0;
}
