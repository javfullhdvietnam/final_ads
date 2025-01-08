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

double cosineSimilarity(Vector3D v1, Vector3D v2) {
    double dot = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

    double mag1 = sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));

    double mag2 = sqrt((v2.x * v2.x) + (v2.y * v2.y) + (v2.z * v2.z));

    if (mag1 == 0.0 || mag2 == 0.0) {
        return 0.0;
    }

    return dot / (mag1 * mag2);
}

void displayVectorsAndDistanceMatrix(const Vector3DList* list) {
    int n = list->size;

    printf("List of 3D Vectors (size = %d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Vector[%d] = (%.2f, %.2f, %.2f)\n",
               i,
               list->arr[i].x,
               list->arr[i].y,
               list->arr[i].z);
    }

    printf("\nCosine Similarity Matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sim = cosineSimilarity(list->arr[i], list->arr[j]);
            printf("%.4f ", sim);
        }
        printf("\n");
    }
}

int main() {
    Vector3DList list;
    list.size = 0;

    int n;
    printf("Enter the number of 3D vectors: ");
    scanf("%d", &n);


    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid input for number of vectors!\n");
        return 1;
    }

    list.size = n;
    for (int i = 0; i < n; i++) {
        printf("Enter x, y, z for vector %d: ", i);
        scanf("%lf %lf %lf",
              &list.arr[i].x,
              &list.arr[i].y,
              &list.arr[i].z);
    }

    displayVectorsAndDistanceMatrix(&list);

    return 0;
}
