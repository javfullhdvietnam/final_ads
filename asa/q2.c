#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector3D;

typedef struct {
    Vector3D* vectors;
    int size, capacity;
} Vector3DList;

Vector3DList* createList(int capacity) {
    Vector3DList* list = malloc(sizeof(Vector3DList));
    list->vectors = malloc(capacity * sizeof(Vector3D));
    list->size = 0;
    list->capacity = capacity;
    return list;
}

void addVector(Vector3DList* list, double x, double y, double z) {
    if (list->size < list->capacity) {
        list->vectors[list->size++] = (Vector3D){x, y, z};
    }
}

double dotProduct(Vector3D v1, Vector3D v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double magnitude(Vector3D v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

double cosineSimilarity(Vector3D v1, Vector3D v2) {
    double mag1 = magnitude(v1);
    double mag2 = magnitude(v2);
    if (mag1 == 0 || mag2 == 0) return 0;
    return dotProduct(v1, v2) / (mag1 * mag2);
}

void displayVectors(Vector3DList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("(%.2f, %.2f, %.2f)\n", list->vectors[i].x, list->vectors[i].y, list->vectors[i].z);
    }
}

void displayCosineSimilarityMatrix(Vector3DList* list) {
    int n = list->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double cosSim = cosineSimilarity(list->vectors[i], list->vectors[j]);
            printf("%.4f ", cosSim);
        }
        printf("\n");
    }
}

int main() {
    int capacity, n;
    scanf("%d %d", &capacity, &n);
    Vector3DList* list = createList(capacity);
    for (int i = 0; i < n; i++) {
        double x, y, z;
        scanf("%lf %lf %lf", &x, &y, &z);
        addVector(list, x, y, z);
    }
    displayVectors(list);
    displayCosineSimilarityMatrix(list);
    free(list->vectors);
    free(list);
    return 0;
}

