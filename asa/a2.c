#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

typedef struct {
    Vector3D arr[MAX_SIZE];
    int size;
} Vector3DList;

double euclidean_distance(Vector3D v1, Vector3D v2) {
    double dx = v2.x - v1.x;
    double dy = v2.y - v1.y;
    double dz = v2.z - v1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void display(Vector3DList* list) {
    int n = list->size;
    printf("list of 3D vector:\n");
    for (int i = 0; i < n; i++) {
        printf("vector[%d] = (%.2f, %.2f, %.2f)\n",
               i,
               list->arr[i].x,
               list->arr[i].y,
               list->arr[i].z);
    }

    printf("\ndistance matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dist = euclidean_distance(list->arr[i], list->arr[j]);
            printf("%.2f ", dist);
        }
        printf("\n");
    }
}


int main() {
    Vector3DList list;
    
    list.size = 4;

    list.arr[0].x = 0.0;  list.arr[0].y = 0.0;  list.arr[0].z = 0.0;
    list.arr[1].x = 1.0;  list.arr[1].y = 2.0;  list.arr[1].z = 3.0;
    list.arr[2].x = -1.5; list.arr[2].y = 2.5;  list.arr[2].z = 0.0;
    list.arr[3].x = 3.0;  list.arr[3].y = 3.0;  list.arr[3].z = 3.0;

    display(&list);

    return 0;
}
