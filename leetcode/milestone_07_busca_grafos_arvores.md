# Milestone 7 - Binary Search, Grafos, Dijkstra e Arvores

**Tema:** Algoritmos de busca, grafos e estruturas de arvore

**Linguagem:** Python

---

## Exercicio 1 - Binary Search

Implemente o algoritmo de busca binaria em uma lista ordenada. A funcao deve retornar o indice do elemento buscado ou -1 se nao encontrado.

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

## Exercicio 2 - Binary Search recursivo

Implemente a versao recursiva da busca binaria.

```python
def busca_binaria_recursiva(lista, alvo, inicio=0, fim=None):
    # seu codigo aqui
    pass

# Exemplos:
# busca_binaria_recursiva([1, 3, 5, 7, 9, 11], 5) -> 2
# busca_binaria_recursiva([1, 3, 5, 7, 9, 11], 6) -> -1
```

---

## Exercicio 3 - Representar um grafo

Crie uma classe `Grafo` que use um dicionario de listas de adjacencia. Implemente:
- `adicionar_vertice(v)`: adiciona um vertice
- `adicionar_aresta(v1, v2)`: adiciona uma aresta entre v1 e v2
- `mostrar()`: imprime a lista de adjacencia

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

## Exercicio 4 - BFS (Busca em Largura)

Implemente o algoritmo de busca em largura (BFS) para percorrer um grafo a partir de um vertice inicial.

```python
from collections import deque

def bfs(grafo, inicio):
    # seu codigo aqui
    pass

# Exemplo com dicionario de adjacencia:
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

## Exercicio 5 - DFS (Busca em Profundidade)

Implemente o algoritmo de busca em profundidade (DFS), tanto na versao iterativa quanto na recursiva.

```python
def dfs_iterativo(grafo, inicio):
    # seu codigo aqui
    pass

def dfs_recursivo(grafo, inicio, visitados=None):
    # seu codigo aqui
    pass

# Usando o mesmo grafo do exercicio anterior:
# dfs_iterativo(grafo, "A") -> ["A", "C", "F", "E", "B", "D"]
# (a ordem pode variar dependendo da implementacao)
```

---

## Exercicio 6 - Arvore binaria

Implemente uma arvore binaria de busca (BST) com as operacoes:
- `inserir(valor)`: insere um valor na arvore
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

## Exercicio 7 - Dijkstra

Implemente o algoritmo de Dijkstra para encontrar o menor caminho entre dois vertices em um grafo com pesos.

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

## Exercicio 8 - Percursos da arvore

Dada a arvore binaria do exercicio 6, implemente os tres tipos de percurso:
- Pre-ordem (pre-order): raiz, esquerda, direita
- Em-ordem (in-order): esquerda, raiz, direita
- Pos-ordem (post-order): esquerda, direita, raiz

```python
def pre_ordem(no):
    pass

def em_ordem(no):
    pass

def pos_ordem(no):
    pass

# Para a arvore [5, 3, 7, 1, 4, 6, 8]:
# pre_ordem  -> [5, 3, 1, 4, 7, 6, 8]
# em_ordem   -> [1, 3, 4, 5, 6, 7, 8]
# pos_ordem  -> [1, 4, 3, 6, 8, 7, 5]
```
