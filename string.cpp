#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class mystr {
	private:
		char *p;
		int len;
	static int objects;
	static int size;
	public:
		mystr() {
			p=NULL;
			len=0;
		}
		
		mystr(const mystr &s) {
			len=strlen(s.p);
			p=new char[len+1];
			objects++;
			size=size+len;
			strcpy(p,s.p);
		}
		
		mystr(int a) {
			char str[100];
			sprintf(str,"%i",a);
			len=strlen(str);
			p=new char[len+1];
			objects++;
			size=size+len;
			strcpy(p,str);
		}

		mystr(const char* s) {
			len=strlen(s);
			p=new char[len+1];
			objects++;
			size=size+len;
			strcpy(p,s);
		}

		mystr(char c, int n) {
			p=new char[n+1];
			len=n;
			objects++;
			size=size+len;
			memset(p,c,n);
		}
		
		~mystr() {
			if (p!=NULL) {
				size=size-len;
				objects--;
				delete[] p;
			}
			if (objects==0)
				cout <<"No more mystr objects (size="<<size <<")"<< endl;
		}

		operator int() const {
			const char*c=p;
			return(atoi(c));
		}

		mystr operator = (const mystr& str) {
			if(len!=str.len) {
				size=size-len;
				delete p;
				len=str.len;
				p=new char[len+1];
				size=size+str.len;
			}
			strcpy(p,str.p);
			return *this;
		}

		mystr operator = (const char* str)
        {
                return mystr(str);
        }

		mystr operator + (const mystr &s)
		{
			mystr a;
			a.len=strlen(s.p)+strlen(this->p);
			a.p=new char[len+1];
			objects++;
			size=size+len;
			strcpy( a.p, this->p );
			strcat( a.p, s.p );
			return a;
		}


		mystr operator += (const mystr &s)
		{
			mystr b;
			b=*this+s;
			*this=b;
			return *this;
		}
			
		bool operator == (const mystr & s2) 
		{
			if (this->len!=s2.len) 
				return 0;
			for (int i=0;i<=strlen(s2.p);i++) {
				if (this->p[i]!=s2.p[i]) return 0;
			}
			return 1;
		}
		char null='\0';

		char& operator[] (unsigned int i) {
			if (i<len) {
				return *(p+i);
			} else {
				return null;
			}
		};

		friend istream& operator >> (istream &in, mystr &s);
		friend ostream& operator << (ostream &out, const mystr &s);
		friend bool operator > (const mystr &s1, const mystr &s2);
		friend bool operator < (const mystr &s1, const mystr &s2);
};

		int mystr::objects=0;
		int mystr::size=0;



		istream& operator >> (istream &in,  mystr &s) {
			delete [] s.p;
			char c;
			char *x=(char*)malloc(1);
			int length=0;
			in>>noskipws>>c;
			while ((c!=' ')&&(c!='\n')) {
				length++;
				x=(char*)realloc(x,length+1);
				*(x+(length-1))=c;
				in>>noskipws>>c;
			}
			*(x+length)='\0';
			s.len=length;
			s.p=new char [length+1];
			s.objects++;
			s.size=s.size+s.len;
			strcpy(s.p,x);
			free(x);
			return in;
		}

		ostream& operator << (ostream &out, const mystr &s) {
			out << s.p << std::endl;
			return out;
 		}
	
		bool operator > (const mystr &s1, const mystr &s2) {
			if (strcmp(s1.p,s2.p)>0) {
				return 1;
			}
				else return 0;
		}
		bool operator < (const mystr &s1, const mystr &s2) {
			if (strcmp(s1.p,s2.p)<0) {
				return 1;
			}
				else return 0;
		}


int main() {
	mystr a="qwer";
	mystr b;
	cin>>b;
	if (a<b) 
		cout<<"a<b"<<endl;
	if (a==b) 
			cout<<"a==b"<<endl;
	if (a>b) 
		cout<<"a>b"<<endl;
	b[5]='A';
	cout<<b;
	mystr c;
	c=a+b;
	cout<<c;
		
}


