#include <windows.h>
#include <iostream>
#include "lab3.h"

using namespace std;

#define THREAD_COUNT 14
#define SEMAPHORE_COUNT 4

DWORD ThreadID;
HANDLE hThread[THREAD_COUNT];
HANDLE hSemaphore[SEMAPHORE_COUNT];
HANDLE hIntC, hContC, hIntF, hContF, hIntF2, hContF2, hIntG, hContG, hIntG2, hContG2, hIntG3, hContG3, hIntG4, hContG4, hIntE, hContE, hIntE2, hContE2, hIntR, hContR, hIntM, hContM, hIntN, hContN, hIntN2, hContN2;
HANDLE hMutex;

DWORD WINAPI thread_a(LPVOID);
DWORD WINAPI thread_b(LPVOID);
DWORD WINAPI thread_c(LPVOID);
DWORD WINAPI thread_d(LPVOID);
DWORD WINAPI thread_e(LPVOID);
DWORD WINAPI thread_f(LPVOID);
DWORD WINAPI thread_g(LPVOID);
DWORD WINAPI thread_h(LPVOID);
DWORD WINAPI thread_i(LPVOID);
DWORD WINAPI thread_r(LPVOID);
DWORD WINAPI thread_k(LPVOID);
DWORD WINAPI thread_m(LPVOID);
DWORD WINAPI thread_n(LPVOID);
DWORD WINAPI thread_p(LPVOID);

DWORD WINAPI thread_a(LPVOID lpParam)
{
	/* step 1 */
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "a" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	/* step 2 */

	// start B
	hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
	if (hThread[1] == NULL) {
		return GetLastError();
	}

	// start C
	hThread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
	if (hThread[2] == NULL) {
		return GetLastError();
	}

	// start F
	hThread[3] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
	if (hThread[3] == NULL) {
		return GetLastError();
	}

	// wait C
	WaitForSingleObject(hIntC, INFINITE);
	// wait F
	WaitForSingleObject(hIntF, INFINITE);
	// close B
	CloseHandle(hThread[1]);


	/* step 3 */
	ReleaseSemaphore(hContC, 1, NULL);
	ReleaseSemaphore(hContF, 1, NULL);

	// start G
	hThread[4] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
	if (hThread[4] == NULL) {
		return GetLastError();
	}

	// start E
	hThread[5] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
	if (hThread[5] == NULL) {
		return GetLastError();
	}

	// start D
	hThread[6] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
	if (hThread[6] == NULL) {
		return GetLastError();
	}

	
	// wait D
	WaitForSingleObject(hThread[6], INFINITE);
	// wait C
	WaitForSingleObject(hThread[2], INFINITE);
	// wait G
	WaitForSingleObject(hIntG, INFINITE);
	// wait F
	WaitForSingleObject(hIntF2, INFINITE);
	// wait E
	WaitForSingleObject(hIntE, INFINITE);

	// close D
	CloseHandle(hThread[6]);
	// close C
	CloseHandle(hThread[2]);	
	

	/* step 4 */
	ReleaseSemaphore(hContF2, 1, NULL);
	ReleaseSemaphore(hContG, 1, NULL);
	ReleaseSemaphore(hContE, 1, NULL);

	// start R
	hThread[7] = CreateThread(NULL, 0, thread_r, NULL, 0, &ThreadID);
	if (hThread[7] == NULL) {
		return GetLastError();
	}

	// start H
	hThread[8] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
	if (hThread[8] == NULL) {
		return GetLastError();
	}

	// wait H
	WaitForSingleObject(hThread[8], INFINITE);
	// wait F
	WaitForSingleObject(hThread[3], INFINITE);
	// wait G
	WaitForSingleObject(hIntG2, INFINITE);
	// wait E
	WaitForSingleObject(hIntE2, INFINITE);
	// wait R
	WaitForSingleObject(hIntR, INFINITE);

	// close H
	CloseHandle(hThread[8]);
	// close F
	CloseHandle(hThread[3]);


	/* step 5 */
	ReleaseSemaphore(hContG2, 1, NULL);
	ReleaseSemaphore(hContE2, 1, NULL);
	ReleaseSemaphore(hContR, 1, NULL);

	// start I
	hThread[9] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
	if (hThread[9] == NULL) {
		return GetLastError();
	}

	// start M
	hThread[10] = CreateThread(NULL, 0, thread_m, NULL, 0, &ThreadID);
	if (hThread[10] == NULL) {
		return GetLastError();
	}

	// start N
	hThread[11] = CreateThread(NULL, 0, thread_n, NULL, 0, &ThreadID);
	if (hThread[11] == NULL) {
		return GetLastError();
	}

	// wait E
	WaitForSingleObject(hThread[5], INFINITE);
	// wait R
	WaitForSingleObject(hThread[7], INFINITE);
	// wait I
	WaitForSingleObject(hThread[9], INFINITE);
	// wait G
	WaitForSingleObject(hIntG3, INFINITE);
	// wait M
	WaitForSingleObject(hIntM, INFINITE);
	// wait N
	WaitForSingleObject(hIntN, INFINITE);

	// close R
	CloseHandle(hThread[7]);
	// close I
	CloseHandle(hThread[9]);


	/* step 6 */
	ReleaseSemaphore(hContG3, 1, NULL);

	// start K sem
	hThread[12] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
	if (hThread[12] == NULL) {
		return GetLastError();
	}

	ReleaseSemaphore(hContM, 1, NULL);
	ReleaseSemaphore(hContN, 1, NULL);

	// wait K
	WaitForSingleObject(hThread[12], INFINITE);
	// wait M
	WaitForSingleObject(hThread[10], INFINITE);
	// wait G
	WaitForSingleObject(hIntG4, INFINITE);
	// wait N
	WaitForSingleObject(hIntN2, INFINITE);

	// close K 
	CloseHandle(hThread[12]);
	// close M 
	CloseHandle(hThread[10]);


	/* step 7 */
	ReleaseSemaphore(hContG4, 1, NULL);
	ReleaseSemaphore(hContN2, 1, NULL);

	// start P
	hThread[13] = CreateThread(NULL, 0, thread_p, NULL, 0, &ThreadID);
	if (hThread[13] == NULL) {
		return GetLastError();
	}

	// wait G
	WaitForSingleObject(hThread[4], INFINITE);
	// wait P
	WaitForSingleObject(hThread[13], INFINITE);
	// wait N
	WaitForSingleObject(hThread[11], INFINITE);

	// close G
	CloseHandle(hThread[4]);
	// close P
	CloseHandle(hThread[13]);
	// close N
	CloseHandle(hThread[11]);

	return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "b" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "c" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntC, 1, NULL);
	WaitForSingleObject(hContC, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "c" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "f" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntF, 1, NULL);
	WaitForSingleObject(hContF, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "f" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntF2, 1, NULL);
	WaitForSingleObject(hContF2, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "f" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}


