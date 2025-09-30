#include <iostream>
#include <string>
#include "system.hpp"

void Sistema::adicionar_usuario(const std::string& nome, const std::string& email) {
    _usuarios[_num_usuarios] = Usuario(nome, email);
    std::cout << "Usuario adicionado: " << _usuarios[_num_usuarios].get_nome() << " " << _usuarios[_num_usuarios].get_email() << std::endl;
    _num_usuarios++;
}

void Sistema::remover_usuario(int id) {
    if (id >= _num_usuarios) {
        std::cout << "Erro: usuario " << id << " nao existe" << std::endl;
        return;
    }
    for (int i = 0; i < _num_projetos; i++) {
        if(_projetos[i].get_dono_id() == id) {
            _projetos[i].set_dono_id(-1);
        }
    }
    for (int i = id; i < _num_usuarios - 1; i++) {
        _usuarios[i] = _usuarios[i + 1];
    }
    _num_usuarios--;
    std::cout << "Usuario removido: " << id << std::endl;
}

void Sistema::buscar_usuario(int id) const {
    if (id >= _num_usuarios) {
        std::cout << "Usuario " << id << " nao encontrado" << std::endl;
        return;
    }
    std::cout << "Usuario " << id << ": " << _usuarios[id].get_nome() << " " << _usuarios[id].get_email() << std::endl;
    return;
}

void Sistema::listar_usuarios() const {
    if (_num_usuarios == 0) {
        std::cout << "Nenhum Usuario" << std::endl;
        return;
    }
    for (int i = 0; i < _num_usuarios; i++) {
        std::cout << _usuarios[i].get_id() << " " << _usuarios[i].get_nome() << " " << _usuarios[i].get_email() << std::endl;
    }
}

void Sistema::adicionar_projeto(const std::string& nome, const std::string& descricao) {
    _projetos[_num_projetos] = Projeto(nome, descricao);
    std::cout << "Projeto adicionado: " << _projetos[_num_projetos].get_id() << " " << _projetos[_num_projetos].get_nome() << " " << _projetos[_num_projetos].get_descricao() << std::endl;
    _num_projetos++;
}

void Sistema::remover_projeto(int id) {
    if (id >= _num_projetos) {
        std::cout << "Erro: projeto " << id << " nao existe" << std::endl;
        return;
    }

    for (int i = id; i < _num_projetos - 1; i++) {
        _projetos[i] = _projetos[i + 1];
    }
    _num_projetos--;
    std::cout << "Projeto removido: " << id << std::endl;
}

void Sistema::buscar_projeto(int id) const {
    if (id >= _num_projetos) {
        std::cout << "Projeto " << id << " nao encontrado" << std::endl;
        return;
    } else if (_projetos[id].get_dono_id() == -1) {
        std::cout << "Projeto " << _projetos[id].get_id() << ": " << _projetos[id].get_nome() << " " << _projetos[id].get_descricao() << std::endl;
    } else {
        std::cout << "Projeto " << _projetos[id].get_id() << ": " << _projetos[id].get_nome() << " " << _projetos[id].get_descricao() << " dono=" << _projetos[id].get_dono_id() << std::endl;
    }
    
}

void Sistema::listar_projetos() const {
    if (_num_projetos == 0) {
        std::cout << "Nenhum projeto" << std::endl;
        return;
    }
    for (int i = 0; i < _num_projetos; i++) {
        std::cout << _projetos[i].get_id() << " " << _projetos[i].get_nome() << " " << _projetos[i].get_descricao() << std::endl;
    }
}

void Sistema::atribuir_dono(int id_projeto, int id_usuario) {
    if (id_projeto >= _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    } else if (id_usuario >= _num_usuarios) {
        std::cout << "Erro: usuario " << id_usuario << " nao existe" << std::endl;
        return;
    } else {
        _projetos[id_projeto].set_dono_id(id_usuario);
        std::cout << "Atribuido dono: projeto" << id_projeto << "-> usuario " << id_usuario << std::endl;
    }
}

void Sistema::adicionar_tarefa(int id_projeto, const std::string& descricao) {
    if (id_projeto >= _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    }
    int id_tarefa;
    _projetos[id_projeto].adicionar_tarefa(descricao, id_tarefa);
    std::cout << "Tarefa adicionada: projeto " << id_projeto << " tarefa " << id_tarefa << " status=" << _projetos[id_projeto].buscar_tarefa(id_tarefa)->get_status() << " " << _projetos[id_projeto].buscar_tarefa(id_tarefa)->get_descricao() << std::endl;
}

void Sistema::atualizar_tarefa(int id_projeto, int id_tarefa, const std::string& status) {
    if (id_projeto >= _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    } else if (id_tarefa >= _projetos[id_projeto].get_num_tarefas()) {
        std::cout << "Erro: tarefa " << id_tarefa << " nao existe no projeto " << id_projeto << std::endl;
        return;
    } 
    _projetos[id_projeto].atualizar_tarefa(id_tarefa, status);
    std::cout << "Tarefa atualizada: projeto " << id_projeto << " tarefa " << id_tarefa << " status=" << _projetos[id_projeto].buscar_tarefa(id_tarefa)->get_status() << std::endl;
}

void Sistema::remover_tarefa(int id_projeto, int id_tarefa) {
    if (id_projeto >= _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    } else if (id_tarefa >= _projetos[id_projeto].get_num_tarefas()) {
        std::cout << "Erro: tarefa " << id_tarefa << " nao existe no projeto " << id_projeto << std::endl;
        return;
    } 
    _projetos[id_projeto].remover_tarefa(id_tarefa);
    std::cout << "Tarefa removida: projeto " << id_projeto << " tarefa " << id_tarefa << std::endl;
}

void Sistema::listar_tarefas(int id_projeto) const {
    if (id_projeto >= _num_projetos) {
        std::cout << "Erro: projeto " << id_projeto << " nao existe" << std::endl;
        return;
    } else if (_projetos[id_projeto].get_num_tarefas() == 0) {
        std::cout << "Nenhuma tarefa no projeto " << id_projeto << std::endl;
    }
    const Tarefa* tarefas_temp = _projetos[id_projeto].get_tarefas();
    for (int i = 0; i < _projetos[id_projeto].get_num_tarefas();i++) {
        std::cout << tarefas_temp->get_id() << " " << tarefas_temp->get_descricao() << " " << tarefas_temp->get_status() << std::endl;
    }
}