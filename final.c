#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nota {
  int id_aluno;
  int id_nota;
  int vl_nota;
} nota;

typedef struct aluno {
  char nome_aluno[50];
  int id_aluno;
  char num_aluno[50];
  nota notas[3];
} aluno;

int alunos_colocados = 0;
aluno alunos[10];
char temp;

void index_delete(aluno *arr, int qual_index_deletado, int nota) {
  // recebe o array, quantos itens estão colocados nele e qual o index que foi
  // nota é booleabo, ou seja, so recebe 0 ou 1ing the result of an assignment as a condition without parenth
  if (nota == 0) {
    for (int i = qual_index_deletado + 1; i < alunos_colocados; i++) {
      arr[i - 1] = arr[i];
    }
    alunos_colocados--;
  } else {
    
  }
}

void tira_aluno_por_id(int id_aluno) {
  int flag = 0;
  for (int i = 0; i < alunos_colocados; i++) {
    if (alunos[i].id_aluno == id_aluno) {
      flag = 1;
      printf("Deseja deletar o aluno de nome %s ? \n", alunos[i].nome_aluno);
      int yesono;
      printf("--------[S]im ou [N]ão ?--------\n");
      scanf("%c", &yesono);
      if (yesono == 'S') {
        index_delete(alunos, alunos_colocados, i);
      } else if (yesono == 'N') {
        printf("Aluno não deletado\n");
      } else {
        printf("!=!=!=! Erro, tecla errada !=!=!=!\n");
      }
    }
  }
  if (!flag) {
    printf("O aluno NÃO existe na base\n");
  }
}

void executa_aluno(int opcao) {
  int id;
  switch (opcao) {

  case 1: {
    printf("===================================\n");
    printf("Codigo do aluno = %d\n", alunos_colocados + 1);
    char nome_aluno[50];
    printf("Digite o nome do aluno: \n");
    scanf("  %c", &temp); // ARRUMAR!!!!
    printf("====================================\n");

    while (strlen(nome_aluno) < 3 || strlen(nome_aluno) == 0) {
      fgets(nome_aluno, 50, stdin);
      strcpy(alunos[alunos_colocados].num_aluno, nome_aluno);
      puts(alunos[alunos_colocados].num_aluno);
    }
  } break;

  case 2: {
    printf("Consultar por id\n");
    printf("Qual id você deseja consultar?\n");
    scanf("%d", &id);
  } break;

  case 3: {
    int id = 0;
    printf("Qual id você deseja excluir? \n");
    scanf("%d", &id);
    tira_aluno_por_id(id);
    printf("Excluir por id\n");
  } break;

  case 4: {
    char novo_nome[50];
    char guardar_nome[50];
    printf("Qual id deseja alterar?\n");
    scanf("%d", &id);
    strcpy(guardar_nome, alunos[id - 1].num_aluno);
    printf("Código do Aluno: %d \n", id);
    printf("Aluno: %s\nPor qual nome deseja Alterar? \n",
           alunos[id - 1].num_aluno);
    scanf("%c", &temp);
    fflush(stdin);
    while (strlen(novo_nome) < 3 || strlen(novo_nome) == 0) {
      fgets(novo_nome, 50, stdin);
      strcpy(alunos[id - 1].num_aluno, novo_nome);
    }
    printf("Novo nome: %s\n", novo_nome);
    char yesono;
    printf("Confirma Alteração? [S]im ou [N]ão\n");
    scanf("%c", &yesono);
    if (yesono == 'N') {
      strcpy(alunos[id - 1].num_aluno, guardar_nome);
    } else {
      printf("!=!=!=! Erro, tecla errada !=!=!=!\n");
    }
  } break;

  case 5: {
    printf("Relatório \n");
  } break;

  default: {
  } break;
  }
}

int executa(int opcao) {
  switch (opcao) {
  case 1: {
    int opcoes;
    while (opcoes != 6) {
      printf("\n \t\t ALUNO \n Escolha uma opção:\n 1- Cadastrar\n 2- "
             "Consultar por id\n 3- Excluir por id\n 4- Alterar por id\n 5- "
             "Relatório\n 6- Sair\n");
      scanf("%d", &opcoes);
      while (opcoes < 1 || opcoes > 6) {
        printf("Número errado, escolha uma opção valida!\nTente de novo!");
        scanf("%d", &opcoes);
      }
      executa_aluno(opcoes);
    }
    printf("Você finalizou o seu executa_aluno!\n");
  } break;
  case 2: {
    int opcoes;
    while (opcoes != 5) {
      printf("\n \t\t NOTAS \n Escolha uma opção:\n 1- Incluir Nota do Aluno\n "
             "2-     Alterar Nota do Aluno\n 3- Excluir Nota do Aluno\n 4- "
             "Consultar Notas do Aluno\n 5- Voltar\n");
      scanf("%d", &opcoes);
      while (opcoes < 1 || opcoes > 5) {
        printf("Número errado, escolha uma opção valida!\nTente de novo!\n");
        scanf("%d", &opcoes);
      }
      executa_aluno(opcoes);
    }
    printf("Você finalizou o seu executa_aluno!\n");
  } break;
  case 3: {

  } break;
  default: {
  } break;
  }
}

int main() {
  int opcoes;
  while (opcoes != 4) {
    printf("\n \t\t MENU \nOlá usuario! Escolha uma opção:\n 1- Aluno\n 2- "
           "Notas\n 3- Relatorios\n 4- Sair\n");
    scanf("%d", &opcoes);
    while (opcoes < 1 || opcoes > 4) {
      printf("Número errado, escolha uma opção valida!\nTente de novo!");
      scanf("%d", &opcoes);
    }
    executa(opcoes);
  }
  return EXIT_SUCCESS;
}