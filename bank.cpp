#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define clear "cls"
#else
#define clear "clear"
#endif
#define MAX_STR_LEN 256

struct person
{
  char fname[256];
  char lname[256];
  char adress[256];
  char nominee[256];
  int account;
  float amount;
};

int found = 0;

void addUser()
{
  char another;
  FILE *fp;
  struct person info;
  do
  {
    int header = 0;

    system(clear);
    cout << "\t.....Add User.....\n\n";

    cout << "Enter First Name: ";
    cin >> info.fname;
    cout << "Enter Last Name: ";
    cin >> info.lname;
    cout << "Enter Adress: ";
    cin >> info.adress;
    cout << "Enter Nominee Name: ";
    cin >> info.nominee;
    cout << "Enter account: ";
    cin >> info.account;
    cout << "Enter amount: ";
    cin >> info.amount;

    fp = fopen("./bank.csv", "a");

    fwrite(&info, sizeof(struct person), 1, fp);
    fclose(fp);
    if (fp == NULL)
    {
      cout << "Can't open the file\n";
    }
    else
    {
      cout << "Record stored successfuly\n";
    }

    cout << "Add another student (y/n)";
    cin >> another;
  } while (another == 'y' || another == 'Y');
}

void updateUser()
{
  FILE *fp, *fp1;
  struct person info;
  char another;
  int account, found = 0;
  do
  {
    system(clear);
    fp = fopen("./bank.csv", "rb");
    fp1 = fopen("./temp_bank.csv", "a");

    if (fp == NULL)
    {
      fprintf(stderr, "can't open file\n");
      exit(0);
    }
    cout << "Enter the account: ";
    cin >> account;
    while (fread(&info, sizeof(struct person), 1, fp))
    {
      if (info.account != account)
      {
        fwrite(&info, sizeof(struct person), 1, fp1);
      }
      else
      {
        found = 1;
      }
    }

    if (found == 1)
    {
      struct person up;

      cout << "Enter the first name: ";
      cin >> up.fname;
      cout << "Enter the last name: ";
      cin >> up.lname;
      cout << "Enter the adress: ";
      cin >> up.adress;
      cout << "Enter the nominee name: ";
      cin >> up.nominee;
      cout << "Enter the account: ";
      cin >> up.account;
      cout << "Enter the amount: ";
      cin >> up.amount;

      fwrite(&up, sizeof(struct person), 1, fp1);
      remove("./bank.csv");
      rename("./temp_bank.csv", "./bank.csv");
      fclose(fp);
      fclose(fp1);
    }
    else
    {
      cout << "Record not found\n";
    }

    cout << "Wana go back (y/n)";
    cin >> another;
  } while (another == 'n' || another == 'N');
}

void deleteUser()
{
  FILE *fp, *fp1;
  struct person info;
  char another;
  int account, found = 0;
  do
  {
    system(clear);
    fp = fopen("./bank.csv", "rb");
    fp1 = fopen("./temp_bank.csv", "a");

    if (fp == NULL)
    {
      fprintf(stderr, "can't open file\n");
      exit(0);
    }
    printf("Enter the account: ");
    cin >> account;

    while (fread(&info, sizeof(struct person), 1, fp))
    {
      if (info.account != account)
      {
        found = 1;
        fwrite(&info, sizeof(struct person), 1, fp1);
        found = 0;
      }
      else
      {
        cout << "Record deleted successfully\n";
        found = -1;
      }
    }

    if (info.account < 0)
    {
      cout << "Record not exists\n";
    }

    if (found == 1)
    {
      printf("Student record not found\n");
    }
    else if (found == -1)
    {
      
    }
    else
    {
      printf("Record not exists\n");
    }

    remove("./bank.csv");
    rename("./temp_bank.csv", "./bank.csv");
    fclose(fp);
    fclose(fp1);

    printf("Wana go back (y/n)");
    cin >> another;
  } while (another == 'n' || another == 'N');
}

void search()
{
  FILE *fp;
  struct person info;
  char another;
  int account;
  do
  {
    system(clear);
    fp = fopen("./bank.csv", "rb");
    if (fp == NULL)
    {
      cout << "can't open file";
      exit(0);
    }
    cout << "Enter the account: ";
    cin >> account;
    while (fread(&info, sizeof(struct person), 1, fp))
    {
      if (info.account == account)
      {
        found = 1;
        cout << "\t\tName: " << info.fname << info.lname << endl;
        cout << "\t\tAdress: " << info.adress << endl;
        cout << "\t\tCourse: "<< info.nominee << endl;
        cout << "\t\taccount:" << info.account << endl;
        cout << "\t\tamount:" << info.amount << endl;
        cout << endl;
      }
    }
    if (!found)
    {
      cout << "Student record not found\n";
    }

    fclose(fp);
    cout << "Wana go back (y/n)";
    cin >> another;
  } while (another == 'n' || another == 'N');
}

void display()
{
  char another;
  FILE *fp;
  struct person info;

  do
  {
    fp = fopen("./bank.csv", "rb");
    system(clear);

    cout << "\t\t\t\t___STUDENTS RECORD___\n\n\n";
    if (fp == NULL)
    {
      cout << "can't open file\n";
      exit(0);
    }
    else
    {
      // printf("");
    }
    struct person data_array[sizeof(struct person)];
    int num_data = 0;
    while (fread(&data_array[num_data], sizeof(struct person), 1, fp))
    {
      num_data++;
    }

    int i, j;
    for (i = 0; i < num_data - 1; i++)
    {
      for (j = 0; j < num_data - i - 1; j++)
      {
        if (data_array[j].account > data_array[j + 1].account)
        {
          struct person temp = data_array[j];
          data_array[j] = data_array[j + 1];
          data_array[j + 1] = temp;
        }
      }
    }

    for (i = 0; i < num_data; i++)
    {
      cout << "\t\tName  : " << data_array[i].fname << data_array[i].lname << endl;
      cout << "\t\tAdress : " << data_array[i].adress << endl;
      cout << "\t\tCourse: " << data_array[i].nominee << endl;
      cout << "\t\taccount :" << data_array[i].account << endl;
      cout << "\t\tamount :" << data_array[i].amount << endl;
      cout << "\n" << endl;
    }

    fclose(fp);

    cout << "Wana go back (y/n)";
    cin >> another;
  } while (another == 'n' || another == 'N');
}

int main()
{
  system(clear);
  int option;
  do
  {
    cout << "\tBank Management System\n 1.Add New User\n 2.Update User Data\n 3.Delete User Record\n 4.Search User Data\n 5.Show All Users\n 6.Exit\n";
    
    printf("\nPlease select the option: ");
    cin >> option;

    switch (option)
    {
    case 1:
      system(clear);
      addUser();
      system(clear);
      break;
    case 2:
      system(clear);
      updateUser();
      system(clear);
      break;
    case 3:
      system(clear);
      deleteUser();
      system(clear);
      break;
    case 4:
      system(clear);
      search();
      system(clear);
      break;
    case 5:
      system(clear);
      display();
      system(clear);
      break;
    case 6:
      exit(1);
    default:
      cout << "Please select the right option\n";
      break;
    }
  } while (option != 6);

  return 0;
}
