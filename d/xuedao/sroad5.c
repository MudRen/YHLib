inherit ROOM;

void create()
{
        set("short", "��ѩɽ��");
        set("long", @LONG
�����ر�ѩ������ǰ�װ�����һƬ��
LONG);
        set("exits", ([
                "eastdown"  : __DIR__"sroad4",
                "southup"   : __DIR__"sroad6",
        ]));
        set("outdoors", "xuedao");
        setup();
	replace_program(ROOM);
}
