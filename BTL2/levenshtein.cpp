#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int LevenshteinDistance(const string &A, const string &B) {
	int *cur = new int[B.size() + 1]; // Gia tri L[i][j] hien tai (cur : current)
	int *nxt = new int[B.size() + 1]; // Gia tri L[i+1][j] ke tiep (nxt : next)
	for (int i = 0; i <= B.size(); i++) cur[i] = i; // Gia tri L[0][i]
	for (int i = 1; i <= A.size(); i++) { // Tinh gia tri L[i][], xet tren ki tu A[i-1] va B[j-1]
		nxt[0] = i;
		for (int j = 1; j <= B.size(); j++) {
			nxt[j] = min(nxt[j - 1] + 1, cur[j] + 1); // nxt[j-1]: L[i][j-1], cur[j]: L[i-1][j]
			// Tinh L[i-1][j-1] + A[i-1] ? B[j-1], khong phan biet hoa / thuong
			char a = A[i - 1], b = B[j - 1];
			int diff = (a == b ? 0 : 1);
			if (a != b) {
				if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z' && (a - 'a') == (b - 'A')) diff = 0;
				if ('a' <= b && b <= 'z' && 'A' <= a && a <= 'Z' && (b - 'a') == (a - 'A')) diff = 0;

			}
			nxt[j] = min(nxt[j], cur[j - 1] + diff);

		}
		for (int i = 0; i <= B.size(); i++) cur[i] = nxt[i];

	}
	int res = cur[B.size()];
	delete[] cur; cur = NULL;
	delete[] nxt; nxt = NULL;
	return res;
}

string compress(const string &s) {
	string res = "";
	int l = 0, n = (int) s.size();
	for (;;) {
		while (l < n && s[l] == ' ') l++;
		if (l == n) break;
		int r = l;
		while (r + 1 < n && s[r + 1] != ' ') r++;
		res += s.substr(l, r - l + 1);
		l = r + 1;
	}
	return res;
}

double LevenshteinProbability(const string &pattern, const string &text) {
	string pattern_ = compress(pattern);
	int distance = LevenshteinDistance(pattern_, text);
	return (double)(text.size() - distance) / pattern_.size();
}

int main() 
{
	string a = "   huong   Doi  tuong c++,  Python   ";
	string b = "Lap trinh Huong doi tuong trong ngon ngu C++ va Java";

	cout << a.size() << " " << b.size() << endl;
	cout << LevenshteinDistance(a, b) << endl;
	cout << LevenshteinProbability(a, b) << endl;

	getchar();

	return 0;
}
