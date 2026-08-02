# Semana 07 - Classes, herança, polimorfismo, operadores e templates de classes com exceções

**Tema:** Classes, herança, polimorfismo, operadores e templates de classes com exceções

**Linguagem:** C++

> Nota: os ficheiros `tests.cpp` contêm os testes automatizados (Google Test) originais de cada exercício — servem como especificação adicional do comportamento esperado, mas não compilam isoladamente sem o framework GoogleTest e o `CMakeLists.txt` originais.

---

## Exercício 1 - Parque de Estacionamento

Pretende-se implementar uma classe `ParqueEstacionamento` que gere os clientes e os lugares disponíveis num parque de estacionamento.

Cada cliente do parque possui um cartão de acesso, representado pela classe `InfoCartao`, com dois campos: o `nome` do cliente e um booleano `presente` que indica se o carro do cliente se encontra atualmente dentro do parque. O parque mantém internamente um `vector<InfoCartao> clientes` com a informação de todos os clientes registados.

O parque tem uma capacidade fixa de lugares (`lotacao`) e um número máximo de clientes que pode registar (`numMaximoClientes`) — ambos definidos na construção do parque e nunca alterados depois, pelo que devem ser declarados como membros `const`.

Implemente a classe `ParqueEstacionamento` com os seguintes métodos:

- **Construtor** `ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli)` — inicializa o parque com a lotação e o número máximo de clientes indicados, sem nenhum cliente registado.
- **`getNumLugares()`** e **`getNumMaximoClientes()`** — devolvem, respetivamente, a lotação total e o número máximo de clientes permitido.
- **`posicaoCliente(nome)`** — pesquisa sequencialmente pelo cliente com o nome dado no vetor `clientes` e devolve o seu índice, ou `-1` se o cliente não existir.
- **`adicionaCliente(nome)`** — regista um novo cliente no parque (inicialmente fora do parque, `presente = false`). Deve verificar se já existe capacidade de registo (`numMaximoClientes`) e se o cliente já não está registado, devolvendo `false` nesses casos de falha.
- **`entrar(nome)`** — simula a entrada de um carro no parque. Deve falhar (devolver `false`) se o cliente não estiver registado, se já estiver dentro do parque, ou se o parque estiver cheio (todos os lugares ocupados). Caso contrário, marca o cliente como presente e devolve `true`.
- **`retiraCliente(nome)`** — remove o registo de um cliente do parque. Só é permitido remover um cliente que esteja atualmente fora do parque (o carro não pode estar lá dentro).
- **`sair(nome)`** — simula a saída de um carro do parque. Deve falhar se o cliente não estiver registado ou não estiver atualmente dentro do parque.
- **`getNumLugaresOcupados()`** — devolve o número de lugares atualmente ocupados (número de clientes com `presente = true`).
- **`getNumClientesAtuais()`** — devolve o número total de clientes atualmente registados no parque.

**Solução:** `01-parque-estacionamento/`

---

## Exercício 2 - Gestão de uma frota de veículos

Pretende-se modelar uma frota de veículos usando hierarquia de classes e polimorfismo.

A classe base `Vehicle` guarda `brand` (marca), `month` e `year` de fabrico, e define os métodos comuns `getYear()`, `getMonth()`, `getBrand()`, um método `info()` (e uma variante `info(ostream&)`) que reporta os dados do veículo, um `operator<` que compara veículos pela data de fabrico (ano e mês), e um método puramente virtual `calculateTax()` que cada subclasse deve implementar.

A partir de `Vehicle` derivam:

- **`MotorVehicle`** — acrescenta `fuel` (combustível) e `cylinder` (cilindrada). Expõe `getFuel()`. Implementa `calculateTax()` com base numa tabela de consulta (cilindrada / combustível / ano).
- **`Car`** (deriva de `MotorVehicle`) e **`Truck`** (deriva de `MotorVehicle`, acrescenta `maximumLoad`) — cada uma sobrepõe `info()` para incluir os seus dados específicos.
- **`Bicycle`** (deriva diretamente de `Vehicle`) — acrescenta `type`. Como não é motorizado, não paga imposto (`calculateTax()` devolve 0).

Implemente os construtores de todas as classes e os métodos `getFuel`/`getBrand`. Decida cuidadosamente quais os métodos que devem ser declarados `virtual` para garantir que a informação correta é impressa, mesmo quando se acede aos objetos através de um ponteiro `Vehicle*`.

A classe `Fleet` gere uma frota — internamente um `vector<Vehicle*>`. Implemente:

- **`addVehicle(Vehicle*)`** — adiciona um veículo à frota.
- **`numVehicles()`** — número de veículos na frota.
- **`lowestYear()`** — ano de fabrico mais antigo entre todos os veículos.
- **`operator<<`** — imprime todos os veículos da frota (deve invocar corretamente o `info()` polimórfico de cada veículo).
- **`operator()(int yearM)`** — operador de chamada de função sobre `Fleet`, que devolve todos os veículos fabricados num determinado ano.
- **`totalTax()`** — soma o imposto (`calculateTax()`) de todos os veículos da frota.
- **`removeOldVehicles(int y1)`** — remove da frota todos os veículos fabricados no ano `y1` ou antes, devolvendo quantos foram removidos.

