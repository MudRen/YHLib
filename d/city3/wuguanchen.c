inherit ROOM;

void create()
{
	set("short", "��ţ���һ��");
	set("long", @LONG
�����ǽ�ţ��ݽ���һ����ʦ����䰽��ڻ����Ṧ������
�ڹ��������мܣ�����ȭ���������ȷ�������������
LONG);
	set("objects", ([
		__DIR__"npc/chenhu" : 1,
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"wuguan",
	]));
	setup();
	replace_program(ROOM);
}
