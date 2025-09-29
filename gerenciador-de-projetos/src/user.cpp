#include "user.hpp"
#include <string>
#include <iostream>

int Usuario::_prox_id = 1;

Usuario::Usuario() : Usuario("", "") {}

Usuario::Usuario(std::string nome, std::string email) : _nome(nome), _email(email) {
    this->_id = Usuario::_prox_id;
    Usuario::_prox_id++;
}

int Usuario::get_id() const{
    return this->_id;
}

const std::string& Usuario::get_nome() const {
    return _nome;
}

const std::string& Usuario::get_email() const {
    return _email;
}

void Usuario::set_nome(const std::string& nome) {
    _nome = nome;
}

void Usuario::set_email(const std::string& email) {
    _email = email;
}