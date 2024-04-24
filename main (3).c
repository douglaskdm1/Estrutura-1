#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#define MAX_USUARIOS 100
#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    char nome[50];
    char senha[20];
    char email[80];
} Usuario;

int verificarEmail(Usuario *usuarios, int totalUsuarios, char *email) {
    int i;

    if (strlen(email) > 80 || strstr(email, "@") == NULL) {
        return 0; 
    }

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0) {
            return 0; 
        }
    }

    return 1; 
}

void ordenarProdutosPorCodigo(Produto *produtos, int totalProdutos) {
    int i, j;
    Produto temp;

    for (i = 0; i < totalProdutos - 1; i++) {
        int min_idx = i;

      
        for (j = i + 1; j < totalProdutos; j++) {
            if (produtos[j].codigo < produtos[min_idx].codigo) {
                min_idx = j;
            }
        }

       
        if (min_idx != i) {
            temp = produtos[min_idx];
            produtos[min_idx] = produtos[i];
            produtos[i] = temp;
        }
    }
}

int realizarLogin(Usuario *usuarios, int totalUsuarios) {
    char nomeUsuario[50];
    char senhaUsuario[20];
    int i;

    printf("Digite seu nome de usuário: ");
    scanf("%s", nomeUsuario);
    printf("Digite sua senha: ");
    scanf("%s", senhaUsuario);
#ifdef _WIN32
    Sleep(2000);
#else
    sleep(2);
#endif
    system("cls || clear");

    for (i = 0; i < totalUsuarios; i++) {
        if (strcmp(nomeUsuario, usuarios[i].nome) == 0 && strcmp(senhaUsuario, usuarios[i].senha) == 0) {
            printf("Login realizado com sucesso!\n");
#ifdef _WIN32
            Sleep(2000);
#else
            sleep(2);
#endif
            system("cls || clear");
            return i;
        }
    }

    printf("Nome de usuário ou senha incorretos. Tente novamente.\n");
#ifdef _WIN32
    Sleep(2000);
#else
    sleep(2);
#endif
    system("cls || clear");
    return -1;
}

void exibirMenu() {
    printf("Selecione uma opção:\n");
    printf("1 - Cadastrar novo produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Editar produto\n");
    printf("4 - Excluir produto\n");
    printf("5 - Buscar produto\n");
    printf("6 - Formas de pagamento\n");
    printf("7 - Produtos em promoção\n");
    printf("8 - Endereço físico e Redes sociais\n");
    printf("9 - De sua nota à empresa\n");
    printf("10 - Fale conosco\n");
    printf("11 - Ordenar produtos por código\n");
    printf("0 - Sair\n");
}

void cadastrarProduto(Produto *produtos, int *totalProdutos) {
    printf("Digite o código do produto: ");
    scanf("%d", &produtos[*totalProdutos].codigo);
    printf("Digite o nome do produto: ");
    scanf("%s", produtos[*totalProdutos].nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &produtos[*totalProdutos].preco);
    (*totalProdutos)++;
    printf("Produto cadastrado com sucesso!\n");
#ifdef _WIN32
    Sleep(2000);
#else
    sleep(2);
#endif
    system("cls || clear");
}

void listarProdutos(Produto *produtos, int totalProdutos) {
    int i;

    printf("Lista de produtos:\n");
    for (i = 0; i < totalProdutos; i++) {
        printf("Código: %d | Nome: %s | Preço: R$ %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
#ifdef _WIN32
    Sleep(2000);
#else
    sleep(2);
#endif
    system("cls || clear");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Usuario usuarios[MAX_USUARIOS];
    Produto produtos[MAX_PRODUTOS];
    int totalUsuarios = 0;
    int totalProdutos = 0;
    int opcao, indiceUsuarioLogado;

    
    do {
        printf("Cadastre um novo usuário:\n");
        printf("Nome de usuário: ");
        scanf("%s", usuarios[totalUsuarios].nome);
        printf("Senha: ");
        scanf("%s", usuarios[totalUsuarios].senha);
        printf("E-mail: ");
        scanf("%s", usuarios[totalUsuarios].email);
#ifdef _WIN32
        Sleep(2000);
#else
        sleep(2);
#endif
        system("cls || clear");

       
        if (totalUsuarios > 0 && !verificarEmail(usuarios, totalUsuarios, usuarios[totalUsuarios].email)) {
            printf("E-mail inválido ou já cadastrado. Tente novamente.\n");
        } else {
            totalUsuarios++;
            break;
        }
    } while (1);

    
    printf("Bem-vindo à Dk eletrônicos\n");
#ifdef _WIN32
    Sleep(2000);
#else
    sleep(2);
#endif
    system("cls || clear");

   
    do {
        indiceUsuarioLogado = realizarLogin(usuarios, totalUsuarios);
    } while (indiceUsuarioLogado == -1);

   
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 2:
                listarProdutos(produtos, totalProdutos);
                break;
            case 11:
                ordenarProdutosPorCodigo(produtos, totalProdutos);
                printf("Produtos ordenados por código!\n");
#ifdef _WIN32
                Sleep(2000);
#else
                sleep(2);
#endif
                system("cls || clear");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


