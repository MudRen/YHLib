inherit ROOM;
void create()
{
	set("short","��ɭ��");
	set("long",@LONG
��ȥ��ͨ��ï�ܵ�ɭ�ֿ��Ե������������������Ѿ���
ľï���˼������ˣ����治Զ���������ĵ���ˡ�
LONG);
	set("outdoors", "kunming");
	set("exits", ([
	    "south" : __DIR__"dianchi",
	    "north" : __DIR__"heisenlin",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

