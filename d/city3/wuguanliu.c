inherit ROOM;

void create()
{
	set("short", "��ţ����Ĳ�");
	set("long", @LONG
�����ǽ�ţ��ݽ����Ĳ���ʦ�����������ڻ����Ṧ����
���ڹ��������мܣ������Ʒ�������������
LONG);
	set("objects", ([
		__DIR__"npc/liuhongying" : 1,
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"wuguan",
	]));
	setup();
	replace_program(ROOM);
}