**Solução:** `02-frota-veiculos/`

---

## Exercício 3 - Gestão de um jardim zoológico (herança múltipla)

Pretende-se modelar a gestão de animais e veterinários num jardim zoológico, explorando herança múltipla.

A classe abstrata `Animal` guarda `name`, `age` e um ponteiro para o `Veterinary` responsável pelo animal (pode ser `nullptr`). Define `getInfo()` (virtual, devolve toda a informação do animal, incluindo o veterinário se existir) e `isYoung()` (puramente virtual — cada espécie decide o que significa "ser jovem"). Tem ainda um membro estático `youngest` e um método estático `getYoungest()` que é atualizado sempre que se consulta se um animal é jovem.

Derivam de `Animal`:

- **`Dog`** — acrescenta `breed` (raça). É considerado jovem se tiver idade inferior a 5 anos.
- **`Bat`** — deriva **simultaneamente** de `Animal` e de `Flying` (herança múltipla). `Flying` acrescenta `maxVelocity` e `maxAltitude`. Um morcego é considerado jovem se tiver idade inferior a 4 anos.

A classe `Veterinary` representa um veterinário (nome e código).

A classe `Zoo` gere o jardim zoológico, com um `vector<Animal*>` e um `vector<Veterinary*>`. Implemente:

- Construtores de todas as classes.
- **`Animal::getYoungest()`** — atualiza o membro estático `youngest` sempre que necessário.
- **`isYoung()`** — específico por espécie, conforme os critérios acima.
- **`Zoo::addAnimal(Animal*)`** — adiciona um animal ao zoo.
- **`Zoo::getInfo()`** — imprime a informação completa de todos os animais do zoo (incluindo o respetivo veterinário).
- **`Zoo::isYoung(nome)`** — verifica se um animal específico (pelo nome) é considerado jovem.
- **`Zoo::allocateVeterinarians(istream&)`** — lê pares nome/código de veterinários a partir de um stream (ficheiro `vets.txt`) e distribui os veterinários uniformemente pelos animais do zoo.
- **`Zoo::removeVeterinary(nome)`** — remove um veterinário do zoo, reatribuindo os animais que ficaram sem veterinário.
- **`Zoo::operator<`** — compara dois zoos pela soma das idades de todos os seus animais.

O enunciado original sugere ainda, como boa prática (não avaliada nos testes), a documentação do código com Doxygen — daí o ficheiro `Doxyfile` que acompanhava originalmente este exercício.

**Solução:** `03-zoo-heranca-multipla/`

---

## Exercício 4 - Grafo genérico com templates

Pretende-se implementar uma classe genérica `Graph<N, E>` que representa um grafo dirigido, em que `N` é o tipo de informação guardada em cada nó e `E` é o tipo de valor associado a cada aresta.

Cada `Graph` mantém internamente um `vector<Node<N,E>*>` com todos os nós. Cada `Node<N,E>` guarda a sua informação (`info`) e um `vector<Edge<N,E>>` com as arestas que saem dele, mantido ordenado pelo destino. Cada `Edge<N,E>` guarda o valor associado (`value`) e um ponteiro para o nó de destino.

Como se trata de uma classe template, **toda a implementação tem de estar no ficheiro `.h`** — não há separação entre declaração e implementação em ficheiros `.cpp`/`.h` distintos.

Implemente:

- **Construtor e destrutor** — o destrutor deve libertar corretamente todos os nós alocados dinamicamente.
- **`numNodes()`** e **`numEdges()`** — número total de nós e de arestas no grafo.
- **`addNode(const N&)`** — adiciona um novo nó ao grafo. Se já existir um nó com a mesma informação, deve lançar a exceção `NodeAlreadyExists<N>` (já disponibilizada).
- **`addEdge(const N& begin, const N& end, const E& val)`** — adiciona uma aresta entre dois nós existentes. Deve lançar `NodeDoesNotExist<N>` se algum dos nós não existir. Deve ainda **implementar uma nova exceção `EdgeAlreadyExists<N>`** (com o respetivo `operator<<`) e lançá-la se já existir uma aresta entre os dois nós.
- **`edgeValue(begin, end)`** — devolve uma referência ao valor associado à aresta entre dois nós (para permitir leitura e escrita). Deve lançar `NodeDoesNotExist<N>` se algum nó não existir, e **implementar uma nova exceção `EdgeDoesNotExist<N>`** (com `operator<<`) se a aresta não existir.
- **`removeEdge(begin, end)`** — remove a aresta entre dois nós, lançando as mesmas exceções que `edgeValue` conforme o caso.
- **`print(ostream&)`** — imprime o grafo no formato `( A [B 5] [C 8] ) ( B [D 9] )`, onde cada `( ... )` representa um nó seguido das suas arestas de saída (`[destino valor]`). Use este método para implementar também o `operator<<` do grafo.

**Exemplo:**
```
Graph<char,int> g;
g.addNode('A').addNode('B').addNode('C');
g.addEdge('A', 'B', 5);
g.addEdge('A', 'C', 8);
cout << g;
// ( A [B 5] [C 8] ) ( B ) ( C )
```

**Solução:** `04-grafo-generico/`

---
