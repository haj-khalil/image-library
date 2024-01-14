#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "include.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// file_list take path of directory and return list of file dans le dir
std::vector<std::string> file_list()
{
    std::vector<std::string> file_list;
    string dir_path = "../Connection/descripteur";
    DIR *dir = opendir(dir_path.c_str());

    if (dir == NULL)
    {
        cout << "directory is damaged";
    }

    struct dirent *object; // object soit un fichier ou directory
    object = readdir(dir);

    while (object != NULL)
    {
        if (object->d_type == DT_REG)
        {
            // test
            // cout <<"file : "<< object->d_name << endl;
            std::string basePath = "../Connection/descripteur/";
            std::string fullPath = basePath + object->d_name;
            file_list.push_back(fullPath);
        }
        object = readdir(dir);
    }

    closedir(dir);
    return file_list;
}

// convert le contenu de un fichier a un vectors "lines"
std::vector<std::string> file_to_lines(string file_path)
{
    fstream myFile;
    myFile.open(file_path, ios::in); // mode read
    vector<string> lines;
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            // Supprimer le caractère "\n" - Linux seulement
            line = line.substr(0, line.size()-1);

            lines.push_back(line);
        }
        myFile.close();
    }
    else
        cout << "this file is damaged";
    // un test pour afficher le contenu de un fichier
    for (int i = 0; i < lines.size(); i++)
    {
        //    cout << lines[i] << endl;
    }

    return lines;
}

bool login_test(string username, string password){
    bool success = 0;

    std::vector<std::string> usernames = file_to_lines("../Connection/login/username.txt");
    std::vector<std::string> passwords = file_to_lines("../Connection/login/password.txt");
    std::vector<std::string> roles = file_to_lines("../Connection/login/role.txt");

    for (int i = 0 ; i< usernames.size() ; i++){
        if(username == usernames[i]){
            if(password == passwords[i]){
                cout << "Login Successful"<<endl;
                success = 1;
                if( roles[i]=="1"){
                cout << "you are admin" <<endl;
                }
                break;
            }else cout << "Password are not Correct !"<<endl;
        }else if(i == usernames.size()-1){
            cout << " Username is not member ! " <<endl;
        }
    }

    return success;
}

void MainWindow::on_btn_connection_clicked()
{
    string username = ui->edt_usr->text().toStdString();
    string password = ui->edt_mdp->text().toStdString();

    bool success=0;

    success = login_test(username, password);
    if (success){
        QMessageBox::information(this,"Login Successful","You are welcome");
        hide();

        tableau = new Tableau(this);
        tableau->show();

        std::vector<std::string> list;
        list = file_list();

        tableau->ui->

/*
        std::vector<std::string> lines;

        for (int i = 0 ; i< list.size() ; i++){
            lines = file_to_lines(list[i]);
        }
    }
*/

    else{
        QMessageBox::warning(this,"Invalid login","You are not welcome");
    }

}

