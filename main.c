
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_Student 10
#define MAX_LINE_LENGTH 100

typedef struct Node* pointerToNode;
struct studentNode {
    int studentID;                // Unique student ID
    char studentName[50];         // Student name
    char homeAddress[100];        // Home address (city)
    int classID;                  // ID of class the student is currently in
    char dateOfEnrollment[20];     // Date of enrollment
};
struct Node{
struct studentNode Student;
struct Node* Left;
struct Node* Right;

};
    struct studentNode* A[100];
//method From slides BST
pointerToNode MakeEmpty( pointerToNode T );
pointerToNode Find( int X, pointerToNode T );
pointerToNode FindMin( pointerToNode T );
pointerToNode FindMax( pointerToNode T );
pointerToNode Insert(int studentID, const char* studentName, const char* homeAddress, int classID, const char* dateOfEnrollment, pointerToNode T );
//New method
int sizeTree(pointerToNode T);
void BSTToArray(pointerToNode T,struct studentNode A[]);
void PrintNameStudentByLexicographic(struct studentNode A[],int size);

void MainFunctionPrintName(pointerToNode T);

void convertToLowercase(char strings[]);
int compareTwoString(char a[],char b[]);
pointerToNode BSTToArrayByClassID(pointerToNode T,pointerToNode BstCountry,int ClassID );
//void BSTToArrayByNameCountry(pointerToNode T,char** ArrayName,const char* homeAddress );
pointerToNode BSTToArrayByNameCountry(pointerToNode T,pointerToNode BstCountry,const char* homeAddress );

char  *removeSpacesFromStr(char string[]);
pointerToNode Delete( int X, pointerToNode T );
void reverseArray(char** array, int size);
void MainFunctionClassID(pointerToNode BST,int ClassID);
void MainFunctionCountryName(pointerToNode BST,const char* homeAddress);
pointerToNode  FindAndUpdate(int X,pointerToNode BST);
void copyArray(struct studentNode array1[],struct studentNode array2[],int size );

pointerToNode InsertToBTSbyName(int studentID, const char* studentName, const char* homeAddress, int classID, const char* dateOfEnrollment, pointerToNode T );
void printBSTBYName(struct Node* root);
pointerToNode loadInfo(pointerToNode BST);

