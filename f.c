#include<stdio.h>
#include<conio.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
// check if being compiled for windows or posix (linux/bsd/mac)
#ifdef _WIN32
    // include minimal windows headers
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    // include posix headers
    #include <time.h>
#endif
#define MAX_LINE 2048
#define FILENAME_SIZE 1024
int reg_stud_count=0;
int reg_fact_count=0;
int student(void);
int faculty(void);
int stud_login(void);
int stud_register(void);
void post_stud_register(void);
void display(void);
void fee(void);
int fact_login(void);
int fact_register(void);
void display_Fd(void);
void post_fact_register(void);
void get_data(void);
void alter_data(void);
void announcement(void);
void display_ann(void);
void reset_stud_data(void);
void delay_print(char *,unsigned int);
void milli_sleep(unsigned int);

int pwd_check_2=0;
int pwd_checkf_2=0;

struct STUD_DATA
{
  int age;
  char gender[2];
  float SGPA;
  char branch[20];
  char name[20];
  int roll_no;
  float fees_paid;

}stud[100];


void main()
{
     
     delay_print(" \t\t\t\t WELCOME TO ERP \n",20);
     printf("\n");
     int case1;
     delay_print(" \t\t\t\t DPU \n",15);
     printf("\n");
     delay_print("1 . Student\n",15);
     delay_print("2 . Faculty\n",15);
     scanf("%d",&case1);
     system("cls");
     
     switch (case1)
     {
     case 1:
        student();
        break;
     case 2 :
        faculty();   
        break;
     default:
        printf("------INVALID INPUT------\n");
        break;
     }


}

int student()
{
   delay_print(" \t\t\t\t DPU \n",17);
   printf("\n");

   delay_print("1 . Log in\n",17);
   delay_print("2 . Register\n",17);

   int case2;
   scanf("%d",&case2);
   switch (case2)
   {
   case 1:
      stud_login();
      break;
   case 2 :
      stud_register();
      break;   
   
   default:
       delay_print("------INVALID INPUT------\n",30);
      break;
   }
return 0;

}




int stud_login()
{  system("cls");
   int count=0,j=0,k=0,pwd_check=-1;
   char user_id[50],pwd[10],ch1[20],ch2[20],ch3,ch4;
   FILE *ptr;
   delay_print(" ENTER USER ID : \n",16);
   scanf("%s",&user_id);
   
 ptr = fopen("stud_data.txt","r");
 
 

 while((ch3 = getc(ptr)) != EOF)
 {
     
     fscanf(ptr,"%s",&ch1);
     pwd_check++;
     
     if(strcmp(user_id,ch1) == 0){
      j=1;
      break;
      }




 }if(j==1){printf("USER FOUND\n");}
 else{printf("INVALID USERNAME\n");}
 
 
  fclose(ptr);

  
  if (j==1){
   delay_print(" ENTER PASSWORD : \n",16);
  scanf("%s",&pwd);
 
 FILE *ptr2;
  
  ptr2=fopen("stud_pwd.txt","r");

  while((ch4 = getc(ptr2)) != EOF )
 {
     pwd_check_2++;
     
     fscanf(ptr2,"%s",ch2);
     //printf("%d %d %s",pwd_check,pwd_check_2,pwd);
     if(strcmp(pwd,ch2) == 0 && pwd_check/7 ==pwd_check_2-1){
      k=1;
      break;
      }
  }
  if(k==1){printf("\nCORRECT PASSWORD\n");}
 else{printf("INCORRECT PASSWORD\n");}
 
  
  if(k==1){
 

 int q;
 do{

 delay_print("ENTER 1 TO DISPLAY YOUR DATA : \n\n",5); 
 delay_print("ENTER 2 PAY FEE : \n\n",5);
 printf("\n");
 delay_print("ENTER 3 TO SEE ANY ANNOUNCEMENTS : \n\n",5);
 delay_print("ENTER 4 TO RESET DATA : \n\n",5);
 delay_print("ENTER 5 TO EXIT\n\n",5);
 scanf("%d",&q);
 
 
 switch (q)
 {
 case 1:
   display();
   break;
 case 2 :
   fee();
 break;
  case 3:
  display_ann();
  break;
 case 4:
   reset_stud_data();
   break;
 default:
  printf("EXIT");
   break;
 }
 }while(q!=5);

   return 0;
}
}
}

