# Semana 08 - Pesquisa e ordenação, listas ligadas, pilhas e filas

**Tema:** Pesquisa e ordenação, listas ligadas, pilhas e filas

**Linguagem:** C++

> Nota: os ficheiros `tests.cpp` contêm os testes automatizados (Google Test) originais de cada exercício — servem como especificação adicional do comportamento esperado, mas não compilam isoladamente sem o framework GoogleTest e o `CMakeLists.txt` originais.

---

## Exercício 1 - Parque de estacionamento com frequência de utilização

Este exercício estende o problema do parque de estacionamento da Semana 01 (agora com as classes renomeadas para `CarPark`/`InfoCard`), acrescentando o registo da frequência de utilização de cada cliente e exigindo o uso de algoritmos de pesquisa e ordenação explícitos.

Cada `InfoCard` passa a ter também um campo `frequency` (número de vezes que o cliente já usou o parque), além de `name` e `present`. São fornecidos os ficheiros auxiliares `sequentialSearch.h` (pesquisa sequencial genérica) e `insertionSort.h` (insertion sort genérico), que devem ser reutilizados na implementação.

Implemente:

- **`clientPosition(nome)`** — reimplementado usando a função de `sequentialSearch.h` em vez de um ciclo manual.
- Atualização de `enter`/`leave` para incrementar corretamente o campo `frequency` de cada cliente sempre que o carro entra no parque.
- **`getFrequency(nome)`** — devolve a frequência de utilização de um cliente. Deve lançar uma nova exceção `ClientDoesNotExist` (que expõe `getName()`) se o cliente não existir.
- **`sortClientsByFrequency()`** — ordena o vetor de clientes usando `insertionSort.h`, por ordem decrescente de frequência; em caso de empate, ordena por ordem alfabética crescente do nome.
- **`clientsBetween(f1, f2)`** — devolve, ordenados alfabeticamente, os nomes de todos os clientes cuja frequência de utilização está entre `f1` e `f2` (inclusive).
- **`sortClientsByName()`** — ordena o vetor de clientes por nome (pode usar qualquer algoritmo de ordenação).
- **`operator<<`** — imprime todos os clientes do parque, indicando nome, se estão presentes e a respetiva frequência.
- **`getClientAtPos(p)`** — devolve o cliente na posição `p` do vetor. Deve lançar uma nova exceção `PositionDoesNotExist` (que expõe `getPosition()`) se a posição for inválida.

**Solução:** `01-parque-estacionamento-v2-pesquisa-ordenacao/`

### Nota teórica (sem código)

A segunda parte do enunciado original pedia também a análise da complexidade algorítmica (notação Big-O) de duas rotinas fornecidas em pseudocódigo: uma rotina de impressão de uma matriz com ciclos aninhados, e uma rotina de pesquisa binária. Essa parte era puramente teórica (papel/análise), sem componente de implementação, pelo que não tem ficheiros de código associados nesta reorganização — consulte `01-parque-estacionamento-v2-pesquisa-ordenacao/enunciado_original.pdf` para o enunciado completo dessa análise.

---

## Exercício 2 - Jogo do Pim Pam Pum

Pretende-se implementar o clássico jogo infantil português "Pim Pam Pum" — uma variante do problema de Josephus — usando `list<Kid>` como estrutura de dados subjacente.

A classe `Kid` representa uma criança, guardando `name` e `age`.

A classe `Game` guarda a lista de crianças em jogo, `list<Kid> kids`. Implemente:

- **Construtores** — um construtor por omissão (sem crianças) e um construtor que recebe uma lista de crianças já existente.
- **`addKid(const Kid&)`** — adiciona uma criança ao fim do jogo.
- **`getKids()`** / **`setKids(const list<Kid>&)`** — getter e setter da lista de crianças.
- **`write()`** — devolve uma string com uma linha `"nome : idade"` por cada criança do jogo.
- **`loseGame(phrase)`** — simula o jogo de eliminação: usando o método auxiliar já fornecido `numberOfWords(phrase)` (conta o número de palavras da lengalenga), percorre ciclicamente a lista de crianças eliminando, a cada volta, a criança em que a contagem "cai", até restar apenas uma. Devolve a criança que ganha o jogo (a última a restar).
- **`reverse()`** — inverte a ordem da lista de crianças *in place* e devolve uma referência à lista invertida.
- **`removeOlder(unsigned a)`** — remove da lista do jogo (e devolve, numa nova lista), todas as crianças com idade superior a `a`.
- **`operator==`** — compara dois jogos, considerando-os iguais se as suas listas de crianças forem idênticas, elemento a elemento, pela mesma ordem.
- **`shuffle()`** — devolve uma nova lista com as crianças do jogo baralhadas aleatoriamente (usando `rand()`), sem alterar a lista original.

