// changlang.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����������ȣ��Ĵ�͸��ŨŨ�ĺ�������ȥ����ɽׯ���ţ���������
��ȥ����ֱ���������Χһ����Ⱦ���ǳ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"dating",
	    "out"   : __DIR__"damen"
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
