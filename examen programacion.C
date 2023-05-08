#include <stdio.h>
#include <string.h>

// Sebastian Potosi

// Función para calcular el precio por kilómetro según el tipo de ruta
float calcularPrecioRuta(char tipoRuta) {
    switch (tipoRuta) {
        case 'U':
            return 0.10;
        case 'I':
            return 0.15;
        case 'N':
            return 0.20;
        default:
            return 0.0;
    }
}

// Función para calcular el descuento según el rango de distancia
float calcularDescuento(float costoTotal) {
    if (costoTotal < 50.0) {
        return 0.0;
    } else if (costoTotal >= 50.0 && costoTotal < 100.0) {
        return costoTotal * 0.05;
    } else if (costoTotal >= 100.0 && costoTotal < 500.0) {
        return costoTotal * 0.1;
    } else {
        return costoTotal * 0.2;
    }
}

// Función para realizar la operación de transporte
void operacionTransporte() {
    printf("Operacion de transporte\n");

    for (int i = 1; i <= 5; i++) {  //Se usa la funcion "For" para el incremento de clientes hasta el limite 5
        printf("Cliente %d\n", i);

        char tipoRuta;
        float distancia;

        printf("Ingrese el tipo de ruta (Urbana [U], Interurbana [I], Internacional [N]): ");
        scanf(" %c", &tipoRuta);

        printf("Ingrese la distancia en kilometros: ");
        scanf("%f", &distancia);

        float precioKm = calcularPrecioRuta(tipoRuta);
        float costoTotal = precioKm * distancia;
        float descuento = calcularDescuento(costoTotal);
        float subtotal = costoTotal - descuento;

        printf("Subtotal: %.2f\n", subtotal);
        printf("Descuento: %.2f\n", descuento);
        printf("Precio total: %.2f\n", subtotal + descuento);

        printf("\n");
    }
}

// Función para interactuar en la red social
void redSocial() {
    printf("Interactuar en la red social\n");

    int noticias = 0;
    int eventos = 0;
    int preguntas = 0;

    for (int i = 1; i <= 5; i++) {
        printf("Mensaje %d\n", i);

        char contenido[100];
        char categoria;

        printf("Ingrese el contenido del mensaje: ");
        scanf(" %[^\n]", contenido);

        printf("Ingrese la categoría (Noticias [N], Eventos [E], Preguntas [P]): ");
        scanf(" %c", &categoria);

        switch (categoria) {
            case 'N':
                noticias++;
                break;
            case 'E':
                eventos++;
                break;
            case 'P':
                preguntas++;
                break;
        }

        printf("\n");
    }

    printf("Cantidad de publicaciones segun categorias:\n");
    printf("Noticias: %d\n", noticias);
    printf("Eventos: %d\n", eventos);
    printf("Preguntas: %d\n", preguntas);
}

// Función para mostrar el menú y gestionar las opciones
void menu() {
    int opcion;

    do {
        printf("\nMenu\n");
        printf("1. Operacion de transporte\n");
        printf("2. Interactuar en la red social\n");
        printf("3. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                operacionTransporte();
                break;
            case 2:
                redSocial();
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 3);
}

// Función de inicio de sesión
int login() {
    char usuarios[3][20] = {"usuario1", "usuario2", "usuario3"};
    char contrasenas[3][20] = {"contrasena1", "contrasena2", "contrasena3"};

    char usuario[20];
    char contrasena[20];
    int intentos = 0;

    do {
        printf("Ingrese su usuario: ");
        scanf("%s", usuario);

        printf("Ingrese su contrasena: ");
        scanf("%s", contrasena);

        for (int i = 0; i < 3; i++) {
            if (strcmp(usuario, usuarios[i]) == 0 && strcmp(contrasena, contrasenas[i]) == 0) { //la funcion strcmp compara el usuario y la contraseña para ver si son sus respctivos usuarios o contraseñas 
                return 1;
            }
        }

        intentos++;

        printf("Usuario o contrasena incorrectos. Intento #%d\n", intentos);

    } while (intentos < 3);

    printf("Imposible ingresar. Saliendo del programa...\n");
    return 0;
}

int main() {
    if (login()) {
        menu();
    }

    return 0;
}