int stud_register()

{  system("cls");
   reg_stud_count++;
   int z=0,space_check=0;
   char user_id[50],pwd[10],c;
   FILE *ptr;
   FILE *ptr3;
   delay_print(" ENTER USER ID : \n",5);
   scanf("%s",&user_id);
   delay_print(" ENTER A PASSWORD [MIN 6 LENGTH] : \n",5);
   scanf("%s",&pwd);
   
   //code to check if already any content exists in file or not
   FILE *check;
   check = fopen("stud_data.txt","r");
   while((c = getc(check)) != EOF)
   {
    fscanf(check,"%c",&c);
    space_check++;
    printf("%d",space_check);
   }
   fclose(check);
   //code to check complete
   ptr = fopen("stud_data.txt","a");
   
      fputs("\n",ptr);
   
   fputs(strcat(user_id,"\n"),ptr);
   

   fclose(ptr);

   ptr3 = fopen("stud_pwd.txt","a");
   
   fputs("\n",ptr3);
   fputs(strcat(pwd,"\n"),ptr3);

   fclose(ptr3);


   system("cls");
   delay_print(" YOU ARE NOW REGISTERED \n\n",10);
   post_stud_register();

   return 0;
}

void post_stud_register()
{
  delay_print("ENTER YOUR FULL NAME : \n",5);
  scanf("%s",&stud[reg_stud_count -1 ].name);
 
  

  delay_print("ENTER YOUR AGE : \n",5);
  scanf("%d",&stud[reg_stud_count -1 ].age);
  

  delay_print("ENTER YOUR GENDER [M/F] : \n",5);
  scanf("%s",&stud[reg_stud_count -1 ].gender);

  delay_print("ENTER YOUR BRANCH (IN CAPITAL) : \n",5);
  scanf("%s",&stud[reg_stud_count -1 ].branch);

  delay_print("ENTER YOUR ROLL NUMBER : \n",5);
  scanf("%d",&stud[reg_stud_count -1 ].roll_no);

  delay_print("ENTER YOUR CURRENT GPA : \n",5);
  scanf("%f",&stud[reg_stud_count -1 ].SGPA);


 //printf("%d",stud[reg_stud_count -1 ].age);
 //printf("%s",stud[reg_stud_count -1 ].gender);
 //printf("%s",stud[reg_stud_count -1 ].branch);
 //printf("%d",stud[reg_stud_count -1 ].roll_no);
 //printf("%f",stud[reg_stud_count -1 ].SGPA);
 FILE *ptr;
 ptr = fopen("stud_data.txt","a");
  
  fputs(stud[reg_stud_count -1 ].branch,ptr);
  fputs("\n",ptr);
  fputs(stud[reg_stud_count -1 ].gender,ptr);
  fputs("\n",ptr);
  fprintf(ptr,"%d",stud[reg_stud_count -1 ].age);
  fputs("\n",ptr);
  fprintf(ptr,"%d",stud[reg_stud_count -1 ].roll_no);
  fputs("\n",ptr);
  fprintf(ptr,"%f",stud[reg_stud_count -1 ].SGPA);
  fputs("\n",ptr);

  fprintf(ptr,"%f",0.00);







 fclose(ptr);

 printf("----DATA ACCEPTED-----");
 system("cls");


}

void display()
{  
FILE *ptr;
char ch5[100];
int m;
float f;
ptr = fopen("stud_data.txt","r");
 
for (int i=0;i<(pwd_check_2 -1)* 7;i++){ 
   fscanf(ptr,"%s",ch5);
   
};

fscanf(ptr,"%s",ch5);
printf("USERNAME : %s\n",ch5);

fscanf(ptr,"%s",ch5);
printf("BRANCH : %s\n",ch5);

fscanf(ptr,"%s",ch5);
printf("GENDER : %s\n",ch5);

fscanf(ptr,"%d",&m);
printf("AGE : %d\n",m);

fscanf(ptr,"%d",&m);
printf("ROLL N0 : %d\n",m);

fscanf(ptr,"%f",&f);
printf("SGPA : %f\n",f);



   
  


fclose(ptr);
}


