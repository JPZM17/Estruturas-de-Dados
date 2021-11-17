#include <iostream>
#include <string>

//elemento que vai ser instanciado e colocado na fila
class Elemento{

public: 
    std::string nome;
    Elemento* proximoElemento;
    Elemento(std::string nome_pessoa, Elemento* proximo_elemento){
        nome = nome_pessoa;
        proximoElemento = proximo_elemento;
    }
};

class Instanciador{

public:
    Elemento* instanciaPilha(){
        Elemento* pilha = new Elemento("pilha", NULL);
        return pilha;
    }

//pilha

    //push
    void push(Elemento* &pilha, std::string novo_nome){

        Elemento* elemento_novo = new Elemento(novo_nome, pilha);
        pilha = elemento_novo;
    }
    //pop
    void pop(Elemento* &pilha)
    {
        Elemento* topoVelho = pilha;
        pilha = topoVelho->proximoElemento;
        delete topoVelho;
    }

};


void crawler(Elemento* ponteiro);
void crawlerDeleter(Elemento* &ponteiro);

int main(void){
    //Criamos uma instancia da classe intanciador
    Instanciador instanciador;

    //-----Funcionamento da pilha em ação-----

    // Elemento* pilha = instanciador.instanciaPilha();

    // instanciador.push(pilha, "p1");
    // instanciador.push(pilha, "p2");
    // instanciador.push(pilha, "p3");

    // crawler(pilha);

    // instanciador.pop(pilha);

    // crawler(pilha);

    // crawlerDeleter(pilha);

    //-----Fim do funcionamento da pilha-----

    //Elemento* fila = new Elemento("fila", NULL);

    return 0;
}


//debug
void crawler(Elemento* ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    if(ponteiro->proximoElemento != NULL)
    {
       crawler(ponteiro -> proximoElemento);
    }
}

void crawlerDeleter(Elemento* &ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    
    if(ponteiro->proximoElemento != NULL)
    {
       crawlerDeleter(ponteiro -> proximoElemento);
    }
    delete ponteiro;
}
