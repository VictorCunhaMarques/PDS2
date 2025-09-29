#include <iostream>
#include <string>

class Usuario {
    private:
        int _id;
        static int _prox_id;
        std::string _nome;
        std::string _email;
    
    public:
        Usuario();
        Usuario(std::string nome, std::string email);
        int get_id() const;
        const std::string& get_nome() const;
        const std::string& get_email() const;
        void set_nome(const std::string&);
        void set_email(const std::string&);
};