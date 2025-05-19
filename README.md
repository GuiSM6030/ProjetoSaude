# Gerenciador de Serviços de Saude
Projeto de Estrutura de Dados em linguagem C

Centro Universitário FEI | Ciência da Computação

Prof. Luciano Rossi

## Sobre o projeto

Este projeto tem como objetivo simular o funcionamento de um sistema de atendimento médico, utilizando estruturas clássicas de dados para organizar os pacientes em diferentes contextos: cadastro, atendimento normal, atendimento prioritário, pesquisa, log de ações e persistência de dados.

## Funções do Menu

### Cadastro
- Adicionar novos pacientes (início da lista encadeada)
- Consultar, editar e remover registros
- Visualizar a lista completa
- Estrutura: lista dinamica encadeada

### Atendimento
- Enfileirar pacientes para atendimento
- Desenfileirar pacientes
- Ver a fila completa (primeiro a chegar, primeiro a ser atendido)
- Estrutura: fila

### Atendimento Prioritário
- Baseado em idade (quanto mais velho, maior a prioridade)
- Gerenciado com uma heap de máximo
- Limite de 20 pacientes por dia
- Estrutura: fila

### Pesquisa
- Organiza os pacientes em uma árvore binária
- Permite busca e ordenação por:
  - Ano, mês, dia de registro
  - Idade do paciente
- Estrutura: Arvore 

### Desfazer
- Lista operações feitas na fila de atendimento
- Possibilidade de desfazer a última ação
- Estrutura: Pilha

### Carregar / Salvar
- Carrega dados de um arquivo externo 
- Salva os dados mantendo a ordem de inserção

### Sobre
- Exibe informações sobre o projeto

### Projeto realizado por:
> Natasha Almeida Trindade RA: 22.123.098-0
> 
> Guilherme SIlva Meireles RA: 22.123.094-9
