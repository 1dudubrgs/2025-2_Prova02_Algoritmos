#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define tam 999

//EDUARDO BORGES PEREIRA - ANÁLISE E DESENVOLVIMENTO DE SISTEMAS - 185.824.286-00
//===============================================================================
//===================================FUNCOES=====================================
//===============================================================================
void att_saldo_diario(char status_transacao[], float saldo_diario[], float val_transacao, int casa_saldo_diario)
{
    float saldo_atual;

    saldo_atual = 0;

    if(status_transacao[casa_saldo_diario] == 'C')
        saldo_atual = val_transacao + saldo_diario[casa_saldo_diario-1];
    else
        saldo_atual = saldo_diario[casa_saldo_diario-1] - val_transacao;

    saldo_diario[casa_saldo_diario] = saldo_atual;
    casa_saldo_diario++;
}
//===============================================================================
void validar_deposito(float val_transacao[], float *val_dep, int contagem_val)
{
    while(*val_dep < 0)
    {
        printf("\nValor inserido invalido! Tente novamente.\n");
        printf("Insira o novo valor aqui ...: ");
        fflush(stdin);
        scanf("%f", &*val_dep);
    }
    val_transacao[contagem_val] = *val_dep;
}
//===============================================================================
void validar_tipo_dep(char nom_transacao[][100], char tipo_dep[100], int contagem_nm)
{
    while(strcmp(tipo_dep, "Pix") != 0 && strcmp(tipo_dep, "Dinheiro") != 0)
    {
        printf("\nTipo de transacao digitado nao reconhecido! Certifique-se que esta digitando corretamente\n");
        printf("Insira nova tentativa aqui ...: ");
        fflush(stdin);
        gets(tipo_dep);
    }
    strcpy(nom_transacao[contagem_nm], tipo_dep);
}
//===============================================================================
void retornar_menu()
{
    int retornar;

    retornar = 0;
    printf("\n\n Pressione ENTER para retornar ao menu");
    do
        retornar = getch();
    while(retornar != 13);
    system("cls");
}
//===============================================================================
void validar_dias(int dia_transacao[], int *dia_hoje, int contagem_dias)
{
    int i;

    i = 0;


    if(contagem_dias == 0)
    {
        while(*dia_hoje < 1 || *dia_hoje > 31)
        {
            printf("\nValor digitado invalido! Tente novamente.\n");
            printf("Insira aqui nova tentativa ...: ");
            fflush(stdin);
            scanf("%d", *&dia_hoje);
        }
        dia_transacao[0] = *dia_hoje;
    }

    else
    {
        while(*dia_hoje < dia_transacao[(contagem_dias-1)] || *dia_hoje < 1 || *dia_hoje > 31)
        {
            printf("\nO dia inserido foi menor que inserido anteriomente, menor do que 1 ou maior do que 31! Tente novamente.\n");
            printf("Insira aqui nova tentativa ...: ");
            fflush(stdin);
            scanf("%d", *&dia_hoje);
        }
        dia_transacao[contagem_dias] = *dia_hoje;
    }
}
//===============================================================================
int main()
{
    //CRIAR VARIAVEIS

    //OBSERVAÇÕES INICIAIS
    int dia_transacao[tam + 1];
    float val_transacao[tam + 1], saldo_diario[tam + 1];
    char nom_transacao[tam + 1][100], status_transacao[tam + 1];

    //GERAIS
    int i;

    //MENU
    int opc_user, continuar_menu;

    //OPC1 e OPC2
    int dia_hoje, contagem_dias, contagem_nm, contagem_val, quant_creditos, casa_saldo_diario;
    float val_dep;
    char tipo_dep[100];

    //OPC4
    int quant_transacoes;

    //INICIALIZAR VARIAVEIS
    opc_user = contagem_dias = continuar_menu = contagem_nm = contagem_val = quant_creditos = casa_saldo_diario = quant_transacoes = dia_hoje = val_dep = 0;
    strcpy(tipo_dep, "");
    for(i = 0; i<=tam; i++)
    {
        dia_transacao[i] = 0;
        val_transacao[i] = 0;
        saldo_diario[i] = 0;
        strcpy(nom_transacao[i], "");
        status_transacao[i] = ' ';
    }

    //COD
    do
    {
        printf("\n ----------TRANSACOES BANCARIAS----------");
        printf("\n ========================================");
        printf("\n\n  1) DEPOSITO (ENTRADA)\n  2) RETIRADAS (SAIDA)\n  3) RELATORIO SALDO ATUAL\n  4) RELATORIO EXTRATO DO PERIODO DO MES\n  5) FINALIZAR");
        printf("\n\n ========================================");
        printf("\n\n Informe uma das opcoes (1, 2, 3, 4 ou 5) ...: ");
        fflush(stdin);
        scanf("%d", &opc_user);

//        printf("\n\n\n");
//        for(i = 0; i<=20; i++)
//        {
//            printf("%5d", dia_transacao[i]);
//        }
//        printf("\n\n\n");
//        for(i = 0; i<=20; i++)
//        {
//            printf("%5.2f ", val_transacao[i]);;
//        }
//        printf("\n\n\n");
//        for(i = 0; i<=20; i++)
//        {
//            printf("%5.2f ", saldo_diario[i]);
//        }
//        printf("\n\n\n");
//        for(i = 0; i<=20; i++)
//        {
//            printf("%5s ", nom_transacao[i]);
//        }
//        printf("\n\n\n");
//        for(i = 0; i<=20; i++)
//        {
//            printf("%5c", status_transacao[i]);
//        }
//        printf("\n\n\n");

        while(opc_user < 1 || opc_user > 5)
        {
            printf("\nValor inserido invalido! Tente novamente.\n");
            printf("Infome aqui o novo valor ...: ");
            fflush(stdin);
            scanf("%d", &opc_user);
        }

        if(opc_user == 1) ///OPC 1
        {
            system("cls");

            printf("\n OPCAO 1 - DEPOSITO(ENTRADA)\n");
            printf(" ===========================\n");
            printf("\n Infome o dia da data de hoje ...: ");
            fflush(stdin);
            scanf("%d", &dia_hoje);
            validar_dias(dia_transacao, &dia_hoje, contagem_dias);
            contagem_dias++;

            system("cls");
            printf("\n OPCAO 1 - DEPOSITO(ENTRADA)\n");
            printf(" ===========================\n");
            printf("\n DIA INFORMADO: %d", dia_transacao[contagem_dias - 1]);
            printf("\n\n Informe o tipo de deposito (escreva EXATAMENTE como demonstrado a seguir: 'Dinheiro', 'Pix') ...: ");
            fflush(stdin);
            gets(tipo_dep);
            validar_tipo_dep(nom_transacao, tipo_dep, contagem_nm);
            contagem_nm++;

            system("cls");
            printf("\n OPCAO 1 - DEPOSITO(ENTRADA)\n");
            printf(" ===========================\n");
            printf("\n DIA INFORMADO: %d", dia_transacao[contagem_dias - 1]);
            printf("\n TIPO DE DEPOSITO INFORMADO: %s", nom_transacao[contagem_nm - 1]);
            printf("\n\n Infome o valor do deposito ...: ");
            fflush(stdin);
            scanf("%f", &val_dep);
            validar_deposito(val_transacao, &val_dep, contagem_val);
            contagem_val++;

            system("cls");
            printf("\n OPCAO 1 - DEPOSITO(ENTRADA)\n");
            printf(" ===========================\n");
            printf("\n DIA INFORMADO: %d", dia_transacao[contagem_dias - 1]);
            printf("\n TIPO DE DEPOSITO INFORMADO: %s", nom_transacao[contagem_nm - 1]);
            printf("\n VALOR DEPOSITADO: R$%.2f", val_transacao[contagem_val-1]);

            status_transacao[quant_creditos] = 'C';
            quant_creditos++;
            att_saldo_diario(status_transacao, saldo_diario, val_dep, casa_saldo_diario);
            casa_saldo_diario++;

            quant_transacoes++;
            retornar_menu();
        }

        else if(opc_user == 2)
        {
            system("cls");
            if(saldo_diario[casa_saldo_diario-1] == 0 || casa_saldo_diario == 0)
            {
                printf("\n Nao eh possivel debitar nenhum valor, pois nao ha saldo!!");
                printf("\n Voltando ao menu...");
                Sleep(2000);
                retornar_menu();
            }
            else
            {
                printf("\n OPCAO 2 - RETIRADAS(SAIDA)\n");
                printf(" ==========================\n");
                printf("\n Infome o dia da data de hoje ...: ");
                fflush(stdin);
                scanf("%d", &dia_hoje);
                validar_dias(dia_transacao, &dia_hoje, contagem_dias);
                contagem_dias++;

                printf("\n\n Informe o tipo de deposito (escreva EXATAMENTE como demonstrado a seguir: 'Dinheiro', 'Pix') ...: ");
                fflush(stdin);
                gets(tipo_dep);
                validar_tipo_dep(nom_transacao, tipo_dep, contagem_nm);
                contagem_nm++;

                printf("\n\nInfome o valor do deposito ...: ");
                fflush(stdin);
                scanf("%f", &val_dep);
                validar_deposito(val_transacao, &val_dep, contagem_val);
                contagem_val++;

                if(val_dep > saldo_diario[casa_saldo_diario - 1])
                {
                    printf("\n Nao eh possivel debitar o valor inserido com o saldo atual!");
                    printf("\n Voltando para o menu...");
                    contagem_dias--;
                    contagem_nm--;
                    contagem_val--;
                    val_transacao[contagem_val] = 0.0;
                    dia_transacao[contagem_dias] = 0;
                    strcpy(nom_transacao[contagem_nm], "");
                    Sleep(1000);
                }
                else
                {
                    status_transacao[quant_creditos] = 'D';
                    quant_creditos++;
                    att_saldo_diario(status_transacao, saldo_diario, val_dep, casa_saldo_diario);
                    casa_saldo_diario++;
                    quant_transacoes++;
                }
                retornar_menu();
            }
        }

        else if(opc_user == 3)
        {
            system("cls");
            printf("\n OPCAO 3 - SALDO ATUAL");
            printf("\n =====================");
            printf("\n\n  R$%.2f\n", saldo_diario[casa_saldo_diario - 1]);
            printf("\n =====================");
            retornar_menu();
        }

        else if(opc_user == 4)
        {
            system("cls");

            if(quant_transacoes == 0)
            {
                printf("\n Ainda nao foi realizada nenhuma transacao! Voltarei vc para o menu para que possa realizar transacoes :)");
                printf("\n Voltando ao menu...");
                Sleep(2000);
                retornar_menu();
            }
            else
            {
                printf("\nEXTRATO COMPLETO");
                printf("\n================");
                printf("\n\n");
                for(i = 0; i<quant_transacoes; i++)
                {
                    printf("\n  DIA  DESCRICAO  STATUS    VALOR DA TRANSACAO    SALDO ATUAL\n");
                    if(strcmp(nom_transacao[i], "Dinheiro") == 0)
                        printf("%3d -  %4s % 4c         R$%.2f               R$%.2f\n", dia_transacao[i], nom_transacao[i], status_transacao[i], val_transacao[i], saldo_diario[i]);
                    else
                        printf("%3d - %4s %9c         R$%.2f             R$%.2f\n", dia_transacao[i], nom_transacao[i], status_transacao[i], val_transacao[i], saldo_diario[i]);
                }
                retornar_menu();
            }
        }

        else
        {
            system("cls");
            printf("\n OBRIGADO POR USAR NOSSO PROGRAMA!!\n ATE A PROXIMA :)\n");
            continuar_menu = 1;
        }
    }while(continuar_menu == 0);

    return 0;
}
