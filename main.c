#include <ctype.h>
#include <stdio.h>
#define MAX 128

//DECLARO ESTRUCTURA
typedef struct {
    char marca[MAX];
    char patente[MAX];
    char gama;
    char caja;
    int ano;
    float precio;
    bool disponivilidad;
}t_auto;

//DECLARO FUNCIONES
void bienvenida();
int menu();
int validarMenu();
void opcionElegida(int opcion);
void opcion1();
char valGama();
char valCaja();
float valPrecio();
bool valDisponivil();
void opcion2();
void opcion3();
void opcion4();
void opcion5();
void opcion6();


//EL MAIN
int main() {

    bienvenida();
    menu();

    return 0;
}

void bienvenida() {
    printf("Bienvenido al sistema\n");
    return;
}

//FUNCION PARA DESPEGLAR MENU Y ELEGIR OPCION
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

//FUNCION PARA VALIDAR LA OPCION ELEGIDA
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

//FUNCION PARA EJECUTAR LA OPCION ELEGIDA
void opcionElegida(int opcion) {

    switch(opcion) {

        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            opcion3();
            break;
        case 4:
            opcion4();
            break;
        case 5:
            opcion5();
            break;
        case 6:
            opcion6();
            break;
    }

    return;
}

//FUNCION PARA EJECUTAR LA OPCION 1
void opcion1() {

    t_auto temp;
    printf("Ingrese la marca de la unidad: ");
    fflush(stdin);
    gets(temp.marca);
    fflush(stdin);

    printf("Ingrese la patente de la unidad: ");
    fflush(stdin);
    gets(temp.patente);
    fflush(stdin);

    printf("Ingrese la GAMA de la unidad(B/M/A): ");
    temp.gama = valGama();

    printf("Ingrese la caja de la unidad(A/M): ");
    temp.caja = valCaja();

    printf("Ingrese el año de fabricacion: ");
    scanf("%d", &temp.ano);

    printf("Ingrese el precio de la unidad por dia: ");
    temp.precio = valPrecio();

    printf("La unidad se encuentra disponible?(S/N): ");
    temp.disponivilidad = valDisponivil();

    FILE *f = fopen("Autos.txt", "a");

    //LO DEL FINAL DEL PRINTF QUE DICE TRUE : FALSE, ES PARA QUE DEPENDIENDO EL VALOR DE LA VARIABLE BOOLEANA, SE ESCRIBA TRUE O FALSE EN EL ARCHIVO TXT
    //EN VEZ DE TRUE O FALSE SE PODRIA PONER CUALQUIER OTRA COSA, COMO DISPONIBLE O NO DISPONIBLE
    fprintf(f,"%s %s %c %c %d %f %s\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio, temp.disponivilidad ? "TRUE" : "FALSE");

    fclose(f);

    return;
}

//VALIDO LA GAMA INGRESADA EN OPCION1
char valGama() {

    char gama;

    fflush(stdin);
    gama = getchar();
    gama = toupper(gama);

    while (gama != 'B' && gama != 'M' && gama != 'A') {
        puts("Error, volver a ingresar: ");
        fflush(stdin);
        gama = getchar();
        gama = toupper(gama);
    }

    return gama;
}
//VALIDO LA CAJA INGRESADA EN OPCION1
char valCaja() {

    char caja;

    fflush(stdin);
    caja = getchar();
    caja = toupper(caja);

    while (caja != 'A' && caja != 'M') {
        puts("Error, volver a ingresar: ");
        fflush(stdin);
        caja = getchar();
        caja = toupper(caja);
    }

    return caja;
}

//VALIDO EL PRECIO INGRESADO EN OPCION1
float valPrecio() {

    float precio;

    scanf("%f", &precio);

    while (precio <= 0.0) {
        puts("Error, volver a ingresar: ");
        scanf("%f", &precio);
    }

    return precio;
}

//VALIDO LA DISPONOVILIDAD INGRESADA EN OPCION1
bool valDisponivil() {

    bool disponivil;
    char respuesta;

    fflush(stdin);
    respuesta = getchar();
    respuesta = toupper(respuesta);

    while (respuesta != 'N' && respuesta != 'S') {
        puts("Error, volver a ingresar: ");
        fflush(stdin);
        respuesta = getchar();
        respuesta = toupper(respuesta);
    }

    if (respuesta == 'N') {
        disponivil = false;
    }else {
        disponivil = true;
    }

    return disponivil;
}