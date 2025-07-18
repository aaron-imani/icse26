#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000000
#define INFL 1000000000000000000L
#define e97 1000000007

typedef struct Node0n {
    int *next_vs;
    int size;
    int capacity;
} Node0n;

void Node0n_init(Node0n *node) {
    node->next_vs = (int *)malloc(sizeof(int) * 10);
    node->size = 0;
    node->capacity = 10;
}

void Node0n_add(Node0n *node, int val) {
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->next_vs = (int *)realloc(node->next_vs, sizeof(int) * node->capacity);
    }
    node->next_vs[node->size++] = val;
}

int Node0n_get(Node0n *node, int ad) {
    return node->next_vs[ad];
}

int *Node0n_getAll(Node0n *node) {
    return node->next_vs;
}

int Node0n_size(Node0n *node) {
    return node->size;
}

void Node0n_clear(Node0n *node) {
    node->size = 0;
}

typedef struct Graph0n {
    Node0n *dt;
    int sz;
} Graph0n;

void Graph0n_init(Graph0n *graph, int sz) {
    graph->dt = (Node0n *)malloc(sizeof(Node0n) * sz);
    graph->sz = sz;
    for (int i = 0; i < sz; i++) {
        Node0n_init(&graph->dt[i]);
    }
}

void Graph0n_add(Graph0n *graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
}

void Graph0n_add2(Graph0n *graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
    Node0n_add(&graph->dt[val], vn);
}

int Graph0n_get(Graph0n *graph, int vn, int index) {
    return Node0n_get(&graph->dt[vn], index);
}

int *Graph0n_get_all(Graph0n *graph, int vn) {
    return Node0n_getAll(&graph->dt[vn]);
}

int Graph0n_sizeOf(Graph0n *graph, int vn) {
    return Node0n_size(&graph->dt[vn]);
}

void Graph0n_clear(Graph0n *graph) {
    for (int i = 0; i < graph->sz; i++) {
        Node0n_clear(&graph->dt[i]);
    }
}

typedef struct Edge {
    int from;
    int v2;
    long long weight;
} Edge;

typedef struct Edge2 {
    int v2;
    long long cost1;
    long long cost2;
} Edge2;

int compare_edge(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return eb->v2 - ea->v2;
}

int compare_v2(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->v2 > eb->v2) return -1;
    else if (ea->v2 < eb->v2) return 1;
    else if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return 0;
}

int compare_antiv2(const void *a, const void *b) {
    Edge *ea = (Edge *)a;
    Edge *eb = (Edge *)b;
    if (ea->v2 > eb->v2) return 1;
    else if (ea->v2 < eb->v2) return -1;
    else if (ea->weight > eb->weight) return -1;
    else if (ea->weight < eb->weight) return 1;
    else return 0;
}

typedef struct Vector {
    int x;
    int y;
} Vector;

void Vector_init(Vector *vec, int sx, int sy) {
    vec->x = sx;
    vec->y = sy;
}

void assertion(bool b) {
    if (!b) {
        fprintf(stderr, "Assertion failed\n");
        exit(1);
    }
}

int abs_int(int a) {
    return (a >= 0) ? a : -a;
}

long long abs_long(long long a) {
    return (a >= 0) ? a : -a;
}

double abs_double(double a) {
    return (a >= 0) ? a : -a;
}

int min_int(int a, int b) {
    return (a > b) ? b : a;
}

long long min_long(long long a, long long b) {
    return (a > b) ? b : a;
}

double min_double(double a, double b) {
    return (a > b) ? b : a;
}

int max_int(int a, int b) {
    return (a > b) ? a : b;
}

long long max_long(long long a, long long b) {
    return (a > b) ? a : b;
}

double max_double(double a, double b) {
    return (a > b) ? a : b;
}

