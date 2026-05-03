# Milestone 11 - Design Patterns

**Tema:** Padrões de projeto mais utilizados na prática

**Linguagem:** Java

---

## Exercício 1 - Singleton

Implemente o padrão Singleton para uma classe `ConfigManager` que carrega e armazena configurações da aplicação. Garanta que apenas uma instância exista.

```java
public class ConfigManager {
    private static ConfigManager instancia;
    private Map<String, String> configs;

    private ConfigManager() {
        configs = new HashMap<>();
    }

    public static ConfigManager getInstancia() {
        // seu codigo aqui
    }

    public void setConfig(String chave, String valor) {
        // seu codigo aqui
    }

    public String getConfig(String chave) {
        // seu codigo aqui
    }

    public static void main(String[] args) {
        ConfigManager c1 = ConfigManager.getInstancia();
        c1.setConfig("tema", "escuro");

        ConfigManager c2 = ConfigManager.getInstancia();
        System.out.println(c2.getConfig("tema")); // "escuro"
        System.out.println(c1 == c2);              // true
    }
}
```

---

## Exercício 2 - Factory Method

Crie uma fábrica de formas geométricas. A classe `FormaFactory` deve receber o tipo da forma como string e retornar a instância correta.

```java
public interface Forma {
    void desenhar();
    double calcularArea();
}

// Implemente Circulo, Quadrado e Triangulo

public class FormaFactory {
    public static Forma criarForma(String tipo, double... parametros) {
        // seu codigo aqui
        // "circulo" -> new Circulo(parametros[0])
        // "quadrado" -> new Quadrado(parametros[0])
        // "triangulo" -> new Triangulo(parametros[0], parametros[1])
    }

    public static void main(String[] args) {
        Forma c = FormaFactory.criarForma("circulo", 5);
        Forma q = FormaFactory.criarForma("quadrado", 4);
        c.desenhar();  // "Desenhando círculo com raio 5"
        System.out.println(c.calcularArea()); // 78.54
    }
}
```

---

## Exercício 3 - Observer

Implemente o padrão Observer para um sistema de notícias. Quando uma notícia é publicada, todos os assinantes são notificados.

```java
public interface Observador {
    void atualizar(String noticia);
}

public interface Publicador {
    void inscrever(Observador o);
    void desinscrever(Observador o);
    void notificarTodos();
}

public class AgenciaNoticias implements Publicador {
    private List<Observador> observadores;
    private String ultimaNoticia;

    // implemente os métodos

    public void publicarNoticia(String noticia) {
        this.ultimaNoticia = noticia;
        notificarTodos();
    }
}

public class Leitor implements Observador {
    private String nome;

    @Override
    public void atualizar(String noticia) {
        System.out.println(nome + " recebeu: " + noticia);
    }
}

// Teste:
// AgenciaNoticias agencia = new AgenciaNoticias();
// agencia.inscrever(new Leitor("Ana"));
// agencia.inscrever(new Leitor("Bruno"));
// agencia.publicarNoticia("Java 25 lançado!");
// -> "Ana recebeu: Java 25 lançado!"
// -> "Bruno recebeu: Java 25 lançado!"
```

---

## Exercício 4 - Strategy

Implemente o padrão Strategy para um sistema de cálculo de frete. Diferentes estratégias de envio têm custos diferentes.

```java
public interface EstrategiaFrete {
    double calcular(double peso, double distancia);
}

public class FreteEconomico implements EstrategiaFrete {
    @Override
    public double calcular(double peso, double distancia) {
        return peso * 0.5 + distancia * 0.1;
    }
}

public class FreteExpresso implements EstrategiaFrete {
    // custo mais alto, entrega rápida
}

public class FreteSedex implements EstrategiaFrete {
    // custo intermediário
}

public class CalculadoraFrete {
    private EstrategiaFrete estrategia;

    public void setEstrategia(EstrategiaFrete estrategia) {
        this.estrategia = estrategia;
    }

    public double calcular(double peso, double distancia) {
        return estrategia.calcular(peso, distancia);
    }
}

// Teste:
// CalculadoraFrete calc = new CalculadoraFrete();
// calc.setEstrategia(new FreteEconomico());
// System.out.println(calc.calcular(2.0, 100)); // 21.0
// calc.setEstrategia(new FreteExpresso());
// System.out.println(calc.calcular(2.0, 100)); // valor diferente
```

