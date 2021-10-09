/*
AUTOR: Daniel García Hernández
EMAIL: alu01013533stoi(value)@ull.edu.es
ASIGNATURA: Algoritmos y estructuras de datos avanzadas
PRÁCTICA Nº: 11
*/

#include "BTreeProgram.h"

int RequestValue() {
  try {
    cout << "Type the sequence size: ";
    int size; cin >> size;
    if (!cin >> size) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      throw "Invalid argument";
    }
    if (size < 2)
      throw "Lenght must be al least 2";
    return size;
  }
  catch(const char* error) {
    cout << error << "\n";
    return RequestValue();
  }
  catch (const invalid_argument& e) {
    cout << e.what() << "\n";
    return RequestValue();
  }
}

vector<string> split(const string str) {
  vector <string> str_split(2);
  unsigned count = 0;
  for (unsigned i = 0; i < str.length(); i++) {
    if (str[i] != ' ')
      str_split[count] += str[i]; 
    else
      count++;
  }
  return str_split;
}

bool IsNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

void MenuMessage() {
  cout << "Type 'insert 'value'' to insert an element into the tree \n";
  cout << "Type 'search 'value'' to search an element into the tree \n";
  cout << "Type 'delete 'value'' to delete an element of the tree \n";
  cout << "Type 'enable trace' to enable trace of rotation \n";
  cout << "Type 'disable trace' to disable trace of rotation \n";
  cout << "Type 'restart now' to restart the tree \n";
  cout << "Type 'exit now' to exit the program \n";
}

void Menu() {
  AVLTree<int> menu_btree;
  string option, value, positive_value ;
  while (1) {
    MenuMessage();
    cin >> option >> value;
    positive_value = value;
    if (positive_value[0] == '-')
      positive_value[0] = '0';
    if (option == "insert" && IsNumeric(positive_value)) {
      menu_btree.Insert(stoi(value));
      menu_btree.Show();
    }
    else if (option == "search" && IsNumeric(positive_value)) {
      if (menu_btree.Search(stoi(value)) == true)
        cout << "Value found! \n";
      else
        cout << "Value not found! \n";
    }
    else if (option == "delete" && IsNumeric(positive_value)) {
      menu_btree.Delete(stoi(value));
      menu_btree.Show();
    }
    else if (option == "enable") {
      menu_btree.trace = 1;
    }
    else if (option == "disable") {
      menu_btree.trace = 0;
    }
    else if (option == "restart") {
      Menu();
      break;
    }
    else if (option == "exit") {
      break;
    }
    else
      cout << "Invalid option! \n";
  }
  return;
}