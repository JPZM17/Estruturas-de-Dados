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
//classe usada para instanciar a fila e a pilha, assim como também operar a pilha.
class Instanciador{

public:
    Elemento* InstanciaPilha(){
        Elemento* pilha = new Elemento("pilha", NULL, NULL);
        return pilha;
    }

    Fila InstanciaFila(){
        Fila fila = Fila();
        return fila;
    }


//pilha

    //push
    void Push(Elemento* &pilha, std::string novo_nome){

        Elemento* elemento_novo = new Elemento(novo_nome, pilha, NULL);
        pilha = elemento_novo;
    }
    //pop
    void Pop(Elemento* &pilha)
    {
        Elemento* topoVelho = pilha;
        pilha = topoVelho->proximoElemento;
        delete topoVelho;
    }

};

void Crawler(Elemento* ponteiro);
void CrawlerDeleter(Elemento* &ponteiro);

int main(void){
    //Criamos uma instancia da classe intanciador
    Instanciador instanciador;

    //-----Funcionamento da pilha em ação-----

    // Elemento* pilha = instanciador.InstanciaPilha();

    // instanciador.Push(pilha, "p1");
    // instanciador.Push(pilha, "p2");
    // instanciador.Push(pilha, "p3");

    // Crawler(pilha);

    // instanciador.Pop(pilha);

    // Crawler(pilha);

    // CrawlerDeleter(pilha);

    //-----Fim do funcionamento da pilha-----

    //Elemento* fila = new Elemento("fila", NULL);

    //-----Inicio do funcionamento da fila-----

    // Fila fila = instanciador.InstanciaFila();

    // fila.Entrar("elemento1");
    // fila.Entrar("elemento2");
    // fila.Entrar("elemento3");

    // Crawler(fila.cabeca);

    // fila.Sair();

    // Crawler(fila.cabeca);

    // CrawlerDeleter(fila.cabeca);

    //-----Fim do funcionamento da fila-----

    return 0;
}



//debug
void Crawler(Elemento* ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    if(ponteiro->proximoElemento != NULL)
    {
       Crawler(ponteiro -> proximoElemento);
    }
}

void CrawlerDeleter(Elemento* &ponteiro){
    std::cout <<ponteiro->nome <<"\n";
    
    if(ponteiro->proximoElemento != NULL)
    {
       CrawlerDeleter(ponteiro -> proximoElemento);
    }
    delete ponteiro;
}
