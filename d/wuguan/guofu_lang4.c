inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�����������ڵ���Ʒ����Ҫ�����������
���˶���ȥ��Ʒ���칤�ߣ��ϱ��Ƕ����䳡��
LONG);
        set("no_fight", 1);
        set("exits", ([
               "north" : __DIR__"guofu_wupinfang",
               "south" : __DIR__"guofu_wuchang4",
        ]));
        set("objects", ([
                __DIR__"npc/wusantong" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