int minN_int(int *ins, int length) {
    int min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN_int(int *ins, int length) {
    int max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

long long minN_long(long long *ins, int length) {
    long long min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long long maxN_long(long long *ins, int length) {
    long long max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd_int(int *dt, int length, int ad) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

long long minExAd_long(long long *dt, int length, int ad) {
    long long min = INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

int minExVal_int(int *dt, int length, int ex_val) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

long long minExVal_long(long long *dt, int length, long long ex_val) {
    long long min = INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

int maxExAd_int(int *dt, int length, int ad) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

long long maxExAd_long(long long *dt, int length, int ad) {
    long long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

int maxExVal_int(int *dt, int length, int ex_val) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

long long maxExVal_long(long long *dt, int length, long long ex_val) {
    long long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

int sumA_int(int *dt, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

long long sumA_long(long long *dt, int length) {
    long long sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

bool same3(long long a, long long b, long long c) {
    if (a != b) return false;
    if (b != c) return false;
    if (c != a) return false;
    return true;
}

bool dif3(long long a, long long b, long long c) {
    if (a == b) return false;
    if (b == c) return false;
    if (c == a) return false;
    return true;
}

bool triangle_inequality(int a, int b, int c) {
    if ((a + b) < c) return false;
    if ((b + c) < a) return false;
    if ((c + a) < b) return false;
    return true;
}

double hypod(double a, double b) {
    return sqrt(a * a + b * b);
}

long long factorial(int n) {
    long long ans = 1;
    for (long long i = n; i > 0; i--) {
        ans *= i;
    }
    return ans;
}

long long facP(int n, long long p) {
    long long ans = 1;
    for (long long i = n; i > 0; i--) {
        ans *= i;
        ans %= p;
    }
    return ans;
}

long long lcm(long long m, long long n) {
    long long ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

long long gcd(long long m, long long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

bool is_prime(long long a) {
    if (a == 1) return false;
    for (long long i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

long long modinv(long long a, long long p) {
    long long b = p, u = 1, v = 0;
    while (b > 0) {
        long long t = a / b;
        long long pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

int pow_int(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

long long pow_long(long long n, int k) {
    long long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2_int(int in) {
    return in * in;
}

long long pow2_long(long long in) {
    return in * in;
}

double pow2_double(double in) {
    return in * in;
}

int getDigit2(long long num) {
    long long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d;
}

int getDigit10(long long num) {
    long long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d;
}

bool isINF(int in) {
    if (((long long)in * 20) > INF) return true;
    else return false;
}

bool isINFL(long long in) {
    if ((in * 10000) > INFL) return true;
    else return false;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    long long *ob_pow_2pow = (long long *)malloc(sizeof(long long) * d);

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    long long ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    free(ob_pow_2pow);
    return ans % p;
}

long long flag(long long pos) {
    return (1LL << pos);
}

bool isFlaged_int(int bit, int pos) {
    if ((bit & (1 << pos)) > 0) return true;
    else return false;
}

bool isFlaged_long(long long bit, int pos) {
    if ((bit & (1LL << pos)) > 0) return true;
    else return false;
}

int deflag(int bit, int pos) {
    return bit & ~(1 << pos);
}

int countFlaged_int(int bit) {
    int ans = 0;
    for (int i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1 << i)) > 0) ans++;
    }
    return ans;
}

int countFlaged_long(long long bit) {
    int ans = 0;
    for (long long i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

void showflag(int bit) {
    for (int i = 0; i < getDigit2(bit); i++) {
        if (isFlaged_int(bit, i)) printf("O");
        else printf(".");
    }
    printf("\n");
}

int biSearch(int *dt, int length, int target) {
    int left = 0, right = length - 1;
    int mid = -1;
    while (left <= right) {
        mid = (right + left) / 2;
        if (dt[mid] == target) return mid;
        if (dt[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int biSearchMax(long long *dt, int length, long long target) {
    int left = -1, right = length;
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

int biSearchMaxAL(int *dt, int length, long long target) {
    int left = -1, right = length;
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

void fill_parent(int *ob, int length) {
    for (int i = 0; i < length; i++) ob[i] = i;
}

int get_root_uf(int *parent, int index) {
    if (parent[index] == index) return index;
    int root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

bool is_same_uf(int *parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return true;
    else return false;
}

void unite_uf(int *parent, int receiver, int attacker) {
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver);
}

int Xdir4[] = {1, 0, 0, -1};
int Ydir4[] = {0, 1, -1, 0};

int Xdir8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int Ydir8[] = {1, 0, -1, 1, -1, 1, 0, -1};

bool is_in_area(int y, int x, int h, int w) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= h) return false;
    if (x >= w) return false;
    return true;
}

void show2_bool(bool **dt, int height, int width, int lit_x, int lit_y) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (i == lit_y && j == lit_x) printf("X");
            else if (dt[j][i]) printf("O");
            else printf(".");
        }
        printf("\n");
    }
}

void show2_int(int **dt, int height, int width, const char *cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void show2_long(long long **dt, int height, int width, const char *cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%lld,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void disp_que(long long *dt, int length) {
    for (int i = 0; i < length; i++) {
        printf("%lld", dt[i]);
    }
    printf("\n");
}

void disp_list(void **dt, int length) {
    for (int i = 0; i < length; i++) {
        printf("%p,", dt[i]);
    }
    printf("\n");
}

void prtlnas_int(int *as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", as[i]);
    }
}

void prtlnas_long(long long *as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%lld\n", as[i]);
    }
}

void prtspas_int(int *as, int length) {
    printf("%d", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", as[i]);
    }
    printf("\n");
}

void prtspas_long(long long *as, int length) {
    printf("%lld", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %lld", as[i]);
    }
    printf("\n");
}

void fill_bool(bool *ob, bool res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_int(int *ob, int res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_long(long long *ob, long long res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_char(char *ob, char res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_double(double *ob, double res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_bool2(bool **ob, bool res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_int2(int **ob, int res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_long2(long long **ob, long long res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_char2(char **ob, char res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_double2(double **ob, double res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_int3(int ***ob, int res, int depth, int height, int width) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

void fill_long3(long long ***ob, long long res, int depth, int height, int width) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    bool *flaged = (bool *)malloc(n * sizeof(bool));
    fill_bool(flaged, false, n);

    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                printf("0\n");
                continue;
            }
            long long dw = surp9;

            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("%d\n", 1 / 0);
                int count = countFlaged_long(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        } else {
            long long dw = surp1;

            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) printf("%d\n", 1 / 0);
                int count = countFlaged_long(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }

    free(s);
    free(flaged);
    return 0;
}
// End of Code