**Exemplo:**
```
Game g;
g.addKid(Kid("Ana", 6));
g.addKid(Kid("Bruno", 8));
g.addKid(Kid("Carla", 7));

cout << g.write();
// Ana : 6
// Bruno : 8
// Carla : 7

Kid vencedor = g.loseGame("Pim pam pum, quem sai es tu");
```

**Solução:** `02-jogo-pim-pam-pum/`

---

## Exercício 3 - Pilha estendida com mínimo em O(1)

Pretende-se implementar uma classe template `StackExt<T>`, um "wrapper" sobre a `stack<T>` da STL, que acrescenta a capacidade de saber, em tempo O(1), qual é o valor mínimo atualmente presente na pilha.

Para isso, a classe mantém duas pilhas internas: `allStack` (a pilha "normal", com todos os elementos) e `minStack` (uma pilha auxiliar que, em cada momento, tem no topo o valor mínimo entre os elementos ainda presentes em `allStack`).

Implemente:

- **`push(const T& val)`** — insere um elemento no topo da pilha. Deve também atualizar `minStack`: se `minStack` estiver vazia ou o novo valor for menor ou igual ao seu topo, o novo valor deve também ser empilhado em `minStack`.
- **`pop()`** — remove o elemento do topo. Se o elemento removido de `allStack` for igual ao topo de `minStack`, este também deve ser removido.
- **`top()`** — devolve uma referência ao elemento no topo da pilha.
- **`empty()`** — indica se a pilha está vazia.
- **`findMin()`** — devolve, em O(1), o valor mínimo atualmente presente na pilha (o topo de `minStack`).

Nota: o `tests.cpp` e o `enunciado_original.pdf` deste exercício são partilhados com o Exercício 4 (ambos vêm do mesmo enunciado original da semana de pilhas e filas), pelo que estão duplicados nas duas subpastas para cada uma ficar autocontida.

**Solução:** `03-pilha-com-minimo/`

---

## Exercício 4 - Simulação de balcão de embrulho de presentes

Pretende-se simular, por eventos discretos, o funcionamento de um balcão de embrulho de presentes com uma única fila de espera (`queue<Client>`).

A classe `Client` representa um cliente que chega ao balcão com um número aleatório de presentes para embrulhar (`numGifts`, entre 1 e 5).

A classe `Counter` representa o balcão e mantém: a fila de clientes em espera, o tempo de embrulho por presente (`wrappingTime`, constante), o instante da próxima entrada (`nextEnter`) e da próxima saída (`nextLeave`), o instante atual da simulação (`actualTime`) e o número total de clientes já atendidos (`numAttendedClients`).

Implemente:

- **`Client()`** — construtor que gera aleatoriamente o número de presentes do cliente (entre 1 e 5). **`getNumGifts()`** — getter correspondente.
- **`Counter(unsigned wt = 2)`** — construtor que inicializa o tempo de embrulho por presente e gera aleatoriamente o instante da primeira entrada (`nextEnter`, entre 1 e 20). Implemente também os restantes getters (`getActualTime`, `getNextEnter`, `getNumAttendedClients`, `getWrappingTime`, `getNextLeave`).
- **`getNextClient()`** — devolve uma referência ao cliente no início da fila. Deve lançar uma exceção `EmptyQueue` (que expõe `getMsg()`) se a fila estiver vazia.
- **`enter()`** — cria um novo cliente e coloca-o na fila; agenda o instante da próxima entrada; se a fila estava vazia antes desta entrada, atualiza também `nextLeave` (o balcão começa imediatamente a atender este cliente); imprime o estado do balcão.
- **`leave()`** — remove o cliente do início da fila (tratando corretamente o caso de fila vazia através da exceção `EmptyQueue`); atualiza `nextLeave` para o cliente seguinte (se existir); imprime o estado do balcão.
- **`nextEvent()`** — determina qual dos dois eventos (`nextEnter` ou `nextLeave`) ocorre primeiro, invoca o método correspondente (`enter()` ou `leave()`) e avança `actualTime` para esse instante.
- **`operator<<`** — imprime o número de clientes já atendidos e o número de clientes atualmente em espera.

Nota: o `tests.cpp` e o `enunciado_original.pdf` deste exercício são partilhados com o Exercício 3 (ambos vêm do mesmo enunciado original da semana de pilhas e filas), pelo que estão duplicados nas duas subpastas para cada uma ficar autocontida.

**Solução:** `04-simulacao-balcao-filas/`

---
