#!/bin/bash

while IFS= read -r command; do
    # Executa o comando e redireciona a saída para a variável "output"
    output=$(bash -c "$command" 2>&1)

    # Verifica o código de saída do comando
    if [ $? -eq 0 ]; then
        # Comando executado com sucesso (código de saída zero)
        echo -e "\033[32m$command\033[0m"  # Exibe o comando em verde
    else
        # Comando com erro (código de saída diferente de zero)
        echo -e "\033[31m$command\033[0m"  # Exibe o comando em vermelho
    fi

    # Exibe a saída do comando
    echo "$output"

    echo "----------------------------------------"
done < comandos.txt
