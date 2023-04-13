#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <vector>
#include <dirent.h>
#include <conio.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

//Function to show all files created in Userfiles folder
void fileTillNow(){
	vector<string> files;
		cout << "        ===============================================================" << endl;
       	cout << "        x  HERE THESE ARE THE FILES WHICH YOU HAVE CREATED TILL NOW   x\n" ;
       	cout << "        ===============================================================\n\n" << endl;
       	
		DIR *dr;
   		struct dirent *en;
   		dr = opendir("./UserCreatedFiles"); //open all directory
   		if (dr) {
      		while ((en = readdir(dr)) != NULL) {
//      			cout << "        "<<en->d_name<<endl;
				files.push_back(en->d_name);
//         		cout<<" \n"<<en->d_name; //print all directory name
      		}
      	closedir(dr); //close all directory
   		}
   		if(files.size() == 2 ){
   			cout << "        =================================" << endl;
   			cout << "             YOUR FOLDER IS EMPTY      " << endl;
   			cout << "        =================================\n\n" << endl;
   			exit(0);
		}
		else{
			cout << "        =================================" << endl;
			for(int i=2;i<files.size();i++){
				cout << "        "<<files[i]<<endl;
			}
			cout << "        =================================" << endl;	
		}
}


string enterFileType(){
	string fileType;
	cout << "        =========================" << endl;
   cout << "          ENTER THE FILE TYPE \n" ;
   cout << "         =========================\n\n" << endl;
   cout << "        HERE: ";
   getline(cin,fileType);
   return fileType;
}

void fileOfSpecificFolder(string fileType){
	vector<string>files;
	cout << "        =======================================================================" << endl;
   	cout << "         HERE THESE ARE THE FILES WHICH YOU HAVE CREATED IN FOLDER "<<fileType<<"\n" ;
   	cout << "        =======================================================================\n\n" << endl;
   	
	DIR *dr;
	struct dirent *en;
	dr = opendir(("./UserCreatedFiles/" + fileType + "Files").c_str()); //open all directory
	if (dr) {
  		while ((en = readdir(dr)) != NULL) {
  			files.push_back(en->d_name);
//  			cout << "        "<<en->d_name<<endl;
//         		cout<<" \n"<<en->d_name; //print all directory name
  		}
  	closedir(dr); //close all directory
	}
   	
   	if(files.size() == 2 ){
		cout << "        =================================" << endl;
		cout << "        x     YOUR FOLDER IS EMPTY      x" << endl;
		cout << "        =================================\n\n" << endl;
		exit(0);
	}
	else{
		cout << "        =================================" << endl;
		for(int i=2;i<files.size();i++){
			cout << "        "<<files[i]<<endl;
		}
		cout << "        =================================" << endl;	
	}
   	
}

string generateFilePath(string fileType,string fileName){
	return "./UserCreatedFiles/"+fileType+"Files/"+fileName+"."+fileType;
}

