#pragma once

#include"Header.h"

int user::login_check()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        cout << "Enter your user id" << endl;
        cin >> user_name;
        cout << "Enter your password" << endl;
        int ch;
        ch = _getch();
        while (ch != 13)
        {
            pass_word.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        int f1 = 0, f2 = 0;
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work login(connectionObject);

        string sql = "SELECT *FROM login WHERE user_name='" + user_name + "'";
        pqxx::result response = login.exec(sql);

        for (int i = 0; i < response.size(); i++)
        {
            f1 = 1;
        }
        string sql1 = "SELECT *FROM login WHERE pass_word='" + pass_word + "'";
        pqxx::result response1 = login.exec(sql);

        for (int i = 0; i < response1.size(); i++)
        {
            f2 = 1;
        }
        if (f1 == 1 && f2 == 1)
        {
            cout << "\nLogin sucessful" << endl;
            return 1;
        }
        else
        {
            cout << "\nInvalid user id/password" << endl;
            return 0;

        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
int user::admin()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    cout << "Enter your password" << endl;
    int ch,f=0;
    ch = _getch();
    while (ch != 13)
    {
        pass_word.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work login(connectionObject);
    string sql = "SELECT *FROM login WHERE pass_word='" + pass_word + "'";
    pqxx::result response1 = login.exec(sql);

    for (int i = 0; i < response1.size(); i++)
    {
        f=1;
    }
    if (f == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void vehicle::reserve_t()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work car_details(connectionObject);
    pqxx::result response = car_details.exec("SELECT * FROM reserve");


    VariadicTable<string, string>vt({ "user_name","register number"});
    for (int i = 0; i < response.size(); i++)
    {
        vt.addRow(response[i][0].as<string>(), response[i][1].as<string>());
    }
    vt.print(cout);
}
void vehicle::rent_t()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work car_details(connectionObject);
    pqxx::result response = car_details.exec("SELECT * FROM rent");


    VariadicTable<string, string>vt({ "user_name","register number" });
    for (int i = 0; i < response.size(); i++)
    {
        vt.addRow(response[i][0].as<string>(), response[i][1].as<string>());
    }
    vt.print(cout);
}
void user::edit_details()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        cout << "Please enter your user id" << endl;
        cin >> user_name;
        cout << "Please enter your password" << endl;
        cin >> pass_word;
        cout << "Please enter your name" << endl;
        cin >> name_user;
        cout << "Please enter your email id" << endl;
        cin >> mail;
        cout << "Please enter your address" << endl;
        cin >> address;
        string sql = "UPDATE login SET pass_word='" + pass_word + "', name_user='" + name_user + "', mail='" + mail + "',address='" + address + "' WHERE user_name='" + user_name + "'";
        pqxx::result response = student.exec(sql);
        student.commit();
        cout << "details updated" << endl;

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}
void user::delete_user()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";

        cout << "Type the uesr name of the user you need to delete" << endl;
        cin >> user_name;
        pqxx::connection connectionObject(connectionString.c_str());

        pqxx::work students(connectionObject);

        pqxx::result response = students.exec("DELETE FROM login WHERE user_name = '" + user_name + "'");

        students.commit();

        cout << "Deleted an entry" << endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}
