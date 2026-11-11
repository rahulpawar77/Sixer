#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

void appendBit(Node*& head, Node*& tail, int bit){
	Node* newNode = new Node();
	newNode->data = bit;
	newNode->next = NULL;
	newNode->prev = tail;
	if (head == NULL){
		head = newNode;
	}
	else{
		tail->next = newNode;
	}
	tail = newNode;
}

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}
Node* getOnesComplement(Node* head){
	Node* compHead = NULL;
	Node* compTail = NULL;
	Node* temp = head;
	while(temp != NULL){
		int flippedBit = (temp->data == 0) ? 1 : 0;
		appendBit(compHead, compTail, flippedBit);
		temp = temp->next;
	}
	return compHead;
}

Node* getTwosComplement(Node* head){
	Node* onesCompHead = getOnesComplement(head);
	Node* temp = onesCompHead;
	while(temp->next != NULL){
		temp = temp->next;
	}
	int carry =1;
	while(temp != NULL){
		int sum = temp->data + carry;
		temp->data = sum % 2;
		carry = sum / 2;
		temp = temp->prev;
	}
	if (carry = 1){
		Node* newHead = new Node();
		newHead->data = 1;
		newHead->prev = NULL;
		newHead->next = onesCompHead;
		onesCompHead->prev = newHead;
		onesCompHead = newHead;
	}
	return onesCompHead;
}

Node* addBinary(Node* head1, Node* head2){
	Node* sumHead = NULL;
	Node* sumTail =NULL;
	Node* t1 = head1;
	Node* t2 = head2;
	
	while(t1 && t1->next) t1 = t1->next;
	while(t2 && t2->next) t2 = t2->next;
	int carry = 0;
	while(t1 != NULL || t2 != NULL || carry != 0){
		int b1 = (t1 != NULL) ? t1->data : 0;
		int b2 = (t2 != NULL) ? t2->data : 0;
		int sum = b1 + b2 + carry;
		int bitResult = sum % 2;
		carry = sum / 2;
		
		Node* newNode = new Node();
		newNode->data = bitResult;
		newNode->prev = NULL;
		newNode->next = sumHead;
		if (sumHead != NULL){
			sumHead->prev = newNode;
		}
		sumHead = newNode;
		if (t1) t1 = t1->prev;
	    if (t2) t2 = t2->prev;
	}
	return sumHead;
}

int main(){
	cout << "======== STUDENT NAME : PRATIK WALTURE ========\n";
	cout << "============  ROLL NO : 263  =============\n";
	Node* num1Head = NULL; Node* num1Tail = NULL;
	Node* num2Head = NULL; Node* num2Tail = NULL;
	
	string s1, s2;
	cout << "Enter First Binary Number : ";
	cin >> s1;
	for(char c : s1) appendBit(num1Head, num1Tail, c - '0');
	cout << "Enter Second Binary Number : ";
	cin >> s2;
	for(char c : s2) appendBit(num2Head, num2Tail, c - '0');
	
	cout << "\n1'S complement of 1st Number : ";
	Node* twos = getTwosComplement(num1Head);
	display(twos);
	
	cout << "\nAddition of Both Binary Numbers : ";
	Node* ones = getOnesComplement(num1Head);
	display(ones);
	
	cout << "\n2'S complement of 1st Number : ";
	Node* sum = addBinary(num1Head, num2Head);
	display(sum);
	return 0;
}