int main () {

	cout<<"\n\n";
	system("color 1");
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
     
	 menu:
	system("color 0");
	 cout << endl;
	 cout << "          =================================" << endl;
     cout << "          x     FILE  MANAGEMENT SYSTEM     x" << endl;
     cout << "          =================================" << endl;
     cout << "          x [1] - Save to a file            x" << endl;
     cout << "          x [2] - View file content         x" << endl;
     cout << "          x [3] - SIZE OF FILE              x" << endl;
     cout << "          x [4] - File Details              x" << endl;
     cout << "          x [5] - Clear the file            x" << endl;
     cout << "          x [6] - Delete the file           x" << endl;
     cout << "          x [7] - Exit Program              x" << endl;
     cout << "          =================================" << endl;
     cout << "\n          Enter Your Choice:	";
     getline(cin,option);


     if (option == "1") {

       system("cls");
       system("color 2");
       
       string textToSave;
       string fileName;
       
       string fileType;
       fileType = enterFileType();
       
       mkdir("./UserCreatedFiles");
       string filePath = "./UserCreatedFiles/"+fileType+"Files";
       mkdir(filePath.c_str());
       
       system("cls");
       cout << "        ======================================================" << endl;
       cout << "          ENTER THE FILE NAME IN WHICH YOU WANT TO SAVE DATA   x\n" ;
       cout << "        ======================================================\n\n" << endl;
       cout << "        HERE: ";
       getline(cin,fileName);

       system("cls");
       cout << "        ==================================" << endl;
       cout << "          ENTER THE CONTENT OF THE FILES  \n" ;
       cout << "        ==================================\n\n" << endl;
       cout << "        HERE: ";
       getline(cin,textToSave);
		
//		string filePath = ("./UserCreated/" + fileName + ".txt");
		
		textToSave +=" ";//This is for creating a space between two lines
		ofstream saveFile((filePath +"/"+ fileName + "." + fileType).c_str(), ios_base::app);

       saveFile << textToSave;
       cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
       saveFile.close();
	
       cout << "         FILE SAVED SUCCESSFULLY....  \n" ;
       cout << "        ==================================\n\n" << endl;
	
       system("pause");
 		system("cls");

		goto menu;
     }

     if(option == "2") {
     	
     	  system("cls");
     	  system("color 3");
          ifstream loadFile;
          
			fileTillNow();
			string fileType;
       		fileType = enterFileType();
       		system("cls");
       		fileOfSpecificFolder(fileType);
          
          string fileName;
        	cout << "        ==========================================================" << endl;
	       	cout << "          ENTER THE FILENAME OF WHICH YOU WANT TO SEE CONTENT   \n" ;
	       	cout << "        ==========================================================\n\n" << endl;
	       	cout << "        HERE: ";
          getline(cin,fileName);
          
          loadFile.open (("./UserCreatedFiles/" + fileType + "Files/" + fileName + "." + fileType ).c_str(), ifstream::in); 
          string str;
          while (loadFile.good()){
//               cout << (char) loadFile.get();
               str+=(char)loadFile.get();
          }
          
        if(str.length()==0){
          cout << "        =================================" << endl;
          cout << "        x             FILE IS EMPTY            x\n" ;
          cout << "        =================================\n\n" << endl;
          cout << "        ";
          exit(0);
		}
		else{
			system("cls");;
		  cout << "        =================================" << endl;
          cout << "        x              FILE CONTENT            x\n" ;
          cout << "        =================================\n\n" << endl;
          cout << "        ";
          cout<<str<<endl;
          cout << " " << endl<< endl<< endl<< endl<< endl<< endl;
		} 

    	  loadFile.close();

    	  system("pause");
 		system("cls");

		goto menu;
     }

      if (option == "3") {

     	system("cls");
 		system("color 4");
		fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
   		
 		string fileName;
        	cout << "        ============================================================" << endl;
	       	cout << "          ENTER THE FILENAME OF WHICH YOU WANT TO SEE THE SIZE   \n" ;
	       	cout << "        ============================================================\n\n" << endl;
	       	cout << "        HERE: ";
        getline(cin,fileName);
 		
 		system("cls");
        streampos begin,end;
  		ifstream myfile (("./UserCreatedFiles/" + fileType + "Files/"+ fileName + "." + fileType).c_str(), ios::binary);
 		begin = myfile.tellg();
  		myfile.seekg (0, ios::end);
  		end = myfile.tellg();
 		myfile.close();
 		cout << "        =================================" << endl;
        cout << "                   THE FILE SIZE IS          \n" ;
        cout << "        =================================\n\n" << endl;
        cout << "\n\n\n\t\t\t";
        if(end-begin == 0){
        	cout<<"YOUR FILE IS EMPTY "<<endl;
		}
		else{
			cout << (end-begin) << " bytes.\n";	
		}
		cout << "" << endl<< endl<< endl<< endl<< endl;

  		system("pause");
 		system("cls");

		goto menu;
     }

      if (option == "4") {

     	system("cls");
     	system("color 5");
        int argc;
		char** argv ;
   		struct stat fileInfo;
   		
   		fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
   		
   		string fileName;
        cout << "        ========================================================" << endl;
	    cout << "          ENTER THE FILENAME OF WHICH YOU WANT TO SEE DETAILS   \n" ;
	    cout << "        ========================================================\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);

   		if (stat(generateFilePath(fileType,fileName).c_str(), &fileInfo) != 0) {
   		  system("color 04");
   		  cout << "\n\n\n\n\n\n\n";
	   	  cout << "       =" << endl;
          cout << "        x      ERROR     x\n" ;
          cout << "       =\n\n" << endl;
          cout << "        ";
	      std::cerr << strerror(errno) << '\n';
	      cout << "\n\n\n\n\n\n\n";
	      return 0;
   		}

		system("color 0");
		cout << "     =================================" << endl;
   		cout << "     x  Size               : " << fileInfo.st_size <<"  bytes"<<'\n';
   		cout << "     x  Drive letter saved : " << (char)(fileInfo.st_dev + 'A') << '\n';
   		cout << "     x  Created            : " << std::ctime(&fileInfo.st_ctime);
   		cout << "     x  Modified           : " << std::ctime(&fileInfo.st_mtime);
   		cout << "     =================================" << endl;
  		cout << "\n\n\n";
  		system("pause");
 		system("cls");

		goto menu;
     }

     if (option == "5") {
     	system("color 0");
     	system("cls");
     	
     	fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);

		string fileName;
        cout << "        =================================================" << endl;
	    cout << "          ENTER THE FILENAME OF WHICH YOU WANT TO CLEAR  \n" ;
	    cout << "        =================================================\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);
     	
 		std::ofstream ofs (generateFilePath(fileType,fileName).c_str(), std::ios::out | std::ios::trunc);
		cout << "\n\n\n\n";
 		cout << "        =================================" << endl;
        cout << "              FILE SUCCESSFULLY CLEARED       \n" ;
        cout << "        =================================\n\n" << endl;

 		system("pause");
 		system("cls");

		goto menu;
     }

     if (option == "6") {
     	system("color 0");
     	system("cls");
     	
     	fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
     	string fileName;
     	
        cout << "        =============================================" << endl;
	    cout << "          ENTER THE FILENAME YOU WANT TO REMOVE   \n" ;
	    cout << "        =============================================\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);
     	
    	std::remove(generateFilePath(fileType,fileName).c_str());
    	cout << "\n\n\n\n";
 		cout << "        =================================" << endl;
        cout << "              FILE SUCCESSFULLY REMOVED       \n" ;
        cout << "        =================================\n\n" << endl;

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
