# 📜Informações

PONTIFÍCIA UNIVERSISADE CATÓLICA DE MINAS GERAIS

Instituto de Ciências Exatas e Informática – ICEI

Autor : Vinícius Miranda de Araújo

Matéria : Arquitetura de Computadores I

Ano : 2024

## 📑 Estrutura do Documento

- [Máquinas de Estado](#máquinas-de-estados)
  - [Mealy e Moore](#modelos-de-mealy-e-moore)
- 
- [Fim](#fim)

# Máquinas de Estados

Uma máquina de estados finitos, ou simplesmente autômato finito, é um modelo de comportamento composto de estados, transições
e ações. Um estado armazena uma informação sobre a história de um sistema (reflete como as mudanças nas entradas trouxeram
o sistema até o estado atual). Uma transição indica uma mudança de estado e é descrita por uma condição que a permite.
Uma ação é a descrição de uma atividade executada em certo instante.

Máquinas de estados finitos podem ser usadas para descrever circuitos sequenciais pois suas saídas e seus novos estados 
são funções de suas entradas e de seus estados atuais.

![Diagrama de Estados](/ACs/images/diagrama_de_estados.png)

Considerar um circuito capaz de identificar a sequência binária (1101):

![Diagrama de Estados da Sequência 1101](/ACs/images/seq_1101.png)

```
FSM

   estado  entrada             estado  entrada
           0     1                     0     1
    >q0    q0    q1             *000   000   001
     q1    q0    q2              001   000   010
     q2    q3    q2              010   011   010
     q3    q0    q4#             011   000   100+

   Matriz de estados/transições
   
   atual\próximo
         q0 q1 q2 q3 q4
     q0   0  1         
     q1   0     1      
     q2         1  0   
     q3   0          1      
     q4              + 
     
```

### Modelos de Mealy e Moore

Os modelos de Mealy e Moore são comumente usados para descrever máquinas de estados finitos.

Caso a saída seja função do estado da máquina e de suas entradas, então o modelo de Mealy será melhor empregado, pois reage 
mais rapidamente às variações das entradas.

Se a saída for função apenas do estado, o modelo de Moore será melhor empregado, pois garante a transição completa entre 
estados, antes de emitir alguma saída.

Na prática, esses dois modelos poderão ser combinados para oferecer uma descrição melhor do funcionamento de uma máquina 
de estados finitos.

![Mealy e Moore](/ACs/images/mealy_moore.png)

```
Mealy 

   estado  entrada; saída       estado entrada; saída
           0     1                     0     1
    >q0    q0;0  q1;0           *000   000 0 001 0
     q1    q0;0  q2;0            001   000 0 010 0
     q2    q3;0  q2;0            010   011 0 010 0
     q3    q0;0  q0;1            011   000 0 000 1
                                           ^     ^
    bit separado = saída __________________|_____|
 
   Matriz de estados/transições (entrada; saída)
   
   atual\pr ximo
         q0   q1  q2  q3  q4 
     q0  0;0  1;0            
     q1  0;0      1;0        
     q2           1;0 0;0    
     q3  0;0              1;1
     q4                   + 
```

```
Moore 

   estado  entrada;saída       estado  [saída]entrada
           0     1                        0      1
    *q0    q0;0  q1;0          *0000   [0]000 [0]001
     q1    q0;0  q2;0           0001   [0]000 [0]010
     q2    q3;0  q2;0           0010   [0]011 [0]010
     q3    q0;0  q4;0           0011   [0]000 [1]100
     q4    q4;1  q4;1           1100   [1]100 [1]100
                                ^       ^      ^
     primeiro bit = saída ______|_______|______|

   Matriz de estados/transições
   
   atual\pr ximo
         q0   q1  q2  q3  q4 
     q0  0;0  1;0            
     q1  0;0      1;0        
     q2           1;0 0;0    
     q3  0;0              1;0
     q4                   _;1+ 
```

# Fim