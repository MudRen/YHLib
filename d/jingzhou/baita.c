inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ������ߵİ������ഫ��ǰ��һλ״Ԫ�ɿ�ȡ��
����������ĸ���޽��ı�������
LONG);
	set("exits", ([  
  		"up" : __DIR__"baita1",
  		"south" : __DIR__"dongdajie1",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                "/d/beijing/npc/shusheng2" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
