#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BUFFER_SIZE 256
#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *inptr = fopen(argv[1], "r"); // Read the file
    BYTE buffer[BUFFER_SIZE]; // Create an array of bytes

    int imageCount = 0;
    char *outfile = malloc(8);
    bool foundJPEG = true;

    while(true)
    {
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // Compare the first 4 bytes of the buffer to those of a JPEG
        {
            if(outfile == NULL)
            {
                // create file
                outfile = sprintf("00%c.jpg", imageCount);
                FILE *img = fopen(outfile, "w");

                // write to file
                fwrite(buffer, sizeof(BYTE), bytesRead, outfile);
            }
            else
            {
                fclose(outfile);
                // create file
                // write to file
            }
        }
        else
        {
            if(foundJPEG)
            {
                // countiue to write

            }
            else
            {
                fclose(outfile);
                // write to file
            }
        }

    }

}
