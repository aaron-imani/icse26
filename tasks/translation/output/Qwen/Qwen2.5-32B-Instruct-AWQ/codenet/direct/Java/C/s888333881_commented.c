#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 100000000
#define INFL 1000000000000000000L
#define e97 1000000007L

typedef struct {
    int x, y;
} Vector;

typedef struct {
    int from, v2;
    long weight;
} Edge;

typedef struct {
    int v2;
    long cost1, cost2;
} Edge2;

typedef struct {
    int *next_vs;
    int size;
} Node0n;

typedef struct {
    Node0n *dt;
    int size;
} Graph0n;

Graph0n* createGraph0n(int sz) {
    Graph0n *graph = (Graph0n*)malloc(sizeof(Graph0n));
    graph->size = sz;
    graph->dt = (Node0n*)malloc(sz * sizeof(Node0n));
    for (int i = 0; i < sz; i++) {
        graph->dt[i].next_vs = (int*)malloc(0 * sizeof(int));
        graph->dt[i].size = 0;
    }
    return graph;
}

void add(Graph0n *graph, int vn, int val) {
    graph->dt[vn].next_vs = (int*)realloc(graph->dt[vn].next_vs, (graph->dt[vn].size + 1) * sizeof(int));
    graph->dt[vn].next_vs[graph->dt[vn].size] = val;
    graph->dt[vn].size++;
}

void add2(Graph0n *graph, int vn, int val) {
    add(graph, vn, val);
    add(graph, val, vn);
}

int get(Graph0n *graph, int vn, int index) {
    return graph->dt[vn].next_vs[index];
}

int* getAll(Graph0n *graph, int vn) {
    return graph->dt[vn].next_vs;
}

int sizeOf(Graph0n *graph, int vn) {
    return graph->dt[vn].size;
}

void clear(Graph0n *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->dt[i].next_vs);
        graph->dt[i].next_vs = NULL;
        graph->dt[i].size = 0;
    }
}

int abs(int a) {
    return (a >= 0) ? a : -a;
}

