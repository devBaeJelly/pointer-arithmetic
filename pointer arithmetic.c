#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point3D
{
    float x;
    float y;
    float z;

};

int main()
{
    void* ptr = malloc(sizeof(struct Point3D) * 3);
    struct Point3D p[3];
    float result1, result2;

    for (int i = 0; i < sizeof(p) / sizeof(struct Point3D); i++)
    {
        scanf("%f %f %f", &p[i].x, &p[i].y, &p[i].z);
    }

    memcpy(ptr, p, sizeof(struct Point3D) * 3);
    memset(p, 0, sizeof(struct Point3D) * 3);

    result1 = ((struct Point3D*)ptr+1)->x;
    result2 = ((struct Point3D*)ptr+2)->z;

    printf("%.1f %.1f\n", result1, result2);

    free(ptr);

    return 0;
}