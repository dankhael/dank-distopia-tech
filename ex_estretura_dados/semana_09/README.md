# Semana 09 - Árvores binárias de pesquisa e tabelas de dispersão

**Tema:** Árvores binárias de pesquisa e tabelas de dispersão

**Linguagem:** C++

> Nota: os ficheiros `tests.cpp` contêm os testes automatizados (Google Test) originais de cada exercício — servem como especificação adicional do comportamento esperado, mas não compilam isoladamente sem o framework GoogleTest e o `CMakeLists.txt` originais.

---

## Exercício 1 - Dicionário com árvore binária de pesquisa

Pretende-se implementar um dicionário de palavras usando uma árvore binária de pesquisa (`BST<WordMeaning>`, já disponibilizada em `bst.h`), mantendo as entradas sempre ordenadas alfabeticamente.

Cada entrada do dicionário é representada por `WordMeaning`, que guarda uma palavra (`word`) e o seu significado (`meaning`), com um `operator<` que ordena por palavra.

A classe `Dictionary` guarda a árvore de entradas (`BST<WordMeaning> words`). Implemente:

- **`readDictionary(ifstream&)`** — lê o dicionário a partir de um ficheiro de texto (`dic.txt`), no qual cada entrada ocupa duas linhas consecutivas (palavra, depois significado), inserindo cada par lido na árvore.
- **`print()`** — imprime todas as entradas do dicionário por ordem alfabética (percorrendo a árvore em-ordem).
- **`searchFor(word)`** — devolve o significado da palavra pedida. Se a palavra não existir no dicionário, deve lançar a exceção `WordInexistent`, que expõe a palavra e o significado imediatamente antes e imediatamente depois da palavra procurada (predecessor e sucessor na árvore), de forma a sugerir entradas próximas ao utilizador.
- **`correct(word, newMeaning)`** — se a palavra já existir no dicionário, atualiza o seu significado e devolve `true`; caso contrário, insere a palavra como uma nova entrada e devolve `false`.

Nota: o `tests.cpp` e o `enunciado_original.pdf` deste exercício são partilhados com o Exercício 2 (ambos vêm do mesmo enunciado original da semana de árvores binárias), pelo que estão duplicados nas duas subpastas para cada uma ficar autocontida.

**Solução:** `01-dicionario-bst/`

---

## Exercício 2 - Jogo de "matraquilhos" numa árvore binária completa

Pretende-se simular um jogo do tipo "pinball", em que uma bola desce por uma árvore binária completa de nós `Circle`, indo de raiz até uma folha, e a pontuação da folha alcançada é a pontuação ganha nessa jogada.

Cada `Circle` guarda uma pontuação (`points`), um estado booleano (`state`) que determina o próximo caminho a seguir (falso → esquerda, verdadeiro → direita) e um contador de visitas (`nVisits`). Sempre que a bola passa por um nó, o seu estado é invertido (`changeState()`) e o contador de visitas é incrementado.

A classe `Game` guarda a árvore do jogo (`BinaryTree<Circle> game`). Implemente:

- **`Game(int h, vector<int>& points, vector<bool>& states)`** — constrói uma árvore binária completa de altura `h`, a partir de vetores com a pontuação e o estado inicial de cada nó, indexados por ordem por níveis (level-order).
- **`writeGame()`** — devolve uma string com o estado de cada nó (pontos, estado, número de visitas) por ordem de níveis.
- **`move()`** — simula uma jogada: percorre a árvore da raiz até uma folha seguindo o estado de cada nó visitado (invertendo-o e incrementando o seu contador de visitas ao longo do percurso), e devolve a pontuação da folha alcançada.
- **`mostVisited()`** — devolve o maior número de visitas registado entre todos os nós da árvore, excluindo a raiz, considerando todas as jogadas efetuadas até ao momento.

Nota: o `tests.cpp` e o `enunciado_original.pdf` deste exercício são partilhados com o Exercício 1 (ambos vêm do mesmo enunciado original da semana de árvores binárias), pelo que estão duplicados nas duas subpastas para cada uma ficar autocontida.

**Solução:** `02-jogo-pinball-arvore-binaria/`

---

## Exercício 3 - Simulador de apostas de Totoloto

Pretende-se implementar um pequeno simulador de apostas de lotaria (à semelhança do Totoloto), usando `unordered_set` para representar conjuntos de números apostados.

A classe `Bet` representa uma aposta, guardando os seus números numa tabela de dispersão `tabHInt` (definida como `unordered_set<unsigned>`), com um número de números apostados entre 6 e 12. Implemente:

- **`generateBet(const vector<unsigned>& values, unsigned n = 6)`** — gera uma aposta escolhendo os primeiros `n` números não repetidos de um vetor `values` (previamente gerado aleatoriamente) e inserindo-os no conjunto da aposta.
- **`contains(num)`** — verifica se um determinado número faz parte da aposta.
- **`countRights(draw)`** — dado o conjunto de números sorteados (`draw`), conta quantos dos números da aposta constam do sorteio.

A classe `Player` representa um jogador, guardando o seu nome e o conjunto de apostas que já fez, num `unordered_set<Bet, betHash, betHash>` (é fornecida a struct `betHash`, que serve simultaneamente de função de hash e de comparação de igualdade entre apostas). Implemente:

- **`addBet(const Bet&)`** — regista uma nova aposta do jogador.
- **`betsInNumber(num)`** — conta, entre todas as apostas do jogador, quantas incluem um determinado número.
- **`drawnBets(draw)`** — devolve o subconjunto das apostas do jogador consideradas "vencedoras" face a um sorteio `draw`, isto é, aquelas que acertam em mais de 3 números.

**Solução:** `03-apostas-totoloto-hashing/`

---