void vehicle::display_two()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work car_details(connectionObject);
    pqxx::result response = car_details.exec("SELECT * FROM two");


    VariadicTable<string, string, string, int>vt({ "reg_num","brand","Color","rent" });
    for (int i = 0; i < response.size(); i++)
    {
        vt.addRow(response[i][0].as<string>(), response[i][1].as<string>(), response[i][2].as<string>(), response[i][3].as<int>());
    }
    vt.print(cout);
}
void vehicle::display_car()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work car_details(connectionObject);
    pqxx::result response = car_details.exec("SELECT * FROM car");


    VariadicTable<string, string, int, int>vt({ "reg_num","brand","seat","rent" });
    for (int i = 0; i < response.size(); i++)
    {
        vt.addRow(response[i][0].as<string>(), response[i][1].as<string>(), response[i][2].as<int>(), response[i][3].as<int>());
    }
    vt.print(cout);
}
void vehicle::display_heavy()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work car_details(connectionObject);
    pqxx::result response = car_details.exec("SELECT * FROM heavy");


    VariadicTable<string, string, int, string>vt({ "reg_num","type","rent","driver available" });
    for (int i = 0; i < response.size(); i++)
    {
        vt.addRow(response[i][0].as<string>(), response[i][1].as<string>(), response[i][2].as<int>(), response[i][3].as<string>());
    }
    vt.print(cout);
}
void vehicle::vehicle_booking()
{
    int k1,k2;
    cout << "Press 1 to view 2-wheelers" << endl;
    cout << "Press 2 to view cars" << endl;
    cout << "Press 3 to view heavy vehicles" << endl;
    cin >> k1;
    if (k1 == 1)
    {
        display_two();
    }
    if (k1 == 2)
    {
        display_car();
    }
    if (k1 == 3)
    {
        display_heavy();
    }
    cout << "Press 1 to rent" << endl;
    cout << "Press 2 to reserve" << endl;
    cin >> k2;
    cout << "Type the register number of the vehicle you had selected" << endl;
    cin >> reg_num;
    cout << "Thankyou" << endl;
    if (k2 == 1)
    {
        v.rent_v();
    }
    else if (k2 == 2)
    {
        v.reserve();
    }
    if (k1 == 1)
    {
        v.delete_two();
    }
    if (k1 == 2)
    {
        v.delete_car();
    }
    if (k1 == 3)
    {
        v.delete_heavy();
    }
    v.delete_ve();
}
int user::sign_in()
{
    int l,k2=0;
    l = us.login_check();
    if (l == 0)
    {
        return 0;
    }
    while (k2 != 3&&k2!=4)
    {
        cout << "Press 1 to book or reserve car" << endl;
        cout << "Press 2 to edit details" << endl;
        cout << "Press 3 to exit" << endl;
        cout << "Press 4 to logout" << endl;
        cin >> k2;
        if (k2 == 1)
        {
            v.vehicle_booking();
        }
        else if (k2 == 2)
        {
            us.edit_details();
        }
        else if (k2 == 4)
        {
            us.execute();
        }
        else if (k2 == 3)
        {
            return 0;
        }
    }
}
void vehicle::rent_v()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work student(connectionObject);
    pqxx::result response = student.exec("INSERT INTO rent (user_name,reg_num) VALUES('" + us.user_name + "','" + reg_num + "')");
    student.commit();
}
void vehicle::reserve()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());
    pqxx::work student(connectionObject);
    pqxx::result response = student.exec("INSERT INTO reserve (user_name,reg_num) VALUES('" + us.user_name + "','" + reg_num + "')");
    student.commit();
}
void user::insert()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        cout << "Please enter your user id" << endl;
        cin >> user_name;
        cout << "Please enter your password" << endl;
        int ch;
        ch = _getch();
        while (ch != 13)
        {
            pass_word.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        cout << "\nPlease enter your name" << endl;
        cin >> name_user;
        cout << "Please enter your email id" << endl;
        cin >> mail;
        cout << "Please enter your address" << endl;
        cin >> address;
        pqxx::result response = student.exec("INSERT INTO login (user_name,pass_word,name_user,mail,address) VALUES('" + user_name + "','" + pass_word + "','" + name_user + "','" + mail + "','" + address + "')");
        student.commit();
        cout << "sign up sucessful" << endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void vehicle::add()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        cout << "Press 1 to add 2 wheeler" << endl;
        cout << "Press 2 to add car" << endl;
        cout << "Press 3 to add heavy vehicle" << endl;
        cin >> a;
        cout << "Type reg number" << endl;
        cin >> reg_num;
        cout << "Type the number of wheels(2/4/heavy)" << endl;
        cin >> type;
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        pqxx::result response = student.exec("INSERT INTO vehicles (reg_num,type)VALUES('" + reg_num + "','" + type + "')");
        student.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    if (a == 1)
    {
        insert_two();
    }
    else if (a == 2)
    {
        insert_4();
    }
    else if (a == 3)
    {
        insert_heavy();
    }
    
    cout << "Sucessfully added" << endl;
}
void vehicle::insert_4()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        cout << "Type the brand" << endl;
        cin >> brand;
        cout << "Type number of seats" << endl;
        cin >> seat;
        cout << "Type the rent" << endl;
        cin >> rent;
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        pqxx::result response = student.exec("INSERT INTO car(reg_num,brand,seat,rent) VALUES('" + reg_num + "','" + brand + "','" + to_string(seat) + "','" + to_string(rent) + "')");
        student.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void vehicle::insert_two()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        cout << "Type the brand" << endl;
        cin >> brand;
        cout << "Type the colour" << endl;
        cin >> colour;
        cout << "Type the rent" << endl;
        cin >> rent;
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        pqxx::result response = student.exec("INSERT INTO two(reg_num,brand,colour,rent) VALUES('" + reg_num + "','" + brand + "','" + colour + "','" + to_string(rent) + "')");
        student.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void vehicle::insert_heavy()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        cout << "Type the model name" << endl;
        cin >> brand;
        cout << "driver available?" << endl;
        cin >> driver;
        cout << "Type the rent"<< endl;
        cin >> rent;
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work student(connectionObject);
        pqxx::result response = student.exec("INSERT INTO heavy(reg_num,typeof,rent,driver) VALUES('" + reg_num + "','" + brand + "','" + to_string(rent) + "','" + driver + "')");
        student.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}
