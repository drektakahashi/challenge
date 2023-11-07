#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    //André Kenji Takahashi
    //Andre Luis Sassiente
    //Rafael Amafaldo
    //Leticia Martin
    //Gabriel Astolfi
    //Marcos Vinicius Bertelli

    //Estrutura utilizada foi a duplamente encadeada, porquê você consegue armazenar os dados e percorrer com ponteiros de maneira mais dinâmica.

typedef struct lista{

    char nome[70];
    char artista[100];
    char estilo[50];
    int duracao;

    //ponteiros
    struct lista *proximo;
    struct lista *anterior;

} Lista;

typedef struct {
    Lista *inicio;
    Lista *fim;
    int tam;
} Data;

void criando_lista(Data *data){
    data->inicio = NULL;
    data->fim = NULL;
    data->tam = 0;
}

void inserir_conjunto(Data *data){

    char nome[70];
    char artista[100];
    char estilo[50];
    int duracao;

    printf("\n\n---Cadastre uma musica---\n\n");

    printf("\nNome da musica: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("\nNome do artista: ");
    fflush(stdin);
    fgets(artista, sizeof(artista), stdin);
    artista[strlen(artista) - 1] = '\0';

    printf("\nEstilo da musica: ");
    fflush(stdin);
    fgets(estilo, sizeof(estilo), stdin);
    estilo[strlen(estilo) - 1] = '\0';

    printf("\nDuracao da musica (segundos): ");
    scanf("%d", &duracao);

    Lista *new = malloc(sizeof(Lista));

if(new != NULL){
        strcpy(new->nome, nome);
        strcpy(new->artista, artista);
        strcpy(new->estilo, estilo);
        new->duracao = duracao;
        new->proximo = NULL;
        new->anterior = data->fim;

        if(data->inicio == NULL){
            data->inicio = new;
        } else {
            data->fim->proximo = new;
        }
        data->fim = new;
        data->tam++;
    } else {
        printf("Erro de alocamento de memoria!\n");
    }
}

void inserir(Data *data){
    char nome[70];
    char artista[100];
    char estilo[50];
    int duracao;

    printf("\n\n---Cadastre uma musica---\n\n");

    printf("\nNome da musica: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("\nNome do artista: ");
    fflush(stdin);
    fgets(artista, sizeof(artista), stdin);
    nome[strlen(artista) - 1] = '\0';

    printf("\nEstilo da musica: ");
    fflush(stdin);
    fgets(estilo, sizeof(estilo), stdin);
    nome[strlen(estilo) - 1] = '\0';

    printf("\nDuracao da musica: ");
    scanf("%d", &duracao);

    Lista *new = malloc(sizeof(Lista));

if(new != NULL){
        strcpy(new->nome, nome);
        strcpy(new->artista, artista);
        strcpy(new->estilo, estilo);
        new->duracao = duracao;
        new->proximo = NULL;
        new->anterior = data->fim;

        if(data->inicio == NULL){
            data->inicio = new;
        } else {
            data->fim->proximo = new;
        }
        data->fim = new;
        data->tam++;
    } else {
        printf("Erro de alocamento de memoria!\n");
    }
}


void exibir(Data *data){
    Lista *atual = data->inicio;

    if(atual == NULL){
        printf("A lista esta vazia!\n");
        return;
    }
    printf("\nLista de todos os itens: ");
    while(atual != NULL) {
        printf("\n---Nova Musica---\n");
        printf("\nNome da Musica: %s \n", atual->nome);
        printf("Autor da Musica: %s \n", atual->artista);
        printf("Estilo da Musica: %s \n\n", atual->estilo);
        printf("Duracao da Musica: %d \n", atual->duracao);

        atual = atual->proximo;
    }

}

Lista *remover_item(Data *data) {
    char nome[70];
    int find = 0;
    printf("\n--Para realizar uma  remocao digite o nome da Musica--\n\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    Lista *aux = data->inicio;
    Lista *remover = NULL;

    while (aux) {
        if (strcmp(aux->nome, nome)==0) {
            remover = aux;
            if(aux->anterior) {
                aux->anterior->proximo = aux->proximo;
            } else {
                data->inicio = aux->proximo;
            }
            if(aux->proximo) {
                aux->proximo->anterior = aux->anterior;
            } else {
                data->fim = aux->anterior;
            }
            data->tam--;
            find = 1;
            break;
        }
        aux = aux->proximo;
}
if(find) {
        printf("Musica removido com sucesso!\n");
        free(remover);
    } else {
        printf("Musica nao encontrado!\n");
    }
    return remover;
}

void buscar(Data *data) {
    char nome[70];
    int find = 0;
    printf("\n--Para realizar uma busca digite o nome da Musica--\n\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    Lista *atual = data->inicio;

    while(atual != NULL){
        if (strcmp(atual->nome, nome) == 0){
            printf("\nMusica registrada!\n");
            printf("\nNome do Musica: %s", atual->nome);
            printf("\nArtista responsavel: %s", atual->artista);
            printf("\nEstilo da Musica: %s", atual->estilo);
            printf("\nDuracao da Musica: %d", atual->duracao);
            find = 1;
            break;
        }
        atual = atual->proximo;
    }
}

Lista *remover_conjunto(Data *data){
    Lista *atual = data->inicio;

    while (atual != NULL){
        Lista *aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    data->inicio = NULL;
    data->fim = NULL;
    data->tam = 0;
}

main()
{
    Data *data;
    Lista *removido;
    criando_lista(&data);
    int op;

    printf("\n---Reprodutor Multimidia---\n\n");

    while(1){
        printf("\n--------MENU---------\n");
        printf("\n[1] - Criar conjunto");
        printf("\n[2] - Inserir no conjunto");
        printf("\n[3] - Exibir todos os dados");
        printf("\n[4] - Remover um dado");
        printf("\n[5] - Buscar um dado");
        printf("\n[6] - Remover conjunto");
        printf("\n[7] - Sair do programa");

        printf("\n\nOpcao desejada:.. ");
        scanf("%d", &op);
        int var;

        switch(op){

        case 1:

            do{

                    inserir_conjunto(&data);
                    printf("\nVoce quer continuar inserindo musicas no conjunto (digite 1 para continuar): ");
                    scanf("%d", &var);

            } while(var == 1);
            break;

        case 2:
            inserir(&data);
            break;

        case 3:
            exibir(&data);
            break;

        case 4:
            remover_item(&data);
            break;

        case 5:
            buscar(&data);
            break;

        case 6:
            remover_conjunto(&data);
            break;

        case 7:
            printf("Leaving the software..");
            return 0;

        default:
            printf("\nOpcao invalida!!");
        }
    }
    }
