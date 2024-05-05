Lab02a - Processos

1 Rode o programa anterior para valores grandes de n. As mensagens sempre estar˜ao ordenadas pelo valor de i?

R: As saídas estão ordenadas pelo valor de ‘i’ porque a função ‘fprintf’ é chamada dentro do ‘loop’ for que está iterando em ‘i’ de ‘1’ até ‘n-1’.

2 O que acontece se o programa anterior escreve-se as mensagenspara sys.stdout, usando print, ao inves de para sys.stderr?

R: Se o programa anterior escrever as mensagens para sys.stdout usando printf em vez de fprintf para sys.stderr, as mensagens serão enviadas para a saída padrão em vez da saída de erro padrão.






Pthreads parte 2

a) Implemente uma solução utilizando Mutex e comparece com a anterior. O que mudou? Por quê?

R:
A principal mudança com o uso do Mutex é evitar condições de corrida ao atualizar a variável compartilhada pi_total. Sem o Mutex, múltiplas threads podem modificar pi_total simultaneamente, o que pode levar a resultados incorretos. Com o Mutex, garantimos que apenas uma thread por vez possa atualizar pi_total, mantendo a corretude do resultado.


b) No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?

R:

Cálculo de Pi usando Pthreads

Este repositório contém duas implementações do cálculo de Pi usando o método Gregory-Leibniz. Ambas as versões utilizam múltiplas threads, mas uma usa Mutex para garantir a segurança na atualização de variáveis compartilhadas.

Diferenças nos Resultados

As diferenças entre os resultados das duas versões podem ser atribuídas à presença de condições de corrida na versão sem Mutex. A ausência de Mutex pode resultar em cálculos imprecisos devido a atualizações concorrentes na variável compartilhada.

Conclusão

O uso de Mutex, apesar de adicionar algum overhead, é essencial para garantir a precisão dos resultados em programas multithread.
