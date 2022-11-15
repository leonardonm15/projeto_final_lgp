from final import Sistema

path1 = r".\nomes.csv"
path2 = r".\notas.csv"

sistema = Sistema()

sistema.load_csv(path1, 'nomes')
sistema.load_csv(path2, 'notas')

sistema.show_df_names()
sistema.print_df('nomes')
sistema.print_df('notas')

sistema.merge_tables("nomes", "notas", "notas_nomes")

sistema.show_df_names()

sistema.print_df("notas_nomes")
sistema.gravar_tabela("notas_nomes")

#sistema.dados_aluno("notas_nomes", id_aluno=1033221237)