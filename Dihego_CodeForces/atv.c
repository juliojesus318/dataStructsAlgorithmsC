#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int vector[n];
        int vau[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &vector[i]);
            vau[i] = vector[i];
        }

        mergeSort(vau, 0, n - 1);

        int repetido = 0;
        for (int i = 1; i < n; i++) {
            if (vau[i] == vau[i - 1]) {
                repetido = 1;
                break;
            }
        }

        if (repetido) {
            printf("YES\n");
            continue;
        }

        int pos[n + 1];
        for (int i = 0; i < n; i++) {
            pos[vau[i]] = i;
        }

        int p[n];
        for (int i = 0; i < n; i++) {
            p[i] = pos[vector[i]];
        }

        int vis[n];
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }

        int cycles = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cycles++;
                int cur = i;

                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = p[cur];
                }
            }
        }

        int resultado = n - cycles;

        if (resultado % 2 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
