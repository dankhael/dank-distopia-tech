# Semana 10 - Filas de prioridade e conjuntos disjuntos

**Tema:** Filas de prioridade e conjuntos disjuntos

**Linguagem:** C++

> Nota: os ficheiros `tests.cpp` contêm os testes automatizados (Google Test) originais de cada exercício — servem como especificação adicional do comportamento esperado, mas não compilam isoladamente sem o framework GoogleTest e o `CMakeLists.txt` originais.

---

## Exercício 1 - Máquina de empacotamento (bin packing guloso)

Pretende-se simular uma máquina que empacota objetos em caixas, seguindo uma heurística gulosa: empacotar sempre primeiro os objetos mais pesados, colocando-os na caixa mais cheia que ainda tenha espaço suficiente para os receber.

A classe `Object` representa um objeto a empacotar, com um identificador (`id`) e um peso (`weight`), e um `operator<` que compara objetos pelo peso.

A classe `Box` representa uma caixa, guardando os objetos já colocados numa pilha (`stack<Object>`), um identificador (`id`), a capacidade total (`capacity`) e a capacidade livre restante (`free`). O `operator<` de `Box` compara caixas pela capacidade livre restante, de forma a que a fila de prioridade das caixas coloque no topo a caixa **com menos espaço livre** (mais cheia) entre as que ainda cabem o próximo objeto.

A classe `PackagingMachine` guarda uma fila de prioridade de objetos por peso (`priority_queue<Object>`, ordenando os mais pesados primeiro) e uma fila de prioridade de caixas por espaço livre (`priority_queue<Box>`). Implemente:

- **`loadObjects(vector<Object>& objs)`** — percorre o vetor de objetos de entrada, filtra os que cabem numa caixa (peso não superior à capacidade das caixas), remove-os do vetor de entrada e insere-os na fila de prioridade de objetos. Devolve o número de objetos carregados.
- **`searchBox(Object& obj)`** — retira da fila de prioridade de caixas a próxima caixa com espaço livre suficiente para o objeto dado; se nenhuma caixa existente tiver espaço suficiente, cria e devolve uma caixa nova. Este método apenas *procura* a caixa — não coloca o objeto lá dentro.
- **`packObjects()`** — repete o processo de retirar o objeto mais pesado da fila, procurar uma caixa adequada com `searchBox`, e colocar o objeto nessa caixa (devolvendo-a depois à fila de prioridade de caixas), até esgotar os objetos carregados. Devolve o número total de caixas usadas.
- **`printObjectsNotPacked()`** — imprime os objetos que não foram (ou não puderam ser) empacotados.
- **`Box::printContent()`** — imprime o conteúdo de uma caixa.
- **`boxWithMoreObjects()`** — devolve a caixa que contém mais objetos empacotados. Deve lançar uma nova exceção `MachineWithoutBoxes` se a máquina não tiver nenhuma caixa criada.

**Solução:** `01-maquina-embalagem-filas-prioridade/`

---

## Exercício 2 - Geração aleatória de labirintos

Pretende-se implementar a estrutura de dados `DisjointSets` (conjuntos disjuntos, representados sobre um `vector<int>` com os inteiros `0..n-1`) e usá-la para gerar labirintos aleatórios através da remoção sucessiva de paredes.

A classe `DisjointSets` implementa a estrutura clássica de union-find, com `find(v)` (devolve o representante do conjunto a que `v` pertence) e `unionSets(root1, root2)` (junta dois conjuntos, na sua versão simples/"weak union", sem otimizações de rank ou compressão de caminho). Implemente:

- **`getNumberOfSets()`** — devolve o número de conjuntos distintos atualmente existentes (isto é, o número de representantes únicos entre todas as células).

A classe `Maze` representa um labirinto retangular de `nrows` × `ncols` células, em que cada célula corresponde inicialmente a um conjunto disjunto próprio (todas as paredes fechadas). Guarda internamente a estrutura `DisjointSets` sobre as células e um vetor `noWalls` com os pares de células entre as quais a parede já foi removida. Implemente:

- **`Maze(int rows, int cols)`** — construtor que inicializa `nrows`, `ncols` e a estrutura de conjuntos disjuntos (uma célula por conjunto).
- **`buildRandomMaze()`** — algoritmo de geração aleatória do labirinto: repetidamente escolhe uma célula `x` ao acaso e uma célula vizinha `y` também ao acaso (usando o método auxiliar `getNeighbours`); se `x` e `y` ainda pertencerem a conjuntos diferentes (isto é, ainda existe parede entre elas), remove a parede entre as duas células (regista o par em `noWalls`) e junta os dois conjuntos com `unionSets`. O processo repete-se até restar um único conjunto (`getNumberOfSets() == 1`), garantindo que todas as células ficam ligadas entre si.

Este exercício não tem testes automatizados de verificação de corretude (é essencialmente estocástico) — a validação é feita visualmente, através do método `printMaze()`, que desenha o labirinto gerado.

**Solução:** `02-labirinto-conjuntos-disjuntos/`

---
