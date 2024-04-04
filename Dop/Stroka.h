#ifndef STROKA_H_
#define STROKA_H_

class Stroka{
	
	public:
		Stroka(char*);
		Stroka();
		Stroka(const Stroka&);
		Stroka& operator=(const Stroka&);
		Stroka& operator=(const char* s);
		Stroka& operator+(const Stroka&);
		int operator == (const Stroka&);
		int dlina();
		void vvod();
		void vyvod();
		~Stroka();
		
	private:
		char *str;
};

#endif /* STROKA_H_ */