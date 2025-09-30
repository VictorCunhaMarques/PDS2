#include <string>
#include <iostream>
#include "../include/task.hpp"
#include "project.hpp"

int Projeto::_prox_id = 1;

Projeto::Projeto() : Projeto("", "") {}

Projeto::Projeto(const std::string& nome, const std::string& descricao) : _nome(nome), _descricao(descricao) {
    _id = _prox_id;
    _dono_id = -1;
    _num_tarefas = 0;
    _prox_id++;
}

int Projeto::get_id() const {
    return _id;
}

const std::string& Projeto::get_nome() const {
    return _nome;
}

const std::string& Projeto::get_descricao() const {
    return _descricao;
}

int Projeto::get_dono_id() const {
    return _dono_id;
}

const Tarefa* Projeto::get_tarefas() const {
    return _tarefas;
}

int Projeto::get_num_tarefas() const {
    return _num_tarefas;
}

void Projeto::set_nome(const std::string& nome) {
    _nome = nome;
}

void Projeto::set_descricao(const std::string& descricao) {
    _descricao = descricao;
}

void Projeto::set_dono_id(int dono) {
    _dono_id = dono;
}

bool Projeto::adicionar_tarefa(const std::string& descricao, int& out_tarefa_id) {
    _tarefas[_num_tarefas] = Tarefa(descricao);
    out_tarefa_id = _tarefas[_num_tarefas].get_id();
    _num_tarefas++;
    
    return true;
}

bool Projeto::atualizar_tarefa(int id_tarefa, const std::string& novo_status) {
    _tarefas[id_tarefa].set_status(novo_status);
    if(_tarefas[id_tarefa].get_status() == novo_status) {
        return true;
    }
    else {
        return false;
    }
}

bool Projeto::remover_tarefa(int id_tarefa) {
    if(id_tarefa >= _num_tarefas) {
        return false;
    }
    for (int i = id_tarefa;i < (_num_tarefas - 1);i++) {
        _tarefas[i] = _tarefas[i + 1];
    }
    _num_tarefas--;
    return true;
}

const Tarefa* Projeto::buscar_tarefa(int id_tarefa) const {
    return &_tarefas[id_tarefa];
}