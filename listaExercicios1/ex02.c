#include <stdlib.h>
#include <stdio.h>

/* 

Escreva uma função, em C, que receba duas listas simplesmente encadeadas
A e B, contendo informações (Código e Nome) dos pacientes do médico X e do
médico Y (respectivamente), de uma determinada clínica. A clínica deseja
possuir uma lista única com as informações dos pacientes desses dois médicos
a partir da junção dessas duas listas. Considere que as listas A e B estão
ordenadas por código de pacientes e que não existem dois (ou mais) pacientes
com o mesmo código. A lista resultante deve conter todos os pacientes dos
médicos X e Y ordenados por código e sem elementos repetidos.

*/

typedef struct Node
{

    char * nome;
    int codigo;
    struct Node * proximo;

} Node;

/* 

    Funções Node

*/




/* 

    Função principal

*/

int main()
{
    return 0;
}