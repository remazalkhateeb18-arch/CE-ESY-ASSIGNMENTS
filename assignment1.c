#include <stdio.h>
#include <string.h>

#define SIZE 5

struct cb {
    char arr[SIZE];
    int h;
    int t;
    int c;
};

void init(struct cb *x) {
    x->h = 0;
    x->t = 0;
    x->c = 0;
}

int full(struct cb *x) {
    return x->c == SIZE;
}

int empty(struct cb *x) {
    return x->c == 0;
}

void write(struct cb *x, char d) {
    if (full(x)) {
        printf("overflow\n");
        return;
    }

    x->arr[x->t] = d;
    x->t = (x->t + 1) % SIZE;
    x->c++;
}

char read(struct cb *x) {
    if (empty(x)) {
        printf("underflow\n");
        return '\0';
    }

    char d = x->arr[x->h];
    x->h = (x->h + 1) % SIZE;
    x->c--;
    return d;
}

int main() {
    struct cb x;
    init(&x);

    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    int i = 0;
    while (name[i] != '\0') {
        write(&x, name[i]);
        i++;
    }

    printf("Result: ");
    while (!empty(&x)) {
        printf("%c", read(&x));
    }

    if (empty(&x)) {
        printf("\nBuffer is empty\n");
    }

    read(&x);

    return 0;
}
