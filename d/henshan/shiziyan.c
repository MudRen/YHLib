inherit ROOM;

void create()
{
        set("short", "ʨ����");
        set("long", @LONG
ʨ���Ҳ������ι�״����ʯ��ϸ�������ʨ�ӣ���Ծ����
��Ф���ࡣ��ʨ���ң�ף�ڷ��Ѿ������ˡ�
LONG);
        set("exits", ([ 
               "southwest"  : __DIR__"nantian",
               "northup"    : __DIR__"wangritai",
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

