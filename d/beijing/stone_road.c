inherit ROOM; 
 
void create() 
{ 
	set("short", "��ʯС·");
	set("long", @LONG
С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻÿ���·��
������ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ����������������ܵ�������
�����м����᷿���ǹ��ھ������ʦ����Ҿ��ס�ġ�
LONG
	);

	set("exits", ([
  		"north" : __DIR__"stone_road2",
  		"east" : __DIR__"stone_road3",
  		"south" : __DIR__"c_garden",
	]));

	setup();
	replace_program(ROOM);
}
