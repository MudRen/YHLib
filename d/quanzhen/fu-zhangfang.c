inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
�����Ǻ�Ա��ҵ��ʷ���������ש�̵أ����Ŵ��������
���ӣ�һ���ܼ�����������С�۾���ס�ظ�����ת��������
�ڴ�ʲô�����⡣
LONG);
        set("exits", ([
                "east" : __DIR__"fu-datang",
        ]));
        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
