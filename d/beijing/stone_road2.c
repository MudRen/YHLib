inherit ROOM; 

void create() 
{  
	set("short", "��ʯС·"); 
	set("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻÿ���·��
������ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ����������������ܵ�������
�����м����᷿���ǹ��ھ������ʦ����Ҿ��ס�ġ�
LONG); 

  	set("exits", ([
  		"north" : __DIR__"pavillion",
  		"south" : __DIR__"stone_road",
  		"west" : __DIR__"cabinet",
	]));

	setup(); 
	replace_program(ROOM); 
} 
