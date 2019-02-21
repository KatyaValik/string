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
			strcpy(p,s.p);
		}
		
		mystr(int a) {
			char str[100];
			sprintf(str,"%i",a);
			len=strlen(str);
			p=new char[len+1];
			strcpy(p,str);
		}

		mystr(const char* s) {
			len=strlen(s);
			p=new char[len+1];
			strcpy(p,s);
		}

		mystr(char c, int n) {
			p=new char[n+1];
			memset(p,c,n);
		}
		
		~mystr() {
			if (p!=NULL)
				delete[] p;
			else cout << "No more mystr objects\n " << endl;
		}

		operator int() const {
			const char*c=p;
			return(atoi(c));
		}


		mystr operator = (const mystr& str)
		{
			if( (str.p == this->p) && (str.len == this->len) )
				return *this;
			else
				return mystr(str);
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
			a.p[len+1]=0;
			for(int i=0;i<strlen(this->p);i++) {
				a.p[i]=this->p[i];
			}
			for (int j=strlen(this->p)+1;j<=len;j++) {
				a.p[j]=s.p[j];
			}
			return a;
		}

	/*	mystr operator + (const mystr &s) {
			char* buf=new char[len+s.len+1];
			//buf[0]='\0';
			strcpy(buf,this->p);
			strcat(buf, s.p);
			mystr rezult(buf);
			delete []buf;
			return rezult;
		}*/
		
		mystr operator += (const mystr &s)
		{
				
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
		friend istream& operator >> (istream &in, const mystr &s);
		friend ostream& operator << (ostream &out, const mystr &s);
};


		/*istream& operator >> (istream &in, const mystr &s) {
			in >> s.p;
			return in;
		}
		istream& operator >> (istream &in, mystr &s) {
			int size=0;
			in.sync();
			mystr tmp;
			while (in.peek()!=10) {
				mystr a((char)in.get());
				//tmp=tmp+(char)in.get();
				tmp=tmp+a;
				size++;
			}
			delete []s.p;
			s.len=tmp.len;
			s.p= new char[s.len];
			s=tmp;
			return in;
		}*/

		ostream& operator << (ostream &out, const mystr &s) {
			out << s.p;
			return out;
 		}
	
	/*	bool mystr::operator > (const mystr &s1, const mystr &s2) {
			if (strcmp(s1.p,s2.p)>0) return 1
				else return 0;
		}
		bool mystr::operator < (const mystr &s1, const mystr &s2) {
			if (strcmp(s1.p,s2.p)<0) return 1
				else return 0;
		}*/


int main() {
	mystr a="qwer";
	//cout << a;
	mystr b(123);
	mystr c(a+b);
	cout << c;
}


