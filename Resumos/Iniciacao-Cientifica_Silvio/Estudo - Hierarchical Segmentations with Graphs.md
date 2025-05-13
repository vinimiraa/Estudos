# **Hierarchical Segmentations with Graphs: Quasi-flat Zones, Minimum Spanning Trees, and Saliency Maps**

## **Hierarquia de Partições Conectadas**

### Partição

A **partição** de um conjunto finito $V$ é um conjunto $P$ de **subconjuntos disjuntos não vazios** de $V$, cuja **união é $V$**, isto é:

$$
\forall\ X,Y \in P, \ X \ \cap \ Y \ = \emptyset\ \text{ se } \ X \neq Y \text{ e } \cup\{X \in P\} = V 
$$

Ou seja:

$$
P = \{R_1, R_2, \cdots, R_k\} \ | \ \cup_{i=1}^{k} R_i = V \text{ e } R_i \cap R_j = \emptyset \ \forall \ i \neq j 
$$

Onde cada subconjunto $R_i$ é uma **região** da partição.

- Se $x$ é um elemento de $V$, existe uma única região de $P$ que contém $x$, assim essa região única é denotada por $[P]_x$.
	
- Dada duas partições $P$ e $P'$ de um conjunto $V$, pode-se dizer que $P'$ é um **refinamento** de $P$ se qualquer região de $P'$ está inclusa em $P$.

### Hierarquia de Partição

Uma hierarquia de partições é uma sequência de partições $\mathcal{H}=(P_0​,P_1​,…,P_\mathscr{l})$ do conjunto $V$ tal que $[P]_{i-1}$ é um refinamento de $[P]_i$ , para qualquer $i \in \{1, \cdots, \mathscr{l}\}$, ou seja cada partição subsequente é **menos refinada** que a anterior.

$$
P_0 < P_1 < P_2 < \cdots < P_\mathscr{l}
$$

- Se $\mathcal{H}=(P_0​,P_1​,…,P_\mathscr{l})$ é uma hierarquia, o inteiro $\mathscr{l}$ é a **profundidade** de $\mathcal{H}$.
	
- Um hierarquia $\mathcal{H}=(P_0​,P_1​,…,P_\mathscr{l})$ é **completa** se $P_\mathscr{l} = \{V\}$ e se $P_0$ contém cada elemento do conjunto $V$, isto é: $P_0 = \{\{x\} \ | \ x \in V\}$. 

### Hierarquia de Partição Conectada

É uma hierarquia de partições onde cada região em cada nível é **conexa** em relação a um grafo $G = (V, E)$.

- Um **partição é conectada** (para $G$) se cada uma de suas regiões for conexa.
	
- Uma hierarquia em $V$ é conectada (para $G$) se cada uma de suas partições for conexa.

> Um conjunto de vértices $X \subseteq V$ é **conexo** se o subgrafo induzido por $X$ é conexo.

### Exemplo

Grafo 3x3 com vértices representando pixels de uma imagem:

- $P_0$​: Cada pixel é uma região (partição mais refinada possível).
    
- $P_1$: Regiões agrupadas por similaridade local.
    
- $P_2$: Grandes regiões fundidas (objetos na imagem).
    
- $P_3 = \{V\}$: Todos os pixels fundidos (partição mais grosseira possível).

## **Zonas Quasi-Flat**

Inicialmente:

- Uma hierarquia conectada pode ser tratada de forma equivalente por meio de um grafo ponderado por arestas.
	
- Os conjuntos de nível de qualquer grafo ponderado por arestas induzem uma hierarquia de zonas quase planas. Essa hierarquia é amplamente utilizada no processamento de imagens e às vezes também é chamada de árvore alfa.

Seja $G = (V, E)$ um grafo conexo e $w : E \rightarrow \mathbb{R}^+$ uma função peso que associa um valor real e positivo a cada aresta, então o par $(G, w)$ é chamado de **grafo ponderado por arestas**. Para qualquer aresta $u$ de $G$, o valor $w(u)$ é chamado de **peso de $u$** (com respeito a $w$).

Notações:

1. Assumindo que $G$ é conexo.
	
2. O intervalo de $w$ é o conjunto $\mathbb{E}$ de todos os inteiros de $0$ a $|E| - 1$. $w = \{0, \cdots, |E|-1\}$
	
3. $\mathbb{E}^\bullet = \mathbb{E} \cup \{|E|\}$.

Seja $X \subseteq G$ e $\lambda \in \mathbb{E}^\bullet$. Define-se:

