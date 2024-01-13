#include <stdio.h>


int main(void){
int opcion, num;   

    printf("---MENU FACTORIAL---\n");
    do
    {
        int i;
        float numFactorial=1;
        printf("\n");
        printf("---Calculo del factorial de un numero---\n");
        printf("1. For\n");
        printf("2. Do while \n");
        printf("3. While \n");
        printf("4. Numero palindromo\n");
        printf("5. Numero armstrong\n");
        printf("6. Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("\n--Factorial por For--\n");
            printf("Ingresar valor entero\n");
            scanf("%d", &num);
            
            for (i= 1; i <= num; i++)
            {
                numFactorial*=i;
            }
            printf("El factorial de %d es %.2f\n", num, numFactorial);
            
            break;
        case 2:
            printf("\n");
            printf("--Factorial por Do while--\n");
            printf("Ingresar valor entero\n");
            scanf("%d", &num);
            i=1;
            do
            {
                numFactorial*=i;
                i++;
                
            } while (i<=num);  
            printf("El factorial de %d es %.2f\n", num, numFactorial);

            break;
        case 3:
            printf("\n");
            printf("--Factorial por While--\n");
            printf("Ingresar valor entero\n");
            scanf("%d", &num);
            i=1;
            while (i<num)
            {
                
                i++;
                numFactorial*=i;
            }
            printf("El factorial de %d es %.2f\n", num, numFactorial);  
            break; 
        case 4:
            int num_aux, digitos, num_palindromo=0;
            printf("\nDigite un numero:\n");
            scanf ("%d", &num);
            num_aux=num;
            do
            {
                digitos=num_aux%10;
                num_palindromo= (num_palindromo*10)+digitos;
                num_aux=num_aux/10;
            } while (num_aux!=0);

            if (num_palindromo==num)
            {
                printf ("El numero si es palindromo ya que se lee igual de izquierda aderecha que viceversa %d\n", num_palindromo);
            }
            else
            {
                printf ("El numero no es palindromo ya que no se lee igual de izquierda a derecha que viceversa %d\n", num_palindromo);
            }
            
            break;
        case 5:
            printf ("\nIngrese un numero:\n");
            scanf ("%d", &num);
            int num_auxarms, num_armstrong=0;
            num_auxarms=num;
            // while (num_aux!=0)
            // {
            //     digitos=num_aux%10;
            //     num_armstrong=(num_armstrong+(digitos*digitos*digitos));
            //     num_aux/=10;
            // }      
            do
            {
                digitos=num_auxarms%10;
                num_armstrong=(num_armstrong+(digitos*digitos*digitos));
                num_auxarms/=10;
            } while (num_auxarms!=0);
            if (num_armstrong==num)
            {
                printf("El numero %d es un numero de armstrong ya que la suma de sus digitos elevados el cubo es %d\n", num, num_armstrong);
            }
            else
            {
                printf("El numero %d no es un numero de armstrong ya que la suma de sus digitos elevados el cubo es %d\n", num, num_armstrong);
            }
            
            break;
        default:
        printf("Opcion no valida\n");
            break;
        }

    } while (opcion!=6);
    
    return 0;
}