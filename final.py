import pandas as pd

class Sistema:
    def __init__(self) -> None:
        self.dfs_dict = {}
        self.merged_df = None
    
    def load_csv(self, path, nome_df):
        try:
            df = pd.read_csv(path, delimiter=';', index_col='id_aluno')
            self.dfs_dict[nome_df] = df
        except Exception as e:
            print(e)

    def show_df_names(self):
        print("============= NOME DOS DF =============")
        for key in self.dfs_dict.keys():
            print(key)
        print("=======================================")

    def merge_tables(self, df1, df2, new_df):
        print("============= COMEÇANDO MERGE =============")
        try:
            df = pd.merge(self.dfs_dict[df1], self.dfs_dict[df2], how="inner", on="id_aluno")
            self.dfs_dict[new_df] = df
            self.merged_df = new_df
        except Exception as e:
            print(e)
        else:
            print("============= MERGE  COMPLETO =============")

    def check_var(self, **kwargs) -> str: # retorna o nome da variavel nao nula
        # verifica qual a variavel nao tem valor nulo em dados_aluno()
        # a vantagem disso é saber em qual df a gente faz a busca
        # uma vez que ele pode nao ter dado merge ainda
        for arg in kwargs:
            if arg != None:
                return (arg, arg.__name__)
        return ValueError

    def print_df(self, nome_df):
        print("===================== PRINTANDO O DF ========================")
        try:
            self.dfs_dict[nome_df]
        except:
            print(f'=========== DF {nome_df} NAO EXISTE ===========')
        else:
            print(self.dfs_dict[nome_df])
        print("=================================================================")

    def gravar_tabela(self, nome_tabela, path=""):
        print('================== GERANDO UM NOVO CSV ==================')
        try:
            self.dfs_dict[nome_tabela].to_csv(f"{path}{nome_tabela}.csv", sep=';')
        except:
            print("============== ALGO DEU ERRADO NA GERAÇÃO DO CSV ==============")
        print("================== FINALIZANDO ==================")

    # ainda nao ta funcionando
    def dados_aluno(self, table, id_aluno=None, Nome=None):
        print("========== COMEÇANDO BUSCA ===========")
        try:
            var_filtro_val= self.check_var(id_aluno, Nome)
        except:
            print("=== ERRO NO PARSING ===")        
        print(self.dfs_dict[table].query(f"{var_filtro_val[0]} == {var_filtro_val[1]}"))
        print("========== BUSCA FINALIZADA ==========")

