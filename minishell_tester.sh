#!/bin/bash

# Caminho para o seu executável do minishell
minishell="./minishell"

# Comando a ser executado no minishell
comando="lss"

# Arquivo temporário para armazenar o comando
tempfile=$(mktemp)
echo "$comando" > "$tempfile"

# Cores para exibir as mensagens
verde='\033[32m'
vermelho='\033[31m'
reset='\033[0m'

# Verifica se o executável do minishell existe
if [ ! -x "$minishell" ]; then
    echo -e "${vermelho}Executável do minishell não encontrado.${reset}"
    rm "$tempfile"
    exit 1
fi

# Executa o minishell lendo o comando do arquivo temporário
output=$($minishell < "$tempfile" 2>&1)
exit_code=$?

# Verifica o código de saída do minishell
if [ $exit_code -eq 0 ]; then
    echo -e "${verde}Comando executado com sucesso: $comando${reset}"
else
    echo -e "${vermelho}Erro na execução do comando: $comando${reset}"
fi

# Exibe a saída do comando
echo "$output"

# Remove o arquivo temporário
rm "$tempfile"
