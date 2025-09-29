#include <iostream>
#include <string>

class Tarefa {
    private:
        static int _prox_id;
        int _id;
        std::string _descricao;
        std::string _status;

    public:
        Tarefa();
        Tarefa(const std::string& descricao);
        int get_id() const;
        const std::string& get_descricao() const;
        const std::string& get_status() const;
        void set_descricao(const std::string&);
        void set_status(const std::string&);
};