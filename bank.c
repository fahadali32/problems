#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    printf("\t.....Add User.....\n\n");

    printf("Enter First Name: ");
    scanf("%s", info.fname);

    printf("Enter Last Name: ");
    scanf("%s", info.lname);
    printf("Enter Adress: ");
    scanf("%s", info.adress);
    printf("Enter Nominee Name: ");
    scanf("%s", info.nominee);
    printf("Enter account: ");
    scanf("%d", &info.account);
    printf("Enter amount: ");
    scanf("%f", &info.amount);

    fp = fopen("./bank.csv", "a");

    fwrite(&info, sizeof(struct person), 1, fp);
    fclose(fp);
    if (fp == NULL)
    {
      printf("Can't open the file\n");
    }
    else
    {
      printf("Record stored successfuly\n");
    }

    printf("Add another user (y/n)");
    scanf("%s", &another);
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
    printf("Enter the account: ");
    scanf("%d", &account);
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

      printf("Enter the first name: ");
      scanf("%s", up.fname);
      printf("Enter the last name: ");
      scanf("%s", up.lname);
      printf("Enter the adress: ");
      scanf("%s", up.adress);
      printf("Enter the nominee name: ");
      scanf("%s", up.nominee);
      printf("Enter the account: ");
      scanf("%d", &up.account);
      printf("Enter the amount: ");
      scanf("%f", &up.amount);

      fwrite(&up, sizeof(struct person), 1, fp1);
      remove("./bank.csv");
      rename("./temp_bank.csv", "./bank.csv");
      fclose(fp);
      fclose(fp1);
    }
    else
    {
      printf("Record not found\n");
    }

    printf("Wana go back (y/n)");
    scanf("%s", &another);
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
    scanf("%d", &account);

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
        printf("Record deleted successfully\n");
        found = -1;
      }
    }

    if (info.account < 0)
    {
      printf("Record not exists\n");
    }

    if (found == 1)
    {
      printf("User record not found\n");
    }
    else if (found == -1)
    {
      /* code */
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
    scanf("%s", &another);
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
      fprintf(stderr, "can't open file\n");
      exit(0);
    }
    printf("Enter the account: ");
    scanf("%d", &account);
    while (fread(&info, sizeof(struct person), 1, fp))
    {
      if (info.account == account)
      {
        found = 1;
        printf("\t\tName: %s %s \n", info.fname, info.lname);
        printf("\t\tAdress: %s\n", info.adress);
        printf("\t\tNominee: %s\n", info.nominee);
        printf("\t\taccount: %d\n", info.account);
        printf("\t\tamount:%.2f\n", info.amount);
        printf("\n");
      }
    }
    if (!found)
    {
      printf("User record not found\n");
    }

    fclose(fp);
    printf("Wana go back (y/n)");
    scanf("%s", &another);
  } while (another == 'n' || another == 'N');
}

void deposit()
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
    scanf("%d", &account);
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
      strcpy(up.fname,info.fname);
      strcpy(up.lname,info.lname);
      strcpy(up.adress,info.adress);
      strcpy(up.nominee,info.nominee);
      up.account = info.account;
      printf("Enter the amount: ");
      scanf("%f", &up.amount);
      up.amount = info.amount+up.amount;
      fwrite(&up, sizeof(struct person), 1, fp1);
      remove("./bank.csv");
      rename("./temp_bank.csv", "./bank.csv");
      fclose(fp);
      fclose(fp1);
    }
    else
    {
      printf("Record not found\n");
    }


    printf("Wana go back (y/n)");
    scanf("%s", &another);
  } while (another == 'n' || another == 'N');
}

void withdraw()
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
    scanf("%d", &account);
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
      strcpy(up.fname,info.fname);
      strcpy(up.lname,info.lname);
      strcpy(up.adress,info.adress);
      strcpy(up.nominee,info.nominee);
      up.account = info.account;
      printf("Enter the amount: ");
      scanf("%f", &up.amount);
      up.amount = info.amount-up.amount;
      fwrite(&up, sizeof(struct person), 1, fp1);
      remove("./bank.csv");
      rename("./temp_bank.csv", "./bank.csv");
      fclose(fp);
      fclose(fp1);
    }
    else
    {
      printf("Record not found\n");
    }


    printf("Wana go back (y/n)");
    scanf("%s", &another);
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

    printf("\t\t\t\t___USER RECORD___\n\n\n");
    if (fp == NULL)
    {
      fprintf(stderr, "can't open file\n");
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
      printf("\t\tName  : %s %s\n", data_array[i].fname, data_array[i].lname);
      printf("\t\tAdress: %s\n", data_array[i].adress);
      printf("\t\tNominee: %s\n", data_array[i].nominee);
      printf("\t\tAccount  : %d\n", data_array[i].account);
      printf("\t\tAmount  :%.2f\n", data_array[i].amount);
      printf("\n");
    }

    fclose(fp);

    printf("Wana go back (y/n)");
    scanf("%s", &another);
  } while (another == 'n' || another == 'N');
}

int main()
{
  system(clear);
  int option;
  do
  {
    char *message =
        "\tBank Management System\n"
        "1.Add New User\n"
        "2.Update User Data\n"
        "3.Delete User Record\n"
        "4.Search User Data\n"
        "5.Show All Users\n"
        "6.Deposit\n"
        "7.Withdraw\n"
        "8.Exit\n";
    printf("%s", message);

    printf("\nPlease select the option: ");
    scanf("%d", &option);

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
      system(clear);
      deposit();
      system(clear);
      break;
    case 7:
      system(clear);
      withdraw();
      system(clear);
      break;
    case 8:
      exit(1);
    default:
      printf("Please select the right option\n");
      break;
    }
  } while (option != 8);

  return 0;
}