---

## Exercício 5 - Decorator

Implemente o padrão Decorator para um sistema de pedidos de café. O café base pode receber decoradores como leite, chocolate, chantilly, etc.

```java
public interface Bebida {
    String descricao();
    double preco();
}

public class CafeSimples implements Bebida {
    @Override
    public String descricao() { return "Café simples"; }

    @Override
    public double preco() { return 5.0; }
}

public abstract class DecoradorBebida implements Bebida {
    protected Bebida bebida;

    public DecoradorBebida(Bebida bebida) {
        this.bebida = bebida;
    }
}

// Implemente: ComLeite, ComChocolate, ComChantilly

// Teste:
// Bebida pedido = new CafeSimples();
// pedido = new ComLeite(pedido);
// pedido = new ComChocolate(pedido);
// System.out.println(pedido.descricao()); // "Café simples + Leite + Chocolate"
// System.out.println(pedido.preco());     // 5.0 + 2.0 + 3.0 = 10.0
```

---

## Exercício 6 - Adapter

Crie um Adapter para integrar um sistema de pagamento antigo com uma nova interface.

```java
// Interface nova que o sistema espera
public interface ProcessadorPagamento {
    boolean processar(String cartao, double valor);
    boolean estornar(String transacaoId);
}

// Sistema legado com interface diferente
public class SistemaPagamentoLegado {
    public int realizarCobranca(String numCartao, int valorCentavos) {
        System.out.println("Cobrando " + valorCentavos + " centavos do cartão " + numCartao);
        return 1; // código de sucesso
    }

    public int cancelarCobranca(int codigoTransacao) {
        System.out.println("Cancelando transação " + codigoTransacao);
        return 1;
    }
}

// Implemente o Adapter
public class AdapterPagamento implements ProcessadorPagamento {
    private SistemaPagamentoLegado sistemaLegado;

    // adapte os métodos
}
```

---

## Exercício 7 - Builder

Implemente o padrão Builder para construir objetos `Pedido` complexos de forma legível.

```java
public class Pedido {
    private String cliente;
    private List<String> itens;
    private String endereco;
    private String formaPagamento;
    private boolean embrulhoPresente;
    private String observacao;

    // construtor privado

    public static class Builder {
        private String cliente;
        private List<String> itens = new ArrayList<>();
        private String endereco;
        private String formaPagamento;
        private boolean embrulhoPresente = false;
        private String observacao = "";

        public Builder(String cliente) {
            this.cliente = cliente;
        }

        public Builder adicionarItem(String item) {
            // seu codigo aqui
        }

        public Builder endereco(String endereco) {
            // seu codigo aqui
        }

        public Builder pagamento(String forma) {
            // seu codigo aqui
        }

        public Builder comEmbrulho() {
            // seu codigo aqui
        }

        public Builder observacao(String obs) {
            // seu codigo aqui
        }

        public Pedido build() {
            // seu codigo aqui
        }
    }

    public static void main(String[] args) {
        Pedido pedido = new Pedido.Builder("Ana")
            .adicionarItem("Notebook")
            .adicionarItem("Mouse")
            .endereco("Rua A, 123")
            .pagamento("Cartao")
            .comEmbrulho()
            .observacao("Entregar pela manhã")
            .build();
    }
}
```

---

## Exercício 8 - Projeto final: Combinando patterns

Crie um mini sistema de e-commerce que combine múltiplos design patterns:

- **Singleton**: `Loja` (única instância)
- **Factory**: Criar diferentes tipos de `Produto` (físico, digital, serviço)
- **Observer**: Notificar clientes quando um produto volta ao estoque
- **Strategy**: Diferentes formas de cálculo de desconto (desconto fixo, percentual, progressivo)
- **Builder**: Construir pedidos complexos

```java
// Este exercício é aberto - planeje a arquitetura e implemente
// o sistema combinando os patterns aprendidos.
//
// Requisitos mínimos:
// 1. Cadastro de produtos (factory)
// 2. Instância única da loja (singleton)
// 3. Notificação de clientes sobre estoque (observer)
// 4. Cálculo de desconto configurável (strategy)
// 5. Montagem de pedidos (builder)
//
// Bônus: adicione Decorator para serviços extras no pedido
// (embrulho, entrega expressa, seguro)
```
