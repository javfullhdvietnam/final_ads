#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector3D;

typedef struct {
    Vector3D* vectors;
    int size;
    int capacity;
} Vector3DList;

Vector3DList* createList(int capacity) {
    Vector3DList* list = (Vector3DList*)malloc(sizeof(Vector3DList));
    list->vectors = (Vector3D*)malloc(capacity * sizeof(Vector3D));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addVector(Vector3DList* list, double x, double y, double z) {
    if (list->size < list->capacity) {
        list->vectors[list->size].x = x;
        list->vectors[list->size].y = y;
        list->vectors[list->size].z = z;
        list->size++;
    }
}

double calculateDistance(Vector3D v1, Vector3D v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

void displayVectors(Vector3DList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("(%.2f, %.2f, %.2f)\n", list->vectors[i].x, list->vectors[i].y, list->vectors[i].z);
    }
}

void displayDistanceMatrix(Vector3DList* list) {
    for (int i = 0; i < list->size; i++) {
        for (int j = 0; j < list->size; j++) {
            printf("%.2f ", calculateDistance(list->vectors[i], list->vectors[j]));
        }
        printf("\n");
    }
}

int main() {
    int capacity, n;
    scanf("%d", &capacity);
    Vector3DList* list = createList(capacity);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        double x, y, z;
        scanf("%lf %lf %lf", &x, &y, &z);
        addVector(list, x, y, z);
    }
    displayVectors(list);
    displayDistanceMatrix(list);
    free(list->vectors);
    free(list);
    return 0;
}
