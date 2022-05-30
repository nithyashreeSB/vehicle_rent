#pragma once
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include <exception>
#include<conio.h>
#include"VariadicTable.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using namespace std;

class user
{
public:
    string user_name, pass_word, name_user, mail, address;
    void insert();
    int login_check();
    void edit_details();
    void delete_user();
    int sign_in();
    int execute();
    int admin();
}us;
class vehicle
{
public:
    string reg_num, brand, status, type, colour, driver;
    int rent, seat, a;
    void vehicle_booking();
    void delete_v();
    void reserve();
    void rent_v();
    void add();
    void edit();
    void display_two();
    void display_car();
    void display_heavy();
    void insert_two();
    void insert_4();
    void insert_heavy();
    void delete_two();
    void delete_car();
    void delete_heavy();
    void delete_ve();
    void reserve_t();
    void rent_t();
}v;