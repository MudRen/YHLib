inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ����᫵�ɽ·�ϣ������ϣ��ͽ������ƹ��ԭ�ˡ�
������һ�������סȥ·��
LONG);
        set("outdoors", "kunming");

        set("exits", ([
		"south": __DIR__"yunnan",
                "north"  :__DIR__"road6",
        ]));
        set("objects", ([
                "/d/beijing/npc/tangzi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}