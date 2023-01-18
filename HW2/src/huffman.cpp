//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname:Emir Sümer
//---Student Number:150200112
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

#include "huffman.h"
#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-----------------------------------------------------//
//-----------Reads the key from text file--------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::readKey(const char* argv){
    ifstream readKeyFile;
    readKeyFile.open(argv);

    if(readKeyFile.is_open()){
        while(!readKeyFile.eof()){
            readKeyFile >> key;
        }
    }
    readKeyFile.close();
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------Sorts the key in an alpabetic order---------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::sortKey(){
    sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//-------Finds the frequency of the characters---------//
//-----------------------------------------------------//
void Huffman::findFrequency(){
    //DO NOT CHANGE THIS
    sortKey();
    //DO NOT CHANGE THIS
    
    //TODO
    int count = 0; 
    if(sortedKey.length() != 0){
        int j = 0;
        //Finds frequencies of characters
        //Creates Node according frequency and character
        //Initializes queue with first form
        while(j<(int)sortedKey.length()-1){
            Node* temp = new Node();
            for(int i = j;i<(int)sortedKey.length();i++){
                if(sortedKey[i] != sortedKey[i+1] || i == (int)sortedKey.length()-1){           //Checks whether keys repeats itself or not
                    count++;                                                                    //Repetition number
                    temp->token.symbol = sortedKey[i];                                          //sets symbol
                    temp->token.val = count;                                                    //sets number of repetition
                    temp->next = NULL;
                    temp->left = NULL;
                    temp->right = NULL;
                    queue.enque(temp);                                                          //add queue setted node
                    j = i+1;
                    count = 0;
                    break;
                }
                count++;                                                                        //Increases repetition number
            }
        }  
    }
 
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//----------------Creates Huffman Tree-----------------//
//-----------------------------------------------------//
void Huffman::createHuffmanTree(){
    //TODO
    //Initialize Queue
    findFrequency();
    //Creates Huffman Tree
    //Takes first node and second node and merge them until one node left
    while(true){
        Node* leftChild = queue.dequeue();                                                      //First node                          
        Node* rightChild = queue.dequeue();                                                     //Second node
        if(rightChild == NULL){                                     
            break;
        }
        Node* parent = huffmanTree.mergeNodes(leftChild,rightChild);                            //merge first and second node
        huffmanTree.root = parent;                                                              //merged node
        queue.enque(parent);                                                                    //inserts merged node to queue
    }
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Prints the Huffman Tree---------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printHuffmanTree(){
    huffmanTree.printTree(huffmanTree.root, 0);
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Finds and returns the binary------------//
//----------------value to given character-------------//
//-----------------------------------------------------//
string Huffman::getTokenBinary(char tokenChar, Node* traverse, string tokenBinary){
    //TODO
    //Recursively Checks whether searched character in left or right if found traverses through there
    //Based on left or right creates tokenBinary
    while(traverse != NULL){
        if(traverse->token.symbol.length() == 1)                                                    //base condition for recursion
            break;
        if(traverse->left != NULL && traverse->left->token.symbol.find(tokenChar) != string::npos){ //checks token in left or not
            tokenBinary = tokenBinary + "0";
            tokenBinary = getTokenBinary(tokenChar,traverse->left,tokenBinary);                     //Recursive call for search in left subtree
            break;
        }
        if(traverse->right != NULL &&traverse->right->token.symbol.find(tokenChar) != string::npos){ //checks token in right or not
            tokenBinary = tokenBinary + "1";
            tokenBinary = getTokenBinary(tokenChar,traverse->right,tokenBinary);                    //Recursive call for search in right subtree
            break;
        }
    }
    return tokenBinary;
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//--------------Encodes the given password-------------//
//-----------------------------------------------------//
void Huffman::encodePassword(string password){
    //TODO
    encodedBinaryPassword = "";
    encodedValPassword = "";
    for(char temp:password){
        string stringToken = getTokenBinary(temp,huffmanTree.root,"");
        encodedValPassword += stringToken.length() + 48;                                            
        encodedBinaryPassword += stringToken;
    }
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the encoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printEncodedPassword(){
    cout << "Encoded Password Binary: " << encodedBinaryPassword << endl;
    cout << "Encoded Password Value: " << encodedValPassword << endl;
};

//-----------------------------------------------------//
//--------------Decodes the given password-------------//
//-----------------------------------------------------//
void Huffman::decodePassword(string encodedBinaryPassword, string encodedValPassword){
    //TODO
    int temp = 0;
    int start = 0;
    int j = 0;
    string tempToken = "";
    //Parses password according to binary and value password 
    for(int i = 0;i<(int)encodedValPassword.length();i++){
        temp = encodedValPassword[i]-48;
        tempToken = "";
        for(j = 0;j<temp;j++){
            tempToken += encodedBinaryPassword[j+start];
        }
        start += j;
    //Decodes token for parsed forms
        decodeToken(tempToken);
    }
};

//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Decodes the given binary--------------//
//-----------------------------------------------------//
void Huffman::decodeToken(string encodedToken){
    //TODO
    //Traverses through tree with given encoded token
    Node* temp = huffmanTree.root;
    for(char c:encodedToken){
        if(c == '0'){
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    decodedPassword += temp->token.symbol;
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the decoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printDecodedPassword(){
    cout << "Decoded Password: " << decodedPassword << endl;
};