- O **conjunto de nível $\lambda$** de $X$ (com respeito a $w$) como:
    
$$
w_\lambda(X) = \{ u \in E(X) \mid w(u) < \lambda \}
$$
    
- O **grafo de nível $\lambda$** de $X$ (com respeito a $w$) como:
    
$$
w^V_\lambda(X) = (V(X), w_\lambda(X))
$$
    
> Ou seja, um subgrafo de $X$ com os mesmos vértices, mas somente com as arestas de peso menor que $\lambda$.
    
- A **partição de nível $\lambda$** de $X$ é a partição dos vértices de $X$ em componentes conexos do grafo $w^V_\lambda(X)$.

Se $\lambda_1, \lambda_2 \in \mathbb{E}^\bullet \mid \lambda_1 \leq \lambda_2$​, então qualquer aresta presente no grafo de nível $\lambda_1$​ também estará no de $\lambda_2$​. Assim, qualquer componente conexo de $w^V_{\lambda_1}(X)$ estará contido em um componente conexo de $w^\vee_{\lambda_2}(X)$. Ou seja, a partição para $\lambda_1$ é um **refinamento** da partição para $\lambda_2$.

Portanto, a sequência:

$$
\mathcal{QFZ}(X, w) = \left( C(w^\vee_\lambda(X)) \mid \lambda \in E^\bullet \right)
$$

onde $C$ indica os componentes conexos, é uma **hierarquia** de partições. Essa hierarquia é chamada de **hierarquia de zonas quasi-flat** de $X$ (para $w$).

> Se $X$ for conexo, essa hierarquia será **completa**.

### Aplicação em Processamento de Imagens

No processamento de imagens, é comum que o peso de uma aresta $\{x, y\}$ represente a **dissimilaridade** entre os vértices. Por exemplo:

- Em imagens em tons de cinza, $w(u)$ pode ser a **diferença absoluta de intensidade** entre os pixels $x$ e $y$.

O modelo do grafo ponderado $(G, w)$ depende do contexto da aplicação, mas o conceito de zonas quasi-flat oferece uma forma natural de gerar **hierarquias de segmentações** baseadas em conectividade e semelhança local.

## **Correspondência entre Hierarquias e Mapas de Saliência**

Qualquer **grafo ponderado por arestas** induz uma **hierarquia conectada de partições**, chamada de **hierarquia de zonas quasi-flat**.

### Problema

**Dado**: uma hierarquia conectada $\mathcal{H}$.  

**Objetivo**: encontrar um mapa de pesos $w$ (ou seja, uma função sobre as arestas $E$) tal que a hierarquia de zonas quasi-flat induzida por $w$ seja exatamente $\mathcal{H}$.

O **mapa de saliência (saliency map)** fornece uma **solução para esse problema**.

### Mapa de Saliência

Seja $\mathcal{H} = (P_0, P_1, \cdots, P_\ell)$ uma **hierarquia de partições** sobre os vértices de um grafo $G = (V, E)$.  
O **mapa de saliência de $\mathcal{H}$** é uma função $\Phi_G(\mathcal{H}): E \to \{0, \cdots, \ell\}$ definida por:

$$
\Phi_G(\mathcal{H})(u) = \max \{ \lambda \in \{0, ..., \ell\} \mid u \in \varphi_G(P_\lambda) \}
$$

Onde $\varphi_G(P_\lambda)$ é o **corte** de $P_\lambda$, ou seja, o conjunto de arestas que **conectam vértices em regiões diferentes** na partição $P_\lambda$:

$$
\varphi_G(P) = \{ \{x, y\} \in E \mid [P]_x \neq [P]_y \}
$$

### Teorema 1

O mapa $\Phi_G$ define uma **bijeção** entre hierarquias conectadas em $V$ de profundidade $|E|$ e mapas de saliência (com intervalo $\mathbb{E}$) com valores em $\{0, ..., |E|\}$.  

O inverso de $\Phi_G$, denotado $\Phi_G^{-1}$, associa a cada saliency map $w$ a sua hierarquia de zonas quasi-flat:

$$
\Phi_G^{-1}(w) = \mathcal{QFZ}(G, w)
$$

Portanto, temos:

$$
\mathcal{QFZ}(G, \Phi_G(\mathcal{H})) = \mathcal{H}
$$

Ou seja, a hierarquia original $\mathcal{H}$ pode ser **recuperada exatamente** a partir de seu mapa de saliência.

