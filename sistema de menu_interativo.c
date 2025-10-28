    // Incluo essas 4 bibliotecas no meu código para que eu consiga
    // trabalhar com acentos e caracteres especiais nas frases e desenvolver
    // o sistema de autenticação por senha
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

int main(){


    // Variáveis
    char senha[20];
    char senha_correta[] = "Pa1234";
    char nome[20];
    char nome_correto[] = "Pedro";

    int opcao; 
    float saldo = 1500.0;
    float deposito = 0;
    float saque = 0;
    int transacoes = 0;
    int num_saque = 0;
    int num_deposito = 0;

    int tentativas = 0;
    const int max_tentativas = 3;

    // Mensagem de boas vindas ao usuário 
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf(" \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    wprintf(L"Olá, seja bem vindo(a) ao menu interativo do YOUBANK!\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(" \n");

    // Validação de usuário
    do{
        wprintf(L"Para prosseguirmos, nos informe o seu nome: ");
        scanf("%14s", nome);

    // Aqui eu preciso estabelecer uma condição para que se o usuário for correto, o 
    // programa continue com o seu objetivo, senão, ele apresenta erro até o usuário acertar

        if (strcmp(nome, nome_correto) == 0){
            printf(" \n");
            wprintf(L"Usuário encontrado!");
            printf(" \n");
        } else {
            wprintf(L"Usuário não encontrado! Tente novamente com um usuário válido.\n");
            printf(" \n");
                } 

    // Foi necessário utilizar o do-while, para que funcionasse o mecanismo de laço, para que
     // toda vez que o nome fosse incorreto o usuário pudesse ir tentando novamente
    } while (strcmp(nome, nome_correto) != 0);

    // Autenticação por senha
    do{
        wprintf(L"Digite a sua senha: ");
        scanf("%19s", senha);

    // Aqui eu preciso estabelecer uma condição para que se a senha for correta, o 
    // programa continue com o seu objetivo, senão, ele apresenta erro até negar o acesso e
    // o usuário ter que começar novamente   

        if (strcmp(senha, senha_correta) == 0){
            printf(" \n");
            printf("Login realizado com SUCESSO.\nSeja muito bem-vindo Sr(a) %s!\n", nome);
            wprintf(L"O que você gostaria de fazer hoje?\n");
            printf(" \n");
        } else {
            tentativas++;
            wprintf(L"Senha incorreta! (%d/%d Tentativas)\n", tentativas, max_tentativas);
                if (tentativas >= max_tentativas){
                    wprintf(L"Acesso bloqueado! Tente novamento mais tarde!");
                    return 1;
                } 
        }

    // Foi necessário utilizar o do-while, para que funcionasse o mecanismo de laço, para que
     // toda vez que a senha fosse incorreta o usuário tivesse outras 2 chances para acertar a senha
    } while (strcmp(senha, senha_correta) != 0);

    // Interação com usuário a partir do menu de opções
    do{

        printf(" \n");
        printf("============== MENU ==============\n");
        printf(" \n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Sair\n");
        printf(" \n");
        wprintf(L"Escolha uma opção: ");
        scanf("%d", &opcao);
        printf(" \n");

    // Aqui é necessário utilizar o switch-case para que eu consiga propor
    // ao usuário uma navegação do que ele pretende fazer no programa

        switch(opcao){
            case 1:
                wprintf(L"Seu saldo atual é: R$%.2f\n", saldo);
                printf(" \n");
            break;

    // No depósito tive que utilizar a condição if-else para que o programa identificasse
    // sucesso no depósito ou se o valor digitado é inválido, para que haja atualização no
    // tenho que utilizar a atribuição incremento para saldo += depósito
            case 2:
                wprintf(L"Digite o valor para depósito: R$");
                scanf("%f", &deposito);
                if (deposito > 0) {
                    saldo += deposito;
                    transacoes++;
                    num_deposito++;
                    printf(" \n");
                    wprintf(L"===========================\n");
                    wprintf(L"O valor de R$%.2f foi depositado com sucesso!\n", deposito);
                    wprintf(L"Seu saldo atual é de: R$%.2f\n", saldo);
                    wprintf(L"===========================\n");
                    printf(" \n");
                } else {
                    wprintf(L"Valor inválido!\n");
                    printf(" \n");
                }
    // Ao final do código peço para ele atribuir 0 ao depósito para que o sistema
    // não utilize o valor anterior no funcionamento do programa, assim, todo
    //  depósito tem um valor único por vez
                deposito = 0;
            break;

    // Assim como no depósito, utilizei basicamente o mesmo sistema para descontar
    // do saldo e manter atualizado durante o sistema, no entanto, tive que estabelecer
    // algumas condições mais complexas criando condições lógico-relacionais
            case 3:
                wprintf(L"Digite o valor para saque: R$");
                scanf("%f", &saque);
    // Para que o usuário digite um valor esperado menor ou igual ao saldo eu crio
    // condição em if e mantenho o saldo atualizado com o decremento em saldo -= saque
                if (saque > 0 && saque <= saldo){
                    saldo -= saque;
                    transacoes++;
                    num_saque++;
                    printf(" \n");
                    wprintf(L"===========================\n");
                    wprintf(L"Saque realizado com sucesso!\n");
                    wprintf(L"Seu saldo atual é de: R$%.2f\n", saldo);
                    wprintf(L"===========================\n");
                    printf(" \n");

    // Prevendo que o usuário não tenha mais saldo na conta, preciso informar isso
    // a ele e dar outra opção para que ele continue no sistema, então eu uso
    // else if para que quando o saque for maior que o saldo o sistema informa impossibilidade
    // e orienta o usuário digitar outro valor abaixo do saldo, e ele fica repetindo essa orientação
    // enquanto o usuário insistir em um saque maior que o saldo          
                } else if (saque > saldo){
                    do {
                    if(saldo > 0) { 
                        wprintf(L"Saldo insuficiente para saque maior que R$%.2f\n", saldo);
                        wprintf(L"Digite outro valor: R$");               
                        scanf("%f", &saque);

                        if(saque > 0 && saque <= saldo){
                            saldo -= saque;
                            transacoes++;
                            num_saque++;
                            printf(" \n");
                            wprintf(L"===========================\n");
                            wprintf(L"Saque realizado com sucesso!\n");
                            wprintf(L"Seu saldo atual é de: R$%.2f\n", saldo);
                            wprintf(L"===========================\n");
                            printf(" \n");
                        }
    // Se o usuário não tiver mais saldo, ou seja, saldo = 0, o sistema informa para ele
    // e direciona ele para o menu, no qual ela possa consultar saldo, depositar ou sair do sistema
                    } else {
                        wprintf(L"Você não tem saldo para saque!\n");
                        printf(" \n");
                        saque = 0;
                        break;
                    }
                    } while (saque > 0 && saque > saldo);
                }
                saque = 0;
            break;

    // O usuário consegue se manter no sistema até que ele queira sair, escolhendo a
    // opção 4 e recebendo uma mensagem calorosa e respeitosa
            case 4:
                printf("Foi um prazer Sr(a)%s! Volte sempre!\n", nome);
                printf(" \n");
            break;
            default:
    // Caso o usuário digitar uma opção diferente das que o menu apresenta, uma mensagem
    // o informa que a opção é inválida e orienta escolher uma das opções apresentadas
                wprintf(L"Opção inválida! Escolha uma das opções apresentadas.\n");
                printf(" \n");
        }
  
    } while (opcao != 4);

    // Ao final do uso do sistema, quero apresentar a quantidade
    // de transações, depósitos e saques feitos pelo usuário
    wprintf(L"Quantidade de transações na sessão: %d\n", transacoes);
    printf(" \n");
    wprintf(L"%d Depósitos realizados\n", num_deposito);
    printf(" \n");
    wprintf(L"%d Saques realizados\n", num_saque);
    printf(" \n");

return 0;
}