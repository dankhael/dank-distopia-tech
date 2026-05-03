# Milestone 7 - Binary Search, Grafos, Dijkstra e Árvores

**Tema:** Algoritmos de busca, grafos e estruturas de árvore

**Linguagem:** Python

---

## Exercício 1 - Binary Search

Implemente o algoritmo de busca binária em uma lista ordenada. A função deve retornar o índice do elemento buscado ou -1 se não encontrado.

```python
def busca_binaria(lista, alvo):
    # seu codigo aqui
    pass

# Exemplos:
# busca_binaria([1, 3, 5, 7, 9, 11, 13], 7) -> 3
# busca_binaria([1, 3, 5, 7, 9, 11, 13], 4) -> -1
# busca_binaria([2, 4, 6, 8, 10], 10) -> 4
```

---

## Exercício 2 - Binary Search recursivo

Implemente a versão recursiva da busca binária.

```python
def busca_binaria_recursiva(lista, alvo, inicio=0, fim=None):
    # seu codigo aqui
    pass

# Exemplos:
# busca_binaria_recursiva([1, 3, 5, 7, 9, 11], 5) -> 2
# busca_binaria_recursiva([1, 3, 5, 7, 9, 11], 6) -> -1
```

---

## Exercício 3 - Representar um grafo

Crie uma classe `Grafo` que use um dicionário de listas de adjacência. Implemente:
- `adicionar_vertice(v)`: adiciona um vértice
- `adicionar_aresta(v1, v2)`: adiciona uma aresta entre v1 e v2
- `mostrar()`: imprime a lista de adjacência

```python
class Grafo:
    def __init__(self):
        self.adjacencia = {}

    def adicionar_vertice(self, v):
        pass

    def adicionar_aresta(self, v1, v2):
        pass

    def mostrar(self):
        pass

# Teste:
# g = Grafo()
# g.adicionar_vertice("A")
# g.adicionar_vertice("B")
# g.adicionar_vertice("C")
# g.adicionar_aresta("A", "B")
# g.adicionar_aresta("A", "C")
# g.adicionar_aresta("B", "C")
# g.mostrar()
# A: [B, C]
# B: [A, C]
# C: [A, B]
```

---

## Exercício 4 - BFS (Busca em Largura)

Implemente o algoritmo de busca em largura (BFS) para percorrer um grafo a partir de um vértice inicial.

```python
from collections import deque

def bfs(grafo, inicio):
    # seu codigo aqui
    pass

# Exemplo com dicionário de adjacência:
# grafo = {
#     "A": ["B", "C"],
#     "B": ["A", "D", "E"],
#     "C": ["A", "F"],
#     "D": ["B"],
#     "E": ["B", "F"],
#     "F": ["C", "E"]
# }
# bfs(grafo, "A") -> ["A", "B", "C", "D", "E", "F"]
```

---

## Exercício 5 - DFS (Busca em Profundidade)

Implemente o algoritmo de busca em profundidade (DFS), tanto na versão iterativa quanto na recursiva.

```python
def dfs_iterativo(grafo, inicio):
    # seu codigo aqui
    pass

def dfs_recursivo(grafo, inicio, visitados=None):
    # seu codigo aqui
    pass

# Usando o mesmo grafo do exercício anterior:
# dfs_iterativo(grafo, "A") -> ["A", "C", "F", "E", "B", "D"]
# (a ordem pode variar dependendo da implementação)
```

---

## Exercício 6 - Árvore binária

Implemente uma árvore binária de busca (BST) com as operações:
- `inserir(valor)`: insere um valor na árvore
- `buscar(valor)`: retorna True se o valor existe
- `em_ordem()`: retorna os valores em ordem crescente (in-order traversal)

```python
class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

class ArvoreBinaria:
    def __init__(self):
        self.raiz = None

    def inserir(self, valor):
        pass

    def buscar(self, valor):
        pass

    def em_ordem(self):
        pass

# Teste:
# arvore = ArvoreBinaria()
# for v in [5, 3, 7, 1, 4, 6, 8]:
#     arvore.inserir(v)
# arvore.em_ordem() -> [1, 3, 4, 5, 6, 7, 8]
# arvore.buscar(4) -> True
# arvore.buscar(9) -> False
```

---

## Exercício 7 - Dijkstra

Implemente o algoritmo de Dijkstra para encontrar o menor caminho entre dois vértices em um grafo com pesos.

```python
import heapq

def dijkstra(grafo, inicio, destino):
    # seu codigo aqui
    pass

# Exemplo:
# grafo = {
#     "A": [("B", 4), ("C", 2)],
#     "B": [("A", 4), ("C", 1), ("D", 5)],
#     "C": [("A", 2), ("B", 1), ("D", 8), ("E", 10)],
#     "D": [("B", 5), ("C", 8), ("E", 2)],
#     "E": [("C", 10), ("D", 2)]
# }
# dijkstra(grafo, "A", "E") -> (9, ["A", "C", "B", "D", "E"])
# (custo total: 9, caminho: A->C->B->D->E)
```

---

## Exercício 8 - Percursos da árvore

Dada a árvore binária do exercício 6, implemente os três tipos de percurso:
- Pré-ordem (pre-order): raiz, esquerda, direita
- Em-ordem (in-order): esquerda, raiz, direita
- Pós-ordem (post-order): esquerda, direita, raiz

```python
def pre_ordem(no):
    pass

def em_ordem(no):
    pass

def pos_ordem(no):
    pass

# Para a árvore [5, 3, 7, 1, 4, 6, 8]:
# pre_ordem  -> [5, 3, 1, 4, 7, 6, 8]
# em_ordem   -> [1, 3, 4, 5, 6, 7, 8]
# pos_ordem  -> [1, 4, 3, 6, 8, 7, 5]
```