void fee()
{
   float total_fee;
   float fee_paid = 0;
   float fee_due;
   int switch_var;
   int cat_var;
   char ch6[20];
   

FILE *pttr;
pttr = fopen("stud_data.txt","a+");   

delay_print("SELECT YOUR CATEGORY : \n",10);
printf("1 --> OPEN\n");
printf("2 --> SC\n");
printf("3 --> ST\n");
printf("4 --> NT\n");
printf("5 --> TFWS\n");
scanf("%d",&cat_var);

system("cls");

if(cat_var == 1){total_fee = 117000.00;}
else if (cat_var == 5)
{
   total_fee = 13500.00;
}
else{total_fee = 65000.00;};
fee_due = total_fee - fee_paid;


printf("S.E TOTAL FEE %f: \n",total_fee);
printf("\n\n");
printf("ENTER 1 TO PAY FEE : \n");
printf("ENTER 2 TO CHECK REMAINING FEE : \n");
printf("ENTER 3 TO GO TO DASHBOARD : \n");
scanf("%d",&switch_var);

system("cls");

for (int i=0;i<(pwd_check_2 * 6) + (pwd_check_2-1);i++){ 
   fscanf(pttr,"%s",&ch6);
   
};

fscanf(pttr,"%s",&ch6);
printf("check : %s",ch6);

//string to float
fee_paid= atof(ch6);

//fscanf(pttr,"%f",&fee_paid);
//printf("check : %f",fee_paid);
fclose(pttr);

switch (switch_var)
{
case 1:
   printf("UPI ID : dypatilinstituteasebuzz@yesbank\n");
   printf("AMOUNT TO PAY : INR %f\n",fee_due);
   //printf("ENTER THE AMOUNT YOU PAID NOW : \n");
   //scanf("%f",&fee_paid);
   
   

    // file pointers for the original file and temp file
  FILE *file, *temp;

  // store the filename and temp filename
  char filename[FILENAME_SIZE] = "stud_data.txt";
  char temp_filename[FILENAME_SIZE];
  char FEE_PAID[20];
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE];
 // char replace[MAX_LINE];
  

  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user to enter the filename, store it into filename
  //printf("File: ");
  //scanf("%s", filename);
  

  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // ask the user for the line number to replace, store it into replace_line
  //printf("Replace Line Number: ");
  //scanf("%d", &replace_line);
  replace_line = (pwd_check_2 * 7) + 1;
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  printf("FEE PAID NOW : \n");
  
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  
  // check if either file failed to open, if either did exit with error status
  
  
  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer
    fgets(buffer, MAX_LINE, file);
    
    // if we've reached the end of the file, stop reading
    if (feof(file)) keep_reading = false;
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
      fputs(replace, temp);
    // otherwise write this line to the temp file
    else fputs(buffer, temp);
    
    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);
  
  // close our access to both files as we are done with them
  fclose(file);
  fclose(temp);
  
  // delete the original file, rename temp file to the original file's name
  remove(filename);
  rename(temp_filename, filename);
  
   break;
case 2:
//printf("%f",total_fee);
//printf("%f",fee_paid);

fee_due = total_fee - fee_paid;
printf("FEE TO BE PAID : inr %f\n",fee_due);

break;
case 3:
stud_login();
break;
default:
printf("wrong entry");

   break;
}





  



}
struct FACULTY_DATA
{
  char name[20];
  int id;
  char gender[2];
  int age;
  char Degree[30];
  char T_subj[20];

}f[100];

int faculty()
{ system("cls");
  printf(" \t\t\t\t DPU \n");
   printf("\n");

   printf("1 . Log in\n");
   printf("2 . Register\n");

   int case2;
   scanf("%d",&case2);
   switch (case2)
   {
   case 1:
      fact_login();
      break;
   case 2 :
      fact_register();
      break;   
   
   default:
       printf("------INVALID INPUT------\n");
      break;
   }
   
return 0;



}