int main()
{
    pointerToNode BST;
    pointerToNode BSTName;
    char  AddressName[20];
    int NumberFound=0;
    int NumberStudentFind=0;
    int sizeStduend;
  //  struct studentNode* A[sizeStduend];
    int choice=1;
    display_Menu();
     printf("\n Enter your choice:");
     scanf("%d",&choice);
     int i=0;
     while(choice != 8)
     {
        switch(choice)
         {


        case 1://readFromFile(4,A);
            //Enter
       BSTName=loadInfo(BST);
            break;
        case 2://

        printf("\nEnter Number student you want Find:");
        scanf("%d",&NumberStudentFind);
        printf("\nIF YOU just want find Enter number 1: ");
        scanf("%d",&NumberFound);
        if(NumberFound==1)
        {

            pointerToNode FindNode;
           FindNode= Find(NumberStudentFind,BSTName);
         printf("\n-----------------\n");
         printf("\nName student : %s \n", FindNode->Student.studentName);
         printf("\nStudent ID : %d \n", FindNode->Student.studentID);
          printf("\nHome Address : %s \n", FindNode->Student.homeAddress);
           printf("\nClass ID : %d \n", FindNode->Student.classID);
           printf("\nDate Of Enrollment : %s \n", FindNode->Student.dateOfEnrollment);
            printf("\n----------------\n");
             break;
        }
        else
        {
            pointerToNode TEMPFound;
           TEMPFound=FindAndUpdate(NumberStudentFind,BSTName);
             BSTName=TEMPFound;
              break;
        }

      case 3://List	all	students	in	lexicographic	order	of	their	names.
              printBSTBYName(BSTName);
        break;

    case 4://Search	for	a	city	and	list	all	students	from	that	city in	lexicographic	order
            //of	their	names.

           // char  *AddressName[20];
             printf("\nEnter the Name Cities  you want to Search : ");
             scanf("%s",AddressName);
              pointerToNode BstCountry;
              pointerToNode TempCountry;
              TempCountry=BSTToArrayByNameCountry(BSTName,BstCountry,AddressName);
              printBSTBYName(TempCountry);



        break;

    case 5://List	all	students	by	their	class	in	lexicographic	order	of	their	names.

    printf("\nEnter the Class ID number you want to delete : ");
            int IdClass;
        scanf("%d",&IdClass);
        pointerToNode BstCLassID;
        pointerToNode TempClassID;
       TempClassID=BSTToArrayByClassID(BSTName,BstCLassID,IdClass);
       printBSTBYName(TempClassID);
        break;
    case 6://Delete	a	student	given	his/her	student	ID
        printf("\nEnter the student ID number you want to delete : ");
        int IdStudent;
        scanf("%d",&IdStudent);
        pointerToNode TempDelete;
        TempDelete=Delete(IdStudent,BSTName);
        BSTName=TempDelete;
        printf("\nDone Student with number %d is Deleted\n",IdStudent);
        break;

    case 7://Save	all	students	in	file	students.data.
       // struct studentNode A[Size];
       // BSTToArray()
       sizeStduend=sizeTree(BSTName);

       BSTToArray(BSTName,A);
        writeStudentsToFile(A,sizeStduend);
        printf("\nCheck File \n");

        break;
    case 8://Exit from program
        break;

    default:printf("\n\nInvalid Value\n");
        break;

         }

     display_Menu();
     printf("\nEnter your choice :");
     scanf("%d",&choice);
     }

        printf("\n\n\n.........................................   GOOD BAY ^-^   ......................................................  \n\n");


    printf("\nHello world!");
    return 0;

}



//Method from slides to BST
pointerToNode MakeEmpty( pointerToNode T ){

if( T != NULL ){

MakeEmpty( T->Left );
MakeEmpty( T->Right );
free( T );

}
return NULL;

}

/*
*�returns a pointer to the node in tree T that has key X
*�if T is NULL, then return NULL
*� Otherwise, make a recursive call on a subtree of T,
*/
pointerToNode Find( int X, pointerToNode T ){

  if( T == NULL)
  {
    return NULL;
  }

  else if( X < T->Student.studentID)
  {
    return Find( X, T->Left );
  }

  else if( X > T->Student.studentID )
  {
    return Find( X, T->Right );
  }


  else
  {

    return T;
  }

}
//recursive implementation of the FindMin
pointerToNode FindMin( pointerToNode T ){

if( T == NULL)
return NULL;

else if( T -> Left == NULL)

return T;

else

return FindMin( T->Left );

}

//�FindMax: the same, except you have to go to the right
//child.

pointerToNode FindMax( pointerToNode T ){

  if( T == NULL)
    return NULL;

  else if( T -> Right == NULL)
    return T;

  else
    return FindMax( T->Right);
}
/*�To insert X into tree T, proceed down the tree as you would
* with a FIND.
*� If X is found, do nothing (or update, duplicates are handled
*by keeping an extra field in the node record indicating the
*frequency of occurrence).
*�Otherwise (X is not found), insert X at the last spot on the
*path traversed.
*/
pointerToNode Insert(int studentID, const char* studentName, const char* homeAddress, int classID, const char* dateOfEnrollment, pointerToNode T ){

  if( T == NULL)
    {

    //create and return a 1-node tree
       T = (struct Node*)malloc( sizeof( struct Node ) );
        if( T == NULL)
        {
          printf("\nOut of space\n");
        }

        else
        {

           T->Student.studentID =studentID;
           strncpy(T->Student.studentName, studentName, sizeof(T->Student.studentName) - 1);
           strncpy(T->Student.homeAddress, homeAddress, sizeof(T->Student.homeAddress) - 1);
           T->Student.classID = classID;
           strncpy(T->Student.dateOfEnrollment, dateOfEnrollment, sizeof(T->Student.dateOfEnrollment) - 1);
            T->Left = T->Right = NULL;
        }

    }
   else if( studentID < T->Student.studentID )
         {
           T->Left = Insert( studentID,studentName,homeAddress,classID,dateOfEnrollment ,T->Left);
         }

   else if( studentID > T->Student.studentID)
    {

           T->Right = Insert( studentID,studentName,homeAddress,classID,dateOfEnrollment, T->Right );
    }

  //else, X is in the tree already; do nothing

    return T;
    }

