cmake_minimum_required(VERSION 3.28.1)

project(composer-db VERSION 0.1.0)

add_executable(composer-db main.cpp Composer.cpp Database.cpp)