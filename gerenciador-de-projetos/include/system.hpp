#include <iostream>
#include <string>
#include "user.hpp"
#include "project.hpp"

const int MAX_PROJETOS = 100;
const int MAX_USUARIOS = 100;

class Sistema {
    private:
        Usuario _usuarios[MAX_USUARIOS];
        int _num_usuarios = 0;
        Projeto _projetos[MAX_PROJETOS];
        int _num_projetos = 0;

    public:
        //users methods
        void adicionar_usuario(const std::string& nome, const std::string& email);
        void remover_usuario(int id);
        void buscar_usuario(int id) const;
        void listar_usuarios() const;
        //projects methods
        void adicionar_projeto(const std::string& nome, const std::string& descricao);
        void remover_projeto(int id);
        void buscar_projeto(int id) const;
        void listar_projetos() const;
        void atribuir_dono(int id_projeto, int id_usuario);
        //tasks methods
        void adicionar_tarefa(int id_projeto, const std::string& descricao);
        void atualizar_tarefa(int id_projeto, int id_tarefa, const std::string& status);
        void remover_tarefa(int id_projeto, int id_tarefa);
        void listar_tarefas(int id_projeto) const;
};