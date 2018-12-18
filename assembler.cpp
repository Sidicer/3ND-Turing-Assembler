/*
	program: TesiamLaborus.cpp
	author: Deividas Gedgaudas 2018 ITF-18/2
	date: 2018 - 12 - 18
	name: 3ND - Assembler
*/

#include <iostream>
using namespace std;

int main() {

	// susikuriam keturis kintamuosius kuriuos naudosime programoje
	int a(0), b(0), c(0), min(0);
	// įsivedame tris skaičius kuriuose lyginsime
	cin >> a >> b >> c;

	_asm {

		// Susikuriam tris INT dydžio registrus
		push eax
		push ebx
		push ecx

		// Tiem registram priskiriame duomenis (šiuo atveju įvestus)
		mov eax, a
		mov ebx, b
		mov ecx, c

		// Palyginame du pirmus registrus tarpusavyje
		cmp eax, ebx // Lyginame a su b
			jl aUzB  // jeigu a mažiau už b, vykdysime "aUzB"
			jg bUzA	 // jeigu b mažiau už a, vykdysime "bUzA"
		
		// Vykdome "aUzB" jeigu a buvo mažesnis už b
		// Ir sulyginame a su c
		aUzB:
			cmp eax, ecx // Lyginame a su c
				jl aUzC  // jeigu a mažiau už c, vykdysime "aUzC"
				jg cUzA	 // jeigu c mažiau už a, vykdysime "cUzA"
		jmp pab	// Jeigu neatitiks nei vieno palyginimo, šoksime į galą (bet užduoties atveju taip įvykti neturėtu)

		// Vykdome "bUzA" jeigu b buvo mažesnis už a
		// Ir sulyginame b su c
		bUzA:
			cmp ebx, ecx // Lyginame b su c
				jl bUzC	 // jeigu b mažiau už c, vykdysime "bUzC"
				jg cUzB	 // jeigu c mažiau už b, vykdysime "cUzB"
		jmp pab // Jeigu neatitiks nei vieno palyginimo, šoksime į galą (bet užduoties atveju taip įvykti neturėtu)

		// Keturios galimos išvestys, radus mažiausią skaičių jį išvedame į "min" kintamajį
		aUzC: // a mažiau už c
			mov min, eax // "min" priskiriame "a" (eax) reiškmę
		jmp pab // priskyrus reikšmę eisime į "pab" programos užbaigimui

		cUzA: // c mažiau už a
			mov min, ecx // "min" priskiriame "c" (ecx) reiškmę
		jmp pab // priskyrus reikšmę eisime į "pab" programos užbaigimui

		bUzC: // b mažiau už c
			mov min, ebx // "min" priskiriame "b" (ebx) reiškmę
		jmp pab // priskyrus reikšmę eisime į "pab" programos užbaigimui
		
		cUzB: // c mažiau už b
			mov min, ecx // "min" priskiriame "c" (ecx) reiškmę
		jmp pab // priskyrus reikšmę eisime į "pab" programos užbaigimui

		// Pabaigoje išvalome registrus
		pab:
		pop eax
		pop ebx
		pop ecx
	}

	// Išvedame mažiausią skaičių iš tryjų
	cout << min;
	return 0;
}
