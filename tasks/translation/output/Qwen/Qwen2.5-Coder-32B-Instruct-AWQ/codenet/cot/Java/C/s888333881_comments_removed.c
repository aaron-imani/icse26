#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

typedef int (*Comparator)(const void*, const void*);

int Comparator_Edge(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->weight > edgeB->weight) return -1;
    else if (edgeA->weight < edgeB->weight) return 1;
    else return edgeB->v2 - edgeA->v2;
}

int V2Comp(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->v2 > edgeB->v2) return -1;
    else if (edgeA->v2 < edgeB->v2) return 1;
    else if (edgeA->weight > edgeB->weight) return -1;
    else if (edgeA->weight < edgeB->weight) return 1;
    else return 0;
}

int antiV2(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->v2 > edgeB->v2) return 1;
    else if (edgeA->v2 < edgeB->v2) return -1;
    else if (edgeA->weight > edgeB->weight) return -1;
    else if (edgeA->weight < edgeB->weight) return 1;
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

void assertion(bool b) {
    if (!b) {
        fprintf(stderr, "Assertion failed\n");
        exit(1);
    }
}

int abs(int a) {
    return (a >= 0) ? a : -a;
}

long absL(long a) {
    return (a >= 0) ? a : -a;
}

double absD(double a) {
    return (a >= 0) ? a : -a;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

long minL(long a, long b) {
    return (a > b) ? b : a;
}

double minD(double a, double b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

long maxL(long a, long b) {
    return (a > b) ? a : b;
}

double maxD(double a, double b) {
    return (a > b) ? a : b;
}

int minN(int* ins, int length) {
    int min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN(int* ins, int length) {
    int max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

long minNL(long* ins, int length) {
    long min = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

long maxNL(long* ins, int length) {
    long max = ins[0];
    for (int i = 1; i < length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd(int* dt, int ad, int length) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

long minExAdL(long* dt, int ad, int length) {
    long min = INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] < min) min = dt[i];
    }
    return min;
}

int minExVal(int* dt, int ex_val, int length) {
    int min = INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

long minExValL(long* dt, long ex_val, int length) {
    long min = INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] < min) min = dt[i];
    }
    return min;
}

int maxExAd(int* dt, int ad, int length) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

long maxExAdL(long* dt, int ad, int length) {
    long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (i != ad && dt[i] > max) max = dt[i];
    }
    return max;
}

int maxExVal(int* dt, int ex_val, int length) {
    int max = -INF;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

long maxExValL(long* dt, long ex_val, int length) {
    long max = -INFL;
    for (int i = 0; i < length; i++) {
        if (dt[i] != ex_val && dt[i] > max) max = dt[i];
    }
    return max;
}

int sumA(int* dt, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

long sumAL(long* dt, int length) {
    long sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

int sumALI(int* dt, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += dt[i];
    }
    return sum;
}

bool same3(long a, long b, long c) {
    if (a != b) return false;
    if (b != c) return false;
    if (c != a) return false;
    return true;
}

bool dif3(long a, long b, long c) {
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

bool is_prime(long a) {
    if (a == 1) return false;
    for (long i = 2L; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

long modinv(long a, long p) {
    long b = p, u = 1L, v = 0L;
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

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

long powL(long n, int k) {
    long ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2(int in) {
    return in * in;
}

long pow2L(long in) {
    return in * in;
}

double pow2D(double in) {
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

bool isINF(int in) {
    if (((long)in * 20) > INF) return true;
    else return false;
}

bool isINFL(long in) {
    if ((in * 10000) > INFL) return true;
    else return false;
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

bool isFlaged(int bit, int pos) {
    if ((bit & (1 << pos)) > 0) return true;
    else return false;
}

bool isFlagedL(long bit, int pos) {
    if ((bit & (1L << pos)) > 0) return true;
    else return false;
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

int countFlagedL(long bit) {
    int ans = 0;
    for (long i = 0; i < getDigit2(bit); i++) {
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

int biSearchMaxAL(int* dt, long target, int length) {
    int left = -1, right = length;
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
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

bool is_same_uf(int* parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return true;
    else return false;
}

void unite_uf(int* parent, int receiver, int attacker) {
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

void show2(bool** dt, int lit_x, int lit_y, int height, int width) {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if ((i == lit_y) && (j == lit_x)) printf("X");
            else if (dt[j][i]) printf("O");
            else printf(".");
        }
        printf("\n");
    }
}

void show2I(int** dt, int height, int width, const char* cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void show2L(long** dt, int height, int width, const char* cmnt) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%ld,", dt[i][j]);
        }
        printf("<-%s:%d\n", cmnt, i);
    }
}

void disp_que(long* dt, int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld", dt[i]);
    }
    printf("\n");
}

void disp_list(void* dt, int size, int type) {
    if (type == 0) { // int
        int* list = (int*)dt;
        for (int i = 0; i < size; i++) {
            printf("%d,", list[i]);
        }
    } else if (type == 1) { // long
        long* list = (long*)dt;
        for (int i = 0; i < size; i++) {
            printf("%ld,", list[i]);
        }
    }
    printf("\n");
}

void prtlnas(int* as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", as[i]);
    }
}

void prtlnasL(long* as, int length) {
    for (int i = 0; i < length; i++) {
        printf("%ld\n", as[i]);
    }
}

void prtspas(int* as, int length) {
    printf("%d", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", as[i]);
    }
    printf("\n");
}

void prtspasL(long* as, int length) {
    printf("%ld", as[0]);
    for (int i = 1; i < length; i++) {
        printf(" %ld", as[i]);
    }
    printf("\n");
}

void prtspasAL(void* as, int length, int type) {
    if (type == 0) { // int
        int* list = (int*)as;
        printf("%d", list[0]);
        for (int i = 1; i < length; i++) {
            printf(" %d", list[i]);
        }
    } else if (type == 1) { // long
        long* list = (long*)as;
        printf("%ld", list[0]);
        for (int i = 1; i < length; i++) {
            printf(" %ld", list[i]);
        }
    }
    printf("\n");
}

void fillB(bool* ob, bool res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fillI(int* ob, int res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fillL(long* ob, long res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fillC(char* ob, char res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fillD(double* ob, double res, int length) {
    for (int i = 0; i < length; i++) {
        ob[i] = res;
    }
}

void fillBB(bool** ob, bool res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fillII(int** ob, int res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fillLL(long** ob, long res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fillCC(char** ob, char res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fillDD(double** ob, double res, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ob[i][j] = res;
        }
    }
}

void fillIII(int*** ob, int res, int depth, int height, int width) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                ob[i][j][k] = res;
            }
        }
    }
}

void fillLLL(long*** ob, long res, int depth, int height, int width) {
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

bool FastScanner_hasNextByte(FastScanner* scanner) {
    if (scanner->ptr < scanner->buflen) {
        return true;
    } else {
        scanner->ptr = 0;
        scanner->buflen = fread(scanner->buffer, 1, sizeof(scanner->buffer), scanner->in);
        if (scanner->buflen <= 0) {
            return false;
        }
    }
    return true;
}

int FastScanner_readByte(FastScanner* scanner) {
    if (FastScanner_hasNextByte(scanner)) return scanner->buffer[scanner->ptr++];
    else return -1;
}

bool isPrintableChar(int c) {
    return 33 <= c && c <= 126;
}

bool FastScanner_hasNext(FastScanner* scanner) {
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
    bool minus = false;
    int b = FastScanner_readByte(scanner);
    if (b == '-') {
        minus = true;
        b = FastScanner_readByte(scanner);
    }
    if (b < '0' || '9' < b) {
        fprintf(stderr, "NumberFormatException\n");
        exit(1);
    }
    while (true) {
        if ('0' <= b && b <= '9') {
            n *= 10;
            n += b - '0';
        } else if (b == -1 || !isPrintableChar(b) || b == ':') {
            return minus ? -n : n;
        } else {
            fprintf(stderr, "NumberFormatException\n");
            exit(1);
        }
        b = FastScanner_readByte(scanner);
    }
}

int FastScanner_nexI(FastScanner* scanner) {
    long nl = FastScanner_nexL(scanner);
    if (nl < INT_MIN || nl > INT_MAX) {
        fprintf(stderr, "NumberFormatException\n");
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

void FastScanner_niL(FastScanner* scanner, long* array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = FastScanner_nexL(scanner);
    }
}

void FastScanner_niI(FastScanner* scanner, int* array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = FastScanner_nexI(scanner);
    }
}

void FastScanner_niII(FastScanner* scanner, int* as, int* bs, int length) {
    for (int i = 0; i < length; i++) {
        as[i] = FastScanner_nexI(scanner);
        bs[i] = FastScanner_nexI(scanner);
    }
}

void FastScanner_niLL(FastScanner* scanner, long* as, long* bs, int length) {
    for (int i = 0; i < length; i++) {
        as[i] = FastScanner_nexL(scanner);
        bs[i] = FastScanner_nexL(scanner);
    }
}

void FastScanner_niIII(FastScanner* scanner, int* as, int* bs, int* cs, int length) {
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
    fillB(flaged, false, n);

    long pop1st = 0L;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
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
                if (dw < 0) printf("%d\n", 1 / 0);
                int count = countFlaged(dw);
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
