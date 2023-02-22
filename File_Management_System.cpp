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
		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
       	cout << "        x  HERE THESE ARE THE FILES WHICH YOU HAVE CREATED TILL NOW   x\n" ;
       	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
       	
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
   		if(files.size() == 0 ){
   			cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
   			cout << "        x     YOUR FOLDER IS EMPTY      x" << endl;
   			cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
   			exit(0);
		}
		else{
			cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
			for(int i=0;i<files.size();i++){
				cout << "        "<<files[i]<<endl;
			}
			cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;	
		}
}


string enterFileType(){
	string fileType;
	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
   cout << "        w  ENTER THE FILE TYPE x\n" ;
   cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
   cout << "        HERE: ";
   getline(cin,fileType);
   return fileType;
}

void fileOfSpecificFolder(string fileType){
	vector<string>files;
	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
   	cout << "        x  HERE THESE ARE THE FILES WHICH YOU HAVE CREATED TILL NOW   x\n" ;
   	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
   	
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
   	
   	if(files.size() == 0 ){
		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
		cout << "        x     YOUR FOLDER IS EMPTY      x" << endl;
		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
		exit(0);
	}
	else{
		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
		for(int i=0;i<files.size();i++){
			cout << "        "<<files[i]<<endl;
		}
		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;	
	}
   	
}

string generateFilePath(string fileType,string fileName){
	return "./UserCreatedFiles/"+fileType+"Files/"+fileName+"."+fileType;
}

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
     cout << "          x [3] - SIZE OF FILE              x" << endl;
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
       
       string fileType;
       fileType = enterFileType();
       
       string filePath = "./UserCreatedFiles/"+fileType+"Files";
       mkdir(filePath.c_str());
       
       system("cls");
    	cout << "       wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
       cout << "        w  ENTER THE FILE NAME IN WHICH YOU WANT TO SAVE DATA   x\n" ;
       cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
       cout << "        HERE: ";
       getline(cin,fileName);

       system("cls");
       cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
       cout << "        w  ENTER THE CONTENT OF THE FILES  x\n" ;
       cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
       cout << "        HERE: ";
       getline(cin,textToSave);
		
//		string filePath = ("./UserCreated/" + fileName + ".txt");
		
		textToSave +=" ";//This is for creating a space between two lines
		ofstream saveFile((filePath +"/"+ fileName + "." + fileType).c_str(), ios_base::app);

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
          
			fileTillNow();
			string fileType;
       		fileType = enterFileType();
       		system("cls");
       		fileOfSpecificFolder(fileType);
          
          string fileName;
        	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
	       	cout << "        w  ENTER THE FILENAME OF WHICH YOU WANT TO SEE CONTENT   x\n" ;
	       	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
	       	cout << "        HERE: ";
          getline(cin,fileName);
          
          loadFile.open (("./UserCreatedFiles/" + fileType + "Files/" + fileName + "." + fileType ).c_str(), ifstream::in); 
          string str;
          while (loadFile.good()){
//               cout << (char) loadFile.get();
               str+=(char) loadFile.get();
          }
          
        if(str.length()==0){
          cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
          cout << "        x     NO SUCH FILE EXIST    x\n" ;
          cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
          cout << "        ";
          exit(0);
		}
		else{
			system("cls");;
		  cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
          cout << "        x     THE FILE CONTAINS THE STRING     x\n" ;
          cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
          cout << "        ";
          cout<<str<<endl;
          cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
		} 

    	  loadFile.close();

    	  system("pause");
 		system("cls");

		goto menu;
     }

      if (option == "3") {

     	system("cls");
     	system("color 0");
 		
		fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
   		
 		string fileName;
        	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
	       	cout << "        w  ENTER THE FILENAME OF WHICH YOU WANT TO SEE THE SIZE   x\n" ;
	       	cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
	       	cout << "        HERE: ";
        getline(cin,fileName);
 		
 		system("cls");
        streampos begin,end;
  		ifstream myfile (("./UserCreatedFiles/" + fileType + "Files/"+ fileName + "." + fileType).c_str(), ios::binary);
 		begin = myfile.tellg();
  		myfile.seekg (0, ios::end);
  		end = myfile.tellg();
 		myfile.close();
 		cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
        cout << "        x            THE FILE SIZE IS          x\n" ;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
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
        int argc;
		char** argv ;
   		struct stat fileInfo;
   		
   		fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
   		
   		string fileName;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
	    cout << "        w  ENTER THE FILENAME OF WHICH YOU WANT TO SEE DETAILS   x\n" ;
	    cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);

   		if (stat(generateFilePath(fileType,fileName).c_str(), &fileInfo) != 0) {
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
     	
     	fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);

		string fileName;
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwWWWWWWWWWWWw" << endl;
	    cout << "        w  ENTER THE FILENAME OF WHICH YOU WANT TO CLEAR  x\n" ;
	    cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwWWWWWWWWWWWww\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);
     	
 		std::ofstream ofs (generateFilePath(fileType,fileName).c_str(), std::ios::out | std::ios::trunc);
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
     	
     	fileTillNow();
		string fileType;
   		fileType = enterFileType();
   		system("cls");
   		fileOfSpecificFolder(fileType);
     	string fileName;
     	
        cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
	    cout << "        w  ENTER THE FILENAME YOU WANT TO REMOVE   x\n" ;
	    cout << "        wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww\n\n" << endl;
	    cout << "        HERE: ";
        getline(cin,fileName);
     	
    	std::remove(generateFilePath(fileType,fileName).c_str());
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
