#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
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
int valAno();
float valPrecio();
bool valDisponivil();
//FUNCIONES OPCION 2
void opcion2();
//FUNCIONES OPCION 3
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
//FUNCIONES OPCION 5
void opcion5();
void writedisponibles();
void writenodisponibles();
//FUNCIONES OPCION 6
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
        printf("2. Listar todas las unidades registradas\n");
        printf("3. Listar solo las unidades disponibles\n");
        printf("4. Busqueda de unidad por algun campo a eleccion\n");
        printf("5. Dividir las unidades disponibles y no disponibles en dos archivos nuevos\n");
        printf("6. SALIR DEL SISTEMA\n");
        printf("\nINGRESAR UNA OPCION: ");
        opcion = validarMenu();

        opcionElegida(opcion);
    }
    return opcion;

}

//FUNCION PARA VALIDAR LA OPCION ELEGIDA
int validarMenu() {

    int numero;

    scanf("%d", &numero);

    fflush(stdin);

    while (numero != 1 && numero != 2 && numero != 3 && numero != 4 && numero != 5 && numero != 6) {

        puts("Error, volver a ingresar\n");
        printf("Ingresar opcion: ");
        scanf("%d", &numero);
        fflush(stdin);

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

    system("cls");
    t_auto temp;

    printf("Ingrese la marca de la unidad: ");
    fflush(stdin);
    gets(temp.marca);
    fflush(stdin);
    mayusculas(temp.marca);

    printf("Ingrese la patente de la unidad: ");
    fflush(stdin);
    gets(temp.patente);
    fflush(stdin);
    mayusculas(temp.patente);

    printf("Ingrese la GAMA de la unidad(B/M/A): ");
    temp.gama = valGama();

    printf("Ingrese la caja de la unidad(A/M): ");
    temp.caja = valCaja();

    printf("Ingrese cuando fue producido(MAYOR A 1925): ");
    temp.ano = valAno();

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

    system("cls");
    printf("Auto registrado con exito!\n");

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

//VALIDO EL AÑO DEL VEHICULO
int valAno() {

    int ano;

    scanf("%d", &ano);
    fflush(stdin);

    while (ano < 1925) {
        puts("Error, volver a ingresar: ");
        scanf("%d", &ano);
        fflush(stdin);
    }

    return ano;
}

//VALIDO EL PRECIO INGRESADO EN OPCION1
float valPrecio() {

    float precio;

    scanf("%f", &precio);
    fflush(stdin);

    while (precio <= 0.0) {

        puts("Error, volver a ingresar: ");
        scanf("%f", &precio);
        fflush(stdin);
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


//INICIO DE FUNCIONES PARA OPCION 2

void opcion2() {

    system("cls");
    int booleano, autos = 0;
    t_auto temp;

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("\nLISTADO DE TODAS LAS UNIDADES\n\n");
        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");

        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano) == 7; i++) {

            if (booleano == 1) {
                printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
            }else if (booleano == 0) {
                printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
            }

            autos++;
        }

        fclose(f);
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

//FIN DE FUNCIONES PARA OPCION 2

//INICIO DE FUNCIONES PARA OPCION 3
void opcion3() {

    system("cls");
    int booleano, autos = 0, cantidad = 0;
    t_auto temp;

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("\nLISTADO DE UNIDADES DISPONIBLES\n\n");
        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");

        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano) == 7; i++) {

            if (booleano == 1) {
                printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                cantidad++;
            }

            autos++;
        }

        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos disponibles\n");
    }

    printf("Se analizaron %d autos\n", autos);

    return;
}

//FIN DE FUNCIONES PARA OPCION 3


//INICIO DE FUNCIONES PARA OPCION 4

void opcion4() {

    system("cls");
    minimenu();

    return;
}

//DESPLEGAR MENU
void minimenu() {

    system("cls");
    int opcion;

    printf("\n1: Buscar por MARCA\n");
    printf("2: Buscar por PATENTE\n");
    printf("3: Buscar por GAMA\n");
    printf("4: Buscar por CAJA\n");
    printf("5: Buscar por cuando fue PRODUCIDO\n");
    printf("6: Buscar por PRECIO\n");
    printf("7: Buscar por DISPONIVILIDAD\n");
    printf("OPCION ELEGIDA: ");
    opcion = validarOpcion();

    campoElegido(opcion);

    return;
}

