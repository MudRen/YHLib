inherit ROOM; 

void create() 
{  
	set("short", "��ʯС·"); 
	set("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻÿ���·��
������ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ����������������ܵ�������
С·�������м����᷿���ǹ��ھ������ʦ�����ּ����
���ס�ġ�
LONG); 

  	set("exits", ([
  		"east" : __DIR__"stone_road4",
  		"west" : __DIR__"stone_road",
	]));

	setup(); 
	replace_program(ROOM); 
} 
