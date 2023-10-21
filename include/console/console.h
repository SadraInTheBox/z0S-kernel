#define PURPLE_TXT 0x5
#define WHITE_TXT 0x7
#define VGA 0xb8000
#define width 81
#define height 26

unsigned int line = 0;


void clear_console()
{
	char *vga = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vga[i]=' ';
		i++;
		vga[i]=WHITE_TXT;
		i++;
	};

	line = 0;
};

unsigned int printText(char *message)
{
	char *vga = (char *) VGA;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n')
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			vga[i]=*message;
			*message++;
			i++;
			vga[i]=WHITE_TXT;
			i++;
		};
	};

	line++;

	return(1);
}

char screen[width][height];

void fill(char f){
    for(int j = 0; j < 25; j++){
        for(int i = 0; i < 80; i++){
            screen[j][i] = f;
        }
    }
}

void update(){
	char *vga = (char *) VGA;
	for(int line = 0; line < height; line++){
		char *msg;
		for(int word = 0; word < width; word++){
			msg[word] = screen[line][word];
		}
		printText(msg);
	}
}

void drawPoint(int x, int y){
    screen[y][x] = '\xDB';
}