> [!NOTE] Nota
> Um mapa de saliência $w$ é precisamente o mapa de saliência de sua hierarquia de zonas quasi-flat. Pode-se deduzir que existem alguns mapas que ponderam as arestas de $G$ e que não são mapas de saliência. Em geral, um mapa $w$ não é igual ao mapa de saliência de sua hierarquia de zonas quasi-flat.

## **Caracterização dos Mapas de Saliência**

Dada uma hierarquia $\mathcal{H}$, podem existir **vários mapas de pesos** $w$ cujas hierarquias de zonas quasi-flat são iguais a $\mathcal{H}$. 

### Problema

**Dado**: uma hierarquia $\mathcal{H}$.

**Objetivo**: encontrar o **menor** mapa $w$ tal que a hierarquia de zonas quasi-flat de $w$ seja exatamente $\mathcal{H}$.

### Teorema 2

Seja $\mathcal{H}$ uma hierarquia e seja $w : E \rightarrow \mathbb{N}$. O mapa $w$ é o **mapa de saliência** de $\mathcal{H}$ **se, e somente se**, as duas condições seguintes forem satisfeitas:

1. A hierarquia de zonas quasi-flat de $w$ é igual a $\mathcal{H}$;
    
2. $w$ é **mínimo** para essa propriedade, ou seja: para qualquer outro mapa $w' \leq w$ (comparação ponto a ponto), se a hierarquia de zonas quasi-flat de $w'$ for $\mathcal{H}$, então $w' = w$.


> [!NOTE] Nota
> Dado um mapa qualquer $w$, pode-se calcular seu **mapa de saliência** associado, chamado $\Psi_G(w)$:
> 
> $\Psi_G(w) = \Phi_G(QFZ(G, w)) \tag{9}$
> 
> Ou seja:
> 
> 1. Construa a hierarquia de zonas quasi-flat a partir de $w$;
>     
> 2. Em seguida, calcule o **mapa de saliência** dessa hierarquia.

###  Propriedade 3

Esse operador é um **filtro morfológico** chamado **ultrametric opening**, com as propriedades:

1. **Idempotente**: aplicar duas vezes não muda nada:
    
    $$\Psi_G(\Psi_G(w)) = \Psi_G(w)$$
    
2. **Anti-extensivo**: o resultado nunca é maior que a entrada:
    
    $$\Psi_G(w) \leq w$$
    
3. **Monótono (increasing)**: se $w \geq w'$, então $\Psi_G(w) \geq \Psi_G(w')$

## **Árvores Geradora Mínima**

Mapas diferentes de pesos nas arestas podem gerar a **mesma hierarquia de zonas quasi-flat**. Logo, **nem todo peso individual importa** para definir a hierarquia, há **redundância**.

### Problema 

**Dado**: um grafo ponderado $(G,w)$.

**Objetivo**: encontrar o **subgrafo mínimo** $X \subseteq G$ tal que a hierarquia de zonas quasi-flat de $X$ **seja igual** à do grafo original $G$.

### Árvore Geradora Mínima

Seja $X \subseteq G$. O peso de $X$ em relação a $w$ é a soma dos pesos de todas as arestas em $E(X)$. Um subgrafo $X$ de $G$ é uma **Árvore Geradora Mínima** (AGM) de $(G, w)$ se:

1. $X$ é **conexo**;
    
2. $V(X) = V$, ou seja, $X$ inclui todos os vértices;
    
3. O peso total de $X$ é **menor ou igual** ao peso de qualquer subgrafo $Y$ de $G$.

### Teorema 4

Um subgrafo $X$ de $G$ é uma AGM de $(G, w)$ se, e somente se:

1. A hierarquia de zonas quasi-flat de $X$ é igual à de $G$;

2. $X$ é **mínimo** para essa propriedade, ou seja: se algum subgrafo $Y \subset X$ tiver a mesma hierarquia, então $Y=X$.

Assim, tem-se que:

- A primeira propriedade indica que a hierarquia de zonas quasi-flat de um grafo e de sua AGM são idênticas.

- O teorema 4 indica que não há um subgrafo apropriado de um AGM que induza a mesma hierarquia de zonas quasi-flat que o grafo ponderado inicial.

- Uma AGM do grafo inicial é uma solução para o problema, fornecendo uma representação gráfica mínima da hierarquia de zonas quase planas de $(G, w)$.

- A correspondência entre mapas de saliência e hierarquias (Teorema 1) nos permite estender o Teorema 4 ao caso em que uma hierarquia $\mathcal{H}$ é fornecida em vez de um mapa de pesos $w$. Portanto, árvores geradoras mínimas permitem caracterizar representações espacial e funcionalmente mínimas de qualquer hierarquia conectada.