long abs(long a) {
    return (a >= 0) ? a : -a;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

long min(long a, long b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long max(long a, long b) {
    return (a > b) ? a : b;
}

int minN(int *ins, int len) {
    int min = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN(int *ins, int len) {
    int max = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

long minN(long *ins, int len) {
    long min = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long maxN(long *ins, int len) {
    long max = ins[0];
    for (int i = 1; i < len; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd(int *dt, int len, int ad) {
    int min = INF;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

long minExAd(long *dt, int len, int ad) {
    long min = INFL;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int minExVal(int *dt, int len, int ex_val) {
    int min = INF;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

long minExVal(long *dt, int len, long ex_val) {
    long min = INFL;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int maxExAd(int *dt, int len, int ad) {
    int max = -INF;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

long maxExAd(long *dt, int len, int ad) {
    long max = -INFL;
    for (int i = 0; i < len; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int maxExVal(int *dt, int len, int ex_val) {
    int max = -INF;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

long maxExVal(long *dt, int len, long ex_val) {
    long max = -INFL;
    for (int i = 0; i < len; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int sumA(int *dt, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

long sumA(long *dt, int len) {
    long sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

int sumA(int *dt, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += dt[i];
    }
    return sum;
}

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

long pow(long n, int k) {
    long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2(int in) {
    return in * in;
}

long pow2(long in) {
    return in * in;
}

int getDigit2(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1L << d);
    }
    return d; // numはd桁の数で、2^dより小さい
}

int getDigit10(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d; // numはd桁の数で、10^dより小さい
}

int isINF(int in) {
    if (((long)in * 20) > INF) return 1;
    else return 0;
}

int isINFL(long in) {
    if ((in * 10000) > INFL) return 1;
    else return 0;
}

long pow10E97(long ob, long soeji, long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    long *ob_pow_2pow = (long*)malloc(d * sizeof(long));

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1L << i)) {
            soeji -= (1L << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

int isFlaged(int bit, int pos) {
    if ((bit & (1 << pos)) > 0) return 1;
    else return 0;
}

int isFlaged(long bit, int pos) {
    if ((bit & (1L << pos)) > 0) return 1;
    else return 0;
}

int deflag(int bit, int pos) {
    return bit & ~(1 << pos);
}

int countFlaged(int bit) {
    int ans = 0;
    for (int i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1 << i)) > 0) ans++;
    }
    return ans;
}

int countFlaged(long bit) {
    int ans = 0;
    for (int i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1L << i)) > 0) ans++;
    }
    return ans;
}

void showflag(int bit) {
    for (int i = 0; i < getDigit2(bit); i++) {
        if (isFlaged(bit, i)) printf("O");
        else printf(".");
    }
    printf("\n");
}

int biSearch(int *dt, int len, int target) {
    int left = 0, right = len - 1;
    int mid = -1;
    while (left <= right) {
        mid = (right + left) / 2;
        if (dt[mid] == target) return mid;
        if (dt[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int biSearchMax(long *dt, int len, long target) {
    int left = -1, right = len;
    int mid = -1;
    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left; // target未満の最大のaddress
}

int biSearchMaxAL(int *dt, int len, long target) {
    int left = -1, right = len;
    int mid = -1;
    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left; // target以下の最大のaddress
}

void fill_parent(int *ob, int len) {
    for (int i = 0; i < len; i++) ob[i] = i;
}

int get_root_uf(int *parent, int index) {
    if (parent[index] == index) return index;
    int root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

int is_same_uf(int *parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return 1;
    else return 0;
}

void unite_uf(int *parent, int receiver, int attacker) {
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver);
}

int Xdir4[] = {1, 0, 0, -1};
int Ydir4[] = {0, 1, -1, 0};

int Xdir8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int Ydir8[] = {1, 0, -1, 1, -1, 1, 0, -1};

int is_in_area(int y, int x, int h, int w) {
    if (y < 0) return 0;
    if (x < 0) return 0;
    if (y >= h) return 0;
    if (x >= w) return 0;
    return 1;
}

void show2(int **dt, int h, int w, char *cmnt) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void show2(long **dt, int h, int w, char *cmnt) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%ld,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void disp_que(long *dt, int len) {
    for (int i = 0; i < len; i++) {
        printf("%ld", dt[i]);
    }
    printf("\n");
}

void disp_list(int *dt, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d,", dt[i]);
    }
    printf("\n");
}

void prtlnas(int *as, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", as[i]);
    }
}

void prtlnas(long *as, int len) {
    for (int i = 0; i < len; i++) {
        printf("%ld\n", as[i]);
    }
}

void prtspas(int *as, int len) {
    printf("%d", as[0]);
    for (int i = 1; i < len; i++) {
        printf(" %d", as[i]);
    }
    printf("\n");
}

void prtspas(long *as, int len) {
    printf("%ld", as[0]);
    for (int i = 1; i < len; i++) {
        printf(" %ld", as[i]);
    }
    printf("\n");
}

void fill(int *ob, int len, int res) {
    for (int i = 0; i < len; i++) ob[i] = res;
}

void fill(long *ob, int len, long res) {
    for (int i = 0; i < len; i++) ob[i] = res;
}

void fill(int **ob, int h, int w, int res) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ob[i][j] = res;
        }
    }
}

void fill(long **ob, int h, int w, long res) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ob[i][j] = res;
        }
    }
}

void fill(int ***ob, int h, int w, int d, int res) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < d; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

void fill(long ***ob, int h, int w, int d, long res) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < d; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int flaged[n];
    fill(flaged, n, 0);

    long pop1st = 0L;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = 1;
            pop1st++;
        }
    }

    long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2L;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1L);
    }

    long surp9 = 0L;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2L;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1L);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long dw = surp9;

            long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1L);
            dw %= (pop1st - 1L);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long dw = surp1;

            long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1L);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("1/0\n");
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
} // End of Code
