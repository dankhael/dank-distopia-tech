# Milestone 10 - Conceitos Complexos e Aplicação de POO

**Tema:** Interfaces, classes abstratas, polimorfismo, composição e tratamento de exceções

**Linguagem:** Java

---

## Exercício 1 - Classe abstrata

Crie uma classe abstrata `Forma` com um método abstrato `calcularArea()` e um método concreto `descricao()`. Implemente as subclasses `Circulo`, `Retangulo` e `Triangulo`.

```java
public abstract class Forma {
    protected String nome;

    public Forma(String nome) {
        this.nome = nome;
    }

    public abstract double calcularArea();

    public void descricao() {
        System.out.println(nome + " com area: " + calcularArea());
    }
}

// Implemente Circulo (raio), Retangulo (largura, altura), Triangulo (base, altura)

// Teste:
// Forma c = new Circulo(5);
// Forma r = new Retangulo(4, 6);
// Forma t = new Triangulo(3, 8);
// c.descricao(); -> "Círculo com área: 78.54"
// r.descricao(); -> "Retângulo com área: 24.0"
// t.descricao(); -> "Triângulo com área: 12.0"
```

---

## Exercício 2 - Interfaces

Crie uma interface `Pagavel` com o método `calcularPagamento()`. Implemente em classes `Funcionario` (salário fixo) e `Freelancer` (valor por hora * horas trabalhadas).

```java
public interface Pagavel {
    double calcularPagamento();
}

public class Funcionario implements Pagavel {
    private String nome;
    private double salario;

    // construtor e implementação
}

public class Freelancer implements Pagavel {
    private String nome;
    private double valorHora;
    private int horasTrabalhadas;

    // construtor e implementação
}

// Teste com polimorfismo:
// Pagavel[] folha = {
//     new Funcionario("Ana", 5000),
//     new Freelancer("Carlos", 75, 80)
// };
// for (Pagavel p : folha) {
//     System.out.println(p.calcularPagamento());
// }
// -> 5000.0
// -> 6000.0
```

---

## Exercício 3 - Polimorfismo em ação

Crie um sistema de notificações com uma interface `Notificavel` e classes `EmailNotificacao`, `SMSNotificacao` e `PushNotificacao`. Cada uma implementa `enviar(String mensagem)` de forma diferente.

Crie uma classe `ServicoNotificacao` que receba uma lista de `Notificavel` e envie uma mensagem para todos.

```java
public interface Notificavel {
    void enviar(String mensagem);
}

// Implemente EmailNotificacao, SMSNotificacao, PushNotificacao

public class ServicoNotificacao {
    private List<Notificavel> canais;

    public void notificarTodos(String mensagem) {
        // seu codigo aqui
    }
}
```

---

## Exercício 4 - Composição

Crie um sistema onde `Universidade` é composta por `Departamento`, que por sua vez contém `Professor`. Demonstre que se a universidade for destruída, os departamentos também deixam de existir (composição), mas professores podem existir independentemente (agregação).

```java
public class Professor {
    private String nome;
    private String especialidade;
    // construtor e métodos
}

public class Departamento {
    private String nome;
    private List<Professor> professores;
    // construtor e métodos
}

public class Universidade {
    private String nome;
    private List<Departamento> departamentos;

    public void criarDepartamento(String nome) {
        // a universidade cria e gerencia departamentos
    }

    // métodos para listar departamentos, adicionar professor a departamento, etc.
}
```

---

## Exercício 5 - Tratamento de exceções

Crie exceções personalizadas para um sistema bancário:
- `SaldoInsuficienteException`
- `ValorInvalidoException`
- `ContaInexistenteException`

Implemente uma classe `Banco` que lance essas exceções quando apropriado.

```java
public class SaldoInsuficienteException extends Exception {
    public SaldoInsuficienteException(String msg) {
        super(msg);
    }
}

// Crie as outras exceções

public class Banco {
    private Map<Integer, ContaBancaria> contas;

    public void depositar(int numeroConta, double valor)
            throws ContaInexistenteException, ValorInvalidoException {
        // seu codigo aqui
    }

    public void sacar(int numeroConta, double valor)
            throws ContaInexistenteException, SaldoInsuficienteException, ValorInvalidoException {
        // seu codigo aqui
    }

    public void transferir(int origem, int destino, double valor)
            throws ContaInexistenteException, SaldoInsuficienteException, ValorInvalidoException {
        // seu codigo aqui
    }
}
```

---

## Exercício 6 - Generics

Crie uma classe genérica `Caixa<T>` que possa armazenar qualquer tipo de objeto. Implemente métodos para guardar, retirar e verificar se está vazia.

Depois crie uma `CaixaLimitada<T>` que tenha um limite máximo de itens.

```java
public class Caixa<T> {
    private T item;

    public void guardar(T item) {
        // seu codigo aqui
    }

    public T retirar() {
        // seu codigo aqui
    }

    public boolean estaVazia() {
        // seu codigo aqui
    }
}

public class CaixaLimitada<T> {
    private List<T> itens;
    private int limite;

    // construtor e métodos
}

// Teste:
// Caixa<String> caixaTexto = new Caixa<>();
// caixaTexto.guardar("Ola");
// System.out.println(caixaTexto.retirar()); // "Ola"
//
// CaixaLimitada<Integer> caixaNum = new CaixaLimitada<>(3);
// caixaNum.guardar(1);
// caixaNum.guardar(2);
// caixaNum.guardar(3);
// caixaNum.guardar(4); // Caixa cheia!
```

---

## Exercício 7 - Enum e Switch

Crie um enum `DiaSemana` e uma classe `Agenda` que associe compromissos a dias da semana. Use switch para retornar mensagens diferentes para dias úteis e fim de semana.

```java
public enum DiaSemana {
    SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO, DOMINGO;

    public boolean ehFimDeSemana() {
        // seu codigo aqui
    }
}

public class Agenda {
    private Map<DiaSemana, List<String>> compromissos;

    public void adicionarCompromisso(DiaSemana dia, String compromisso) {
        // seu codigo aqui
    }

    public void mostrarDia(DiaSemana dia) {
        // use switch para dar mensagens diferentes
    }
}
```

---

## Exercício 8 - Sistema completo

Crie um sistema de biblioteca com:
- Classe abstrata `ItemBiblioteca` (título, autor, ano)
- Classes `Livro`, `Revista` e `DVD` que herdam de `ItemBiblioteca`
- Interface `Emprestavel` com métodos `emprestar()` e `devolver()`
- Classe `Biblioteca` que gerencia os itens (adicionar, buscar, emprestar, devolver, listar disponíveis)
- Tratamento de exceções para operações inválidas

```java
// Implemente o sistema completo combinando todos os conceitos:
// herança, interfaces, polimorfismo, encapsulamento, exceções e coleções
```
