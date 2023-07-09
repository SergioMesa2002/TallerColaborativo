#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int NumeroMagico(int number){
    int ac, c, r, aux;
    while (c <= 9) {
        aux = number;
        while (aux > 0) {
            r = aux % 10;
            if (r == c) {
                ac = (ac * 10) + r;
            }
            aux = (aux - r) / 10;
        }
        c = c + 1;
    }
    int menor=ac;
    int invert=0;
    while(ac>0){
        invert=(invert *10)+ (ac%10);
        ac = ac/10;

    }
    int mayor=invert;

    int resta=mayor-menor;
    if(resta==number){
        return 1;
    }else{
        return 0;
    }

}






int romanToInt(char *s) {
    int result = 0;
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'I') {
            if (s[i + 1] == 'V' || s[i + 1] == 'X') {
                result -= 1;
            } else {
                result += 1;
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'X') {
            if (s[i + 1] == 'L' || s[i + 1] == 'C') {
                result -= 10;
            } else {
                result += 10;
            }
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'C') {
            if (s[i + 1] == 'D' || s[i + 1] == 'M') {
                result -= 100;
            } else {
                result += 100;
            }
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        } else {
            return -1;  // dato invalido
        }
    }
    return result;
}

void aux_romanToInt() {
    char roman[16];
    printf("Ingrese el numero romano que desee convertir... : ");
    scanf("%s", roman); //se captura el dato ingresado
    int result = romanToInt(roman); //se envia el resultado al metodo de conversion
    if (result == -1) {
        printf("Null\n");
    } else {
        printf("%d\n", result);
    }
}














void deleteSpace(char *text) {
    int i = 0, j = 0;
    int len = strlen(text);
    int inSpace=0;

    while (isspace(text[i]) && i < len) i++;

    while (isspace(text[len - 1]) && len > 0) len--;

    while (i < len) {
        if (!isspace(text[i]) || (isspace(text[i]) && !isspace(text[j - 1]))) {
            text[j++] = text[i];
        }
        i++;
    }

    text[j] = '\0';
}

void enterText(){
#define MAX_LEN 100
    char text[MAX_LEN];

    printf("Ingresar un texto al que desea quitar los espacios extras: \n");
    fflush(stdin);
    fgets(text, MAX_LEN, stdin);

    deleteSpace(text);
    printf("Texto ingresado con los espacios extra borrados: %s \n", text);
}

int productPoint() {

    int vectorOne[5], vectorTwo[5];
    int aux[5];
    int result = 0;
    int lenOne, lenTwo;

    printf("\nIngrese la longitud del vector 1\n");
    scanf("%d", &lenOne);

    printf("\nIngrese la longitud del vector 2\n");
    scanf("%d", &lenTwo);


    if (lenOne == lenTwo) {
        printf("Agregue valores al primer vector \n");
        for (int i = 0; i < lenOne; i++)
            scanf("%d", &vectorOne[i]);
        printf("Agregue valores al segundo vector \n");
        for (int i = 0; i < lenTwo; i++)
            scanf("%d", &vectorTwo[i]);


    } else {

        printf("Null\n");
        return 0;
    }

    for (int i = 0; i < lenTwo; i++) {
        aux[i] = vectorOne[i] * vectorTwo[i];
        result += aux[i];
    }

    printf("El producto punto de los vectores es: %d \n ", result);

    return result;

}

int NumerosEgolatras(int n){
    int numeroDigitos = floor(log10(n)+1);
    char cadena [numeroDigitos + 1];

    sprintf (cadena,"%d",n);

    int suma=0;
    for(int i=0;i<numeroDigitos; i++){
        int cont = cadena[i] - '0';

        int elevado = pow(cont, numeroDigitos);
        suma=suma +elevado;
    }
    if(suma==n){
        return 1;
    }else{
        return 0;
    }


}

int option;
void *menu (){
    printf("\t.........MENU........ \n\n"
           "1. Numeros Romanos\n"
           "2. Factores Primos\n"
           "3. Borrar Espacios\n"
           "4. Numeros Egolatras \n"
           "5. Numero Magico \n"
           "6. Fechas\n"
           "7. Producto Punto\n"
           "8. Multiplicacion de Matrices\n"
           "9. Matriz Magica\n"
           "10. Salir\n\n"
           "Dijite una opcion del menu: \n");
            scanf("%i", &option);
            fflush(stdin);
}

int main() {
    do {
        menu();
        switch (option) {

            case 0:
                printf("Se esta saliendo del programa...\n");
                break;
            case 1:
                printf(".......Numeros Romanos.......\n");
                aux_romanToInt();
                break;
            case 2:
                printf(".......Factores Primos.......\n");
                break;
            case 3:
                printf(".......Borrar Espacios.......\n");
                enterText();
                break;
            case 4:

                printf(".......Numeros Egolatras.......\n");
                printf("Por favor ingrese el numero \n ");
                int num ;
                scanf("%d", &num);
                printf("El numero %d %s",num, NumerosEgolatras( num)?"es egolatra\n":"No es egolatra\n");
                break;
            case 5:
                printf(".......Numero Magico.......\n");

                printf("Ingrese el numero \n ");
                scanf("%d",&num);
                printf("El numero %d %s",num,  NumeroMagico(num)?"es magico":"No es magico\n");

                break;

                break;
            case 6:
                printf(".......Fechas.......\n");
                break;
            case 7:
                printf(".......Producto Punto.......\n");
                productPoint();
                break;
            case 8:
                printf(".......Multiplicacion de Matrices.......\n");
                break;
            case 9:
                printf(".......Matriz Magica.......\n");
                break;
            default:
                printf("\n\n Opcion digitada incorrecta\n\n\n");
        }
    } while (option != 10);

    return 0;
}
