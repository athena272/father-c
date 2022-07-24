cmake_minimum_required(VERSION 3.22)
project(FatherC C)

set(CMAKE_C_STANDARD 11)

add_executable(FatherC
        Estudos/Livro/multiplicationTable/table.c
        Estudos/Livro/pointers/main.c
        Projetos/jogoAdvinhacao/adivinhacao.c
        Projetos/jogoForca/forca.c)
