#include <stdlib.h>
#include <stdio.h>

/* 

Escreva uma função, em C, que receba uma lista simplesmente encadeada, e
retorne uma lista ordenada (crescente) sem alocar espaços para novos
elementos da lista.

*/


typedef struct Node
{
    
    struct Node * proximo;
    int valor;

}Node;

/* 

    Funções node

*/

void adicionar_valor(Node ** inicio, int valor);
void printar_lista(Node * inicio);
Node * encontrar_ultimo_valor(Node * inicio);
void ordenarLista(Node **inicio);

int main()
{
    int resposta = 0;
    Node * inicio = NULL;

    do 
    {
        printf("Digite um número inteiro (0 para encerrar o programa): ");
        scanf("%d", &resposta);

        if (resposta == 0)
        {
            break;
        }

        adicionar_valor(&inicio, resposta);
        

    } while (1);

    printf("\n*** Printando lista... ***\n\n");
    ordenarLista(&inicio);
    printar_lista(inicio);

    return 0;
}

void adicionar_valor(Node **inicio, int valor)
{
    Node * novoValor = (Node *)malloc(sizeof(Node));
    novoValor->valor = valor;

    if (novoValor == NULL)
    {
        printf("Não foi possível alocar memória para o novo valor!");
        exit(1);
    }

    if (*inicio == NULL)
    {
        *inicio = novoValor;
        (*inicio)->proximo = NULL;
    }
    else
    {
        Node * ultimo_valor = encontrar_ultimo_valor(*inicio);
        ultimo_valor->proximo = novoValor;
    }
}

void printar_lista(Node *inicio)
{
    Node * aux = inicio;

    while(aux != NULL)
    {
        printf(" | %d |", aux->valor);
        if (aux->proximo != NULL)
        {
            printf(" -> ");
        }
        aux = aux->proximo;
    }

    printf("\n\n");
}

Node *encontrar_ultimo_valor(Node *inicio)
{
    Node * aux = inicio;
    
    while(aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    return aux;
}

void ordenarLista(Node **inicio)
{
    if (*inicio == NULL || (*inicio)->proximo == NULL)
    {
        return;
    }

    Node * atual = *inicio;
    Node * inicioOrdenada = NULL;

    while (atual != NULL)
    {
        Node * proximo = atual->proximo;

        if (inicioOrdenada == NULL || atual->valor <= inicioOrdenada->valor)
        {
            atual->proximo = inicioOrdenada;
            inicioOrdenada = atual;
        }
        else
        {
            Node * atualOrdenada = inicioOrdenada;

            while (atualOrdenada->proximo != NULL && atualOrdenada->proximo->valor < atual->valor)
            {
                atualOrdenada = atualOrdenada->proximo;
            }

            atual->proximo = atualOrdenada->proximo;
            atualOrdenada->proximo = atual;
        }


        atual = proximo;
    }

    *inicio = inicioOrdenada;
}
