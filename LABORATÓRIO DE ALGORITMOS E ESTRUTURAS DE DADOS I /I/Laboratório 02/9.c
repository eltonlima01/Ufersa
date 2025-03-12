/*
Declare um registro Horário com os campos horas e minutos. Crie uma 
função MostrarHorario que deve receber um ponteiro para um Horário e 
mostrá-lo no formato HH:MM. Na função principal, declare uma variável do 
tipo Horário e um ponteiro que aponta para ela. Peça que o usuário digite o 
horário atual e guarde-o na variável. Usando o ponteiro, incremente o horário 
recebido em uma hora e em seguida mostre o horário corrigido com 
MostrarHorario.
*/

#include<stdio.h>

typedef struct{

    unsigned int Horas, Minutos;

} Horario;

void MostrarHorario(Horario *ptr);

int main(){

    Horario hour, *ptr = &hour;

    printf("Que horas são (HH:MM)?: ");

    scanf("%i%i", &hour.Horas, &hour.Minutos);

    while((hour.Horas > 23) || (hour.Horas < 0) || (hour.Minutos > 59) || (hour.Horas < 0)){

        if((hour.Horas > 23) || (hour.Horas < 0)){

            printf("%i hora(s) é um horário inválido!\nTente novamente: ", hour.Horas);

            scanf("%i", &hour.Horas);

        }else if((hour.Minutos > 59) || (hour.Horas < 0)){

            printf("%i minuto(s) é um horário inválido!\nTente novamente: ", hour.Minutos);

            scanf("%i", &hour.Minutos);

        }

    }

    MostrarHorario(ptr);

    printf("Seu relógio está atrasado, o horário correto é: %i:%i\n", hour.Horas, hour.Minutos);

    return 0;
}

void MostrarHorario(Horario *ptr){

    ptr->Horas = ptr->Horas +1;

    if(ptr->Horas == 24){

        ptr->Horas = 0;

    }

}
