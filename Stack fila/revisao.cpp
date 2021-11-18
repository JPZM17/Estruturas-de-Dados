#include <iostream>
#include <string>

//elemento que vai ser instanciado e colocado na fila e na pilha
class Elemento{

public: 
    std::string nome;
    Elemento* proximoElemento;
    Elemento* elementoAnterior; 
    Elemento(std::string nome_pessoa, Elemento* proximo_elemento, Elemento* elemento_anterior){
        nome = nome_pessoa;
        proximoElemento = proximo_elemento;
        elementoAnterior = elemento_anterior;
    }
};

class Fila{

public:
    Elemento* cabeca;
    Elemento* cauda;
    

    void Entrar(std::string novo_nome){
        if(cabeca == NULL)
        {
            Elemento* novo_elemento = new Elemento(novo_nome, NULL, NULL);
            cabeca = novo_elemento;
            cauda = novo_elemento; 
        }
        else
        {
            Elemento* novo_elemento = new Elemento(novo_nome, NULL, NULL);
            cauda -> proximoElemento = novo_elemento;
            novo_elemento -> elementoAnterior = cauda;
            cauda = novo_elemento;
        }
    }

    void Sair()
    {
        cabeca = cabeca -> proximoElemento;
        Elemento* cabeca_velha = cabeca -> elementoAnterior;
        cabeca -> elementoAnterior = NULL;
        delete cabeca_velha;
    }

};

class Pilha{

public:
    Elemento* topo;


    void Push(std::string novoNome){
        if(topo == NULL)
        {
            Elemento* novoElemento = new Elemento(novoNome, NULL, NULL);
            topo = novoElemento;
        }
        else
        {
            Elemento* novoElemento = new Elemento(novoNome, topo, NULL);
            topo = novoElemento;
        }
    }
    void Pop(){
        Elemento* topoVelho = topo;
        topo = topoVelho->proximoElemento;
        delete topoVelho;
    }

};

class Instanciador{

public:
    Pilha InstanciaPilha(){
        Pilha pilha = Pilha();
        return pilha;
    }

     Fila InstanciaFila(){
        Fila fila = Fila();
        return fila;
    }

};

void Leitor(Elemento* ponteiro);
void LeitorDeleter(Elemento* &ponteiro);

int main(void){
    //Criando uma instancia do instanciador
    Instanciador Instanciador;

    //-----Inicio do funcionamento da pilha-----
    Pilha pilha = Instanciador.InstanciaPilha();

    pilha.Push("p1");
    pilha.Push("p2");
    pilha.Push("p3");
    pilha.Push("p4");

    Leitor(pilha.topo);

    pilha.Pop();

    Leitor(pilha.topo);

    pilha.Pop();

    Leitor(pilha.topo);

    LeitorDeleter(pilha.topo);
    //-----Fim do funcionamento da pilha-----

    //-----Inicio do funcionamento da fila-----
    Fila fila = Instanciador.InstanciaFila();

    fila.Entrar("elemento 1");
    fila.Entrar("elemento 2");
    fila.Entrar("elemento 3");
    fila.Entrar("elemento 4");

    Leitor(fila.cabeca);

    fila.Sair();

    Leitor(fila.cabeca);

    fila.Sair();

    Leitor(fila.cabeca);

    LeitorDeleter(fila.cabeca);

    //-----Fim do funcionamento da fila-----
    return 0;
}

//debug
void Leitor(Elemento* ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    if(ponteiro->proximoElemento != NULL)
    {
       Leitor(ponteiro -> proximoElemento);
    }
}

void LeitorDeleter(Elemento* &ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    
    if(ponteiro->proximoElemento != NULL)
    {
       LeitorDeleter(ponteiro -> proximoElemento);
    }
    delete ponteiro;
}