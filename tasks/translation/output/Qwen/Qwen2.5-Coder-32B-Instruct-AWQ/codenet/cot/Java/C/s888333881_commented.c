#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node0n {
    int* next_vs;
    int size;
    int capacity;
} Node0n;

void Node0n_init(Node0n* node) {
    node->next_vs = (int*)malloc(10 * sizeof(int));
    node->size = 0;
    node->capacity = 10;
}

void Node0n_add(Node0n* node, int val) {
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->next_vs = (int*)realloc(node->next_vs, node->capacity * sizeof(int));
    }
    node->next_vs[node->size++] = val;
}

int Node0n_get(Node0n* node, int ad) {
    return node->next_vs[ad];
}

int* Node0n_getAll(Node0n* node) {
    return node->next_vs;
}

int Node0n_size(Node0n* node) {
    return node->size;
}

void Node0n_clear(Node0n* node) {
    node->size = 0;
}

typedef struct Graph0n {
    Node0n* dt;
    int size;
} Graph0n;

void Graph0n_init(Graph0n* graph, int sz) {
    graph->dt = (Node0n*)malloc(sz * sizeof(Node0n));
    graph->size = sz;
    for (int i = 0; i < sz; i++) {
        Node0n_init(&graph->dt[i]);
    }
}

void Graph0n_add(Graph0n* graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
}

void Graph0n_add2(Graph0n* graph, int vn, int val) {
    Node0n_add(&graph->dt[vn], val);
    Node0n_add(&graph->dt[val], vn);
}

int Graph0n_get(Graph0n* graph, int vn, int index) {
    return Node0n_get(&graph->dt[vn], index);
}

int* Graph0n_getAll(Graph0n* graph, int vn) {
    return Node0n_getAll(&graph->dt[vn]);
}

int Graph0n_sizeOf(Graph0n* graph, int vn) {
    return Node0n_size(&graph->dt[vn]);
}

void Graph0n_clear(Graph0n* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node0n_clear(&graph->dt[i]);
    }
}

typedef struct Edge {
    int from;
    int v2;
    long weight;
} Edge;

typedef struct Edge2 {
    int v2;
    long cost1;
    long cost2;
} Edge2;

typedef struct Comparator_Edge {
    int (*compare)(Edge* a, Edge* b);
} Comparator_Edge;

int Comparator_Edge_compare(Edge* a, Edge* b) {
    if (a->weight > b->weight) return -1;
    else if (a->weight < b->weight) return 1;
    else return b->v2 - a->v2;
}

typedef struct V2Comp {
    int (*compare)(Edge* a, Edge* b);
} V2Comp;

int V2Comp_compare(Edge* a, Edge* b) {
    if (a->v2 > b->v2) return -1;
    else if (a->v2 < b->v2) return 1;
    else if (a->weight > b->weight) return -1;
    else if (a->weight < b->weight) return 1;
    else return 0;
}

typedef struct antiV2 {
    int (*compare)(Edge* a, Edge* b);
} antiV2;

int antiV2_compare(Edge* a, Edge* b) {
    if (a->v2 > b->v2) return 1;
    else if (a->v2 < b->v2) return -1;
    else if (a->weight > b->weight) return -1;
    else if (a->weight < b->weight) return 1;
    else return 0;
}

typedef struct Vector {
    int x;
    int y;
} Vector;

void Vector_init(Vector* vector, int sx, int sy) {
    vector->x = sx;
    vector->y = sy;
}

#define INF (int)1e8
#define INFL (long)1e17
#define e97 (long)1e9 + 7

void assertion(int b) {
    if (!b) {
        fprintf(stderr, "Assertion failed\n");
        exit(1);
    }
}

int abs_int(int a) {
    return (a >= 0) ? a : -a;
}

long abs_long(long a) {
    return (a >= 0) ? a : -a;
}

double abs_double(double a) {
    return (a >= 0) ? a : -a;
}

int min_int(int a, int b) {
    return (a > b) ? b : a;
}

long min_long(long a, long b) {
    return (a > b) ? b : a;
}

double min_double(double a, double b) {
    return (a > b) ? b : a;
}

int max_int(int a, int b) {
    return (a > b) ? a : b;
}

long max_long(long a, long b) {
    return (a > b) ? a : b;
}

double max_double(double a, double b) {
    return (a > b) ? a : b;
}