int fact_login()
{
   system("cls");
   int count=0,j=0,k=0,pwd_check=0;
   char user_id[50],pwd[10],ch1[20],ch2[20],ch3,ch4;
   FILE *ptr;
   printf(" ENTER USER ID : \n");
   scanf("%s",&user_id);
   
 ptr = fopen("fact_data.txt","r");
 
 

 while((ch3 = getc(ptr)) != EOF)
 {
     
     fscanf(ptr,"%s",&ch1);
     pwd_check++;
     
     if(strcmp(user_id,ch1) == 0){
      j=1;
      break;
      }




 }if(j==1){printf("USER FOUND\n");}
 else{printf("INVALID USERNAME\n");}
 
 
  fclose(ptr);

  
  if (j==1){
   printf(" ENTER A PASSWORD [MIN 6 LENGTH] : \n");
  scanf("%s",&pwd);
 
 FILE *ptr2;
  
  ptr2=fopen("fact_pwd.txt","r");

  while((ch4 = getc(ptr2)) != EOF )
 {
     pwd_checkf_2++;
     
     fscanf(ptr2,"%s",ch2);
     
     if(strcmp(pwd,ch2) == 0 && pwd_check/4 ==pwd_checkf_2-1){
      k=1;
      break;
      }
  }
  if(k==1){printf("\nCORRECT PASSWORD\n");}
 else{printf("INCORRECT PASSWORD\n");}
 
  
  }
 if(k==1){
 while(1)
 {
 int q;

 printf("ENTER 1 TO DISPLAY YOUR DATA : \n\n");
 printf("\n");
 printf("ENTER 2 TO ACCESS STUDENT DATA : \n\n");
 printf("\n");
 printf("ENTER 3 TO CHANGE CPA :\n\n");
 printf("\n");
 printf("ENTER 4 FOR ANNOUNCEMENT\n\n");
 printf("\n");
 printf("ENTER 5 TO EXIT : \n\n");

 scanf("%d",&q);
 
 if(q==1)
 {
   display_Fd();
 }
 else if(q==2){
    get_data();

 }
 else if(q==3)
 {
   alter_data();
 }
 else if (q==4)
 {
    announcement();
 }
 
 else
 {
   printf("\n EXIT");
   break;
 }
 
 }


   return 0;

}}

int fact_register()

{  system("cls");
   reg_fact_count++;
   printf("%d",reg_fact_count);
   int z=0;
   char user_id[50],pwd[10];
   FILE *ptr;
   FILE *ptr3;
   printf(" ENTER USER ID : \n");
   scanf("%s",&user_id);
   printf(" ENTER A PASSWORD [MIN 6 LENGTH] : \n");
   scanf("%s",&pwd);
   
   
   

   
   ptr = fopen("fact_data.txt","a");
   
   if(reg_fact_count==1){fputs("\n",ptr);}
   fputs(strcat(user_id,"\n"),ptr);
   

   fclose(ptr);

   ptr3 = fopen("fact_pwd.txt","a");

   if(reg_fact_count==1){fputs("\n",ptr);}
    
   fputs(strcat(pwd,"\n"),ptr3);

   fclose(ptr3);


   system("cls");
   printf(" YOU ARE NOW REGISTERED \n\n");
   post_fact_register();

   return 0;
}
void post_fact_register()
{ 
  system("cls");
  printf("ENTER YOUR FULL NAME : \n");
  scanf("%s",&f[reg_fact_count -1 ].name);
 
  

  printf("ENTER YOUR AGE : \n");
  scanf("%d",&f[reg_fact_count -1 ].age);
  

  printf("ENTER YOUR GENDER [M/F] : \n");
  scanf("%s",&f[reg_fact_count -1 ].gender);

  printf("ENTER YOUR TEACHING SUBJECT: \n");
  scanf("%s",&f[reg_fact_count -1 ].T_subj);

  printf("ENTER YOUR degree: \n");
  scanf("%s",&f[reg_fact_count -1 ].Degree);

  

 FILE *ptr;
 ptr = fopen("fact_data.txt","a");
  
  
  fprintf(ptr,"%d",f[reg_fact_count -1 ].age);
  fputs("\n",ptr);
  fputs(f[reg_fact_count -1 ].gender,ptr);
  fputs("\n",ptr);
  fputs(f[reg_fact_count -1 ].T_subj,ptr);
  fputs("\n",ptr);
  fputs(f[reg_fact_count -1 ].Degree,ptr);
  fputs("\n",ptr);






 fclose(ptr);

 printf("----DATA ACCEPTED-----");
 system("cls");


}
void display_Fd()
{  
FILE *ptr;
char ch5[100];
int m;

ptr = fopen("fact_data.txt","r");
 
for (int i=0;i<(pwd_checkf_2 -1)* 5;i++){ 
   fscanf(ptr,"%s",ch5);
   
};

fscanf(ptr,"%s",ch5);
printf("USERNAME : %s\n",ch5);

fscanf(ptr,"%d",&m);
printf("AGE : %d\n",m);

fscanf(ptr,"%s",ch5);
printf("GENDER : %s\n",ch5);

fscanf(ptr,"%s",ch5);
printf("TEACHING SUBJECT : %s\n",ch5);

fscanf(ptr,"%s",ch5);
printf("COMPLETED DEGREE : %s\n",ch5);




  
  


fclose(ptr);
}

