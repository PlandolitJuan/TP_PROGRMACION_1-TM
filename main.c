#include <stdio.h>
#define MAX 128

typedef struct {
    char marca[MAX];
    char patente[MAX];
    char gama;
    char caja;
    int ano;
    float precio;
    bool disponivilidad;
};
void bienvenida();
int menu();
int validarMenu();
void opcionElegida(int opcion);
void opcion1();
void opcion2();
void opcion3();
void opcion4();
void opcion5();
void opcion6();



int main() {

    bienvenida();
    menu();

    return 0;
}

void bienvenida() {

    printf("Bienvenido al sistema\n");

    return;
}


int menu() {

    int opcion = 0;

    while (opcion != 6) {

        printf("\n1. Registrar una unidad\n");
        printf("2. Listar todas las unidades registrados\n");
        printf("3.Listar solo las unidades disponibles\n");
        printf("4. Busqueda de unidad por algun campo\n");
        printf("5. Dividir las unidades disponibles y no disponibles en dos archivos nuevo\n");
        printf("6. SALIR DEL SISTEMA\n");
        printf("INGRESAR UNA OPCION: ");
        opcion = validarMenu();

        opcionElegida(opcion);
    }

    return opcion;
}

int validarMenu() {

    int numero;

    scanf("%d", &numero);

    while (numero != 1 && numero != 2 && numero != 3 && numero != 4 && numero != 5 && numero != 6) {
        puts("Error, volver a ingresar\n");
        printf("Ingresar opcion: ");
        scanf("%d", &numero);
    }

    return numero;
}

void opcionElegida(int opcion) {

    if (opcion == 1) {
        opcion1();
    }else if (opcion == 2) {
        opcion2();
    }else if (opcion == 3) {
        opcion3();
    }else if (opcion == 4) {
        opcion4();
    }else if (opcion == 5) {
        opcion5();
    }else if (opcion == 6) {
        opcion6();
    }
    
    return;
}