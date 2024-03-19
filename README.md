Lab02a - Processos

1 Rode o programa anterior para valores grandes de n. As mensagens sempre estar˜ao ordenadas pelo valor de i?

R: As saídas estão ordenadas pelo valor de ‘i’ porque a função ‘fprintf’ é chamada dentro do ‘loop’ for que está iterando em ‘i’ de ‘1’ até ‘n-1’.

2 O que acontece se o programa anterior escreve-se as mensagenspara sys.stdout, usando print, ao inves de para sys.stderr?

R:Se o programa anterior escrever as mensagens para sys.stdout usando printf em vez de fprintf para sys.stderr, as mensagens serão enviadas para a saída padrão em vez da saída de erro padrão.