void get_data(){

int roll,line_no=0,ch1_int,m;
float f;    
char ch,ch1[20];
system("cls");    
printf("ENTER ROLL NUMBER OF STUDENT ACCESS HIS/HER DATA : \n");
scanf("%d",&roll);

FILE *ptr;
ptr = fopen("stud_data.txt","r");
while((ch = getc(ptr)) != EOF)
{


fscanf(ptr,"%s",ch1);
line_no++;
ch1_int = atoi(ch1);
if(ch1_int == roll)
{
    break;
}



}
fclose(ptr);

line_no=line_no/7;
//printf("%d",line_no);
ptr = fopen("stud_data.txt","r");
for(int i=0;i<(line_no)*7;i++)
{
    fscanf(ptr,"%s",ch1);
    
}

fscanf(ptr,"%s",ch1);
printf("USERNAME : %s\n",ch1);

fscanf(ptr,"%s",ch1);
printf("BRANCH : %s\n",ch1);

fscanf(ptr,"%s",ch1);
printf("GENDER : %s\n",ch1);

fscanf(ptr,"%d",&m);
printf("AGE : %d\n",m);

fscanf(ptr,"%d",&m);
printf("ROLL N0 : %d\n",m);

fscanf(ptr,"%f",&f);
printf("SGPA : %f\n",f);

fclose(ptr);

}

void alter_data()
{
   int roll,line_no=0,ch1_int;
   char ch,ch1[20];
   system("cls");
   printf("ENTER ROLL NUMBER OF STUDENT TO CHANGE HIS/HER SGPA : \n");
   scanf("%d",&roll);
   
   FILE *ptr;
ptr = fopen("stud_data.txt","r");
while((ch = getc(ptr)) != EOF)
{


fscanf(ptr,"%s",ch1);
line_no++;
ch1_int = atoi(ch1);
if(ch1_int == roll)
{
    break;
}



}
fclose(ptr);
//printf("%d",line_no);
line_no+=2;

 
   // file pointers for the original file and temp file
  FILE *file, *temp;
  
  // store the filename and temp filename
  char filename[] = "stud_data.txt";
  char temp_filename[2024];
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE];

  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user to enter the filename, store it into filename
  //printf("File: ");
  //scanf("%s", filename);
  

  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // ask the user for the line number to replace, store it into replace_line
  //printf("Replace Line Number: ");
  //scanf("%d", &replace_line);
  replace_line = line_no;
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  //printf("New Line: ");
  printf("ENTER THE NEW GPA :\n");
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  
  
  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer
    
    fgets(buffer, MAX_LINE, file);
    
    // if we've reached the end of the file, stop reading
    if (feof(file)) keep_reading = false;
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
      fputs(replace, temp);
    // otherwise write this line to the temp file
    else fputs(buffer, temp);
    
    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);
  
  // close our access to both files as we are done with them
  fclose(file);
  fclose(temp);
  
  // delete the original file, rename temp file to the original file's name
  remove(filename);
  rename(temp_filename, filename);

  


   
}

void announcement()
{

 int d_final,m_final,y_final;  
 char ann[500]; 
 system("cls");
 printf("TYPE THE DATE UNTIL WHEN ANNOUNCEMENT IS TO BE DISPLAYED\n");
 printf("ENTER IN FORMAT DD MM YYYY\n");
 


    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    //getch();
    
    scanf("%d %d %d",&d_final,&m_final,&y_final);
    printf("TYPE AND ENTER YOUR ANNOUNCEMENT\n");
    printf("ENTER UNDERSCORE INSTEAD OF SPACE\n");
    scanf("%s",&ann);

    FILE *ptr;
    ptr = fopen("ann.txt","a+");

    fputs("\n",ptr);
    fprintf(ptr,"%d %d %d\n",d_final,m_final,y_final);
    fputs(ann,ptr);


    fclose(ptr);

    


}

