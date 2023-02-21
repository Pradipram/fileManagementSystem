#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
using namespace std;


int main () {


	system("color 0");
	cout<<"\n\n";
	cout<<"  [][][] [][][] []     [][][]\n";
	cout<<"  []       []   []     []\n";
	cout<<"  [][]     []   []     [][]\n";
	cout<<"  []       []   []     [] \n";
	cout<<"  []     [][][] [][][] [][][]\n\n";
	cout<<"  []    []   []   []]  []   []   [][][][] [][][][] []    [] [][][][] []]   [] [[][][][]]\n";
	cout<<"  []}[]{[] []  [] [][] [] []  [] []       []       []}[]{[] []       [] [] []     []\n";
	cout<<"  [] [] [] [][][] [] [][] [][][] [] [][]] [][][][] [] [] [] [][][][] []  [][]     []\n";
	cout<<"  []    [] []  [] []  []] []  [] []    [] []       []    [] []       []   []]     []\n";
	cout<<"  []    [] []  [] []   [] []  [] [][][][] [][][][] []    [] [][][][] []    []     []\n\n";
	cout<<"  [][][][] []    [] [][][][] [[][][][]] [][][][] []}[]{[]\n";
	cout<<"  []         [] []  []           []     []       [] [] []\n";
	cout<<"  [][][][]    []    [][][][]     []     [][][][] []    []\n";
	cout<<"        []    []          []     []     []       []    []\n";
	cout<<"  [][][][]    []    [][][][]     []     [][][][] []    []\n\n";

	system("pause");
	system("cls");



     string option;
     system("color 1");
	 menu:
	 cout << endl;
	 cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
     cout << "          x     FILE  MANAGEMENT SYSTEM     x" << endl;
     cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
     cout << "          x [1] - Save to a file            x" << endl;
     cout << "          x [2] - View file content         x" << endl;
     cout << "          x [3] - Obtain file size          x" << endl;
     cout << "          x [4] - File Details              x" << endl;
     cout << "          x [5] - Clear the file            x" << endl;
     cout << "          x [6] - Delete the file           x" << endl;
     cout << "          x [7] - Exit Program              x" << endl;
     cout << "          wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
     cout << "\n          Enter Your Choice:	";
     getline(cin,option);


     if (option == "1") {

       system("cls");
       system("color 0");
       string textToSave;
       string fileName;
       cout<<"Enter the fileName in which you want to store data : ";
       getline(cin,fileName);
       
       cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
       cout << "        w  ENTER THE STRING YOU WANT TO SAVE   x\n" ;
       cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
       cout << "        HERE: ";
       getline(cin,textToSave);
//       ofstream saveFile ("file.txt");
		textToSave +="\n";//This is for creating a space between two lines
		ofstream saveFile(("./" + fileName + ".txt").c_str(), ios_base::app);

       saveFile << textToSave;
       cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
       saveFile.close();

       system("pause");
 		system("cls");

		goto menu;
     }

     if(option == "2") {
     	  system("color 0");
     	  system("cls");
          ifstream loadFile;
          loadFile.open ("file.txt", ifstream::in);
          cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
          cout << "        x     THE FILE CONTAINS THE STRING     x\n" ;
          cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
          cout << "        ";
          while (loadFile.good()){
               cout << (char) loadFile.get();
          }
          cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
    	  loadFile.close();

    	  system("pause");
 		system("cls");

		goto menu;
     }

      if (option == "3") {

     	system("cls");
     	system("color f");
        streampos begin,end;
  		ifstream myfile ("file.txt", ios::binary);
 		begin = myfile.tellg();
  		myfile.seekg (0, ios::end);
  		end = myfile.tellg();
 		myfile.close();
 		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
        cout << "        x            THE FILE SIZE IS          x\n" ;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
        cout << "\n\n\n\t\t\t";
  		cout << (end-begin) << " bytes.\n";
		cout << "" << endl<< endl<< endl<< endl<< endl;

  		system("pause");
 		system("cls");

		goto menu;
     }

      if (option == "4") {

     	system("cls");
        int argc;
		char** argv ;
   		struct stat fileInfo;

   		if (stat("file.txt", &fileInfo) != 0) {
   		  system("color 04");
   		  cout << "\n\n\n\n\n\n\n";
	   	  cout << "        wwwwwwwwwwwwwwwwww" << endl;
          cout << "        x      ERROR     x\n" ;
          cout << "        wwwwwwwwwwwwwwwwww\n\n" << endl;
          cout << "        ";
	      std::cerr << strerror(errno) << '\n';
	      cout << "\n\n\n\n\n\n\n";
	      return 0;
   		}

		system("color 0");
		cout << "     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
   		cout << "     x  Size               : " << fileInfo.st_size <<"  bytes"<<'\n';
   		cout << "     x  Drive letter saved : " << (char)(fileInfo.st_dev + 'A') << '\n';
   		cout << "     x  Created            : " << std::ctime(&fileInfo.st_ctime);
   		cout << "     x  Modified           : " << std::ctime(&fileInfo.st_mtime);
   		cout << "     wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
  		cout << "\n\n\n";
  		system("pause");
 		system("cls");

		goto menu;
     }

     if (option == "5") {
     	system("color 0");
     	system("cls");
 		std::ofstream ofs ("file.txt", std::ios::out | std::ios::trunc);
		cout << "\n\n\n\n";
 		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
        cout << "        x      FILE SUCCESSFULLY CLEARED       x\n" ;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;

 		system("pause");
 		system("cls");

		goto menu;
     }

     if (option == "6") {
     	system("color 0");
     	system("cls");
    	std::remove("file.txt");
    	cout << "\n\n\n\n";
 		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
        cout << "        x      FILE SUCCESSFULLY REMOVED       x\n" ;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;

 		system("pause");
 		system("cls");

		goto menu;
     }

     if (option == "7") {
     	system("color 0");
     	system("cls");
 			cout<<"\n\n";
			cout<<"[][][] [][][] [][][] [][][] [][][]    []    []    []\n";
			cout<<"[]  [] []  [] []  [] []     []  []  []  []  [][][][]\n";
			cout<<"[][][] [][][] []  [] [] []  [][][] [][][][] [] [] []\n";
			cout<<"[]     [] []  []  [] []  [] [] []  []    [] []    []\n";
			cout<<"[]     []  [] [][][] [][][] []  [] []    [] []    []\n\n";
			cout<<"[][][] [][][]     [][][] []     [][][] [][][] [][][] []   [] [][][]\n";
			cout<<"  []   []         []  [] []     []  [] []       []   []]  [] []\n";
			cout<<"  []   [][][]     []     []     []  [] [][][]   []   [][] [] [] []\n";
			cout<<"  []       []     []  [] []     []  []     []   []   [] [][] []  []\n";
			cout<<"[][][] [][][]     [][][] [][][] [][][] [][][] [][][] []  [[] [][][]\n\n";
			cout<<"[][][]  []     [] [][][]   [] [] []\n";
			cout<<"[]   []  []  []   []       [] [] []\n";
			cout<<"[]  []     []     [][][]   [] [] []\n";
			cout<<"[]   []    []     []\n";
			cout<<"[][][]     []     [][][]   [] [] []\n\n";

 		system("pause");
 		return 0;
     }

     else;
     system("cls");
			cout<<"\n\n\n\n\n\n";
			cout<<"\t\t\t[][][] [][][] [][][] [][][] [][][]\n";
			cout<<"\t\t\t[]     []  [] []  [] []  [] []  []\n";
			cout<<"\t\t\t[][][] [][][] [][][] []  [] [][][]\n";
			cout<<"\t\t\t[]     [] []  [] []  []  [] [] []\n";
			cout<<"\t\t\t[][][] []  [] []  [] [][][] []  []\n\n";

			cout<<"\t\t\tPlease input a valid number.\n";
			cout<<"\t\t\tPress any key to go back to the Menu.\n\n\n\n\n\n\n";

			system("pause");
			system("cls");
			goto menu;


     system("pause");
	 return 0;
}
