// CST407_assignment4_RSA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>

using namespace std;

//to calculate the GDC of 'e' (encryption) and totient (Euler's totient formula)
unsigned long long gcd(unsigned long long e, unsigned long long totient)
{
	unsigned long long temp;
	while (1)
	{
		temp = e % totient;
		if (temp == 0)
			return totient;
		e = totient;
		totient = temp;
	}
}

int menu()
{
	int option = 0;
	cout << "***********************" << endl;
	cout << "****      RSA      ****" << endl;
	cout << "***********************" << endl;
	cout << "\n\n";

	cout << "Selections: [1/2/3]" << endl;
	cout << "  1. Encrypt" << endl
		<< "  2. Decrypt" << endl
		<< "  3. Exit" << endl
		<< "\n" 
		<< "Select: "; 

	cin >> option;

	return option;
}

unsigned long long createD(unsigned long long e, unsigned long long totient)
{
	//d ⋅ e ≡ 1 (mod φ(n))
	unsigned long long d;
	unsigned long long k = 1;
	
	//sets d value
	//d = (1 + (k*totient)) / e;

	while (1)
	{
		k = k + totient;
		if (k%e == 0)
		{
			d = (k / e);
			return d;
		}
	}

	//return d;
}

void RSA(int option) //option: 1 = encrypt; 2 = decrypt
{
	//////////////////////////////////////////
	//  Defined variables
	unsigned long long pt = 0;
	unsigned long long ct = 0;
	unsigned long long e = 2;
	unsigned long long d = 0;
	unsigned long long m = 0;
	//unsigned long long k = 2;
	unsigned long long p = 0;
	unsigned long long q = 0;
	unsigned long long counter;	//counter for gcd
	//////////////////////////////////////////


	//////p & q = 2 prime numbers  //text.txt has prime number list
	//p = 149;	
	//q = 277;
	//e = 221; //for use if not using user input 
	//d = 1109;
	//// using these numbers, 5 is encrypted to 

	cout << "Enter Prime1 and Prime2: " << endl;
	cin >> p >> q;
	cout << endl;
	
	//n = public key quotient
	unsigned long long n = p * q;
	
	//Euler's Totient --> T = (p-1)(q-1)	
	unsigned long long totient = (p - 1)*(q - 1);
	
	if (option == 1) //if encrypting
	{
		//Get user input for plaintext value
		cout << "Type in a plaintext value: ";
		cin >> pt;
		cout << endl;
	}

	else if (option == 2) //if decrypting
	{
		//Get user input for encrypted value
		cout << "Type in a ciphertext value: ";
		cin >> ct;
		cout << endl;

	}
	

	//checks for prime between e and totient which satisfies e>1
	while (e < totient) {
		counter = gcd(e, totient);
		if (counter == 1)
			break;
		else
			e++;
	}
	
	d = createD(e, totient);

	if (option == 1)
	{
		ct = 1;
		for (int i = 0; i < e; i++)
		{
			ct = (ct * pt) % n;
		}

		cout << "Plaintext = " << pt;
		cout << "\n" << "p = " << p;
		cout << "\n" << "q = " << q;
		cout << "\n" << "n = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "e = " << e;
		cout << "\n" << "Encrypted data = " << ct << endl;
	}
	else if (option == 2)
	{

		pt = 1;
		for (int i = 0; i < d; i++)
		{
			pt = (pt * ct) % n;
		}

		cout << "\n" << "Encrypted data = " << ct;
		cout << "\n" << "p = " << p;
		cout << "\n" << "q = " << q;
		cout << "\n" << "n = " << n;
		cout << "\n" << "totient = " << totient;
		cout << "\n" << "d = " << d;
		cout << "\n" << "Original Message sent = " << pt << endl;
	}

	cout << "\n\n";
	cin.clear();
}

int main()
{
	//////////////////////////////////////////
	//  Defined variables
	//menu option
	int option;
	//
	//////////////////////////////////////////
	cin.clear();
	do
	{

		option = menu();
		if (option == 1 || option == 2)
			RSA(option);
		else
			option = 3;
		cin.clear();
	} while (option != 3);

	cout << "\nExiting RSA program.\n";
	system("pause");

    return 0;
}