void display_ann()
{   
   time_t t;
   t = time(NULL);
   struct tm tm = *localtime(&t);

   FILE *ptr;
   ptr = fopen("ann.txt","r");
   int d_final,m_final,y_final;
   char s[50],c;
   while((c=getc(ptr)) != EOF)
   {

   fscanf(ptr,"%d",&d_final);
   //printf("%d",m);
   
   fscanf(ptr,"%d",&m_final);
   //printf("%d",m);

   fscanf(ptr,"%d",&y_final);
   //printf("%d",m);

   fscanf(ptr,"%s",&s);
   //printf("%s",s);

   if((y_final > tm.tm_year+1900) || (m_final > tm.tm_mon+1))
   { printf("TODAY IS : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
     printf("%s\n\n",s);
   }
   else if((y_final <= tm.tm_year+1900) && (m_final <= tm.tm_mon+1) && (d_final <= tm.tm_mday))
   {
     printf("\n");
   }
   else{
      printf("TODAY IS : %d-%d-%d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
      printf("%s\n\n",s);
      }


}
fclose(ptr);
}

void reset_stud_data()
{  
   int choice;
   char u_name[20];
   system("cls");
   printf("1 . CHANGE YOUR USERNAME : \n");
   printf("2 . RESET PASSWORD : \n");
   scanf("%d",&choice);

   if(choice == 1)
   {
      
    // file pointers for the original file and temp file
  FILE *file, *temp;

  // store the filename and temp filename
  char filename[FILENAME_SIZE] = "stud_data.txt";
  char temp_filename[FILENAME_SIZE];
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE] ;
  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user to enter the filename, store it into filename
  //printf("File: ");
  //scanf("%s", filename);
  

  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // ask the user for the line number to replace, store it into replace_line
  //printf("Replace Line Number: ");
  //scanf("%d", &replace_line);
  replace_line = ((pwd_check_2-1) * 7) + 2;
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  //printf("New Line: ");
  printf("enter new username : \n");
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  

  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer
    fgets(buffer, MAX_LINE, file);
    
    // if we've reached the end of the file, stop reading
    if (feof(file)) keep_reading = false;
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
      fputs(replace, temp);
    // otherwise write this line to the temp file
    else fputs(buffer, temp);
    
    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);
  
  // close our access to both files as we are done with them
  fclose(file);
  fclose(temp);
  
  // delete the original file, rename temp file to the original file's name
  remove(filename);
  rename(temp_filename, filename);

  
   }
   else
   {
    // file pointers for the original file and temp file
  FILE *file1, *temp1;

  // store the filename and temp filename
  char filename[FILENAME_SIZE] = "stud_pwd.txt";
  char temp_filename[FILENAME_SIZE];
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE] ;
  
  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user to enter the filename, store it into filename
  //printf("File: ");
  //scanf("%s", filename);
  

  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp___");
  strcat(temp_filename, filename);
  
  // ask the user for the line number to replace, store it into replace_line
  //printf("Replace Line Number: ");
  //scanf("%d", &replace_line);
  replace_line = (pwd_check_2 * 2);
  printf("replace line : %d",replace_line);
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  //printf("New Line: ");
  printf("enter new password : \n");
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file1 = fopen(filename, "r");
  temp1 = fopen(temp_filename, "w");
  

  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer
    fgets(buffer, MAX_LINE, file1);
    
    // if we've reached the end of the file, stop reading
    if (feof(file1)) keep_reading = false;
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
      fputs(replace, temp1);
    // otherwise write this line to the temp file
    else fputs(buffer, temp1);
    
    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);
  
  // close our access to both files as we are done with them
  fclose(file1);
  fclose(temp1);
  
  // delete the original file, rename temp file to the original file's name
  remove(filename);
  rename(temp_filename, filename);

   }

}
void delay_print(char* str, unsigned int milliseconds)
{
    for (; *str; str++) {
        putchar(*str);
        fflush(stdout);
        milli_sleep(milliseconds); 
    }
}

void milli_sleep(unsigned int milliseconds)
{
#ifdef _WIN32
    // use windos Sleep function, sleeps for a number of milliseconds
    Sleep(milliseconds);
#else
    // use posix nanosleep function, sleeps for a number of nanoseconds
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}