pointerToNode InsertToBTSbyName(int studentID, const char* studentName, const char* homeAddress, int classID, const char* dateOfEnrollment, pointerToNode T ){

  if( T == NULL)
    {

    //create and return a 1-node tree
       T = (struct Node*)malloc( sizeof( struct Node ) );
        if( T == NULL)
        {
          printf("\nOut of space\n");
        }

        else
        {

           T->Student.studentID =studentID;
           strncpy(T->Student.studentName, studentName, sizeof(T->Student.studentName) - 1);
           strncpy(T->Student.homeAddress, homeAddress, sizeof(T->Student.homeAddress) - 1);
           T->Student.classID = classID;
           strncpy(T->Student.dateOfEnrollment, dateOfEnrollment, sizeof(T->Student.dateOfEnrollment) - 1);
            T->Left = T->Right = NULL;
        }

    }
   else if( strcmp(studentName,T->Student.studentName)<=0 )
         {
           T->Left = InsertToBTSbyName( studentID,studentName,homeAddress,classID,dateOfEnrollment ,T->Left);
         }

   else if( strcmp(studentName,T->Student.studentName)>0)
    {

           T->Right = InsertToBTSbyName( studentID,studentName,homeAddress,classID,dateOfEnrollment, T->Right );
    }

  //else, X is in the tree already; do nothing

    return T;
    }

int sizeTree(pointerToNode T)
{
    if(T==NULL)
    {
        return 0;
    }
    else
    {
        return sizeTree(T->Left)+sizeTree(T->Right)+1;
    }
}
//Function convert BST to array of student
void BSTToArray(pointerToNode T,struct studentNode A[])
{
    static int pos=0;
    if(T==NULL)
    {
        return NULL;
    }
    else
    {
        //In-order traversal
        //left-root-right
        BSTToArray(T->Left,A);
        A[pos++]=T->Student;
        BSTToArray(T->Right,A);
    }


}
//Function print Name by lexi.
void printBSTBYName(pointerToNode root) {
    if (root != NULL) {
        printBSTBYName(root->Left);
        printf("\n-----------------\n");
        printf("\nName student : %s \n", root->Student.studentName);
         printf("\nStudent ID : %d \n", root->Student.studentID);
          printf("\nHome Address : %s \n", root->Student.homeAddress);
           printf("\nClass ID : %d \n", root->Student.classID);
           printf("\nDate Of Enrollment : %s \n", root->Student.dateOfEnrollment);
            printf("\n----------------\n");
        printBSTBYName(root->Right);
    }
}
pointerToNode BSTToArrayByNameCountry(pointerToNode T,pointerToNode BstCountry,const char* homeAddress )
{
  int Size=sizeTree(T);
    struct studentNode A[Size];
    BSTToArray(T,A);
    int i=0;
    //A[i]
    for(i=0;i<Size;i++)
    {
         if(strcmp(A[i].homeAddress,homeAddress)==0)
         {

              BstCountry=InsertToBTSbyName(A[i].studentID,A[i].studentName,A[i].homeAddress,A[i].classID,A[i].dateOfEnrollment,BstCountry);
         }
    }

    return BstCountry;
}
pointerToNode BSTToArrayByClassID(pointerToNode T,pointerToNode BstCountry,int ClassID )
{
  int Size=sizeTree(T);
    struct studentNode A[Size];
    BSTToArray(T,A);
    int i=0;
    //A[i]
    for(i=0;i<Size;i++)
    {
         if(A[i].classID ==ClassID)
         {

              BstCountry=InsertToBTSbyName(A[i].studentID,A[i].studentName,A[i].homeAddress,A[i].classID,A[i].dateOfEnrollment,BstCountry);
         }
    }

    return BstCountry;
}


