#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
//FUNCIONES MENU
int menu();
int validarMenu();
void opcionElegida(int opcion);
//FUNCIONES OPCION 1
void opcion1();
char valGama();
char valCaja();
float valPrecio();
bool valDisponivil();

void opcion2();
void opcion3();
//FUNCIONES PARA OPCION 4
void opcion4();
void minimenu();
int validarOpcion();
void campoElegido(int opcion);
void campo1();
void campo2();
void campo3();
void campo4();
void campo5();
void campo6();
void campo7();
void mayusculas(char string[]);



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

//INICIO DE FUNCIONES PARA OPCION 1
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

    if (f == NULL) {
        puts("Error al abrir el archivo");
    }else {
        fprintf(f,"%s %s %c %c %d %f %d\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio, temp.disponivilidad);
    }


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
//FIN DE FUNCIONES PARA OPCION 1

//ACA PONER TOD0 LO QUE TENGA QUE VER CON OPCION 2, Y DESPUES TOD0 LO QUE TENGA QUE VER CON LA OPCION 3



//INICIO DE FUNCIONES PARA OPCION 4
void opcion4() {

    minimenu();

    return;
}

void minimenu() {

    int opcion;

    printf("\n1: Buscar por MARCA\n");
    printf("2: Buscar por PATENTE\n");
    printf("3: Buscar por GAMA\n");
    printf("4: Buscar por CAJA\n");
    printf("5: Buscar por AÑO\n");
    printf("6: Buscar por PRECIO\n");
    printf("7: Buscar por DISPONIVILIDAD\n");
    printf("OPCION ELEGIDA: ");
    opcion = validarOpcion();

    campoElegido(opcion);

    return;
}

int validarOpcion() {

    int opcion;

    scanf("%d", &opcion);
    while (opcion < 1 || opcion > 7) {
        puts("Error, volver a ingresar: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

void campoElegido(int opcion){

    switch (opcion) {
        case 1:
            campo1();
            break;
        case 2:
            campo2();
            break;
        case 3:
            campo3();
            break;
        case 4:
            campo4();
            break;
        case 5:
            campo5();
            break;
        case 6:
            campo6();
            break;
        case 7:
            campo7();
            break;
    }

    return;
}

void campo1() {

    char marca[MAX];
    int cantidad = 0, booleano, autos = 0;

    printf("Ingresa una marca de autos: ");
    fflush(stdin);
    gets(marca);
    fflush(stdin);
    mayusculas(marca);

    t_auto temp;
    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (strcmp(temp.marca, marca) == 0) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos con esa MARCA\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo2() {

    char patente[MAX];
    int booleano, cantidad = 0, autos = 0;

    printf("Ingresa una patente: ");
    fflush(stdin);
    gets(patente);
    fflush(stdin);
    mayusculas(patente);

    t_auto temp;
    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (strcmp(temp.patente, patente) == 0) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }

        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos con esa PATENTE\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo3() {

    char gama;
    int booleano, cantidad = 0, autos=0;
    t_auto temp;

    printf("Ingresa una gama(B/M/A): ");
    fflush(stdin);
    gama = valGama();

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.gama == gama) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (temp.gama == gama) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos de esa GAMA\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo4() {

    char caja;
    int booleano, cantidad = 0, autos=0;
    t_auto temp;

    printf("Ingresar el tipo de CAJA(A/M): ");
    caja = valCaja();

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.caja == caja) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos con ese tipo de CAJA\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo5() {

    int ano, cantidad = 0, autos=0, booleano;
    t_auto temp;
    printf("Ingresar el AÑO del vehiculo: ");
    scanf("%d", &ano);

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.ano == ano) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos de ese AÑO\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo6() {

    float precio;
    int autos = 0, cantidad = 0, booleano;
    t_auto temp;

    printf("Ingresar el precio del auto: ");
    precio = valPrecio();

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.precio == precio) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }
        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos con ese PRECIO\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

void campo7() {

    int cantidad = 0, autos=0, booleano;
    bool disponivilidad;
    t_auto temp;
    printf("Ingresar DISPONIVILIDAD(S/N): ");
    disponivilidad = valDisponivil();

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (disponivilidad == true) {
                if (booleano == 1) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tDISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                    cantidad++;
                }
            }else {
                if (booleano == 0) {
                    printf("%-15s%-10s\t%c\t%c\t%d\t%f\tNO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                    cantidad++;
                }
            }
            autos++;
        }
        fclose(f);
    }

   if (cantidad == 0) {
       printf("No Se encontraron autos\n");
   }

    printf("Se analizaron %d autos\n", autos);

    return;
}


void mayusculas(char string[]) {

    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }

}
//FIN DE OPCION 4



//ROMAN ACORDATE DE SI VAS A CODEAR LAS OPCIONES 2 Y 3, ESCRIBI
//TODOS LAS FUNCIONES QUE TENGAN QUE VER CON ESAS DOS ARRIBA DE LAS FUNCIONES DE LA 4
//ASI LAS FUNCIONES ESTAN EN ORDEN Y NO QUEDAN DESORDENADAS