#include <iostream>
#include <fstream>
#include <string> 


using namespace std;

string printUnion(int arr1[], int arr2[], int m, int n)
{
    string result;
    int i = 0, j = 0;
    result=result+"Union: ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            result=result+to_string(arr1[i++])+" ";
 
        else if (arr2[j] < arr1[i])
            result=result+to_string(arr2[j++])+" ";
 
        else {
            result=result+to_string(arr2[j++])+" ";
            i++;
        }
    }
    /* Print remaining elements of the larger array */
    while (i < m)
        result=result+to_string(arr1[i++])+" ";
 
    while (j < n)
        result=result+to_string(arr2[j++])+" ";
    return result;
}

string printIntersection(int arr1[], int arr2[], int m, int n)
{
    string result;
    int i = 0, j = 0;
    result=result+"Intersection: ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            result=result+to_string(arr2[j])+" ";
            i++;
            j++;
        }
    }
    return result;
}

  

 
    


int main(void) {
    // Create a text string, which is used to output the text file
    string myText;
    int linenum = 0;
    // Read from the text file
    ifstream MyReadFile("sets.txt");
    
    //while (getline (MyReadFile, myText)) {
    //    linenum++;
    //}
    int arrlist[2][5];
    int row=0;
    cout << "Linenum is " << linenum << endl;
    while (getline (MyReadFile, myText)) {
        cout << myText << endl;
        // get length of string str
        int str_length = myText.length();
        // create an array with size as string
        // length and initialize with 0
        int arr[str_length] = { 0 };
        int j = 0, i, sum = 0;
        // Traverse the string
        for (i = 0; myText[i] != '\0'; i++) {
            // if str[i] is ', ' then split
            if (myText[i] == ',' || myText[i] == '{' || myText[i] == '}') //กรองเอาอักษรที่ไม่เกี่ยวออก
                continue;
            if (myText[i] == ' '){
                // Increment j to point to next
                // array location
                j++;
            }
            else {
                arr[j] = arr[j] * 10 + (myText[i] - 48); 
            }
            
        }
        for (j=0; j<=4;j++){
            arrlist[row][j] = arr[j];
            //cout << arr[j] << endl;
        }
        row++;
    }
    for (int j=0; j<=4;j++){ 
            cout << arrlist[0][j] << " "; //พิมพ์สมาชิกใน arrlist ลำดับที่ 0 ออกมา 
    }
    cout << endl;
    for (int j=0; j<=4;j++){
            cout << arrlist[1][j] << " ";   //พิมพ์สมาชิกใน arrlist ลำดับที่ 1 ออกมา 
    }  
    cout << endl;
   
 
    int m = sizeof(arrlist[0]) / sizeof(arrlist[0][0]);
    int n = sizeof(arrlist[1]) / sizeof(arrlist[1][0]);
    string unionresult, intersectresult, diffresult;
    unionresult = printUnion(arrlist[0], arrlist[1], m, n);
    cout << endl;
    intersectresult = printIntersection(arrlist[0], arrlist[1], m, n);

    
    diffresult=diffresult+"difference: ";
    unsigned int l = 0, OK2=0;
    int d[100], i,j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arrlist[0][i] == arrlist[1][j])
                OK2 = 1;      
        }
        if (OK2==0){
            d[l] = arrlist[0][i];
            l++;
        }
        OK2=0;
    }
    cout << unionresult <<endl;
    cout << intersectresult << endl;
    
    for (i = 0; i < l; i++)
        diffresult=diffresult+to_string(d[i])+" ";

    cout << '\n';
    cout << diffresult;
    

    //ofstream outfile;
    //outfile.open("sets.txt", ios::app);
    std::ofstream outfile("C:\\Users\\DELL\\Desktop\\project2\\sets2.txt",ios_base::app | ios_base::out);
    if(!outfile){
        std::cout << endl << "Something failed while opening the file\n";
    }
    else if (outfile.is_open()){
        outfile << "{ ";
        for (int i =0; i<5;i++){
            outfile << arrlist[0][i];
            outfile << ",";
        }
        outfile << "}" << endl;
        outfile << "{ ";
        for (int i =0; i<5;i++){
            outfile << arrlist[1][i];
            outfile << ",";
        }
        outfile << "}" << endl;
        
        outfile << unionresult << endl;
        outfile << intersectresult << endl;
        outfile << diffresult << endl;
        cout << "Entering the line" << endl;
        outfile.close();
    }
    //filePutContents("sets.txt",);
    //filePutContents("C:\\Users\\DELL\\Desktop\\project2\\sets.txt",intersectresult,true);



}