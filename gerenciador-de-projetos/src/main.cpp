#include <iostream>
#include <string>
#include <vector>
#include "../include/project.hpp"
#include "../include/system.hpp"
#include "../include/task.hpp"
#include "../include/user.hpp"

int main(void) {
    Sistema gerenciador_de_projetos;
    std::string action;
    std::vector<std::string> options = {"adicionar_usuario", 
                                        "remover_usuario", 
                                        "buscar_usuario",
                                        "listar_usuarios",
                                        "adicionar_projetos",
                                        "remover_projeto",
                                        "buscar_projeto",
                                        "listar_projetos",
                                        "atribuir_dono",
                                        "adicionar_tarefa",
                                        "atualizar_tarefa",
                                        "remover_tarefa",
                                        "listar_tarefas"};
    while(std::cin >> action) {
        int opt = -1;
        for (int i = 0; i < options.size(); i++) {
            if(action == options[i]) {
                opt = i;
            }
        }
        switch (opt) {
        case 0: {
            std::string nome, email;
            std::cin >> nome >> email;
            gerenciador_de_projetos.adicionar_usuario(nome, email);
            break;
        }
        
        case 1: {
            int id;
            std::cin >> id;
            gerenciador_de_projetos.remover_usuario(id);
            break;
        }
        case 2: {
            int id;
            std::cin >> id;
            gerenciador_de_projetos.buscar_usuario(id);
            break;
        }
        case 3: {
            gerenciador_de_projetos.listar_usuarios();
            break;
        }
        case 4: {
            std::string nome, descricao;
            std::cin >> nome >> descricao;
            gerenciador_de_projetos.adicionar_projeto(nome, descricao);
            break;
        }
        case 5: {
            int id;
            std::cin >> id;
            gerenciador_de_projetos.remover_projeto(id);
            break;
        }
        case 6: {
            int id;
            std::cin >> id;
            gerenciador_de_projetos.buscar_projeto(id);
            break;
        }
        case 7: {
            gerenciador_de_projetos.listar_projetos();
            break;
        }
        case 8: {
            int id_projeto, id_usuario;
            std::cin >> id_projeto >> id_usuario;
            gerenciador_de_projetos.atribuir_dono(id_projeto, id_usuario);
            break;
        }
        case 9: {
            int id_projeto;
            std::string descricao;
            std::cin >> id_projeto >> descricao;
            gerenciador_de_projetos.adicionar_tarefa(id_projeto, descricao);
            break;
        }
        case 10: {
            int id_projeto, id_tarefa;
            std::string status;
            std::cin >> id_projeto >> id_tarefa >> status;
            gerenciador_de_projetos.atualizar_tarefa(id_projeto, id_tarefa, status);
            break;
        }
        case 11: {
            int id_projeto, id_tarefa;
            std::cin >> id_projeto >> id_tarefa;
            gerenciador_de_projetos.remover_tarefa(id_projeto, id_tarefa);
            break;
        }
        case 12: {
            int id;
            std::cin >> id;
            gerenciador_de_projetos.listar_tarefas(id);
            break;
        }
        default:
            break;
        }
    }
}