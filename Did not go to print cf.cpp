//(Recently, K1o0n bought himself a new expensive printer, which is distinguished by its memory, that is, it may not print immediately. Yesterday, while he was away from his new purchase, his friends used the printer.

There are 𝑛
 documents numbered from 1
 to 𝑛
. Initially, the printer memory is empty. The friends sequentially performed 𝑛
 commands on the printer, where the 𝑖
-th command can be one of:

'1'  — scanning. Document 𝑖
 is sent to the device memory and is placed on top of everything already there.
'2'  — printing from memory. If the memory is not empty, the device prints the topmost document in memory and removes it from there. Otherwise, the device prints document 𝑖
.
'3'  — quick print. The device prints document 𝑖
.
Today, the friends came to K1o0n with a complaint — not all documents were printed. Help K1o0n find the indices of all documents that were not printed.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

The first line of each testcase contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of documents.

The second line of each testcase contains a string 𝑠
 of length 𝑛
, consisting of the characters '1', '2' and '3' — the friends' commands.

It is guaranteed that the sum of 𝑛
 over all testcases does not exceed 2⋅105
.

Output
For each testcase, output two lines.

In the first line — the number 𝑘
 of documents that were not printed.

In the second line — their numbers in increasing order, separated by spaces. If 𝑘=0
, the second line is empty.

Example
InputCopy
6
2
12
2
13
2
23
6
112332
3
112
6
211213
OutputCopy
1
2 
1
1 
0

2
3 6 
2
1 3 
3
2 4 5 
Note
In the first testcase, the first document number 1
 is stored in memory, and then it is printed at the next step, so document number 2
 is not printed.

In the second testcase, document number 1
 is put into memory, but is never printed, because the next command prints document number 2
.

In the fifth testcase, the first document number 1
 is put into memory, then document number 2
 is put into memory, and by the third command we print the last document put into memory — document number 2
.)






#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int o = 0;
    vector<int>ones;

    for(int i=0; i<n; i++){
    if(s[i]=='1'){
        ones.push_back(i);
    }
    else if(s[i]=='2'){
        if(!ones.empty()){
            int pos = ones.back();
            s[pos] = '0';
            ones.pop_back();
        }
        else{
            s[i] = '0';
        }
    }
    else if(s[i]=='3'){
        s[i] = '0';
    }
      
    }
  
    int zeroCount = count(s.begin(), s.end(), '0');
    o = s.size()-zeroCount;

    cout<<o<<'\n';
    for(int i=0; i<n; i++){
        if(s[i]!='0'){
            cout<<i+1<<" ";
        }
    }
    cout<<'\n';
}}
