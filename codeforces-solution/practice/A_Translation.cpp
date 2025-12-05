#include <bits/stdc++.h>
using namespace std;

bool isAnagram(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) return false;

    int cnt[256] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
        cnt[(unsigned char)s1[i]]++;

    for (int i = 0; s2[i] != '\0'; i++)
        cnt[(unsigned char)s2[i]]--;

    for (int i = 0; i < 256; i++)
        if (cnt[i] != 0) return false;

    return true;
}

int main() {
    char s1[100], s2[100];
    cin >> s1 >> s2;

    if (isAnagram(s1, s2))   // <-- CHỖ SỬA
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
