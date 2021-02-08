#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

int main()
{
    FILE *image;
    image = fopen("out.ppm", "a"); 
    fprintf(image, "P3 501 501 255\n");

    int i;
    int j;
    char n[] = "\n";
    for(i = 0; i < 501; i++)
    {
        for(j = 0; j < 501; j++)
        {
            double x = (double) (i - 250) / 250.0;
            double y = (double) (j - 250) / 250.0;

            int r = fmod(floor(128 * (fabs(sin(50 * x) + sin(50 * y)))), 256);
            int g = fmod(floor(128 * (fabs(cos(50 * x) + sin(50 * y)))), 256);
            int b = fmod(floor(128 * (fabs(sin(50 * x) + cos(50 * y)))), 256);
            // 0 - 255
            fprintf(image, "%d %d %d ", r, g, b);

        } 
        fprintf(image, "\n");
    }

    fclose(image);
    return 0;




}
