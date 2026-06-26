Problem 1 :

![alt text](image.png)

example : 

Input : A = [{1,2,3},{4,5,6},{7,8,9}]
        B = 2

Output : [{2,4,6},{8,10,12},{14,16,18}]

Solution :
```cpp
vector<vector<int>> Solution:: solve(vector<vector<int>> &A , int B) {
    //number of rows and columns
    int rows = A.size();
    int cols = A[0].size();

    for(int i = 0; i<rows ; i++) {
        for(int j = 0; j<cols ; j++) {
            A[i][j]=A[i][j]*B ;
        } 
    }

    return A;
}
```

Problem 2 :

![alt text](image-1.png)

Solution :

```cpp

int rows = A.size();
int cols = A[0].size();

vector <vector <int>> ans;

for(int i = 0; i<rows; i++) {
    vector <vector<int>> temp;
    for(int j = 0; j<cols ; j++){
        temp.push_back(A[i][j]+B[i][j]);
    }
    ans.push_back(temp);
}

return ans;
```

Problem 3 :

Transpose of a Matrix using Vectors:
![alt text](image-2.png)

solution:

```cpp

vector<vector<int>> v;
int rows = A.size();
int cols = A[0].size();

for(int i = 0; i<cols ; i++){
    vector<int> temp;
    for(int j = 0 ; j < rows ; j++) {
        temp.push_back(A[j][i]);
    }
    v.push_back(temp);
}

return v;