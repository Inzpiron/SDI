program HELLO_WORLD_PROG {
	version HELLO_WOLRD_VERS {
		string HW(void) = 1;
		int getid(string) = 2;
		void newmessage(string) = 3;
		string getmessage(int) = 4;
	} = 1;
} = 0x30009998;
