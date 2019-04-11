// By Andreza Fernandes de Oliveira, april/2019
// FALTA TERMINAR
// #include "QuickSort_Versions.h"
// #include "instancias_ruins_QuickSort.hpp"
#include <iostream>
#include <random>
#include <new>
#include <time.h>
using namespace std;
// Chamar "escrever_instancia(v,n)" sobre o vetor "v" de "n" elementos no qual a instância deve ser escrita.
// Testar se a função retornou "true" (indica erro, falta de memória). Se o retorno for "false", a instância foi construída com sucesso.
// DOING
void print_vector(int *inicio, int *fim){
    cout << "-----------------------------------------------------------------------------------------------\n\t\t";
    for(; inicio != fim; inicio++){
        cout << *inicio << "  ";
    }
    cout << "\n---------------------------------------------------------------------------------------------\n";
}

//TODO: função pra checar se o vetor tá ordenado
void check(int* inicio, int *fim){
}

int* copy_vector(int* inicio, int* fim){
    return inicio;
}

int* vetor_aleatorio(int tamanho, int valor_inicial, int valor_final){
    int *vetor = new int[tamanho];
    srand(time(nullptr));
    for(int *i = vetor; i != vetor + tamanho; ++i){
        *i = valor_inicial + (rand() % valor_final);
    }
    return vetor;
}

void menu(){
    int tamanho;
    int opcao;
    int* vetor;
    clock_t inicio;
    clock_t total;
    
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    cout << "\n1. Gerador de instâncias ruins \n2. Gerador de vetor aleatório \nEscolha a opção para geração do vetor: ";
    cin >> opcao;

    switch (opcao){
        case 1:
            break;
        case 2:
            int valor_inicial, valor_final;
            cout << "\nDigite o valor inicial do intervalo: ";
            cin >> valor_inicial;

            cout << "Digite o valor final do intervalo: ";
            cin >> valor_final;
            vetor = vetor_aleatorio(tamanho, valor_inicial, valor_final);
            print_vector(vetor, vetor + tamanho);
            break;
        default:
            cout << "\nOPÇÃO INVÁLIDA!\nPor favor, tente novamente\n";
            break;
    }

    //TODO: Fazer as cópias dos vetores

    inicio = clock();
    // Chamada ao QuickSort via Índice
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort via Índice: " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";

    inicio = clock();
    // Chamada ao QuickSort via Particionamento Duplo
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort via Particionamento Duplo: " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";

    inicio = clock();
    // Chamada ao QuickSort via Particionamento Triplo
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort via Particionamento Triplo: " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";

    inicio = clock();
    // Chamada ao QuickSort Memória Log(n)
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort Memória Log(n): " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";

    inicio = clock();
    // Chamada ao QuickSort via Mediana das Medianas
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort via Mediana das Medianas: " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";

    inicio = clock();
    // Chamada ao QuickSort Pivô Aleatório
    total = clock() - inicio;
    cout << "\n========================================================================";
    cout << "\nQuickSort via Pivô Aleatório: " << ((float)total/CLOCKS_PER_SEC);
    cout << check(vetor, vetor+tamanho);
    cout << "\n========================================================================\n";
}

int main(){
  menu();
  return 0;
}