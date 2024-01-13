#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
// Lenin arevalo 
#define MAX_SALUD 100
#define MAX_COMIDA 100
#define MAX_AGUA 100
#define MIN_SALUD 0
#define MIN_COMIDA 0
#define MIN_AGUA 0
#define MAX_DIAS 15

int main (){
    srand (time(0));
    int menu_principal;
    do{
    printf ("'Epik Gamez' presenta el juego survival:\n'Viviste o viviras'\n");
    printf ("Elija una opcion\n");
    printf ("1.-Jugar\n");
    printf ("2.-Creditos.\n");
    printf ("3.-Salir.\n");
    scanf ("%d", &menu_principal);
    switch (menu_principal)
    {
    case 1:
        printf ("Eres una persona millonaria algo egocentrica, estas en una de tus casa vacacionales en el bosque dijiste haber ido por trabajo pero la verdad es que escapaste de tu familia, tu esposa e hijos te frustraron y estas cansado de pelear con ellos.\nVas de caminata por el bosque para tratar de despejarte, el tipico sendero que lo conoces, pero decides ir por una nueva ruta\n");
        printf("Vas hablando solo imaginando las discuciones que tienes con tu familia diciendo lo que no te atreves a decir en persona y al estar distraido no notas que el camino acabo y aparte estaba camuflado por la espesura del bosque y caes rodando por varios metros, afortunadamente no te haces daño pero no hay posibilidad de regresar por ahi mismo.\nEntras en panico por un momento te encuentras solo y no saben con exactitud donde estas, logras tranquilizarte y decides adentrarte mas al bosque con la esperanza de encontrar otra salida.\n");
        printf("Pero despues de varias horas sin un panorama favorable te das cuenta que ahora si estas solo y deberas sobrevivir, y tu mente te hace una pregunta que te deja paralizado ¿Viviste o viviras?.\n");
        int salud=100, comida=100, agua=100, arma=0, dia=1, menu_juego, probabilidad, probabilidad_pelea;
        char decision;
        do{
        printf ("Decide que haras en el dia:\n");
        printf ("1.-Descanzar, si tu salud no esta al maximo recuperaras 10 puntos.\n");
        printf ("2.-Salir a buscar agua. Puedes encontrar un pequeño arroyo, encontrar varias botellas de agua casi vacias o sufrir un accidente un perder salud.\n");
        printf ("3.-Cazar.\n");
        printf ("4.-Buscar objetos.\n");
        scanf ("%d", &menu_juego);
        switch (menu_juego)
        {
        case 1:
            comida-=15;
            agua-=20;
            if (salud<100)
            {
                salud+=10;
                if (salud>MAX_SALUD)
                {
                    salud=MAX_SALUD; 
                } 
            }
            // se condiciona si al restaurar la salud no sobrepase el maximo
            // luego que en caso de tener comida o agua en cero disminuir la salud lo mismo es en todos los demas opciones ademas de condicionar el maximo y minimo de salud, comida y agua 
            if ((comida<=MIN_COMIDA)||(agua<=MIN_AGUA))
            {
                salud-=20;
            }
            if (salud<MIN_SALUD)
            {
                salud=MIN_SALUD;
                break;
            }
            if (comida<MIN_COMIDA)
            {
                comida=MIN_COMIDA;
            }
            if (agua<MIN_AGUA)
            {
                agua=MIN_AGUA;
            }
            if (comida>MAX_COMIDA)
            {   
                comida=MAX_COMIDA;
            }
            if (agua>MAX_AGUA)
            {   
                agua=MAX_AGUA;
            }
            // se realizaran los calculos y mostraran los resultados del dia.
            printf ("Este dia has decicido descanzar.\nPero no has recolectado ni agua ni comida por lo que estas se veran afectadas.\n");
            dia+=1;
            printf ("Tu salud actual es: %d\n", salud);
            printf ("Tu nivel de comida es: %d\n", comida);
            printf ("Tu nivel de agua es: %d\n", agua);
            printf ("Mañana comienza el: %d dia\n", dia);
            break;
        case 2:
            probabilidad = rand()%100+1;
            if ((comida<=MIN_COMIDA)||(agua<=MIN_AGUA))
            {
                salud-=20;
            }
            if (salud<MIN_SALUD)
            {
                break;
            }
            printf ("Saliste a buscar agua.\n");
            // dependiendo el valor de la probabilidad se sumara o restara en agua y comida, los mismo sera en todas las demas opciones
            if (probabilidad<=20)
            {
                printf ("Encontraste un arroyo.\n");
                agua+=25;
                comida-=15;
            }
            else if (probabilidad>20 && probabilidad<=55)
            {
                printf ("Has encontrado botellas de agua casi vacias que apenas logran saciarte.\n");
                agua+=5;
                comida-=20;
            }
            else
            {
                printf ("Tuviste un accidente y perderas salud pero no agua. Tu comida tambien se ve afectada.\n");
                salud-=5;
                comida-=20;
            }
            if (comida<MIN_COMIDA)
            {
                comida=MIN_COMIDA;
            }
            if (agua<MIN_AGUA)
            {
                agua=MIN_AGUA;
            }
            if (comida>MAX_COMIDA)
            {   
                comida=MAX_COMIDA;
            }
            if (agua>MAX_AGUA)
            {   
                agua=MAX_AGUA;
            }
            dia+=1;
            printf ("Tu salud actual es: %d\n", salud);
            printf ("Tu nivel de comida es: %d\n", comida);
            printf ("Tu nivel de agua es: %d\n", agua);
            printf ("Mañana comienza el: %d dia\n", dia);
            break;
        case 3:
            probabilidad = rand() %100+1;
            if ((comida<=MIN_COMIDA)||(agua<=MIN_AGUA))
            {
                salud-=20;
            }
            if (salud<MIN_SALUD)
            {
                break;
            }
            if (probabilidad<=30)
            {
                printf ("Lograste cazar un conejo algo pequeño pero te servira muy bien de alimento.\n");
                comida+=30;
                agua-=25;
            }
            else if (probabilidad>30 && probabilidad<=60)
            {
                printf ("Lograste pescar algo aunque no conseguiras cocinarlo bien, te servira de alimento.\n");
                comida+=10;
                agua-=25;
            }
            else
            {
                printf ("Al salir a cazar eres mas indiscreto, temerario y osado por lo que te has encontrado con un animal salvaje.\nTe esta atacando pero puedes escapar o luchar contra el teniendo la posibilidades tanto de morir como de vencerlo.\n Si encontraste un arma tus probabilidades aumentaran.\n");
                agua-=30;
                salud-=25;
                fflush(stdin);
                printf ("Que decides, luchar o escapar.\nQuieres luchar s/n:\n");
                scanf ("%c", &decision);
// añadi que en caso de ser atacado por un animal salvaje decidir si enfrentarlo, donde puede perder la vida, o escapar independientemente lo que elija la salud disminuye pero si ganara el enfrentamiento la comida la trendra al maximo y si al elegir la opcion 4 encontro un objeto para usar como arma tiene mas probabilidades de vivir pero sino las mismas probabilidades es tanto morir como vivir.
                if (decision=='s')
                {
                    probabilidad_pelea = rand() %100+1;
                    if (arma>0)
                    {
                        if (probabilidad_pelea<=70)
                        {
                        printf ("Lograste sobrevivir. Tu salud y agua se veran afectadas pero la comida sera el maximo\n");
                        comida=MAX_COMIDA;
                        }
                        else
                        {
                            printf ("No lograste vencer en la lucha, perdiste la vida.\n");
                            salud=MIN_SALUD;
                            break;
                        }
                    }
                    else
                    {
                        if (probabilidad_pelea<=50)
                        {
                        printf ("Lograste sobrevivir. Tu salud y agua se veran afectadas pero la comida sera el maximo\n");
                        comida=MAX_COMIDA;
                        }
                        else
                        {
                        printf ("No lograste vencer en la lucha, perdiste la vida.\n");
                        salud=MIN_SALUD;
                        break;
                        }
                    }
                }
                else
                {
                    printf("Lograste escapar, viviras un dia mas.\n");
                    comida-=20;
                }   
            }
            if (comida<MIN_COMIDA)
            {
                comida=MIN_COMIDA;
            }
            if (agua<MIN_AGUA)
            {
                agua=MIN_AGUA;
            }
            if (comida>MAX_COMIDA)
            {   
                comida=MAX_COMIDA;
            }
            if (agua>MAX_AGUA)
            {
                agua=MAX_AGUA;
            }
            if (salud<MIN_SALUD)
            {
                break;
            }
            dia+=1;
            printf ("Tu salud actual es: %d\n", salud);
            printf ("Tu nivel de comida es: %d\n", comida);
            printf ("Tu nivel de agua es: %d\n", agua);
            printf ("Mañana comienza el: %d dia\n", dia);
            break;
        case 4:
            probabilidad = rand() %100+1;
            if ((comida<=MIN_COMIDA)||(agua<=MIN_AGUA))
            {
                salud-=20;
            }
            if (salud<MIN_SALUD)
            {
                break;
            }
            printf ("Saldras en busca de objetos. Puedes encontrar comida, kit de primeros auxilios, un enjambre de avispas, tropezar y caer en un foso o encontrar un objeto que lo podras usar de arma.\n");
            if (probabilidad<=25)
            {
                printf ("Encontraste un kit de primeros auxilios aumentara tu salud si te encuentras por debajo del maximo.\n");
                comida-=20;
                agua-=30;
                if (salud<MAX_SALUD)
                {
                    salud+=15; 
                    if (salud > MAX_SALUD)
                    {
                        salud = MAX_SALUD; 
                    } 
                } 
            }
            else if (probabilidad>25 && probabilidad<=50)
            {
                printf ("Encontraste algo de comida enlatada.\n");
                comida+=10;
                agua-=25; 
            }
            else if (probabilidad>50 && probabilidad<=90)
            {
                printf ("Te has topado con un enjambre de avispas y te atacaron.\n");
                salud-=10;
                comida-=20;
                agua-=30;
            }
            else
            {
// aqui añadi una opcion de poder encontrar un objeto para usarlo como arma para complementar el enfrentamiento en la opcion 3 
                printf ("Encontraste un objeto que lo puedes usar como arma para defenderte.\n");
                comida-=20;
                agua-=30;
                arma+=1;
            }
            if (comida<MIN_COMIDA)
            {
                comida=MIN_COMIDA;
            }
            if (agua<MIN_AGUA)
            {
                agua=MIN_AGUA;
            }
            if (comida>MAX_COMIDA)
            {   
                comida=MAX_COMIDA;
            }
            if (agua>MAX_AGUA)
            {
                agua=MAX_AGUA;
            }
            dia+=1;
            printf ("Tu salud actual es: %d\n", salud);
            printf ("Tu nivel de comida es: %d\n", comida);
            printf ("Tu nivel de agua es: %d\n", agua);
            printf ("Objetos para usar como arma %d\n", arma);
            printf ("Mañana comienza el: %d dia\n", dia);
        default:
            break;
        }
        } while (dia<MAX_DIAS && salud>0);
        if (dia=15 && salud>0)
        {
            printf ("Felicidades lograste sobrevivir, todo este tiempo lo unico que te impulsaba era poder volver a tu familia y aunque no lo creas en cuanto tu familia no supo nada de ti se pusieron a buscarte, eres alguien afortunado.\n");
        }
        else
        {
            printf ("No lograste sobrevivir. En tus ultimos momentos te arrepentiste de tus malos actos y lamentaste no valorar y aprovechar los momentos que te dio la vida.\n");
        }  
        break;
    case 2:
        printf ("Escrito, dirigido y producido por:\n <Lenin Arevalo>\nCalificado por:\n <Nicolas Rojas>\n"); 
        break; 
    case 3:
        printf ("Gracias por visitar Epik Gamez");
        break;
    default:
        break;
    }
    } while (menu_principal!=3);
return 0;
}
// el juego es dificil de ganar, el agua y comida bajan mucho ya que el ser humano sin agua muere a los tres dias