void vehicle::edit()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    int k1;
    cout << "Press 1 to edit two wheelers" << endl;
    cout << "Press 2 to edit cars" << endl;
    cout << "Press 3 to edit heavy vehicles" << endl;
    cin >> k1;
    cout << "Type the register number" << endl;
    cin >> reg_num;
    if (k1 == 1)
    {
        try
        {
            cout << "Type the brand" << endl;
            cin >> brand;
            cout << "Type the colour" << endl;
            cin >> colour;
            cout << "Type the rent" << endl;
            cin >> rent;
            pqxx::connection connectionObject(connectionString.c_str());

            pqxx::work car_details(connectionObject);

            string sql = "UPDATE two SET brand='" + brand + "', colour='" + colour + "', rent='" + to_string(rent) + "' WHERE reg_num='" + reg_num + "'";
            pqxx::result response = car_details.exec(sql);
            car_details.commit();
            cout << "sucessfully edited" << endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

    }
    if (k1 == 2)
    {
        try
        {
            cout << "Type the brand" << endl;
            cin >> brand;
            cout << "Type the number of seats" << endl;
            cin >> seat;
            cout << "Type the rent" << endl;
            cin >> rent;
            pqxx::connection connectionObject(connectionString.c_str());

            pqxx::work car_details(connectionObject);

            string sql = "UPDATE car SET brand='" + brand + "', seat='" +to_string(seat) + "', rent='" + to_string(rent) + "' WHERE reg_num='" + reg_num + "'";
            pqxx::result response = car_details.exec(sql);
            car_details.commit();
            cout << "sucessfully edited" << endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else if (k1 == 3)
    {
        try
        {
            cout << "Type the type" << endl;
            cin >> brand;
            cout << "is driver available?" << endl;
            cin >> driver;
            cout << "Type the rent" << endl;
            cin >> rent;
            pqxx::connection connectionObject(connectionString.c_str());

            pqxx::work car_details(connectionObject);

            string sql = "UPDATE heavy SET typeof='" + brand + "', rent='" + to_string(rent) + "', driver='" + driver + "' WHERE reg_num='" + reg_num + "'";
            pqxx::result response = car_details.exec(sql);
            car_details.commit();
            cout << "sucessfully edited" << endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
void vehicle::delete_v()
{
        int k1;
        cout << "Press 1 to view 2-wheelers" << endl;
        cout << "Press 2 to view cars" << endl;
        cout << "Press 3 to view heavy vehicles" << endl;
        cin >> k1;
        if (k1 == 1)
        {
            display_two();
            cout << "Press the register number of vehicle you need to delete" << endl;
            cin >> reg_num;
            delete_two();
        }
        if (k1 == 2)
        {
            display_car();
            cout << "Press the register number of vehicle you need to delete" << endl;
            cin >> reg_num;
            delete_car();
        }
        if (k1 == 3)
        {
            display_heavy();
            cout << "Press the register number of vehicle you need to delete" << endl;
            cin >> reg_num;
            delete_heavy();
        }
        delete_ve();
}
void vehicle::delete_ve()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";

        pqxx::connection connectionObject(connectionString.c_str());

        pqxx::work car_details(connectionObject);

        pqxx::result response = car_details.exec("DELETE FROM vehicles WHERE reg_num = '" + reg_num + "'");

        car_details.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void vehicle::delete_two()
{
    try
    {
        string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
        pqxx::connection connectionObject(connectionString.c_str());

        pqxx::work car_details(connectionObject);

        pqxx::result response = car_details.exec("DELETE FROM two WHERE reg_num = '" + reg_num + "'");

        car_details.commit();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
void vehicle::delete_car()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work car_details(connectionObject);

    pqxx::result response = car_details.exec("DELETE FROM car WHERE reg_num = '" + reg_num + "'");

    car_details.commit();
}
void vehicle::delete_heavy()
{
    string connectionString = "host=localhost port=5432 dbname=vehicle_rent user=postgres password =1312";
    pqxx::connection connectionObject(connectionString.c_str());

    pqxx::work car_details(connectionObject);

    pqxx::result response = car_details.exec("DELETE FROM heavy WHERE reg_num = '" + reg_num + "'");

    car_details.commit();
}
int user::execute()
{
    int k1,l,k2=0;
    cout << "Press 1 for sign in" << endl;
    cout << "Press 2 for sign up/new user" << endl;
    cout << "Press 3 for receptionist" << endl;
    cin >> k1;
    if (k1 == 1)
    {
        l = us.sign_in();
        if (l == 0)
        {
            return 0;
        }
    }
    else if (k1 == 2)
    {
        us.insert();
        while (k2 != 3&&k2!=4)
        {
            cout << "Press 1 to book or reserve car" << endl;
            cout << "Press 2 to edit details" << endl;
            cout << "Press 3 to exit" << endl;
            cout << "Press 4 to logout" << endl;
            cin >> k2;
            if (k2 == 1)
            {
               v.vehicle_booking();
            }
            else if (k2 == 2)
            {
                us.edit_details();
            }
            else if (k2 == 3)
            {
                exit;
            }
            else if(k2==4)
            {
                us.execute();
            }

        }
    }
    else if (k1 == 3)
    {
        int k4=0,flag,kd;
        flag = us.admin();
        if (flag == 1)


        {
            while (k4!=11&&k4!=10)
            {
                cout << "\nPress 1 to edit a user" << endl;
                cout << "Press 2 to delete a user" << endl;
                cout << "Press 3 to book/reserve a vehicle" << endl;
                cout << "Press 4 to edit a vehicle" << endl;
                cout << "Press 5 to add a vehicle" << endl;
                cout << "Press 6 to delete a vehicle" << endl;
                cout << "Press 7 to view reserve table" << endl;
                cout << "Press 8 to view rented vehicle details" << endl;
                cout << "Press 10 to logout" << endl;
                cout << "Press 11 to exit" << endl;
                cin >> k4;
                switch (k4)
                {
                case 1:
                {
                    us.edit_details();
                    break;
                }
                case 2:
                {
                    us.delete_user();
                    break;
                }
                case 3:
                {
                    v.vehicle_booking();
                    break;
                }
                case 4:
                {
                    v.edit();
                    break;
                }
                case 5:
                {
                    v.add();
                    break;
                }
                case 6:
                {
                    v.delete_v();
                    cout << "Sucessfully deleted" << endl;
                    break;
                }
                case 7:
                {
                    v.reserve_t();
                    break;
                }
                case 8:
                {
                    v.rent_t();
                    break;
                }
          
                case 9:
                {
                    cout << "press 1 to view two whellers" << endl;
                    cout << "press 2 to view cars" << endl;
                    cout << "Press 3 to view heavy" << endl;
                    cin >> kd;
                    if (kd == 1)
                    {
                        v.display_two();
                    }
                    else if (kd == 2)
                    {
                        v.display_car();
                    }
                    else if (kd == 3)
                    {
                        v.display_heavy();
                    }
                    else
                    {
                        cout << "Invalid key" << endl;
                    }
                    break;
                }
                case 10:
                {
                    us.execute();
                    exit;
                    break;
                }
                case 11:
                {
                    exit;
                }
                }
                

            }

        }
        else
        {
            cout << "\nINVALID PASSWORD" << endl;
        }


    }

}
int main()
{
    int e;
    e = us.execute();
    if (e == 0)
    {
        return 0;
    }
}