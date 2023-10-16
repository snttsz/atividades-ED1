#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node * inicio;

    struct Node * proximo;
    struct Node * anterior;
    
    char * palavra;

} Node;

/* 

    Funções do Node

*/

void editar_palavra(Node ** node, char * novaPalavra);
void inserir_palavra(Node ** node, char * palavra);
void eliminar_palavra(Node ** node);
void printar_frase(Node * node);
void palavra_anterior(Node ** node);
void proxima_palavra(Node ** node);
void mudar_inicio(Node ** node);

/* 

    Funções com ponteiros de char

*/

char * criar_ponteiro_char();

/* 

    Função principal

*/

int main()
{
    int resposta;
    char * palavra = NULL;
    char * palavra_atual = "...";
    Node * node_atual = NULL;

    while(1)
    {
        system("clear");

        if (node_atual != NULL)
        {
            printf("Frase: \n");
            printar_frase(node_atual);
            printf("\n\n");
            
            printf("Palavra atual: %s", node_atual->palavra);
        }
        else
        {
            printf("Ainda não há nenhuma palavra!");
        }

        printf("\n\tE: Editar palavra atual\n\tD: Inserir (depois da palavra atual)\n\tS: Eliminar palavra\n\t<: Palavra anterior\n\t>: Próxima palavra\n\tX: Sair");
        
        printf("\nDigite uma opção: ");
        resposta = getchar();

        switch (resposta)
        {
            case 'E':

                if (node_atual != NULL)
                {
                    palavra = criar_ponteiro_char();
                    editar_palavra(&node_atual, palavra);
                }
                
                break;
            
            case 'D':

                palavra = criar_ponteiro_char();
                inserir_palavra(&node_atual, palavra);
                break;

            case 'S':

                eliminar_palavra(&node_atual);
                break;
            
            case '<':

                palavra_anterior(&node_atual);
                break;
            
            case '>':

                proxima_palavra(&node_atual);
                break;
            
            case 'X':

                printf("\nPrograma encerrado!\n");
                break;
            
            default:

                printf("Opção inválida! Opção: %c", resposta);
                break;
        }
        
    }

    return 0;
}

void editar_palavra(Node **node, char * palavra)
{
    if ((*node) == NULL || (*node)->palavra == NULL)
    {
        return;
    }

    char * palavraAntiga = (*node)->palavra;
    (*node)->palavra = palavra;

    free(palavraAntiga);
}

void inserir_palavra(Node **node, char * palavra)
{
    if ((*node) != NULL)
    {
        Node * auxAtual = (*node);
        Node * auxProximo = auxAtual->proximo;

        Node * novoNodo = (Node *)malloc(sizeof(Node));

        if (novoNodo == NULL)
        {
            printf("\nErro ao alocar memória para nova palavra!\n");
            exit(1);
        }
        
        novoNodo->anterior = auxAtual;
        novoNodo->proximo = auxProximo;
        novoNodo->palavra = palavra;

        novoNodo->inicio = auxAtual->inicio;
        novoNodo->inicio->anterior = novoNodo;

        auxAtual->proximo = novoNodo;
        auxProximo->anterior = novoNodo;

        (*node) = novoNodo;
    }
    else
    {
        (*node) = (Node *)malloc(sizeof(Node));

        if (*node == NULL)
        {
            printf("\nErro ao alocar memória para nova palavra!\n");
            exit(1);
        }
        
        (*node)->inicio = *node;
        (*node)->anterior = *node;
        (*node)->proximo = *node;
        (*node)->palavra = palavra;
    }

}

void eliminar_palavra(Node **node)
{
    if (*node == NULL || (*node)->palavra == NULL || (*node)->inicio == NULL)
    {
        return;
    }

    Node * auxAnterior = (*node)->anterior;
    Node * auxProximo = (*node)->proximo;
    Node * auxAtual = *node;

    if (auxAtual == auxAtual->inicio)
    {
        /* 
            Muda o inicio dos nodes para a próxima palavra após o início
        */
        mudar_inicio(node);
    }

    if (auxAnterior != NULL)
    {
        auxAnterior->proximo = auxProximo;
    }
    if (auxProximo != NULL)
    {
        auxProximo->anterior = auxAnterior;
    }

    *node = auxAtual->inicio;

    free(auxAtual->palavra);
    free(auxAtual);
}

void printar_frase(Node *node)
{
    if (node == NULL || node->inicio == NULL)
    {
        return;
    }

    Node * aux = node->inicio;
    Node * auxInicio = node->inicio;    

    do
    {
        printf(" %s ", aux->palavra);

        aux = aux->proximo;

    } while(aux != auxInicio);
}

void palavra_anterior(Node ** node)
{
    if (*node == NULL)
    {
        return;
    }

    if ((*node)->anterior != NULL)
    {
        (*node) = (*node)->anterior;
    }
}

void proxima_palavra(Node ** node)
{
    if (*node == NULL)
    {
        return;
    }

    if ((*node)->proximo != NULL)
    {
        (*node) = (*node)->proximo;
    }
}

void mudar_inicio(Node **node)
{
    if ((*node)->inicio == NULL || (*node)->inicio->proximo == NULL)
    {
        return;
    }

    Node * aux = (*node)->inicio;
    Node * auxInicio = (*node)->inicio;
    Node * novoInicio = (*node)->inicio->proximo;

    do
    {
    
        aux->inicio = novoInicio;
        aux = aux->proximo;
    
    } while(aux != auxInicio);
}

char * criar_ponteiro_char()
{
    system("clear");

    char * ponteiroPalavra = NULL;
    int tamanhoDaPalavra = 0;

    printf("Digite uma palavra: ");
    getchar();

    int caractere = 0;
    
    while (1)
    {
        caractere = getchar();

        if (caractere == ' ' || caractere == '\n' || caractere == EOF)
        {
            break;
        }

        tamanhoDaPalavra++;

        ponteiroPalavra = (char *)realloc(ponteiroPalavra, tamanhoDaPalavra);
        ponteiroPalavra[tamanhoDaPalavra - 1] = (char)caractere;
        
    }

    /* 
        Adicionando o caractere nulo 
    */
    ponteiroPalavra = (char *)realloc(ponteiroPalavra, tamanhoDaPalavra + 1);
    ponteiroPalavra[tamanhoDaPalavra] = '\0'; 

    return ponteiroPalavra;
}