//VALIDAR OPCION DE MENU
int validarOpcion() {

    int opcion;

    scanf("%d", &opcion);
    fflush(stdin);
    while (opcion < 1 || opcion > 7) {

        puts("Error, volver a ingresar: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    return opcion;
}

//REDIRECCIONAR A LA OPCION DE BUSQUEDA ELEGIDA
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


//FUNCION PARA CADA CAMPO DE BUSQUEDA
void campo1() {

    system("cls");
    char marca[MAX];
    int cantidad = 0, booleano, autos = 0;
    t_auto temp;

    printf("Ingresa una marca de autos: ");
    fflush(stdin);
    gets(marca);
    fflush(stdin);
    mayusculas(marca);

    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (strcmp(temp.marca, marca) == 0) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
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

    printf("\nSe analizaron %d autos\n", autos);

    return;

}

void campo2() {

    system("cls");
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

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (strcmp(temp.patente, patente) == 0) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }

        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos con esa PATENTE\n");
    }

    printf("\nSe analizaron %d autos\n", autos);

    return;
}

void campo3() {

    system("cls");
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

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.gama == gama) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
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

    printf("\nSe analizaron %d autos\n", autos);

    return;
}

void campo4() {

    system("cls");
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

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.caja == caja) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
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

    printf("\nSe analizaron %d autos\n", autos);

    return;
}

void campo5() {

    system("cls");
    int ano, cantidad = 0, autos=0, booleano;
    t_auto temp;

    printf("Ingresar cuando fue producido el vehiculo: ");
    scanf("%d", &ano);


    FILE *f = fopen("Autos.txt", "r");

    if (f == NULL) {
        puts("Error al abrir el archivo\n");
    }else {
        printf("Buscando autos...\n\n");

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.ano == ano) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }
                cantidad++;
            }
            autos++;
        }

        fclose(f);
    }

    if (cantidad == 0) {
        printf("No se encontraron autos en ese tiempo\n");
    }

    printf("\nSe analizaron %d autos\n", autos);

    return;
}

void campo6() {

    system("cls");
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

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (temp.precio == precio) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                }else if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
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

    printf("\nSe analizaron %d autos\n", autos);

    return;
}

void campo7() {

    system("cls");
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

        printf("%-15s %-10s %-6s %-6s %-12s %-12s %s\n", "MARCA", "PATENTE", "GAMA", "CAJA", "PRODUCIDO", "PRECIO", "DISPONIBILIDAD");
        for (int i = 0; fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {

            if (disponivilidad == true) {
                if (booleano == 1) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
                    cantidad++;
                }
            }else {
                if (booleano == 0) {
                    printf("%-15s %-10s %-6c %-6c %-12d %-12.1f NO DISPONIBLE\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio);
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

    printf("\nSe analizaron %d autos\n", autos);

    return;

}

//OPCION PARA PASAR A MAYUSCULAS A CUALQUIER STRING
void mayusculas(char string[]) {

    for (int i = 0; i < strlen(string); i++) {
        string[i] = toupper(string[i]);
    }

}
//FIN DE OPCION 4

//INICION DE OPCION 5

void opcion5() {

    system("cls");
    writedisponibles();
    writenodisponibles();

    printf("Archivos creados con exito!\n");

    return;
}

//ESCRIBIR EN ARCHIVO DE DISPONIBLES
void writedisponibles() {

    t_auto temp;
    int booleano;

    FILE *f = fopen("Autos.txt", "r");
    FILE *j = fopen("DISPONIBLES.txt", "w");

    if (f == NULL) {
        puts("Error al abrir el archivo Autos.txt\n");
    }else {
        if (j == NULL) {
            puts("Error al abrir el archivo DISPONIBLES.txt\n");
        }else {
            for (int i = 0;fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {
                if (booleano == 1) {
                    fprintf(j,"%s %s %c %c %d %f %d\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio, booleano);
                }
            }
        }
    }

    fclose(f);
    fclose(j);

    return;
}

//ESCRIBIR EN ARCHIVO DE NO DISPONIBLES
void writenodisponibles() {

    t_auto temp;
    int booleano;

    FILE *f = fopen("Autos.txt", "r");
    FILE *j = fopen("NO_DISPONIBLES.txt", "w");

        if (f == NULL) {
            puts("Error al abrir el archivo Autos.txt\n");
        }else {
            if (j == NULL) {
                puts("Error al abrir el archivo NO_DISPONIBLES.txt\n");
            }else {
                for (int i = 0;fscanf(f, "%s %s %c %c %d %f %d", temp.marca, temp.patente, &temp.gama, &temp.caja, &temp.ano, &temp.precio, &booleano ) == 7; i++) {
                    if (booleano == 0) {
                        fprintf(j,"%s %s %c %c %d %f %d\n", temp.marca, temp.patente, temp.gama, temp.caja, temp.ano, temp.precio, booleano);
                    }
                }
            }
        }

    fclose(f);
    fclose(j);

    return;
}

//OPCION 6
void opcion6() {

    system("cls");
    printf("\nFin de Programa\n");

    return;
}
