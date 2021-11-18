#include <iostream>
#include <string>

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
};

void Leitor(Elemento* ponteiro);
void LeitorDeleter(Elemento* &ponteiro);

int main(void){
    Instanciador Instanciador;

    Pilha pilha = Instanciador.InstanciaPilha();

    pilha.Push("p1");
    pilha.Push("p2");
    pilha.Push("p3");

    Leitor(pilha.topo);

    pilha.Pop();

    Leitor(pilha.topo);

    LeitorDeleter(pilha.topo);


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