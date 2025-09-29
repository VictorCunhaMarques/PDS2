#include "task.hpp"
#include <string>
#include <iostream>

int Tarefa::_prox_id = 1;

Tarefa::Tarefa() : Tarefa("") {}

Tarefa::Tarefa(const std::string& descricao) : _descricao(descricao) {
    _status = "aberta";
    _id = Tarefa::_prox_id;
    Tarefa::_prox_id++;
}

int Tarefa::get_id() const {
    return _id;
}

const std::string& Tarefa::get_descricao() const {
    return _descricao;
}

const std::string& Tarefa::get_status() const {
    return _status;
}

void Tarefa::set_descricao(const std::string& descricao) {
    _descricao = descricao;
}

void Tarefa::set_status(const std::string& status) {
    _status = status;
}