DWORD WINAPI thread_g(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntG, 1, NULL);
	WaitForSingleObject(hContG, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntG2, 1, NULL);
	WaitForSingleObject(hContG2, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntG3, 1, NULL);
	WaitForSingleObject(hContG3, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[0], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[1], 1, NULL);
	}

	ReleaseSemaphore(hIntG4, 1, NULL);
	WaitForSingleObject(hContG4, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "e" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntE, 1, NULL);
	WaitForSingleObject(hContE, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "e" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntE2, 1, NULL);
	WaitForSingleObject(hContE2, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "e" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "d" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_r(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "r" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntR, 1, NULL);
	WaitForSingleObject(hContR, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "r" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "h" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "i" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[1], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "k" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[2], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_m(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntM, 1, NULL);
	WaitForSingleObject(hContM, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[2], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[3], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_n(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "n" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	ReleaseSemaphore(hIntN, 1, NULL);
	WaitForSingleObject(hContN, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[3], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "n" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[0], 1, NULL);
	}

	ReleaseSemaphore(hIntN2, 1, NULL);
	WaitForSingleObject(hContN2, INFINITE);

	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "n" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}


DWORD WINAPI thread_p(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "p" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_g_sem(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[0], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[1], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_k_sem(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[1], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "k" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[2], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_m_sem(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[2], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[3], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_n_sem(LPVOID lpParam)
{
	for (int i = 0; i < 4; i++) {
		WaitForSingleObject(hSemaphore[3], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "n" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[0], 1, NULL);
	}

	return 0;
}

unsigned int lab3_thread_graph_id()
{
	return 20;
}

const char* lab3_unsynchronized_threads()
{
	return "bcf";
}

const char* lab3_sequential_threads()
{
	return "gkmn";
}

int lab3_init()
{
	hMutex = CreateMutex(NULL, 0, NULL);
	if (hMutex == NULL) {
		cout << "CreateMutex error: " << GetLastError();
		return 1;
	}

	for (int i = 0; i < SEMAPHORE_COUNT; i++) {
		hSemaphore[i] = CreateSemaphore(NULL, i == 0 ? 1 : 0, 1, NULL);
		if (hSemaphore[i] == NULL) {
			cout << "CreateSemaphore error: " << GetLastError();
			return 1;
		}
	}

	hIntC = CreateSemaphore(NULL, 0, 2, NULL);
	hContC = CreateSemaphore(NULL, 0, 2, NULL);
	hIntF = CreateSemaphore(NULL, 0, 2, NULL);
	hContF = CreateSemaphore(NULL, 0, 2, NULL);
	hIntF2 = CreateSemaphore(NULL, 0, 2, NULL);
	hContF2 = CreateSemaphore(NULL, 0, 2, NULL);
	hIntG = CreateSemaphore(NULL, 0, 2, NULL);
	hContG = CreateSemaphore(NULL, 0, 2, NULL);
	hIntG2 = CreateSemaphore(NULL, 0, 2, NULL);
	hContG2 = CreateSemaphore(NULL, 0, 2, NULL);
	hIntG3 = CreateSemaphore(NULL, 0, 2, NULL);
	hContG3 = CreateSemaphore(NULL, 0, 2, NULL);
	hIntG4 = CreateSemaphore(NULL, 0, 2, NULL);
	hContG4 = CreateSemaphore(NULL, 0, 2, NULL);
	hIntE = CreateSemaphore(NULL, 0, 2, NULL);
	hContE = CreateSemaphore(NULL, 0, 2, NULL);
	hIntE2 = CreateSemaphore(NULL, 0, 2, NULL);
	hContE2 = CreateSemaphore(NULL, 0, 2, NULL);
	hIntR = CreateSemaphore(NULL, 0, 2, NULL);
	hContR = CreateSemaphore(NULL, 0, 2, NULL);
	hIntM = CreateSemaphore(NULL, 0, 2, NULL);
	hContM = CreateSemaphore(NULL, 0, 2, NULL);
	hIntN = CreateSemaphore(NULL, 0, 2, NULL);
	hContN = CreateSemaphore(NULL, 0, 2, NULL);
	hIntN2 = CreateSemaphore(NULL, 0, 2, NULL);
	hContN2 = CreateSemaphore(NULL, 0, 2, NULL);

	// start A
	hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
	if (hThread[0] == NULL) {
		return GetLastError();
	}
	// wait A
	WaitForSingleObject(hThread[0], INFINITE);
	// close A
	CloseHandle(hThread[0]);

	CloseHandle(hIntC);
	CloseHandle(hContC);
	CloseHandle(hIntF);
	CloseHandle(hContF);
	CloseHandle(hIntF2);
	CloseHandle(hContF2);
	CloseHandle(hIntG);
	CloseHandle(hContG);
	CloseHandle(hIntG2);
	CloseHandle(hContG2);
	CloseHandle(hIntG3);
	CloseHandle(hContG3);
	CloseHandle(hIntG4);
	CloseHandle(hContG4);
	CloseHandle(hIntE);
	CloseHandle(hContE);
	CloseHandle(hIntE2);
	CloseHandle(hContE2);
	CloseHandle(hIntR);
	CloseHandle(hContR);
	CloseHandle(hIntM);
	CloseHandle(hContM);
	CloseHandle(hIntN);
	CloseHandle(hContN);
	CloseHandle(hIntN2);
	CloseHandle(hContN2);

	CloseHandle(hMutex);

	for (int i = 0; i < SEMAPHORE_COUNT; i++) {
		CloseHandle(hSemaphore[i]);
	}

	return 0;
}