## **Resumo Geral**

### Hierarquias de Partições Conectadas

- Uma **partição** de um conjunto finito $V$ divide os elementos em subconjuntos disjuntos e não vazios cuja união é $V$.
    
- Uma **hierarquia de partições** é uma sequência ordenada ($P_0, P_1, ..., P_\ell$) onde cada partição é **menos refinada** que a anterior, isto é, as regiões vão se unindo progressivamente.
    
- A hierarquia é **completa** se começa com cada elemento em sua própria região $(P_0 = \{\{x\} \mid x \in V\})$ e termina com todos unidos em uma única região $(P_\ell = \{V\})$.
    
- Uma **hierarquia conectada** (em um grafo $G$) exige que todas as regiões em todos os níveis sejam **conjuntos conexos** no grafo.

### Zonas Quasi-flat

- Uma **zona quasi-flat** é definida a partir de um **grafo ponderado $(G,w)$**, onde o peso $w(e)$ indica a dissimilaridade entre os vértices ligados por cada aresta.
    
- Para cada limiar $\lambda$, forma-se o subgrafo com as arestas cujo peso é menor que $\lambda$, e a partição resultante é obtida pelas **componentes conexas** desse subgrafo.
    
- A sequência dessas partições, variando $\lambda$, forma a **hierarquia de zonas quasi-flat**, uma hierarquia conectada.
    
- É um modelo natural para segmentação hierárquica de imagens, onde regiões são agrupadas por similaridade local.

### Correspondência entre Hierarquias e Mapas de Saliência

- A relação entre hierarquias e pesos pode ser invertida:  
	
	- Dada uma **hierarquia conectada $\mathcal{H}$**, é possível encontrar um **mapa de saliência $\Phi_G(\mathcal{H})$**.
    
- O **mapa de saliência** atribui a cada aresta o **nível mais alto da hierarquia em que ela separa regiões distintas**.
    
- O Teorema 1 mostra que essa função $\Phi_G$ é uma **bijeção** entre mapas de saliência e hierarquias conectadas:
    
$$
\mathcal{QFZ}(G, \Phi_G(\mathcal{H})) = \mathcal{H}
$$

### Caracterização dos Mapas de Saliência

- Pode haver **vários mapas de pesos** que induzem a mesma hierarquia. O **mapa de saliência** é o **único que é mínimo** entre eles.
    
- Teorema 2: $w$ é o mapa de saliência de uma hierarquia $\mathcal{H}$ se:
    
    1. $\mathcal{QFZ}(G, w) = \mathcal{H}$;
        
    2. Nenhum outro mapa $w' \leq w$ satisfaz essa igualdade, a menos que $w'=w$.
        
- O operador $\Psi_G(w) = \Phi_G(\mathcal{QFZ}(G, w))$ transforma qualquer mapa em seu correspondente mapa de saliência. Ele é um **filtro morfológico** chamado **ultrametric opening**, que é:
    
    - **Idempotente**: $\Psi_G(\Psi_G(w)) = \Psi_G(w))$,
        
    - **Anti-extensivo**: $\Psi_G(w) \leq w)$,
        
    - **Monótono**.

### Árvores Geradoras Mínima

- AGMs reduzem a redundância: diferentes mapas de pesos podem gerar a **mesma hierarquia de zonas quasi-flat**.
    
- Problema (P3): encontrar o **subgrafo mínimo** que gera a mesma hierarquia de zonas quasi-flat que $G$.
    
- Teorema 4: esse subgrafo mínimo é uma **Árvore Geradora Mínima (AGM)** de $(G, w)$, e:
    
    - A AGM preserva exatamente a hierarquia.
        
    - Não existe subgrafo estritamente menor que a AGM que mantenha a mesma hierarquia.
        
- Isso permite representar uma hierarquia de forma **compacta e eficiente**, tanto do ponto de vista computacional quanto de armazenamento.

### Conclusão

1. **Hierarquias $\leftrightarrow$ Zonas quasi-flat**: qualquer grafo ponderado gera uma hierarquia via conectividade em níveis de limiar.
    
2. **Hierarquias $\leftrightarrow$ Mapas de saliência**: qualquer hierarquia pode ser representada unicamente por um mapa mínimo de saliência.
    
3. **Hierarquias $\leftrightarrow$ AGMs**: qualquer hierarquia pode ser representada minimamente por uma árvore geradora mínima do grafo ponderado.
