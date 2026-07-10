#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

void toggleCase(char ch[]){
    int i = 0;
    while(ch[i]!='\0'){
        if(isalpha(ch[i])){
            if(isupper(ch[i])){
                ch[i] = tolower(ch[i]);
            }
            else{
                ch[i] = tolower(ch[i]);
            }
            
        }else{
            string m = "Invaild Input";
            cout << m << endl;
        }
        i++;
    }
}

    /* void toggleCase(char ch[]){
    int i = 0;
    while(ch[i]!='\0'){
        if(isalpha(ch[i])){
            if(ch[i]>=65 && ch[i]<90){
            ch[i]=ch[i]+32;
        }else {
            ch[i]=ch[i]-32;
        }
        i++;
        }
        
    }
} */

int main() {





int main() {

    char ch[100];
    cin>>ch;

    toggleCase(ch);
    cout<<ch<<endl;

    /*char ch[5]= {'h','e','l','l','o'};
    //cout << ch << endl;
    //char ch1[5] = "hello"; // we can't do this as the null char can't get the slot allocated
    char ch2[6] = "hello"; // this is correct
    //cout << ch1 << endl;
    cout << ch2 << endl;
    return 0;  */

    //string - set of characters ,  you can change the characters
    //string literal - a set of characters , it is not editable

    string a = "hello";
    auto i = "abc";

    reverse(a.begin(),a.end());  //for reversing a string
    cout << a;

    return 0;
}

//strcpy(source,destination) -> This is an inbuilt function in strings which copy content from source string to dsnt string;





  