int minN_int(int* ins, int length) {
    int min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN_int(int* ins, int length) {
    int max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

long minN_long(long* ins, int length) {
    long min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long maxN_long(long* ins, int length) {
    long max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd_int(int* dt, int ad, int length) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

long minExAd_long(long* dt, int ad, int length) {
    long min = INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

int minExVal_int(int* dt, int ex_val, int length) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

long minExVal_long(long* dt, long ex_val, int length) {
    long min = INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

int maxExAd_int(int* dt, int ad, int length) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

long maxExAd_long(long* dt, int ad, int length) {
    long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

int maxExVal_int(int* dt, int ex_val, int length) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

long maxExVal_long(long* dt, long ex_val, int length) {
    long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

int sumA_int(int* dt, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

long sumA_long(long* dt, int length) {
    long sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

int sumA_list(List* dt) {
    int sum = 0;
    for (int i = 0; i < dt->size; i++) {
        sum += dt->elements[i];
    }
    return sum;
}

int same3(long a, long b, long c) {
    if (a != b) return 0;
    if (b != c) return 0;
    if (c != a) return 0;
    return 1;
}

int dif3(long a, long b, long c) {
    if (a == b) return 0;
    if (b == c) return 0;
    if (c == a) return 0;
    return 1;
}

int triangle_inequality(int a, int b, int c) {
    if ((a + b) < c) return 0;
    if ((b + c) < a) return 0;
    if ((c + a) < b) return 0;
    return 1;
}

double hypod(double a, double b) {
    return sqrt(a * a + b * b);
}

long factorial(int n) {
    long ans = 1;
    for (long i = n; i > 0; i--) {
        ans *= i;
    }
    return ans;
}

long facP(int n, long p) {
    long ans = 1;
    for (long i = n; i > 0; i--) {
        ans *= i;
        ans %= p;
    }
    return ans;
}

long lcm(long m, long n) {
    long ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

long gcd(long m, long n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

int is_prime(long a) {
    if (a == 1) return 0;
    for (long i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

long modinv(long a, long p) {
    long b = p, u = 1, v = 0;
    while (b > 0) {
        long t = a / b;
        long pe = a % b;
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

long pow_long(long n, int k) {
    long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2_int(int in) {
    return in * in;
}

long pow2_long(long in) {
    return in * in;
}

double pow2_double(double in) {
    return in * in;
}

int getDigit2(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1L << d);
    }
    return d;
}

int getDigit10(long num) {
    long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d;
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
    long* ob_pow_2pow = (long*)malloc(d * sizeof(long));

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

long flag(long pos) {
    return (1L << pos);
}

int isFlaged_int(int bit, int pos) {
    if ((bit & (1 << pos)) > 0) return 1;
    else return 0;
}

int isFlaged_long(long bit, int pos) {
    if ((bit & (1L << pos)) > 0) return 1;
    else return 0;
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

int countFlaged_long(long bit) {
    int ans = 0;
    for (long i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1L << i)) > 0) ans++;
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

int biSearch(int* dt, int target, int length) {
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

int biSearchMax(long* dt, long target, int length) {
    int left = -1, right = length;
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

int biSearchMaxAL(List* dt, long target) {
    int left = -1, right = dt->size;
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt->elements[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

void fill_parent(int* ob, int length) {
    for (int i = 0; i < length; i++) ob[i] = i;
}

int get_root_uf(int* parent, int index) {
    if (parent[index] == index) return index;
    int root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

int is_same_uf(int* parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return 1;
    else return 0;
}

void unite_uf(int* parent, int receiver, int attacker) {
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

void show2_bool(bool** dt, int lit_x, int lit_y, int height, int width) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (i == lit_y && j == lit_x) printf("X");
            else if (dt[j][i]) printf("O");
            else printf(".");
        }
        printf("\n");
    }
}

void show2_int(int** dt, int height, int width, char* cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void show2_long(long** dt, int height, int width, char* cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%ld,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void disp_que(ArrayDeque* dt) {
    long a = 0;
    while (dt->size > 0) {
        a = dt->removeFirst();
        printf("%ld", a);
    }
    printf("\n");
}

void disp_list(List* dt) {
    for (int i = 0; i < dt->size; i++) {
        printf("%d,", dt->elements[i]);
    }
    printf("\n");
}

void prtlnas_int(int* as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", as[i]);
    }
}

void prtlnas_long(long* as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%ld\n", as[i]);
    }
}

void prtspas_int(int* as, int length) {
    printf("%d", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", as[i]);
    }
    printf("\n");
}

void prtspas_long(long* as, int length) {
    printf("%ld", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %ld", as[i]);
    }
    printf("\n");
}

void prtspas_list(List* as) {
    printf("%d", as->elements[0]);
    for (int i = 1; i < as->size; i++) {
        printf(" %d", as->elements[i]);
    }
    printf("\n");
}

void fill_bool(bool* ob, bool res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_int(int* ob, int res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_long(long* ob, long res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_char(char* ob, char res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_double(double* ob, double res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fill_bool2(bool** ob, bool res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_int2(int** ob, int res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_long2(long** ob, long res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_char2(char** ob, char res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_double2(double** ob, double res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fill_int3(int*** ob, int res, int depth, int height, int width) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

void fill_long3(long*** ob, long res, int depth, int height, int width) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

typedef struct FastScanner {
    FILE* in;
    char buffer[1024];
    int ptr;
    int buflen;
} FastScanner;

int FastScanner_hasNextByte(FastScanner* scanner) {
    if (scanner->ptr < scanner->buflen) {
        return 1;
    } else {
        scanner->ptr = 0;
        scanner->buflen = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->in);
        if (scanner->buflen <= 0) {
            return 0;
        }
    }
    return 1;
}

int FastScanner_readByte(FastScanner* scanner) {
    if (FastScanner_hasNextByte(scanner)) return scanner->buffer[scanner->ptr++];
    else return -1;
}

int isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

int FastScanner_hasNext(FastScanner* scanner) {
    while (FastScanner_hasNextByte(scanner) && !isPrintableChar(scanner->buffer[scanner->ptr])) scanner->ptr++;
    return FastScanner_hasNextByte(scanner);
}

char* FastScanner_next(FastScanner* scanner) {
    if (!FastScanner_hasNext(scanner)) {
        fprintf(stderr, "No next element\n");
        exit(1);
    }
    char* sb = (char*)malloc(1024 * sizeof(char));
    int b = FastScanner_readByte(scanner);
    int index = 0;
    while (isPrintableChar(b)) {
        sb[index++] = b;
        b = FastScanner_readByte(scanner);
    }
    sb[index] = '\0';
    return sb;
}

long FastScanner_nexL(FastScanner* scanner) {
    if (!FastScanner_hasNext(scanner)) {
        fprintf(stderr, "No next element\n");
        exit(1);
    }
    long n = 0;
    int minus = 0;
    int b = FastScanner_readByte(scanner);
    if (b == '-') {
        minus = 1;
        b = FastScanner_readByte(scanner);
    }
    if (b < '0' || '9' < b) {
        fprintf(stderr, "Number format exception\n");
        exit(1);
    }
    while (1) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !isPrintableChar(b) || b == ':') {
            return minus ? -n : n;
        } else {
            fprintf(stderr, "Number format exception\n");
            exit(1);
        }
        b = FastScanner_readByte(scanner);
    }
}

int FastScanner_nexI(FastScanner* scanner) {
    long nl = FastScanner_nexL(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "Number format exception\n");
        exit(1);
    }
    return (int)nl;
}

double FastScanner_nexD(FastScanner* scanner) {
    char* str = FastScanner_next(scanner);
    double result = atof(str);
    free(str);
    return result;
}

void FastScanner_ni_long(FastScanner* scanner, long* array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = FastScanner_nexL(scanner);
    }
}

void FastScanner_ni_int(FastScanner* scanner, int* array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = FastScanner_nexI(scanner);
    }
}

void FastScanner_ni_int2(FastScanner* scanner, int* as, int* bs, int length) {
    for (int i = 0; i < length; i++) {
        as[i] = FastScanner_nexI(scanner);
        bs[i] = FastScanner_nexI(scanner);
    }
}

void FastScanner_ni_long2(FastScanner* scanner, long* as, long* bs, int length) {
    for (int i = 0; i < length; i++) {
        as[i] = FastScanner_nexL(scanner);
        bs[i] = FastScanner_nexL(scanner);
    }
}

void FastScanner_ni_int3(FastScanner* scanner, int* as, int* bs, int* cs, int length) {
    for (int i = 0; i < length; i++) {
        as[i] = FastScanner_nexI(scanner);
        bs[i] = FastScanner_nexI(scanner);
        cs[i] = FastScanner_nexI(scanner);
    }
}

void FastScanner_nisan(FastScanner* scanner, int** as, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            as[i][j] = FastScanner_nexI(scanner);
        }
    }
}

int main() {
    FastScanner scanner;
    scanner.in = stdin;
    scanner.ptr = 0;
    scanner.buflen = 0;

    int n = FastScanner_nexI(&scanner);
    char* s = FastScanner_next(&scanner);
    bool* flaged = (bool*)malloc(n * sizeof(bool));
    fill_bool(flaged, 0, n);

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
                if (dw < 0) printf("%d\n", 1 / 0);
                int count = countFlaged_int(dw);
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
                if (dw < 0) printf("%d\n", 1 / 0);
                int count = countFlaged_int(dw);
                dw %= count;
                ans++;
            }
            printf("%d\n", ans);
        }
    }

    free(flaged);
    free(s);
    return 0;
}
// End of Code