void writeStudentsToFile(struct studentNode* students, int numStudents) {
    FILE* file = fopen("C:\\Users\\qarma\\Desktop\\testProj\\testvercise\\studentsData.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
       // fprintf(file, "------------------");
        fprintf(file, "%d", students[i].studentID);
        fprintf(file, " %s", students[i].studentName);
        fprintf(file, " %s", students[i].homeAddress);
        fprintf(file, " %d", students[i].classID);
        fprintf(file, " %s\n", students[i].dateOfEnrollment);
        //fprintf(file, "------------------");
    }

    fclose(file);
}

//display menu for choice
void display_Menu()
{
    printf("\n\n////////////////////////                          WELCOM BACK IN STUDENT Managment                //////////////////////////////\n\n\n");
    printf("                                      Enter your choice:\t\n\n");
    printf("                          1-Read From File\n");
    printf("                          2-Find a student by his/her student ID, and support updating of the student info if found\n");
    printf("                          3-List all students in lexicographic order of their names.\n");
    printf("                          4-Search for a city and list all students from that city in lexicographic order of their names\n");
    printf("                          5-List all students by their class in lexicographic order of their names.\n");
    printf("                          6-Delete a student given his/her student ID \n");
    printf("                          7-Save all students in file students.data.\n");
    printf("                          8-Exit\t\t\n\n");

}

pointerToNode loadInfo(pointerToNode BST) {
    FILE* file = fopen("C:\\Users\\qarma\\Desktop\\testProj\\testvercise\\studentsData.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char studentName[20], homeAddress[20],DateEnrollment[20];
        int studentID,ClassId;
        //studentID,StudentName,HomeAddress,CLASSid,DateEnroll
        sscanf(line, "%d %s %s %d %s",&studentID ,studentName,homeAddress,&ClassId,DateEnrollment);

       // printf("hello");
        BST=Insert(studentID,studentName,homeAddress,ClassId,DateEnrollment,BST);
    }

    fclose(file);

    pointerToNode ReturnBst=BST;
    //printBSTBYName(ReturnBst);
    printf("Student loaded from file.\n");
    return ReturnBst;
}


pointerToNode Delete( int X, pointerToNode T )
{
pointerToNode TmpCell;

if( T == NULL )
{
 printf( "Element not found" );
}
else if( X < T->Student.studentID )
{

  /* Go left */
   T->Left = Delete( X, T->Left );
}
else if( X > T->Student.studentID )
{

    /* Go right */
    T->Right = Delete( X, T->Right );
}
else /* Found element to be deleted */
if( T->Left && T->Right )
/* Two children */
{
/* Replace with smallest in right

subtree */

TmpCell = FindMin( T->Right );
T->Student.studentID = TmpCell->Student.studentID;
T->Right = Delete( T->Student.studentID, T->Right );
}
else /* One or zero children */
{
TmpCell = T;
if( T->Left == NULL )
/* Also handles 0 children */

T = T->Right;
else if( T->Right == NULL )
T = T->Left;
free( TmpCell );
}

return T;
} //end of Delete routine

pointerToNode  FindAndUpdate(int X,pointerToNode BST)
{
    int choice =0;
    int studentID=0;
     char studentName[30];
     char homeAddress[30];
    int classID=0;
     char dateOfEnrollment[30];
      BST=Delete(X,BST);
       printf("\nEnter ID student: ");
       scanf("%d",&studentID);
       printf("Enter student  name: ");
       scanf("%s",studentName);
       printf("\nEnter Home Address: ");
       scanf("%s",homeAddress);
       printf("\nEnter class Id: ");
       scanf("%d",&classID);
       printf("Enter date Of Enrollment student: ");
       scanf("%s",dateOfEnrollment);
       BST=Insert(studentID,studentName,homeAddress,classID,dateOfEnrollment,BST);
       return BST;

}
