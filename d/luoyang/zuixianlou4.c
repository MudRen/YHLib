inherit ROOM;

void create()
{
	set("short", "����¥�Ĳ�");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳�
�ȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ��
���Ŀ�������������һ�غ�ˮ���̲��������������ǳ�ɽ���룬�����ۻ룬
Ρ��׳�ۡ�
LONG);

	set("no_clean_up", 0);
	set("exits", ([
  		"down" : __DIR__"zuixianlou3",
	]));
        set("objects", ([
                __DIR__"npc/libai" : 1,
                "/d/beijing/npc/richman1" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
