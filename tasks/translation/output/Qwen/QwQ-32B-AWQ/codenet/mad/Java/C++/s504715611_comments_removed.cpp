#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

struct UnionFind {
    vector<int> Parent;
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) {
        return -Parent[root(A)];
    }
    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
public:
    FastScanner(istream& in = cin) : in(in) {}
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = in.read(buffer, sizeof(buffer)).gcount();
        if (buflen <= 0) return false;
        return true;
    }
    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += static_cast<char>(b);
            b = readByte();
        }
        return sb;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No element");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Invalid number");
        while (true) {
            if (b >= '0' && b <= '9') {
                n = n * 1	double mod = 1000000007;
		const double eps = 1.0e-14;
		const int big = INT_MAX;
		const double PI = 3.14159265358979323846262338327950288;

		long long modlcm(long long a,long long b) {return a*b*modint(gcd(a,b),mod);}
		long long gcd (long long a, long long b) {return b>0?gcd(b,a%b):a;}
		long long lcm (long long a, long long b) {return a/gcd(a,b)*b;}
		int max(int a,int b) {return a>b?a:b;}
		int min(int a,int b) {return a<b?a:b;}
		long long lmax(long long a,long long b) {return a>b?a:b;}
		long long lmin(long long a,long long b) {return a<b?a:b;}
		long long factorial(int i) {return i==1?1LL:i*factorial(i-1);}

		int lower_bound(const vector<int>& a, int key) {
			int right=a.size();
			int left=0;
			while(right-left>1) {
				int mid=(right+left)/2;
				if(a[mid]<key) {
					left=mid;
				}
				else {
					right=mid;
				}
			}
			return left;
		}
		int upper_bound(const vector<int>& a, int key) {
			int right=a.size();
			int left=0;
			while(right-left>1) {
				int mid=(right+left)/2;
				if(a[mid]<=key) {
					left=mid;
				}
				else {
					right=mid;
				}
			}
			return left;
		}
		bool isPrime (long long n) {
			if (n==2) return true;
			if (n<2 || n%2==0) return false;
			long long d = sqrt(n);
			for (long long i=3; i<=d; i+=2)if(n%i==0){return false;}
			return true;
		}
		int upper_division(int a,int b) {
			return a%b==0?a/b:a/b+1;
		}
		long long lupper_division(long long a,long long b) {
			return a%b==0?a/b:a/b+1;
		}
		vector<int> setArray(int a, FastScanner& scan) {
			vector<int> b(a);
			for(int i=0;i<a;i++) b[i]=scan.nextInt();
			return b;
		}
		vector<long long> lsetArray(int a, FastScanner& scan) {
			vector<long long> b(a);
			for(int i=0;i<a;i++) b[i]=scan.nextLong();
			return b;
		}
		string reverse(const string& str) {
			string ret(str);
			int a=str.size();
			for(int i=0;i<upper_division(a,2);i++) {
				ret[i]=str[a-i-1];
				ret[a-i-1]=str[i];
			}
			return ret;
		}
		void printArray(const vector<int>& que) {
			for(size_t i=0;i<que.size()-1;i++) cout<<que[i]<<" ";
			cout<<que.back()<<endl;
		}
		vector<vector<int>> doublesort(vector<vector<int>>& a) {
			sort(a.begin(),a.end(),[](const vector<int>& x,const vector<int>& y){return x[0]<y[0];});
			return a;
		}
		vector<vector<long long>> ldoublesort(vector<vector<long long>>& a) {
			sort(a.begin(),a.end(),[](const vector<long long>& x,const vector<long long>& y){return x[0]<y[0];});
			return a;
		}
		long long modpow(long long x,long long n,long long mo) {
			long long sum=1;
			while(n>0) {
				if(n&1) sum=sum*x%mo;
				x=x*x%mo;
				n>>=1;
			}
			return sum;
		}
		vector<char> revch(const vector<char>& ch) {
			vector<char> ret(ch.size());
			for(int i=ch.size()-1,j=0;i>=0;i--,j++) ret[j]=ch[i];
			return ret;
		}
		vector<int> revint(const vector<int>& ch) {
			vector<int> ret(ch.size());
			for(int i=ch.size()-1,j=0;i>=0;i--,j++) ret[j]=ch[i];
			return ret;
		}
		void warshall_floyd(vector<vector<int>>& v, int n) {
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
		}
		long long modint(long long a,long long m) {
			long long b=m,u=1,v=0;
			while(b!=0) {
				long long t=a/b;
				a -=t*b;
				long long x=a;
				a=b;
				b=x;
				u -=t*v;
				x=u;
				u=v;
				v=x;
			}
			u %=m;
			if(u<0) u +=m;
			return u;
		}
}

int main() {
	FastScanner scan;
	string str = scan.next();
	cout << (str.size() >=6 && str[2]==str[3] && str[4]==str[5] ? "Yes" : "No") << endl;
	return 0;
}
// End of Code
