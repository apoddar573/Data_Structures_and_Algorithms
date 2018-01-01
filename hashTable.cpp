#include<iostream>
#include<string>

using namespace std;

int hashFunc(string s) {
	int sum = 0;
	for(int i = 0; s[i] != '\0'; i++) {
		sum += s[i];
	}
	return sum%600;
}

void insert(string *hashTable, int *indicator, string s) {
	int index = hashFunc(s);
	if(indicator[index] == 0) {
		hashTable[index] = s;
		indicator[index] = 1;
	} else {
		while(1) {
			index = (index+1)%600;
			if(indicator[index] == 0) {
				hashTable[index] = s;
				indicator[index] = 1;
				break;
			}
		}
	}
}

int news(string s) {
	return hashFunc(s);
}

int search(string *hashTable, int *indicator, string s) {
	int index = hashFunc(s);
	if(indicator[index] == 1 && hashTable[index] == s)
		return index;
	else{
		while(1) {
			index = (index+1)%600;
			if(indicator[index] == 1 && hashTable[index] == s)
				return index;
		}
	}
}

int main() {
	string s1 = "hello";
	string s2 = "ehllo";
	string s3 = "hfllo";
	string hashTable[600];
	int indicator[600];
	for(int i = 0; i<600; i++) {
		indicator[i] = 0;
	}
	cout<<news(s1)<<endl;
	hashTable[2] = s1;
//	cout<<hashTable[2];	
	insert(hashTable, indicator, s1);
	insert(hashTable, indicator, s2);
	insert(hashTable, indicator, s3);

	cout<<search(hashTable, indicator, s1)<<endl;
	cout<<search(hashTable, indicator, s2)<<endl;
	cout<<search(hashTable, indicator, s3)<<endl;

}