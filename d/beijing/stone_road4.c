inherit ROOM; 

void create() 
{  
	set("short", "��ʯС·"); 
	set("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻÿ���·��
������ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ����������������ܵ�������
·�����Ը���һ����լ��
LONG); 

  	set("exits", ([
  		"south" : __DIR__"son_cabinet1",
  		"north" : __DIR__"son_cabinet2",
  		"west" : __DIR__"stone_road3",
  		"east" : __DIR__"rain",
	]));

	setup(); 
	replace_program(ROOM); 
} 
