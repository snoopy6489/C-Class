#include<stdio.h>
#include<conio.h>
#pragma warning(disable : 4996)

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int numVertices;
    Point vertices[100];
    int linecolor;
    int fillcolor;
} Shape;
int numShapes = 0;
Shape Shapes[30];
void MovePoint(Point* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

void MoveShape(Shape* s, int dx, int dy) {
    int i;
    for (i = 0; i < s->numVertices; i++) {
        MovePoint(&s->vertices[i], dx, dy);
    }
}

void PrintPoint(Point p) {
    printf("(%d, %d)", p.x, p.y);
}

void printShape(Shape s) {
    int i;
    printf("Shape with %d vertices:\n", s.numVertices);
    for (i = 0; i < s.numVertices; i++) {
        PrintPoint(s.vertices[i]);
        printf("\n");
    }
}
void scanf_sShape(Shape* s) {
    int i;
    printf("Enter number of vertices: ");
    scanf_s("%d", &s->numVertices);
    for (i = 0; i < s->numVertices; i++) {
        printf("Enter vertex %d: ", i + 1);
        scanf_s("%d %d", &s->vertices[i].x, &s->vertices[i].y);
    }
}
void UpdateShape(Shape* s, int numVertices, Point vertices[]) {
    int i;
    s->numVertices = numVertices;
    for (i = 0; i < numVertices; i++) {
        s->vertices[i] = vertices[i];
    }
}

void AddShape(Shape s) {
    Shapes[numShapes] = s;
    numShapes++;
}

void SaveShapestoFile() {
    FILE* fp;
    int i, j;
    fopen_s(&fp, "shapes.txt", "w");
    fprintf(fp, "%d\n", numShapes);
    for (i = 0; i < numShapes; i++) {
        fprintf(fp, "%d\n", Shapes[i].numVertices);
        for (j = 0; j < Shapes[i].numVertices; j++) {
            fprintf(fp, "%d %d\n", Shapes[i].vertices[j].x, Shapes[i].vertices[j].y);
        }
    }
    fclose(fp);
}

void LoadShapesFromFile() {
    FILE* fp;
    int i, j;
    fopen_s(&fp, "shapes.txt", "r");
    fscanf_s(fp, "%d\n", &numShapes);
    for (i = 0; i < numShapes; i++) {
        fscanf_s(fp, "%d\n", &Shapes[i].numVertices);
        for (j = 0; j < Shapes[i].numVertices; j++) {
            fscanf_s(fp, "%d %d\n", &Shapes[i].vertices[j].x, &Shapes[i].vertices[j].y);
        }
    }
    fclose(fp);
}
void RemoveShape(int index) {
    int i;
    for (i = index; i < numShapes - 1; i++) {
        Shapes[i] = Shapes[i + 1];
    }
    numShapes--;
}
void PrintMenu()
{
    printf("1. Add a new shape\n");
    printf("2. Update a shape\n");
    printf("3. Remove a shape\n");
    printf("4. Print all shapes\n");
    printf("5. Save shapes to file\n");
    printf("6. Load shapes from file\n");
    printf("q. Exit\n");
    printf("Enter your choice: ");
}

void main()
{
    char choice;
    int index;
    Shape s;
    Point vertices[100];
    int numVertices;
    while (1) {
        PrintMenu();
        choice = getch();
        switch (choice) {
        case '1':
            scanf_sShape(&s);
            AddShape(s);
            break;
        case '2':
            printf("Enter index of shape to update: ");
            scanf_s("%d", &index);
            scanf_sShape(&s);
            UpdateShape(&Shapes[index], s.numVertices, s.vertices);
            break;
        case '3':
            printf("Enter index of shape to remove: ");
            scanf_s("%d", &index);
            RemoveShape(index);
            break;
        case '4':
            for (index = 0; index < numShapes; index++) {
                printShape(Shapes[index]);
            }
            break;
        case '5':
            SaveShapestoFile();
            break;
        case '6':
            LoadShapesFromFile();
            break;
        case 'q':
        case 'Q':

            return;
        }
    }
}